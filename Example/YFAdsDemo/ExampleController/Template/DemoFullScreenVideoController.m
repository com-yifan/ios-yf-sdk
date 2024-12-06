//
//  DemoFullScreenVideoController.m

//
//  Created by CherryKing on 2020/4/13.
//  Copyright © 2020 bayescom. All rights reserved.
//

#import "DemoFullScreenVideoController.h"
#import <YFAdsSDK/YFAdFullScreenVideo.h>
#import "AdDataJsonManager.h"
#import "YFEnvironmentManager.h"
#import "DemoPresentViewController.h"


@interface DemoFullScreenVideoController () <YFAdFullScreenVideoDelegate>
@property (nonatomic, strong) YFAdFullScreenVideo *fullScreenVideo;
@property (nonatomic) bool isAdLoaded;

@end

@implementation DemoFullScreenVideoController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"全屏视频";
    self.dic = [[AdDataJsonManager shared] loadAdDataWithType:JsonDataType_fullScreenVideo];
}



-(void)changeVC {
    
    if (!self.fullScreenVideo) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    
    DemoPresentViewController * pvc = [[DemoPresentViewController alloc] init];
    pvc.adapter = self.fullScreenVideo;
    [self.navigationController pushViewController:pvc animated:YES];
    
}

- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    
    self.fullScreenVideo = [[YFAdFullScreenVideo alloc] initWithAdUnitID:[YFEnvironmentManager getFULLSCREEN_ID] viewController:self];
    self.fullScreenVideo.delegate = self;
    [self.fullScreenVideo loadAd];
    [self loadAdWithState:AdState_Loading];

}

- (void)showAd {
    if (!self.fullScreenVideo || !self.isLoaded) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    if (!self.fullScreenVideo.isValid) {
        [JDStatusBarNotification showWithStatus:@"广告已失效，请重新拉取" dismissAfter:1.5];
        return;
    }
    [self.fullScreenVideo showAd];

}

- (void)loadAndShowAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    

    self.fullScreenVideo = [[YFAdFullScreenVideo alloc] initWithAdUnitID:[YFEnvironmentManager getFULLSCREEN_ID] viewController:self];
    self.fullScreenVideo.delegate = self;
    [self.fullScreenVideo loadAndShowAd];
    [self loadAdWithState:AdState_Loading];

}

- (void)deallocAd {
    self.fullScreenVideo.delegate = nil;
    self.fullScreenVideo = nil;
    self.isLoaded = NO;
    [self loadAdWithState:AdState_Normal];

}

/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    AlertIfNotMainThread
    self.isLoaded = YES;
    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
    ///===================
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功", __func__]];
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

- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description{
    AlertIfNotMainThread
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
    [JDStatusBarNotification showWithStatus:@"广告加载失败" dismissAfter:1.5];
    //通知主线程刷新
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error.userInfo.description]];
        [self showErrorWithDescription:description];
    });
    [self loadAdWithState:AdState_LoadFailed];
    [self deallocAd];
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



/// 广告关闭
- (void)fcAdDidClose:(id)adapter  {
    AlertIfNotMainThread
    NSLog(@"广告关闭了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭了", __func__]];
    [self deallocAd];

}

/// 广告播放完成
- (void)fcAdFullScreenVideoOnAdPlayFinish {
    AlertIfNotMainThread
    NSLog(@"广告播放完成 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告播放完成", __func__]];
}



-(void)dealloc {
    NSLog(@"全屏视频释放 %s", __func__);
}

@end
