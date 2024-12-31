//
//  DemoBannerViewController.m
//  Example
//
//  Created by CherryKing on 2019/11/8.
//  Copyright © 2019 CherryKing. All rights reserved.
//

#import "DemoBannerChangeViewController.h"
#import <YFAdsSDK/YFAdBanner.h>
#import <YFAdsSDK/YFKit.h>

#import "YFDataJsonManager.h"
#import "YFEnvironmentManager.h"
#import "DemoPresentViewController.h"

@interface DemoBannerChangeViewController () <YFAdBannerDelegate>
@property (nonatomic, strong) YFAdBanner *adBanner;
@property (nonatomic, strong) UIView *contentV;
@property (nonatomic, strong) UIView *container;
@property (nonatomic, strong) UISlider * slider;
@property (nonatomic, strong) UILabel * marginLabel;
@property (nonatomic, assign) BOOL isShowLogView;
@property (nonatomic, assign) BOOL isChangeVC;

@end

@implementation DemoBannerChangeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
   
    self.title = @"切换控制器展示";
    self.btnLoad.hidden = YES;
    self.btnShow.hidden = NO;
    self.btnLoadAndShow.hidden = YES;

    UIBarButtonItem *rightBar = [[UIBarButtonItem alloc] initWithTitle:@"显示日志" style:UIBarButtonItemStylePlain target:self action:@selector(showLogView)];
    self.navigationItem.rightBarButtonItem = rightBar;

//    _container = [[UIView alloc] initWithFrame:CGRectMake(0, self.view.frame.size.height / 2.0 ,self.view.frame.size.width,self.view.frame.size.height/ 2.0)];
//    _container.backgroundColor = UIColor.systemBlueColor;
//    [self.view addSubview:_container];
    
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

-(void)showAd {
    
    if(_adView){
        
        [self showProcessWithText:[NSString stringWithFormat:@"%@" ,self.adapter.isValid ? @"有效":@"无效"]];

        [self.adapter setNewDelegate:self];
        [self.adapter setRootController:self];
//        [_adView removeFromSuperview];
        [self.view addSubview:_adView];
    }

    
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
        [self.container addSubview:self.contentV];
    }

    [self loadAdWithState:AdState_Normal];
    self.adBanner = [[YFAdBanner alloc] initWithAdUnitID:[YFEnvironmentManager getBANNER_ID] adContainer:_contentV viewController:self];
    self.adBanner.delegate = self;
    [self.adBanner loadAndShowAd];
    [self loadAdWithState:AdState_Loading];
}



- (void)changeVC {
    
    _isChangeVC = !_isChangeVC;
    [JDStatusBarNotification showWithStatus:@"VC切换-请重新展示广告" dismissAfter:1.5];
    
}


- (void)deallocAd {
    self.isLoaded = NO;
    [self.contentV removeFromSuperview];
    self.contentV = nil;

}

/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    AlertIfNotMainThread
    self.isLoaded = YES;
//    [self.adBanner setNewDelegate:self];
//    [self.adBanner setRootController:[UIViewController new]];
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
//    [self deallocAd];
    
    [self.adView removeFromSuperview];
    self.adView = nil;
}

-(void)dealloc {
    NSLog(@"横幅释放 %s", __func__);
    [self deallocAd];
}

@end
