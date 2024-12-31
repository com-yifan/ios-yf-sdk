//
//  DemoPresentViewController.m
//  YFAdsSDK_Example
//
//  Created by jiangchao on 2023/12/25.
//  Copyright © 2023 Cheng455153666. All rights reserved.
//

#import "DemoPresentViewController.h"
#import <YFAdsSDK/YFAdBaseDelegate.h>
#import <objc/runtime.h>
#import <objc/message.h>
@interface DemoPresentViewController ()<YFAdBaseDelegate>

@property (nonatomic, assign) BOOL isShowLogView;

@end


@implementation DemoPresentViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title = @"切换控制器展示";
    self.btnLoad.hidden = YES;
    self.btnShow.hidden = NO;
    self.btnLoadAndShow.hidden = YES;

    UIBarButtonItem *rightBar = [[UIBarButtonItem alloc] initWithTitle:@"显示日志" style:UIBarButtonItemStylePlain target:self action:@selector(showLogView)];
    self.navigationItem.rightBarButtonItem = rightBar;

}

- (void)showAd {
    if (!self.adapter) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    if (!self.adapter.isValid) {
        [JDStatusBarNotification showWithStatus:@"广告已失效，请重新拉取" dismissAfter:1.5];
        return;
    }
    [self.adapter setNewDelegate:self];
    [self.adapter setRootController:self];
    [self.adapter showAd];

}

- (void)showLogView {
    [UIView animateWithDuration:0.2 animations:^{
        self.textV.frame = CGRectMake(0,((self->_isShowLogView = !self->_isShowLogView) ? kAppTopH : -300 ), self.view.frame.size.width, 300);
        self.navigationItem.rightBarButtonItem.title = self->_isShowLogView ? @"隐藏日志":@"显示日志";
    }];
}

#pragma mark - YFAdBaseDelegate

/// 广告曝光成功
- (void)fcAdExposured:(id)adapter  {
    AlertIfNotMainThread
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
    NSLog(@"广告曝光成功 %s", __func__);
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

@end
