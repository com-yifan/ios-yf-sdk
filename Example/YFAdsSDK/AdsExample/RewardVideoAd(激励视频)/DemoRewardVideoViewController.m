//
//  DemoRewardVideoViewController.m
//  YFAdsSDKDemo
//
//  Created by CherryKing on 2020/1/3.
//  Copyright © 2020 BAYESCOM. All rights reserved.
//

#import "DemoRewardVideoViewController.h"
#import "YFEnvironmentManager.h"

#import <YFAdsSDK/YFAdRewardVideo.h>
#import "YFDataJsonManager.h"
#import "DemoPresentViewController.h"

@interface DemoRewardVideoViewController () <YFAdRewardVideoDelegate>
@property (nonatomic, strong) YFAdRewardVideo *rewardVideo;
@property (nonatomic) bool isAdLoaded;

@end

@implementation DemoRewardVideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"激励视频";
    self.dic = [[YFDataJsonManager shared] loadAdDataWithType:JsonDataType_rewardVideo];

}

- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    // 初始化激励视频加载器 viewController需传入最上层可见控制器，否则无法模态推出广告落地页及广告，影响展示和转化
    self.rewardVideo = [[YFAdRewardVideo alloc] initWithAdUnitID:[YFEnvironmentManager getREWARD_ID] viewController:self];
    self.rewardVideo.userId = @"test";
    self.rewardVideo.extra = @"test 1212321321";
    self.rewardVideo.delegate = self;
    [self.rewardVideo loadAd];
    [self loadAdWithState:AdState_Loading];
}

- (void)showAd {
    if (!self.rewardVideo || !self.isLoaded) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    if (!self.rewardVideo.isValid) {
        [JDStatusBarNotification showWithStatus:@"广告已失效，请重新拉取" dismissAfter:1.5];
        return;
    }
    [self.rewardVideo showAd];

}

- (void)loadAndShowAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    // 激励视频广告 viewController需传入最上层可见控制器，否则无法模态推出广告落地页及广告，影响展示和转化
    self.rewardVideo = [[YFAdRewardVideo alloc] initWithAdUnitID:[YFEnvironmentManager getREWARD_ID] viewController:self];
    self.rewardVideo.adsShowDirection = YFAdsShowDirectionVertical;
    self.rewardVideo.delegate = self;
    [self.rewardVideo loadAndShowAd];
    self.rewardVideo.userId = @"test";
    self.rewardVideo.extra = @"test 1212321321";
    [self loadAdWithState:AdState_Loading];
}

- (void)deallocAd {
    self.rewardVideo.delegate = nil;
    self.rewardVideo = nil;
    self.isLoaded = NO;
    [self loadAdWithState:AdState_Normal];
}

#pragma mark - YFAdRewardVideoDelegate

/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    AlertIfNotMainThread
    self.isLoaded = YES;
    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
    ///===================
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功", __func__]];
}

/// 视频缓存成功
- (void)fcAdRewardVideoOnAdVideoCached
{
    AlertIfNotMainThread
    NSLog(@"视频缓存成功 %s", __func__);
    [JDStatusBarNotification showWithStatus:@"视频缓存成功" dismissAfter:1.5];
    self.isLoaded = YES;
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 视频缓存成功", __func__]];
    [self loadAdWithState:AdState_LoadSucceed];

}

/// 到达激励时间
- (void)fcAdRewardVideoAdDidRewardEffective {
    AlertIfNotMainThread
    NSLog(@"到达激励时间 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 到达激励时间", __func__]];
}

/// 广告曝光
- (void)fcAdExposured:(id)adapter  {
    AlertIfNotMainThread
    NSLog(@"广告曝光回调 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光回调", __func__]];
}

/// 广告点击
- (void)fcAdClicked:(id)adapter  {
    AlertIfNotMainThread
    NSLog(@"广告点击 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击", __func__]];
}

/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter  description:(NSDictionary *)description{
    AlertIfNotMainThread
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error,description);
    //通知主线程刷新
    dispatch_async(dispatch_get_main_queue(), ^{
            [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error]];
            [self showErrorWithDescription:description];
    });
    [self loadAdWithState:AdState_LoadFailed];
    [self deallocAd];
}

/// 广告关闭
- (void)fcAdDidClose:(id)adapter  {
    AlertIfNotMainThread
    NSLog(@"广告关闭了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭了", __func__]];
    [self deallocAd];
}

/// 播放完成
- (void)fcAdRewardVideoAdDidPlayFinish {
    AlertIfNotMainThread
    NSLog(@"播放完成 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 播放完成", __func__]];
}

- (void)dealloc {
    NSLog(@"激励视频释放 %s", __func__);
}

@end
