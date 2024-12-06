//
//  DemoLaunchSplashViewController.m
//  YFAdsSDK_Example
//
//  Created by feng on 2023/11/27.
//  Copyright © 2023 Cheng455153666. All rights reserved.
//

#import "DemoLaunchSplashViewController.h"
#import <YFAdsSDK/YFAdSplash.h>
#import "AdDataJsonManager.h"
#import "ViewController.h"
#import "YFEnvironmentManager.h"

@interface DemoLaunchSplashViewController ()<YFAdSplashDelegate>
@property(strong,nonatomic) YFAdSplash * adSplash;
@property(strong,nonatomic)  UIImageView  *bgImageView;
///是否满足切换SwitchRootVC条件
@property(assign,nonatomic)  Boolean isSwitchRootVC;
///设置超时时间 增加兜底
@property(assign,nonatomic) NSUInteger timeOut;
@end

@implementation DemoLaunchSplashViewController

#pragma mark  - property
- (UIImageView *)bgImageView{
    if (_bgImageView == nil) {
        _bgImageView = [[UIImageView alloc] initWithFrame:self.view.frame];
        _bgImageView.contentMode = UIViewContentModeScaleAspectFit;
    }
    return _bgImageView;
}

#pragma mark  - life crycle

- (void)viewDidLoad {
    [super viewDidLoad];
    self.isSwitchRootVC = YES;
    self.view.backgroundColor = [UIColor clearColor];
    self.bgImageView.image = [UIImage imageNamed:@"splashBg"];;
    [self.view addSubview:self.bgImageView];
    self.timeOut = 7;
}

- (void)dealloc {
    NSLog(@"开屏释放 %s", __func__);
    [self deallocAd];
}

- (void)deallocAd {
    self.bgImageView = nil;
    self.adSplash.delegate = nil;
    self.adSplash = nil;
}

#pragma mark - 加载开屏广告
/// 加载广告
- (void)loadAndShowSplashAd{
    self.adSplash = [self returnAdInstance];
    [self.adSplash loadAndShowAd];
    // 增加超时兜底 防止代理回调异常
    [self toAddSplashTimer];
}

/// 初始化开屏广告对象
- (YFAdSplash *)returnAdInstance {
    /// 获取当前最上层控制器
    UIViewController *topViewController = [self getFrontViewControllerFromController:[self getKeyWindowMethod].rootViewController];
    YFAdSplash *splash = [[YFAdSplash alloc] initWithAdUnitID:[YFEnvironmentManager getColdSPLASH_ID] viewController:[self getKeyWindowMethod].rootViewController];
    splash.delegate = self;
    splash.showLogoRequire = NO;
    
#pragma mark =============== 新接口 ===============
    UIImageView *imageView = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, kScreenW, 80)];
    imageView.image = [UIImage imageNamed:@"app_logo"];
    
    UILabel *bottomLabel = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, 200, 80)];
    bottomLabel.text = @"这是开屏底部视图，不要超过屏幕高度的20%";
    bottomLabel.textAlignment = NSTextAlignmentCenter;
    [imageView addSubview:bottomLabel];
    
    splash.bottomView = imageView;
    
    
    UIImageView *backgroundV = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, kScreenW, kScreenH)];
    backgroundV.image = [UIImage imageNamed:@"splashBg"];
        
    splash.backgroundView = backgroundV;
  
#pragma mark =============== 老接口 ===============
    splash.logoImage = [UIImage imageNamed:@"app_logo"];
    splash.backgroundImage = [UIImage imageNamed:@"splashBg"];
    splash.timeout = 5;
    return splash;
}

#pragma mark - YFAdSplashDelegate
/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    AlertIfNotMainThread
    self.isSwitchRootVC = NO;
    NSLog(@"广告加载成功 %s", __func__);

}

/// 广告曝光成功
- (void)fcAdExposured:(id)adapter  {
    AlertIfNotMainThread
    self.isSwitchRootVC = NO;
    NSLog(@"广告曝光成功 %s", __func__);
}

/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter  description:(NSDictionary *)description{
    AlertIfNotMainThread
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
    [self deallocAd];
    [self toSwitchRootVC];
}

/// 广告点击
- (void)fcAdClicked:(id)adapter {
    AlertIfNotMainThread
    self.isSwitchRootVC = NO;
    NSLog(@"广告点击 %s", __func__);
}

/// 广告关闭
- (void)fcAdDidClose:(id)adapter {
    AlertIfNotMainThread
    NSLog(@"广告关闭了 %s", __func__);
    [self deallocAd];
    [self toSwitchRootVC];

}

/// 广告倒计时结束
- (void)fcAdSplashOnAdCountdownToZero {
    AlertIfNotMainThread
    NSLog(@"广告倒计时结束 %s", __func__);
    [self toSwitchRootVC];
}

/// 点击了跳过
- (void)fcAdSplashOnAdSkipClicked {
    AlertIfNotMainThread
    NSLog(@"点击了跳过 %s", __func__);
    [self deallocAd];
    [self toSwitchRootVC];
}

#pragma mark - private method
///增加超时兜底 防止代理回调异常
- (void)toAddSplashTimer {
    __weak typeof(self) weakSelf = self;
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(self.timeOut * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if (weakSelf.isSwitchRootVC) {
            [weakSelf toSwitchRootVC];
        }
    });
}

/// 返回根控制器
- (void)toSwitchRootVC {
    self.isSwitchRootVC = NO;
    UINavigationController *navVC = [[UINavigationController alloc] initWithRootViewController:[ViewController new]];
    [UIApplication sharedApplication].keyWindow.rootViewController = navVC;
}

/// 获取最上层控制器
- (UIViewController *)getFrontViewControllerFromController:(UIViewController *)controller {
    UIViewController *vc = controller;
    
    while (vc.presentedViewController != nil) {
        vc = vc.presentedViewController;
    }
    
    if ([vc isKindOfClass:[UITabBarController class]]) {
        UITabBarController *tabBarController = (UITabBarController *)vc;
        if (tabBarController.selectedViewController != nil) {
            return [self getFrontViewControllerFromController:tabBarController.selectedViewController];
        }
    }
    
    if ([vc isKindOfClass:[UINavigationController class]]) {
        UINavigationController *navController = (UINavigationController *)vc;
        if (navController.topViewController != nil) {
            return [self getFrontViewControllerFromController:navController.topViewController];
        }
    }
    
    return vc;
}

/// 获取window
- (UIWindow *)getKeyWindowMethod {
    if (@available(iOS 13.0, *)) {
        UIWindow *mainWindow = [UIApplication sharedApplication].windows.firstObject;
        [mainWindow makeKeyWindow];
        return mainWindow;
    } else {
        UIWindow *mainWindow = [UIApplication sharedApplication].keyWindow;
        return mainWindow;
    }
}

@end
