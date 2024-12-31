//
//  DemoInterstitialViewController.m
//  advancelib
//
//  Created by allen on 2019/12/31.
//  Copyright © 2019 Bayescom. All rights reserved.
//

#import "DemoInterstitialViewController.h"
#import <YFAdsSDK/YFAdInterstitial.h>
#import "YFDataJsonManager.h"
#import "YFEnvironmentManager.h"
#import "DemoPresentViewController.h"
#import "UIAlertController+Blocks.h"

@interface DemoInterstitialViewController () <YFAdInterstitialDelegate>

@property (nonatomic, strong) YFAdInterstitial *interstitial;
@property (nonatomic) bool isAdLoaded;

@end

@implementation DemoInterstitialViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.dic = [[YFDataJsonManager shared] loadAdDataWithType:JsonDataType_interstitial];
    self.title = @"插屏广告";
}

- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    // 插屏广告初始化 viewController需传入最上层可见控制器，否则无法模态推出广告落地页及广告，影响展示和转化
    self.interstitial = [[YFAdInterstitial alloc] initWithAdUnitID:[YFEnvironmentManager getINSERT_ID] viewController:self];
    self.interstitial.delegate = self;
    _isAdLoaded = false;
    [self.interstitial loadAd];
    [self loadAdWithState:AdState_Loading];
}

- (void)showAd {
    if (!self.interstitial || !self.isLoaded) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    if (!self.interstitial.isValid) {
        [JDStatusBarNotification showWithStatus:@"广告已失效，请重新拉取" dismissAfter:1.5];
        return;
    }
    // 如需切换页面展示 可重设rootController
//    [self.interstitial setRootController:<#(nonnull UIViewController *)#>];
    [self.interstitial showAd];
}

- (void)loadAndShowAd {
    [super loadAndShowAd];
    [self loadAdWithState:AdState_Normal];
    // 插屏广告初始化 viewController需传入最上层可见控制器，否则无法模态推出广告落地页及广告，影响展示和转化
    self.interstitial = [[YFAdInterstitial alloc] initWithAdUnitID:[YFEnvironmentManager getINSERT_ID] viewController:self];
    self.interstitial.delegate = self;
    _isAdLoaded = false;
    [self.interstitial loadAndShowAd];
    [self loadAdWithState:AdState_Loading];
}

- (void)deallocAd {
    self.interstitial.delegate = nil;
    self.interstitial = nil;
    self.isLoaded = NO;
    [self loadAdWithState:AdState_Normal];
}

- (void)dealloc {
    NSLog(@"插屏释放 %s",__func__);
}

#pragma mark - YFAdInterstitialDelegate

/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    AlertIfNotMainThread
    self.isLoaded = YES;
    ///===================
    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功", __func__]];
}

/// 广告曝光
- (void)fcAdExposured:(YFAdBaseAdapter *)adapter  {
    AlertIfNotMainThread
    NSLog(@"广告曝光回调 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

/// 广告点击
- (void)fcAdClicked:(id)adapter  {
    AlertIfNotMainThread
    NSLog(@"广告点击 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击成功", __func__]];
}

/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter  description:(NSDictionary *)description{
    AlertIfNotMainThread
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
    //通知主线程刷新
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error.userInfo.description]];
        [self showErrorWithDescription:description];
    });
    [self loadAdWithState:AdState_LoadFailed];
    [self deallocAd];
}

/// 广告关闭了
- (void)fcAdDidClose:(id)adapter  {
    AlertIfNotMainThread
    NSLog(@"广告关闭了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭了", __func__]];
    [self deallocAd];
}

/// 广告关闭了
- (void)fcAdDidCloseWithView:(id)adapter  {
    AlertIfNotMainThread
    NSLog(@"广告关闭了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭了", __func__]];
    [self deallocAd];
}

- (void)fcAdDidCloseOtherController:(id)adapter interactionType:(YFAdInteractionType)interactionType {
    AlertIfNotMainThread
    NSLog(@"广告关闭-fcAdDidCloseOtherController");
}

@end
