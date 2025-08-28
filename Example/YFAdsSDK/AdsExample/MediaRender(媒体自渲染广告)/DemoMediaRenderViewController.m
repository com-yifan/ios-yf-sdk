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

#import "YFDataJsonManager.h"
#import "YFEnvironmentManager.h"
#import "DemoNativeSelfRenderView.h"
#import "DemoMediaRenderDetailViewController.h"

@interface DemoMediaRenderViewController () <YFAdMediaDelegate>
@property (nonatomic, strong) YFAdMediaRender *adMediaRender;
@property (nonatomic) bool isLoadAndShow;
@property (nonatomic, strong) YFAdMedia *adMedia;
@property (nonatomic, strong) NSTimer *timer;
@property (nonatomic, strong) NSArray *mediaRenders;

@end

@implementation DemoMediaRenderViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.dic = [[YFDataJsonManager shared] loadAdDataWithType:JsonDataType_interstitial];
    self.title = @"媒体自渲染广告";
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [self.timer invalidate];
    self.timer = nil;
}

- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    [self.timer invalidate];
    self.timer = nil;
    // 初始化加载器 viewController传入当前最上层可见控制器，否则无法模态推出广告落地页影响转化和收益
    self.adMediaRender = [[YFAdMediaRender alloc] initWithAdUnitID:[YFEnvironmentManager getMEDIA_ID] viewController:self];
    self.adMediaRender.delegate = self;
    self.isLoadAndShow = NO;
    [self.adMediaRender loadAd];
    [self loadAdWithState:AdState_Loading];
}

- (void)showAd {
    if (!self.adMediaRender || !self.isLoaded) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    if (!self.adMedia) {
        [JDStatusBarNotification showWithStatus:@"广告数据为空，请重新加载广告" dismissAfter:1.5];
        return;
    }
    [self showRenderAd:self.adMedia];
}

- (void)loadAndShowAd {
    [super loadAndShowAd];
    [self loadAdWithState:AdState_Normal];
    [self.timer invalidate];
    self.timer = nil;
    // 初始化加载器 viewController传入当前最上层可见控制器，否则无法模态推出广告落地页影响转化和收益
    self.adMediaRender = [[YFAdMediaRender alloc] initWithAdUnitID:[YFEnvironmentManager getMEDIA_ID] viewController:self];
#warning 6042版本代理变更，请核对代理类型及方法
    self.adMediaRender.delegate = self;
    self.isLoadAndShow = YES;
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
- (void)showRenderAd:(id)media {
    [media muteEnable:YES];
    DemoNativeSelfRenderView *selfRenderView = [[DemoNativeSelfRenderView alloc] initWithOffer:media];
    NSMutableArray * clickableViews = [[NSMutableArray alloc] initWithCapacity:0];
    if(selfRenderView.mediaView){
        [clickableViews addObject:selfRenderView.mediaView];
    }
    
    [clickableViews addObjectsFromArray:@[selfRenderView.ctaLabel,selfRenderView.titleLabel,selfRenderView.textLabel,selfRenderView.mainImageView,selfRenderView.iconImageView]];

    [media registerContainer:selfRenderView withClickableViews:clickableViews];
    [(YFAdMedia *)media trackVideoViewImpression];
    DemoMediaRenderDetailViewController *showVc = [[DemoMediaRenderDetailViewController alloc] initWithAdView:selfRenderView offer:media];
    [self.navigationController pushViewController:showVc animated:YES];

    __weak typeof(self) weakSelf = self;
    // 测试使用获取当前播放时间
    self.timer = [NSTimer scheduledTimerWithTimeInterval:1 repeats:YES block:^(NSTimer * _Nonnull timer) {
        [self showProcessWithText:[NSString stringWithFormat:@"\r\n 获取视频当前进度(时间单位原因会出现当前时间内重复回调) %f", weakSelf.adMedia.currentPlayTime]];
    }];
}

#pragma mark - YFAdMediaDelegate

/// 获取自渲染数据
- (void)fcAdGetMediaRenderDataSuccess:(NSArray *)mediaRenders {
    AlertIfNotMainThread
    self.isLoaded = YES;
    self.adMedia = mediaRenders.firstObject;
    if (_isLoadAndShow) {
        [self showRenderAd:self.adMedia];
    }
    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功", __func__]];
}

- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter description:(NSDictionary *)description {
    AlertIfNotMainThread
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error.userInfo.description]];
    [self showErrorWithDescription:description];
    [self loadAdWithState:AdState_LoadFailed];
    [self deallocAd];
}

- (void)mediaAdExposure:(YFAdMedia *)mediaAd {
    AlertIfNotMainThread
    NSLog(@"广告曝光回调 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

/**
 This method is called when native ad  render  success
 */
- (void)mediaAdRenderSuccess:(YFAdMedia *)mediaAd {
    AlertIfNotMainThread
    NSLog(@"广告渲染成功回调 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染成功", __func__]];
}

/**
 This method is called when native ad  render  fail
 */
- (void)mediaAdRenderFail:(YFAdMedia *)mediaAd {
    AlertIfNotMainThread
    NSLog(@"广告渲染失败回调 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染失败", __func__]];
}

/**
 This method is called when native ad is clicked.
 */
- (void)mediaAdDidClick:(YFAdMedia *)mediaAd {
    AlertIfNotMainThread
    NSLog(@"广告点击 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击成功", __func__]];
}

- (void)mediaAdVideoCacheFail:(YFAdMedia *)mediaAd error:(NSError *)error {
    NSLog(@"广告视频缓存失败 %s %@", __func__,error);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告视频缓存失败%@", __func__,error]];
}

/**
 This method is called when native ad play finished.
 */
- (void)mediaAdVideoPlayFinished:(YFAdMedia *)mediaAd {
    AlertIfNotMainThread
    NSLog(@"广告视频播放完成 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告视频播放完成", __func__]];
}

- (void)mediaAdVideoStartPlay:(YFAdMedia *)mediaAd {
    NSLog(@"广告视频开始播放 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告视频开始播放", __func__]];
}

- (void)mediaAdVideoPlayProgress:(int)progress {
    NSLog(@"广告视频当前进度回调(时间单位原因会出现当前时间内重复回调) %s %d", __func__,progress);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告视频当前进度回调(时间单位原因会出现当前时间内重复回调) %d", __func__,progress]];
}

@end
