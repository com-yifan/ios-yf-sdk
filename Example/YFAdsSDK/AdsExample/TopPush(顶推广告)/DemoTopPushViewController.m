//
//  DemoTopPushViewController.m
//  YFAdsDemo_Example
//
//  Created by Erik on 2025/9/18.
//  Copyright © 2025 Nanjing Fengchuan Yunju Infomation Technology Co., LTD. All rights reserved.
//

#import "DemoTopPushViewController.h"
#import <YFAdsSDK/YFAdTopPush.h>
#import "YFDataJsonManager.h"
#import "YFEnvironmentManager.h"
#import "DemoPresentViewController.h"
#import "UIAlertController+Blocks.h"

@interface DemoTopPushViewController ()<YFAdTopPushDelegate>

@property (nonatomic, strong) YFAdTopPush *topPush;
@property (nonatomic) bool isAdLoaded;
@property (nonatomic, assign) BOOL isLoadAndShow;
@property (nonatomic, strong) UIButton *loadShowVcAd;

@end

@implementation DemoTopPushViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    self.dic = [[YFDataJsonManager shared] loadAdDataWithType:JsonDataType_interstitial];
    self.title = @"顶推广告";
}

- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    _isLoadAndShow = NO;
    [self loadAdWithState:AdState_Normal];
    // 广告初始化 viewController需传入最上层可见控制器，否则无法模态推出广告落地页及广告，影响展示和转化
    self.topPush = [[YFAdTopPush alloc] initWithAdUnitID:[YFEnvironmentManager getTopPush_ID] withViewController:self];
    self.topPush.delegate = self;
    _isAdLoaded = false;
    [self.topPush loadAd];
    [self loadAdWithState:AdState_Loading];
}

- (void)showAd {
    if (!self.topPush || !self.isLoaded) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    if (!self.topPush.isValid) {
        [JDStatusBarNotification showWithStatus:@"广告已失效，请重新拉取" dismissAfter:1.5];
        return;
    }
    // 如需切换页面展示 可选 showAdFromViewController
    [self.topPush showAdFromViewController:self];
//    [self.interstitial showAd];
}

- (void)loadAndShowAd {
    [super loadAndShowAd];
    [self loadAdWithState:AdState_Normal];
    _isLoadAndShow = YES;

    // 广告初始化 viewController需传入最上层可见控制器，否则无法模态推出广告落地页及广告，影响展示和转化
    self.topPush = [[YFAdTopPush alloc] initWithAdUnitID:[YFEnvironmentManager getTopPush_ID] withViewController:self];
    self.topPush.delegate = self;
    _isAdLoaded = false;
    [self.topPush loadAndShowAd];
}


- (void)deallocAd {
    self.topPush = nil;
    self.isLoaded = NO;
    [self loadAdWithState:AdState_Normal];
}

- (void)dealloc {
    NSLog(@"顶推释放 %s",__func__);
}

/// 顶推广告加载成功
- (void)fcAdTopPushOnAdLoadSuccess:(YFAdTopPush *)topPush {
    self.isLoaded = YES;
    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功 请求ID：%@", __func__,topPush.mgr.rID]];
}

/// 顶推广告加载失败
- (void)fcAdTopPushOnAdLoadFail:(YFAdTopPush *)topPush withError:(NSError *)error {
    //通知主线程刷新
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error.userInfo.description]];
        [self showErrorWithDescription:error.userInfo.description];
    });
    [self loadAdWithState:AdState_LoadFailed];
    [self deallocAd];
}

/// 顶推广告曝光
- (void)fcAdTopPushOnAdShow:(YFAdTopPush *)topPush {
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

/// 顶推广告渲染成功，建议在此回调后展示
- (void)fcAdTopPushOnAdRenderSuccess:(YFAdTopPush *)topPush {
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染成功 %@", __func__,topPush.isValid?@"✅有效":@"❌失效"]];
}

/// 顶推广告渲染失败
- (void)fcAdTopPushOnAdRenderFail:(YFAdTopPush *)topPush {
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染失败", __func__]];
}

/// 顶推广告关闭
- (void)fcAdTopPushOnAdClose:(YFAdTopPush *)topPush {
    NSLog(@"广告关闭了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭了", __func__]];
    [self deallocAd];
}

/// 顶推广告点击
- (void)fcAdTopPushOnAdClick:(YFAdTopPush *)topPush {
    NSLog(@"广告点击了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击了", __func__]];
}

/// 顶推广告关闭落地页
- (void)fcAdTopPushOnAdDetailPageClose:(YFAdTopPush *)topPush {
    NSLog(@"广告点击了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭落地页", __func__]];
}


@end
