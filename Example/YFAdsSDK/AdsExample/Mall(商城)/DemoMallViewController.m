//
//  DemoMallViewController.m
//  YFAdsDemo_Example
//
//  Created by Erik on 2025/11/1.
//  Copyright © 2025 Nanjing Fengchuan Yunju Infomation Technology Co., LTD. All rights reserved.
//

#import "DemoMallViewController.h"
#import <YFAdsSDK/YFAdMall.h>
#import "YFDataJsonManager.h"
#import "YFEnvironmentManager.h"
#import "DemoPresentViewController.h"
#import "UIAlertController+Blocks.h"
#import "DemoIntertitialAdManager.h"

@interface DemoMallViewController ()<YFAdMallDelegate>

@property (nonatomic, strong) YFAdMall *mall;
@property (nonatomic) bool isAdLoaded;
@property (nonatomic, assign) BOOL isLoadAndShow;
@property (nonatomic, strong) UIButton *loadShowVcAd;

@end

@implementation DemoMallViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.dic = [[YFDataJsonManager shared] loadAdDataWithType:JsonDataType_interstitial];
    self.title = @"商城广告";
}

- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    _isLoadAndShow = NO;
    [self loadAdWithState:AdState_Normal];
    // 广告初始化 viewController需传入最上层可见控制器，否则无法模态推出广告落地页及广告，影响展示和转化
    self.mall = [[YFAdMall alloc] initWithAdUnitID:[YFEnvironmentManager getMall_ID]];
    self.mall.delegate = self;
    _isAdLoaded = false;
    [self.mall loadAd];
    [self loadAdWithState:AdState_Loading];
}

- (void)showAd {
    if (!self.mall || !self.isLoaded) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    if (!self.mall.isValid) {
        [JDStatusBarNotification showWithStatus:@"广告已失效，请重新拉取" dismissAfter:1.5];
        return;
    }
    // 如需切换页面展示 可选 showAdFromViewController
    [self.mall showAd];
}

- (void)loadAndShowAd {
    [self showSelectedType:^{
        [super loadAndShowAd];
        [self loadAdWithState:AdState_Normal];
        _isLoadAndShow = YES;

        // 广告初始化 viewController需传入最上层可见控制器，否则无法模态推出广告落地页及广告，影响展示和转化
        self.mall = [[YFAdMall alloc] initWithAdUnitID:[YFEnvironmentManager getMall_ID]];
        self.mall.delegate = self;
        _isAdLoaded = false;
        [self.mall loadAndShowAd];
    }];
}


- (void)deallocAd {
    self.mall = nil;
    self.isLoaded = NO;
    [self loadAdWithState:AdState_Normal];
}

- (void)dealloc {
    NSLog(@"商城释放 %s",__func__);
}

- (void)showSelectedType:(dispatch_block_t)completion {
    UIAlertController *alertVc = [UIAlertController alertControllerWithTitle:@"选择类型" message:@"红包样式类型" preferredStyle:(UIAlertControllerStyleAlert)];
    UIAlertAction *newAction = [UIAlertAction actionWithTitle:@"新人红包" style:(UIAlertActionStyleDefault) handler:^(UIAlertAction * _Nonnull action) {
        [[NSUserDefaults standardUserDefaults] setValue:@"1" forKey:@"YFTestMallType"];
        [[NSUserDefaults standardUserDefaults] synchronize];
        completion();
    }];
    UIAlertAction *bigAction = [UIAlertAction actionWithTitle:@"大促红包" style:(UIAlertActionStyleDefault) handler:^(UIAlertAction * _Nonnull action) {
        [[NSUserDefaults standardUserDefaults] setValue:@"2" forKey:@"YFTestMallType"];
        [[NSUserDefaults standardUserDefaults] synchronize];
        completion();
    }];
    UIAlertAction *signlAction = [UIAlertAction actionWithTitle:@"单品红包" style:(UIAlertActionStyleDefault) handler:^(UIAlertAction * _Nonnull action) {
        [[NSUserDefaults standardUserDefaults] setValue:@"3" forKey:@"YFTestMallType"];
        [[NSUserDefaults standardUserDefaults] synchronize];
        completion();
    }];
    UIAlertAction *unknowAction = [UIAlertAction actionWithTitle:@"重置" style:(UIAlertActionStyleDefault) handler:^(UIAlertAction * _Nonnull action) {
        [[NSUserDefaults standardUserDefaults] setValue:@"4" forKey:@"YFTestMallType"];
        [[NSUserDefaults standardUserDefaults] synchronize];
        completion();
    }];
    [alertVc addAction:newAction];
    [alertVc addAction:bigAction];
    [alertVc addAction:signlAction];
    [alertVc addAction:unknowAction];
    [self presentViewController:alertVc animated:YES completion:nil];
}

#pragma mark - YFAdMallDelegate

/// 商城广告加载成功
- (void)fcAdMallOnAdLoadSuccess:(YFAdMall *)mall {
    self.isLoaded = YES;
    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功 请求ID：%@", __func__,mall.mgr.rID]];
}

/// 商城广告加载失败
- (void)fcAdMallOnAdLoadFail:(YFAdMall *)mall withError:(NSError *)error {
    //通知主线程刷新
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error.userInfo.description]];
        [self showErrorWithDescription:error.userInfo.description];
    });
    [self loadAdWithState:AdState_LoadFailed];
    [self deallocAd];
}

/// 商城广告曝光
- (void)fcAdMallOnAdShow:(YFAdMall *)mall {
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

/// 商城广告渲染失败
- (void)fcAdMallOnAdRenderFail:(YFAdMall *)mall {
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染失败", __func__]];
}

/// 商城广告关闭
- (void)fcAdMallOnAdClose:(YFAdMall *)mall {
    NSLog(@"广告关闭了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭了", __func__]];
    [self deallocAd];
}

/// 商城广告点击
- (void)fcAdMallOnAdClick:(YFAdMall *)mall {
    NSLog(@"广告点击了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击了", __func__]];
}

/// 商城广告关闭落地页
- (void)fcAdMallOnAdDetailPageClose:(YFAdMall *)mall {
    NSLog(@"广告点击了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭落地页", __func__]];
}


@end
