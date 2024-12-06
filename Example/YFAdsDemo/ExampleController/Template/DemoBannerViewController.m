//
//  DemoBannerViewController.m
//  Example
//
//  Created by CherryKing on 2019/11/8.
//  Copyright © 2019 CherryKing. All rights reserved.
//

#import "DemoBannerViewController.h"
#import <YFAdsSDK/YFAdBanner.h>
#import <YFAdsSDK/YFKit.h>

#import "AdDataJsonManager.h"
#import "YFEnvironmentManager.h"
#import "DemoPresentViewController.h"
#import "DemoBannerChangeViewController.h"

@interface DemoBannerViewController () <YFAdBannerDelegate>
@property (nonatomic, strong) YFAdBanner *adBanner;
@property (nonatomic, strong) UIView *contentV;
@property (nonatomic, strong) UIView *container;
@property (nonatomic, strong) UISlider * slider;
@property (nonatomic, strong) UILabel * marginLabel;
@property (nonatomic, assign) BOOL isShowLogView;
@property (nonatomic, assign) BOOL isChangeVC;

@end

@implementation DemoBannerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
   
    self.title = @"横幅";

    UIBarButtonItem *rightBar = [[UIBarButtonItem alloc] initWithTitle:@"显示日志" style:UIBarButtonItemStylePlain target:self action:@selector(showLogView)];
    self.navigationItem.rightBarButtonItem = rightBar;
    
    self.slider = [UISlider new];
    self.slider.frame = CGRectMake(30, 330,self.view.frame.size.width - 60, 20);
    [self.slider addTarget:self action:@selector(sliderEndChangeValue:) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:self.slider];
    
    self.marginLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 350,self.view.frame.size.width, 20)];
    self.marginLabel.textAlignment = NSTextAlignmentCenter;
    self.marginLabel.text = @"边距：0";
    [self.view addSubview:self.marginLabel];
    
    self.textV.frame = CGRectMake(0,0 - 300, self.view.frame.size.width, 300);
    
    float width = self.view.bounds.size.width;
    _container = [[UIView alloc] initWithFrame:CGRectMake(0, self.view.frame.size.height / 2.0 ,self.view.frame.size.width,self.view.frame.size.height/ 2.0)];
    _container.backgroundColor = UIColor.systemBlueColor;
    

    
    
    
}
- (void)sliderEndChangeValue:(id)va {
    self.marginLabel.text = [NSString stringWithFormat:@"边距：%d", (int)[self calMargin]];
}

- (CGFloat)calMargin {
    return (self.slider.value * 60);
}

- (void)popVC{
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)showLogView {
    [UIView animateWithDuration:0.2 animations:^{
        self.textV.frame = CGRectMake(0,((self->_isShowLogView = !self->_isShowLogView) ? kAppTopH : -300 ), self.view.frame.size.width, 300);
        self.navigationItem.rightBarButtonItem.title = self->_isShowLogView ? @"隐藏日志":@"显示日志";
    }];
}

-(void)changeVC {
    
    if (!self.isLoaded) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    if (!self.adBanner.isValid) {
        [JDStatusBarNotification showWithStatus:@"广告已失效，请重新拉取" dismissAfter:1.5];
        return;
    }
    DemoBannerChangeViewController * pvc = [[DemoBannerChangeViewController alloc] init];
    pvc.adapter = self.adBanner;
    pvc.adView = self.container;
    [self.navigationController pushViewController:pvc animated:YES];
    
}

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
   // [self loadAndShowAd];
    self.navigationController.navigationBar.hidden = NO;

}

- (void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
}

-(void)viewDidDisappear:(BOOL)animated{
    [super viewDidDisappear:animated];    
}

- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    if (_contentV == nil) {
        float width = self.view.bounds.size.width - (self.slider.value * 60 * 2);
        _contentV = [[UIView alloc] initWithFrame:CGRectMake(self.slider.value * 60, 10,width, 400)];
        _contentV.backgroundColor = UIColor.whiteColor;
        [_container removeFromSuperview];
        [self.container addSubview:self.contentV];
        [_container removeFromSuperview];
        [self.view addSubview:self.container];
    }
    [self loadAdWithState:AdState_Normal];
    self.adBanner = [[YFAdBanner alloc] initWithAdUnitID:[YFEnvironmentManager getBANNER_ID] adContainer:_contentV viewController:self];
    self.adBanner.delegate = self;
    [self.adBanner loadAndShowAd];
    [self loadAdWithState:AdState_Loading];
    self.isOnlyLoad = YES;
    self.container.hidden = YES;
}

- (void)showAd {
    if (!self.isLoaded) {
        [JDStatusBarNotification showWithStatus:@"请先拉取广告" dismissAfter:1.5];
        return;}
    if (!self.adBanner.isValid) {
        [JDStatusBarNotification showWithStatus:@"广告已失效，请重新拉取" dismissAfter:1.5];
        return;
    }
    self.container.hidden = NO;
}

- (void)loadAndShowAd{
    [super loadAndShowAd];
    [self deallocAd];
    if (_contentV == nil) {
        float width = self.view.bounds.size.width - (self.slider.value * 60 * 2);
         _contentV = [[UIView alloc] initWithFrame:CGRectMake(self.slider.value * 60, 10,width, 400)];
        [self.container addSubview:self.contentV];
        [_container removeFromSuperview];
        [self.view addSubview:self.container];
    }
    
    [self loadAdWithState:AdState_Normal];
    
    if (!self.adBanner) {
        self.adBanner = [[YFAdBanner alloc] initWithAdUnitID:[YFEnvironmentManager getBANNER_ID] adContainer:_contentV viewController:self];
        self.adBanner.delegate = self;
        [self.adBanner loadAndShowAd];
    }
    
    [self loadAdWithState:AdState_Loading];
}


- (void)deallocAd {
    self.isLoaded = NO;
    [self.contentV removeFromSuperview];
    self.contentV = nil;
    if (self.adBanner) {
        self.adBanner = nil;
    }
}

/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    AlertIfNotMainThread
    self.isLoaded = YES;
//    [self.adBanner setNewDelegate:self];
//    [self.adBanner setRootController:[UIViewController new]];

    if(self.isOnlyLoad){}
    
    ///===================

//
    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功", __func__]];
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
}


/// 广告曝光
- (void)fcAdExposured:(id)adapter {
    AlertIfNotMainThread
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

/// 广告点击
- (void)fcAdClicked:(id)adapter  {
    AlertIfNotMainThread
    NSLog(@"广告点击 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击", __func__]];
}

/// 广告关闭回调
- (void)fcAdDidClose:(id)adapter  {
    AlertIfNotMainThread
    NSLog(@"广告关闭了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭了", __func__]];
    [self deallocAd];
}

-(void)dealloc {
    NSLog(@"横幅释放 %s", __func__);
    [self deallocAd];
}

@end
