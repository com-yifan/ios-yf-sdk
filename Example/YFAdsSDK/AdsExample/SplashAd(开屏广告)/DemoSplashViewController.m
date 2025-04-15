//
//  DemoSplashViewController.m
//  AAA
//
//  Created by CherryKing on 2019/11/1.
//  Copyright © 2019 CherryKing. All rights reserved.
//

#import "DemoSplashViewController.h"
#import <YFAdsSDK/YFAdSplash.h>
#import "YFDataJsonManager.h"
#import "YFEnvironmentManager.h"
#import "DemoPresentViewController.h"

// 加载提示视图宽高
#define ProgressViewWidth 60.0
#define ProgressViewHeight 60.0

@interface DemoSplashViewController () <YFAdSplashDelegate>

@property(strong,nonatomic) YFAdSplash *FCAdSplash;
@property (nonatomic, strong) UISlider * slider;
@property (nonatomic, strong) UILabel * marginLabel;
// 开屏加载加载提示
@property (nonatomic, strong) UIActivityIndicatorView *hotSplashProgressView;
// 开屏广告背景视图
@property(strong,nonatomic)  UIImageView  *bgImageView;
@end

@implementation DemoSplashViewController

- (UIActivityIndicatorView *)hotSplashProgressView {
    if (!_hotSplashProgressView) {
        if (@available(iOS 13.0, *)) {
            _hotSplashProgressView = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyleMedium)];
        } else {
            // Fallback on earlier versions
            _hotSplashProgressView = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyleGray)];
        }
        _hotSplashProgressView.hidesWhenStopped = YES;
        _hotSplashProgressView.frame = CGRectMake(kScreenW/2 - ProgressViewWidth/2, kScreenH/2 - ProgressViewHeight/2, ProgressViewWidth, ProgressViewHeight);
    }
    return _hotSplashProgressView;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"开屏广告";
    self.slider = [UISlider new];
    self.slider.frame = CGRectMake(30, 330,self.view.frame.size.width - 60, 20);
    self.slider.minimumValue = 0;
    self.slider.maximumValue = 100;
    self.slider.value = 10;
    [self.slider addTarget:self action:@selector(sliderEndChangeValue:) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:self.slider];

    self.marginLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 350,self.view.frame.size.width, 20)];
    self.marginLabel.textAlignment = NSTextAlignmentCenter;
    self.marginLabel.text = [NSString stringWithFormat:@"底部视图高度：%d%%", (int)self.slider.value];
    [self.view addSubview:self.marginLabel];
    
    UILabel *remindLab = [[UILabel alloc] initWithFrame:CGRectMake(0, 372,self.view.frame.size.width, 15)];
    remindLab.font = [UIFont systemFontOfSize:13];
    remindLab.textAlignment = NSTextAlignmentCenter;
    remindLab.text = @"底部视图高度不要超过屏幕高度的20%哦～";
    remindLab.textColor = [UIColor colorWithRed:144/255.0 green:147/255.0 blue:153/255.0 alpha:1.0];
    [self.view addSubview:remindLab];
}

- (void)childVCTakeResultImmediately{
    [self.FCAdSplash takeResultImmediately];
}

- (void)sliderEndChangeValue:(id)va {
    self.marginLabel.text = [NSString stringWithFormat:@"底部视图高度：%d%%", (int)self.slider.value];
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
    
    // 初始化广告加载器
    self.FCAdSplash = [self returnAdInstance];
    // 加载开屏广告
    [self.FCAdSplash loadAd];
    // 加载广告提示
    [self.hotSplashProgressView startAnimating];
    [self loadAdWithState:AdState_Loading];
    
    [super generateEarlyReturn];
}

// 使用完及时释放掉，跟随控制器释放，广告关闭后仍可能会触发摇一摇
- (void)deallocAd {
    self.FCAdSplash = nil;
    [self.hotSplashProgressView stopAnimating];
    self.hotSplashProgressView = nil;
    [self.bgImageView removeFromSuperview];
}

- (void)loadAndShowSplashAd{
    // 广告实例不要用初始化加载, 要确保每次都用最新的实例, 且一次广告流程中 delegate 不能发生变化
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    // 初始化广告加载器 viewController需传入最上层可见控制器，否则无法模态推出广告落地页影响转化
    self.FCAdSplash = [self returnAdInstance];
    // 开屏背景图
    _bgImageView = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, kScreenW, kScreenH)];
    _bgImageView.image = [UIImage imageNamed:@"splashBg"];
    // 避免背景图展示时点击到加载展示按钮
    _bgImageView.userInteractionEnabled = YES;
    // 可自行选择添加背景图的对象
    [self.navigationController.view addSubview:_bgImageView];
    // 添加广告加载提示视图
    [_bgImageView addSubview:self.hotSplashProgressView];
    // 加载开屏广告
    [self.FCAdSplash loadAndShowAd];
    [self loadAdWithState:AdState_Loading];
    
    [super generateEarlyReturn];
}

- (YFAdSplash *)returnAdInstance {
    // 初始化广告加载器 viewController需传入最上层可见控制器，否则无法模态推出广告落地页影响转化
    YFAdSplash *splash = [[YFAdSplash alloc] initWithAdUnitID:[YFEnvironmentManager getHotSPLASH_ID] viewController:self];
    splash.delegate = self;
    if (self.slider.value>0) {
        
        splash.showLogoRequire = YES;
        // 设置底部视图 不要超过屏幕高度20%
        UIImageView *imageView = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, kScreenW, roundf(self.slider.value*kScreenH/100))];
        imageView.image = [UIImage imageNamed:@"app_logo"];
        imageView.backgroundColor = [UIColor whiteColor];
        imageView.contentMode = UIViewContentModeScaleAspectFit;
        
        // bottomView超出25%后，会限制为25%，子视图则会被截断。
        UILabel *bottomLabel = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, kScreenW, roundf(10*kScreenH/100))];
        //    bottomLabel.text = @"这是bottomView的子视图";
        bottomLabel.textAlignment = NSTextAlignmentCenter;
        [imageView addSubview:bottomLabel];
        splash.bottomView = imageView;
    }
    splash.timeout = 5;
    [self showProcessWithText:@""];

    return splash;
}

#pragma mark - YFAdSplashDelegate

/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    AlertIfNotMainThread
    self.isLoaded = YES;
    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
    NSLog(@"=========%@",self.FCAdSplash.isValid?@"有效":@"无效");
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功", __func__]];
    [self.hotSplashProgressView stopAnimating];
}

/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter  description:(NSDictionary *)description{
    AlertIfNotMainThread
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error.userInfo.description]];
        [self showErrorWithDescription:description];
    });
    [self deallocAd];
}

/// 广告曝光成功
- (void)fcAdExposured:(id)adapter  {
    AlertIfNotMainThread
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
    NSLog(@"广告曝光成功 %s", __func__);
}

/// 广告点击
- (void)fcAdClicked:(id)adapter  {
    AlertIfNotMainThread
    /// 部分联盟需要使用当前控制器的navigate，避免背景视图覆盖落地页，需要在点击的时候移除背景视图
    [_bgImageView removeFromSuperview];
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
}

- (void)fcAdSplashBackViewTimeout:(UIView *)view {
    AlertIfNotMainThread
    NSLog(@"开屏背景图 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 开屏背景图结束", __func__]];
}

- (void)dealloc {
    NSLog(@"开屏释放 %s", __func__);
}

@end
