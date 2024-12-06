//
//  DemoSplashViewController.m
//  AAA
//
//  Created by CherryKing on 2019/11/1.
//  Copyright © 2019 CherryKing. All rights reserved.
//

#import "DemoSplashViewController.h"
#import <YFAdsSDK/YFAdSplash.h>
#import "AdDataJsonManager.h"
#import "YFEnvironmentManager.h"
#import "DemoPresentViewController.h"

@interface DemoSplashViewController () <YFAdSplashDelegate>

@property(strong,nonatomic) YFAdSplash *FCAdSplash;
@property (nonatomic, strong) UISlider * slider;
@property (nonatomic, strong) UILabel * marginLabel;

//@property(assign,nonatomic)UIBackgroundTaskIdentifier backgroundTask;
@end

@implementation DemoSplashViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"开屏广告";
//    self.isOnlyLoad = NO;
//    self.dic = [[AdDataJsonManager shared] loadAdDataWithType:JsonDataType_splash];
//    NSLog(@"%@", self.dic);
   // [self startBackgroundTask];
    self.slider = [UISlider new];
    self.slider.frame = CGRectMake(30, 330,self.view.frame.size.width - 60, 20);
    self.slider.minimumValue = 0;
    self.slider.maximumValue = kScreenH;
    self.slider.value = 80.;
    [self.slider addTarget:self action:@selector(sliderEndChangeValue:) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:self.slider];

    self.marginLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 350,self.view.frame.size.width, 20)];
    self.marginLabel.textAlignment = NSTextAlignmentCenter;
    self.marginLabel.text = @"底部视图高度：80";
    [self.view addSubview:self.marginLabel];

}

- (void)sliderEndChangeValue:(id)va {
    self.marginLabel.text = [NSString stringWithFormat:@"底部视图高度：%d", (int)self.slider.value];
}



- (void)loadAndShowAd {
    [self loadAndShowSplashAd];
}

- (void)showAd {
    if (!self.FCAdSplash) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    if (!self.FCAdSplash.isValid) {
        [JDStatusBarNotification showWithStatus:@"广告未加载成功或者已失效" dismissAfter:1.5];
        return;
    }
    [self.FCAdSplash showAd];

}

- (void)loadAd {
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    
    self.FCAdSplash = [self returnAdInstance];
    [self.FCAdSplash loadAd];
    
    [self loadAdWithState:AdState_Loading];

}

-(void)changeVC {
    
    if (!self.FCAdSplash) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    if (!self.FCAdSplash.isValid) {
        [JDStatusBarNotification showWithStatus:@"广告已失效，请重新拉取" dismissAfter:1.5];
        return;
    }
    DemoPresentViewController * pvc = [[DemoPresentViewController alloc] init];
    pvc.adapter = self.FCAdSplash;
    [self.navigationController pushViewController:pvc animated:YES];
    
}

- (void)deallocAd {
//    self.YFAdSplash = nil;
//    self.YFAdSplash.delegate = nil;
}

- (void)loadAndShowSplashAd{
    // 广告实例不要用初始化加载, 要确保每次都用最新的实例, 且一次广告流程中 delegate 不能发生变化
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    
    self.FCAdSplash = [self returnAdInstance];
    [self.FCAdSplash loadAndShowAd];
    
    [self loadAdWithState:AdState_Loading];

}

- (YFAdSplash *)returnAdInstance {
    
    YFAdSplash *splash = [[YFAdSplash alloc] initWithAdUnitID:[YFEnvironmentManager getHotSPLASH_ID] viewController:self];
    splash.delegate = self;
    splash.showLogoRequire = YES;
#pragma mark =============== sp-new ===============
    UIImageView *imageView = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, kScreenW, self.slider.value)];
    imageView.image = [UIImage imageNamed:@"app_logo"];
    imageView.contentMode = UIViewContentModeScaleToFill;
    
    UILabel *bottomLabel = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, kScreenW, 80)];
    bottomLabel.text = @"这是开屏底部视图，不要超过屏幕高度的20%";
    bottomLabel.textAlignment = NSTextAlignmentCenter;
    [imageView addSubview:bottomLabel];
    splash.bottomView = imageView;
    
    UIImageView *backgroundV = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, kScreenW, kScreenH)];
    backgroundV.image = [UIImage imageNamed:@"splashBg"];
        
    splash.backgroundView = backgroundV;
#pragma mark =============== sp-old ===============

//    splash.logoImage = [UIImage imageNamed:@"app_logo"];
//    splash.backgroundImage = [UIImage imageNamed:@"LaunchImage_img"];
    splash.timeout = 5;
    [self showProcessWithText:@""];

    return splash;
}

/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    AlertIfNotMainThread
    self.isLoaded = YES;
    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
    NSLog(@"=========%@",self.FCAdSplash.isValid?@"有效":@"无效");
    ///===================

    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功", __func__]];
}

/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter  description:(NSDictionary *)description{
    AlertIfNotMainThread
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error.userInfo.description]];
        [self showErrorWithDescription:description];
    });
}



/// 广告曝光成功
- (void)fcAdExposured:(id)adapter  {
    AlertIfNotMainThread
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
    NSLog(@"广告曝光成功 %s", __func__);
}

/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description{
    AlertIfNotMainThread
    NSLog(@"广告加载失败 %s  error: %@ 详情:%@", __func__, error, description);
    //通知主线程刷新
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error.userInfo.description]];
        [self showErrorWithDescription:description];
    });
    [self loadAdWithState:AdState_LoadFailed];
    [self deallocAd];

}



/// 广告点击
- (void)fcAdClicked:(id)adapter  {
    AlertIfNotMainThread
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击", __func__]];
    NSLog(@"广告点击 %s", __func__);
}

/// 广告关闭
- (void)fcAdDidClose:(id)adapter  {
    AlertIfNotMainThread
    NSLog(@"广告关闭了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭", __func__]];
    [self loadAdWithState:AdState_Normal];
    [self deallocAd];
}

/// 广告关闭
- (void)fcAdDidCloseOtherController:(id)adapter  interactionType:(YFAdInteractionType)interactionType  {
    AlertIfNotMainThread
    NSLog(@"广告关闭了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭", __func__]];
    [self loadAdWithState:AdState_Normal];
    [self deallocAd];
}



/// 广告倒计时结束
- (void)fcAdSplashOnAdCountdownToZero {
    AlertIfNotMainThread
    NSLog(@"广告倒计时结束 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告倒计时结束", __func__]];
}

/// 点击了跳过
- (void)fcAdSplashOnAdSkipClicked {
    AlertIfNotMainThread
    NSLog(@"点击了跳过 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 点击了跳过", __func__]];
    [self loadAdWithState:AdState_Normal];
    [self deallocAd];
}

- (void)fcAdSplashBackViewTimeout:(UIView *)view {
    AlertIfNotMainThread
    NSLog(@"开屏背景图 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 开屏背景图结束", __func__]];

}

-(void)dealloc {
    NSLog(@"开屏释放 %s", __func__);
}

@end
