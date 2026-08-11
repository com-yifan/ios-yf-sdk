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
@property (nonatomic, strong) YFAdMall *customEntryMall;
@property (nonatomic) bool isAdLoaded;
@property (nonatomic, assign) BOOL isLoadAndShow;
@property (nonatomic, strong) UIButton *loadShowVcAd;
@property (nonatomic, strong) UIButton *customEntryButton;
@property (nonatomic, assign) BOOL customEntryAdReady;
@property (nonatomic, assign) BOOL customEntryAdLoading;

@end

@implementation DemoMallViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.dic = [[YFDataJsonManager shared] loadAdDataWithType:JsonDataType_interstitial];
    self.title = @"商城广告";
    [self setupCustomEntryView];
    [self preloadCustomEntryMallAd];
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    [self layoutCustomEntryView];
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
    [super loadAndShowAd];
    [self loadAdWithState:AdState_Normal];
    _isLoadAndShow = YES;

    // 广告初始化 viewController需传入最上层可见控制器，否则无法模态推出广告落地页及广告，影响展示和转化
    self.mall = [[YFAdMall alloc] initWithAdUnitID:[YFEnvironmentManager getMall_ID]];
    self.mall.delegate = self;
    _isAdLoaded = false;
    [self.mall loadAndShowAd];
}


- (void)deallocAd {
    self.mall = nil;
    [self resetCustomEntryMallAd];
    self.isLoaded = NO;
    [self loadAdWithState:AdState_Normal];
}

- (void)dealloc {
    NSLog(@"商城释放 %s",__func__);
}

- (void)setupCustomEntryView {
    [self.view addSubview:self.customEntryButton];
    [self layoutCustomEntryView];
}

- (UIButton *)customEntryButton {
    if (!_customEntryButton) {
        _customEntryButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _customEntryButton.backgroundColor = [UIColor colorWithRed:1.0 green:0.96 blue:0.90 alpha:1.0];
        _customEntryButton.layer.cornerRadius = 10.0;
        _customEntryButton.layer.borderWidth = 1.0;
        _customEntryButton.layer.borderColor = [UIColor colorWithRed:1.0 green:0.58 blue:0.22 alpha:1.0].CGColor;
        _customEntryButton.titleLabel.numberOfLines = 1;
        _customEntryButton.titleLabel.font = [UIFont boldSystemFontOfSize:16.0];
        _customEntryButton.titleLabel.textAlignment = NSTextAlignmentCenter;
        [_customEntryButton setTitle:@"商城自定义入口 Banner，点击加载并展示" forState:UIControlStateNormal];
        [_customEntryButton setTitleColor:[UIColor colorWithRed:0.85 green:0.28 blue:0.08 alpha:1.0] forState:UIControlStateNormal];
        [_customEntryButton addTarget:self action:@selector(customEntryButtonDidClick) forControlEvents:UIControlEventTouchUpInside];
        _customEntryButton.accessibilityIdentifier = @"DemoMallViewController.customEntryButton";
    }
    return _customEntryButton;
}

- (void)customEntryButtonDidClick {
    if (self.customEntryAdReady && self.customEntryMall.isValid) {
        [self showProcessWithText:@"点击自定义入口 Banner，展示已预加载商城广告"];
        [self.customEntryMall showAd];
        return;
    }
    [self loadAndShowCustomEntryMallAd];
}

- (YFAdMall *)createCustomEntryMall {
    YFAdMall *mall = [[YFAdMall alloc] initWithAdUnitID:[YFEnvironmentManager getMall_ID]];
    mall.customEntry = YES;
    mall.delegate = self;
    return mall;
}

- (void)preloadCustomEntryMallAd {
    self.customEntryMall = [self createCustomEntryMall];
    self.customEntryAdReady = NO;
    self.customEntryAdLoading = YES;
    [self updateCustomEntryButtonTitle];
    [self loadAdWithState:AdState_Loading];
    [self showProcessWithText:@"进入商城页面，开始预加载自定义入口商城广告"];
    [self.customEntryMall loadAd];
}

- (void)loadAndShowCustomEntryMallAd {
    self.customEntryMall = [self createCustomEntryMall];
    self.customEntryAdReady = NO;
    self.customEntryAdLoading = YES;
    [self updateCustomEntryButtonTitle];
    [self loadAdWithState:AdState_Loading];
    [self showProcessWithText:@"点击自定义入口 Banner，开始加载并展示商城广告"];
    [self.customEntryMall loadAndShowAd];
}

- (void)resetCustomEntryMallAd {
    self.customEntryMall = nil;
    self.customEntryAdReady = NO;
    self.customEntryAdLoading = NO;
    [self updateCustomEntryButtonTitle];
}

- (void)updateCustomEntryButtonTitle {
    NSString *title = @"商城自定义入口 Banner，点击加载并展示";
    if (self.customEntryAdReady) {
        title = @"商城自定义入口 Banner，点击展示";
    } else if (self.customEntryAdLoading) {
        title = @"商城自定义入口 Banner，广告预加载中";
    }
    [self.customEntryButton setTitle:title forState:UIControlStateNormal];
}

- (BOOL)isStaleCustomEntryMall:(YFAdMall *)mall {
    return mall.customEntry && mall != self.customEntryMall;
}

- (void)layoutCustomEntryView {
    CGFloat horizontalMargin = 16.0;
    CGFloat bannerHeight = 56.0;
    CGFloat safeBottom = 0;
    if (@available(iOS 11.0, *)) {
        safeBottom = self.view.safeAreaInsets.bottom;
    }
    CGFloat bannerY = self.view.bounds.size.height - safeBottom - bannerHeight - 8.0;
    self.customEntryButton.frame = CGRectMake(horizontalMargin, bannerY, self.view.bounds.size.width - horizontalMargin * 2.0, bannerHeight);

    CGFloat textMaxY = CGRectGetMinY(self.customEntryButton.frame) - 12.0;
    if (textMaxY > CGRectGetMinY(self.textV.frame)) {
        CGRect textFrame = self.textV.frame;
        textFrame.size.height = textMaxY - textFrame.origin.y;
        self.textV.frame = textFrame;
    }
}

#pragma mark - YFAdMallDelegate

/// 商城广告加载成功
- (void)fcAdMallOnAdLoadSuccess:(YFAdMall *)mall {
    if ([self isStaleCustomEntryMall:mall]) {
        return;
    }
    if (mall == self.customEntryMall) {
        self.customEntryAdReady = YES;
        self.customEntryAdLoading = NO;
        [self updateCustomEntryButtonTitle];
    } else if (mall == self.mall) {
        self.isLoaded = YES;
    }
    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
    NSString *entryType = mall.customEntry ? @"自定义入口" : @"默认入口";
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n %@广告数据拉取成功 请求ID：%@\r\n优惠券类型：%ld 金额/折扣：%@", __func__, entryType, mall.mgr.rID, (long)mall.couponType, mall.couponAmount]];
}

/// 商城广告加载失败
- (void)fcAdMallOnAdLoadFail:(YFAdMall *)mall withError:(NSError *)error {
    if ([self isStaleCustomEntryMall:mall]) {
        return;
    }
    //通知主线程刷新
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error.userInfo.description]];
        [self showErrorWithDescription:error.userInfo.description];
    });
    [self loadAdWithState:AdState_LoadFailed];
    if (mall == self.customEntryMall) {
        [self resetCustomEntryMallAd];
    } else {
        [self deallocAd];
    }
}

/// 商城广告展示失败 未回调加载成功调用展示则回调
- (void)fcAdMallOnAdShowFail:(YFAdMall *)mall withError:(NSError *)error {
    if ([self isStaleCustomEntryMall:mall]) {
        return;
    }
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 商城广告展示失败: \r\n%@", __func__, error.userInfo.description]];
    [JDStatusBarNotification showWithStatus:@"广告展示失败" dismissAfter:1.5];
    if (mall == self.customEntryMall) {
        [self resetCustomEntryMallAd];
    }
}

/// 商城广告曝光
- (void)fcAdMallOnAdShow:(YFAdMall *)mall {
    if ([self isStaleCustomEntryMall:mall]) {
        return;
    }
    if (mall == self.customEntryMall) {
        self.customEntryAdReady = NO;
        self.customEntryAdLoading = NO;
        [self updateCustomEntryButtonTitle];
    }
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

/// 商城广告关闭
- (void)fcAdMallOnAdClose:(YFAdMall *)mall {
    if ([self isStaleCustomEntryMall:mall]) {
        return;
    }
    NSLog(@"广告关闭了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭了", __func__]];
    if (mall == self.customEntryMall) {
        [self resetCustomEntryMallAd];
        [self loadAdWithState:AdState_Normal];
    } else {
        [self deallocAd];
    }
}

/// 商城广告点击
- (void)fcAdMallOnAdClick:(YFAdMall *)mall {
    if ([self isStaleCustomEntryMall:mall]) {
        return;
    }
    NSLog(@"广告点击了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击了", __func__]];
}

@end
