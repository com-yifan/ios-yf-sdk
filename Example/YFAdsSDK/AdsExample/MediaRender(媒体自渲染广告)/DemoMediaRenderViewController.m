//
//  DemoInterstitialViewController.m
//  advancelib
//
//  Created by allen on 2019/12/31.
//  Copyright © 2019 Bayescom. All rights reserved.
//

#import "DemoMediaRenderViewController.h"
#import <YFAdsSDK/YFAdMediaRender.h>
#import <YFAdsSDK/YFAdMedia.h>
#import <YFAdsSDK/YFAdInterstitialDelegate.h>

#import "YFDataJsonManager.h"
#import "YFEnvironmentManager.h"
#import "DemoNativeSelfRenderView.h"
#import "DemoMediaRenderDetailViewController.h"

@interface DemoMediaRenderViewController () <YFAdInterstitialDelegate>
@property (nonatomic, strong) YFAdMediaRender *adMediaRender;
@property (nonatomic) bool isAdLoaded;
@property (nonatomic, strong) YFAdMedia *adMedia;

@end

@implementation DemoMediaRenderViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.dic = [[YFDataJsonManager shared] loadAdDataWithType:JsonDataType_interstitial];
    self.title = @"媒体自渲染广告";
}

- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    // 初始化加载器 viewController传入当前最上层可见控制器，否则无法模态推出广告落地页影响转化和收益
    self.adMediaRender = [[YFAdMediaRender alloc] initWithAdUnitID:[YFEnvironmentManager getMEDIA_ID] viewController:self];
    self.adMediaRender.delegate = self;
    _isAdLoaded = YES;
    [self.adMediaRender loadAndShowAd];
    [self loadAdWithState:AdState_Loading];
}

- (void)showAd {
    if (!self.adMediaRender || !self.isLoaded) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    [self.adMediaRender showAd];
}

- (void)loadAndShowAd {
    [super loadAndShowAd];
    [self loadAdWithState:AdState_Normal];
    // 初始化加载器 viewController传入当前最上层可见控制器，否则无法模态推出广告落地页影响转化和收益
    self.adMediaRender = [[YFAdMediaRender alloc] initWithAdUnitID:[YFEnvironmentManager getMEDIA_ID] viewController:self];
    self.adMediaRender.delegate = self;
    _isAdLoaded = false;
    [self.adMediaRender loadAndShowAd];
    [self loadAdWithState:AdState_Loading];
}

- (void)deallocAd {
    self.adMediaRender.delegate = nil;
    self.adMediaRender = nil;
    self.isLoaded = NO;
    [self loadAdWithState:AdState_Normal];
}

//广告展示
- (void)showRanderAd:(id)media {
    self.adMedia = media;
    if(_isAdLoaded == NO){
        [media muteEnable:YES];

        DemoNativeSelfRenderView *selfRenderView = [[DemoNativeSelfRenderView alloc] initWithOffer:media];
        NSMutableArray * clickableViews = [[NSMutableArray alloc] initWithCapacity:0];
        if(selfRenderView.mediaView){
            [clickableViews addObject:selfRenderView.mediaView];
        }
        
        [clickableViews addObjectsFromArray:@[selfRenderView.ctaLabel,selfRenderView.titleLabel,selfRenderView.textLabel,selfRenderView.mainImageView,selfRenderView.iconImageView]];

        [media registerContainer:selfRenderView withClickableViews:clickableViews];
        DemoMediaRenderDetailViewController *showVc = [[DemoMediaRenderDetailViewController alloc] initWithAdView:selfRenderView offer:media];
        [self.navigationController pushViewController:showVc animated:YES];
    }
}

#pragma mark - YFAdInterstitialDelegate

/// 获取自渲染数据
- (void)fcAdGetMediaRenderDataSuccess:(NSArray *)mediaRenders {
    AlertIfNotMainThread
    [self showRanderAd:mediaRenders.firstObject];
    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功", __func__]];
}

- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter description:(NSDictionary *)description {
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

/**
 This method is called when native ad  render  success
 */
- (void)mediaAdRenderSuccess:(YFAdMedia *)mediaAd {
    AlertIfNotMainThread
    NSLog(@"广告曝光回调 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

/**
 This method is called when native ad  render  fail
 */
- (void)mediaAdRenderFail:(YFAdMedia *)mediaAd {
    AlertIfNotMainThread
    NSLog(@"广告曝光回调 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光失败", __func__]];
}

/**
 This method is called when native ad is clicked.
 */
- (void)mediaAdDidClick:(YFAdMedia *)mediaAd {
    AlertIfNotMainThread
    NSLog(@"广告点击 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击成功", __func__]];
}

/**
 This method is called when native ad play finished.
 */
- (void)mediaAdVideoPlayFinished:(YFAdMedia *)mediaAd {
    AlertIfNotMainThread
    NSLog(@"广告视频播放完成 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告视频播放完成", __func__]];
}

@end
