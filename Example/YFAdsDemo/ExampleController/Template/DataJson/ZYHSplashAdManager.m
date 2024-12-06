//
//  SplashAdManager.m
//  Volunteer
//
//  Created by liwei sun on 2024/3/7.
//  Copyright © 2024 Hangzhou Yicun Technology Co., Ltd. All rights reserved.
//

#import "ZYHSplashAdManager.h"
#import <YFAdsSDK/YFAdSDKManager.h>
#import <YFAdsSDK/YFAdSplash.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>
#import "YFEnvironmentManager.h"
#import "DemoLaunchSplashViewController.h"
#import "DemoUtils.h"

@interface ZYHSplashAdManager () <YFAdSplashDelegate>

/**
 亿帆开屏广告
 */
@property(nonatomic, strong)YFAdSplash *coldSplashAd;
@property(nonatomic, assign)BOOL isEnd;
/// 开屏广告背景图可选择添加；
@property (nonatomic, strong) UIImageView *splashBackgroundView;

@end

@implementation ZYHSplashAdManager

static ZYHSplashAdManager *manager = nil;

+ (instancetype)sharedManager {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        manager = [[ZYHSplashAdManager alloc] init];
    });
    return manager;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        //在UIApplicationDidFinishLaunching时初始化开屏广告,做到对业务层无干扰,当然你也可以直接在AppDelegate didFinishLaunchingWithOptions方法中初始化
        [[NSNotificationCenter defaultCenter] addObserverForName:UIApplicationDidFinishLaunchingNotification object:nil queue:nil usingBlock:^(NSNotification * _Nonnull note) {
            NSLog(@"冷启开屏");
            [self showSplashAdWithID:[YFEnvironmentManager getColdSPLASH_ID]];
        }];
        
    }
    return self;
}

- (void)initAdSDK {
///  添加拓展参数
    NSMutableDictionary * customDefine = [[NSMutableDictionary alloc] initWithCapacity:0];
//    [customDefine setValue:@"c1" forKey:@"c1"];
//    [customDefine setValue:@"c2" forKey:@"c2"];
//    [customDefine setValue:@"c3" forKey:@"c3"];
//    [customDefine setValue:@"c4" forKey:@"c4"];
//    [customDefine setValue:@"5" forKey:@"c5"];
//    [customDefine setValue:@"6" forKey:@"c6"];
    [YFAdSDKSetting shareInstance].customDefine = customDefine;
    
///  自定义用户标签
    NSMutableDictionary * userDefine = [[NSMutableDictionary alloc] initWithCapacity:0];
//    这里需要替换成真实的用户ID
//    [userDefine setValue:@"<#yf_demo_user_id#>" forKey:@"UserID"];
    [YFAdSDKSetting shareInstance].userDefine = userDefine;

    [YFAdSDKSetting shareInstance].userId = @"test";
    [YFAdSDKSetting shareInstance].logEnable = YES;
    [YFAdSDKSetting shareInstance].fc_conf_url = [YFEnvironmentManager getFC_CONF_URL];
    [YFAdSDKSetting shareInstance].fc_upload_url = [YFEnvironmentManager getFC_UPLOAD_URL];
    [YFAdSDKSetting shareInstance].yf_conf_url = [YFEnvironmentManager getYF_CONF_URL];
    [YFAdSDKSetting shareInstance].fc_data_url = [YFEnvironmentManager getYF_DATA_URL];
    [YFAdSDKSetting shareInstance].useLocation = YES;
    //SDK注册
    [YFAdSDKManager setupSDKWithAppId:[YFEnvironmentManager getAPP_ID]];
}

/**
 展示开屏广告
 */
- (void)showSplashAdWithID:(NSString *)adID {
    
    [ZYHSplashAdManager sharedManager].show = YES;
    self.isEnd = NO;
    /// 获取keywindow
    self.window = [DemoUtils getKeyWindow];
    /// 获取当前最上层控制器
    UIViewController *rootVC = [self getFrontViewControllerFromController:self.window.rootViewController];
    NSLog(@"开屏-亿帆-启动");
    /// 初始化自定义的广告背景图（可选）
    if (!_splashBackgroundView)
        _splashBackgroundView = [UIImageView new];
    _splashBackgroundView.image = [UIImage imageNamed:@"splashBg"];
    [self.window addSubview:_splashBackgroundView];
    _splashBackgroundView.frame = UIScreen.mainScreen.bounds;
//    [self.window bringSubviewToFront:_splashBackgroundView];
    /// 注意： 初始化传入当前可见最上层控制器，避免无法弹出落地页
    self.coldSplashAd = [[YFAdSplash alloc] initWithAdUnitID:adID viewController:rootVC];
    self.coldSplashAd.delegate = self;
    /// 设置开屏底部视图（可选）
    UIImageView *imageView = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, kScreenW, 80)];
    imageView.image = [UIImage imageNamed:@"app_logo"];
    UILabel *bottomLabel = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, kScreenW, 80)];
    bottomLabel.text = @"这是开屏底部视图，不要超过屏幕高度的20%";
    bottomLabel.textAlignment = NSTextAlignmentCenter;
    [imageView addSubview:bottomLabel];
    self.coldSplashAd.bottomView = imageView;
    /// 设置开屏背景图（可选）
    UIImageView *backgroundV = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, kScreenW, kScreenH)];
    backgroundV.image = [UIImage imageNamed:@"splashBg"];
    self.coldSplashAd.backgroundView = backgroundV;
    /// 超时时间
    self.coldSplashAd.timeout = 5;
    /// 是否展示底部logo视图
    self.coldSplashAd.showLogoRequire = YES;
    /// 加载广告
    [self.coldSplashAd loadAd];
    /// 兜底倒计时
    [self countDown];
}

/// 个别广告不走广告关闭的回调，所以加一个倒计时兜底，防止进入不了首页
-(void)countDown {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(15 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self execEnd];
    });
}

/// 广告结束
-(void)execEnd {
    if(!self.isEnd) {
        self.isEnd = YES;
        self.coldSplashAd = nil;
        dispatch_async(dispatch_get_main_queue(), ^{
            [self->_splashBackgroundView removeFromSuperview];
        });
        [[NSNotificationCenter defaultCenter] postNotificationName:@"YFSplashNotificationCenter" object:nil];
    }
}

#pragma mark - YFAdSplashDelegate
/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    NSLog(@"开屏-亿帆-广告数据加载成功");
    if(!self.isEnd) {
        [model showAd];
    }
}

/// 广告曝光成功
- (void)fcAdExposured:(YFAdBaseAdapter *)model {
    NSLog( @"开屏-亿帆-广告曝光成功");
    [ZYHSplashAdManager sharedManager].show = YES;
}

///  获取数据失败
- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter description:(NSDictionary *)description {
    NSLog(@"开屏-亿帆-广告加载失败-%@", error);
    [ZYHSplashAdManager sharedManager].show = NO;
    [self execEnd];
}

/// 广告点击
- (void)fcAdClicked:(YFAdBaseAdapter *)model {
    NSLog(@"开屏-亿帆-广告点击");
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_splashBackgroundView removeFromSuperview];
    });
}

-(void)fcAdDidCloseOtherController:(id)adapter interactionType:(YFAdInteractionType)interactionType {
    NSLog(@"开屏-亿帆-广告关闭-fcAdDidCloseOtherController");
    [self execEnd];
}

/// 广告关闭
- (void)fcAdDidClose:(YFAdBaseAdapter *)model {
    NSLog(@"开屏-亿帆-广告关闭");
    [ZYHSplashAdManager sharedManager].show = NO;
    [self execEnd];
}

/// 广告倒计时结束
- (void)fcAdSplashOnAdCountdownToZero {
    NSLog(@"开屏-亿帆-广告倒计时结束");
    [ZYHSplashAdManager sharedManager].show = NO;
    [self execEnd];
}

/// 点击了跳过
- (void)fcAdSplashOnAdSkipClicked {
    NSLog(@"开屏-亿帆-点击了跳过");
    [ZYHSplashAdManager sharedManager].show = NO;
    [self execEnd];
}

//loadandeshow
/// 广告背景超时
- (void)fcAdSplashBackViewTimeout:(UIView *)view {
    NSLog(@"开屏背景图 %s", __func__);
}

#pragma mark - private method
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

@end
