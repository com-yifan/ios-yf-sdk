//
//  DemoPatchViewController.m
//  Example
//
//  Created by CherryKing on 2019/11/8.
//  Copyright © 2019 CherryKing. All rights reserved.
//

#import "DemoPatchViewController.h"
#import <YFAdsSDK/YFAdPatch.h>
#import <YFAdsSDK/YFKit.h>

#import "AdDataJsonManager.h"
#import "YFEnvironmentManager.h"
#import "DemoPresentViewController.h"
#import "DemoBannerChangeViewController.h"

@interface DemoPatchViewController () <YFAdPatchDelegate>
@property (nonatomic, strong) YFAdPatch *adPatch;
@property (nonatomic, strong) UIView *contentV;

@end

@implementation DemoPatchViewController

- (void)viewDidLoad {
    [super viewDidLoad];
  
    self.title = @"贴片";
    self.isOnlyLoad = NO;
//    if (self.navigationController) {
//        UIBarButtonItem *rightBar = [[UIBarButtonItem alloc] initWithTitle:@"Push" style:UIBarButtonItemStylePlain target:self action:@selector(pushVC)];
//        self.navigationItem.rightBarButtonItem = rightBar;
//    }else{
//        UIButton *closeBtn = [[UIButton alloc]initWithFrame:CGRectMake(20,40, 50, 50)];
//        [closeBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
//        [closeBtn addTarget:self action:@selector(popVC) forControlEvents:UIControlEventTouchUpInside];
//        [closeBtn setTitle:@"关闭" forState:UIControlStateNormal];
//        [self.view addSubview:closeBtn];
//        
//        UIButton *pushBtn = [[UIButton alloc]initWithFrame:CGRectMake(self.view.frame.size.width - 50 - 20,40, 50, 50)];
//        [pushBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
//        [pushBtn addTarget:self action:@selector(pushVC) forControlEvents:UIControlEventTouchUpInside];
//        [pushBtn setTitle:@"Push" forState:UIControlStateNormal];
//        [self.view addSubview:pushBtn];
//    }
    
}

- (void)popVC{
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)pushVC{
    DemoPresentViewController *newVC = [[DemoPresentViewController alloc]init];
    [self.navigationController pushViewController:newVC animated:YES];
//    newVC.modalPresentationStyle = 0;
//    [self presentViewController:newVC animated:YES completion:nil];
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
    if (!_contentV) {
        _contentV = [[UIView alloc] initWithFrame:CGRectMake(0, 100, self.view.bounds.size.width, self.view.bounds.size.width *5/32)];
//        [self.view addSubview:self.contentV];
    }
    
    [self loadAdWithState:AdState_Normal];
    self.adPatch = [[YFAdPatch alloc] initWithAdUnitID:[YFEnvironmentManager getPATCH_ID] adContainer:_contentV viewController:self];
    self.adPatch.delegate = self;
    [self.adPatch loadAndShowAd];
    [self loadAdWithState:AdState_Loading];
    self.isOnlyLoad = YES;

}


- (void)loadAndShowAd{
    [super loadAndShowAd];
    if (!_contentV) {
        _contentV = [[UIView alloc] initWithFrame:CGRectMake(0, 100, self.view.bounds.size.width, self.view.bounds.size.width * 400.0 /600.0)];
        [self.view addSubview:self.contentV];
    }
    
    [self loadAdWithState:AdState_Normal];
    
    if (!self.adPatch) {
        self.adPatch = [[YFAdPatch alloc] initWithAdUnitID:[YFEnvironmentManager getPATCH_ID] adContainer:_contentV viewController:self];
        self.adPatch.delegate = self;
        [self.adPatch loadAndShowAd];
    }
    
    [self loadAdWithState:AdState_Loading];
}


-(void)changeVC {
    
    if (!self.isLoaded) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    
    DemoBannerChangeViewController * pvc = [[DemoBannerChangeViewController alloc] init];
    pvc.adapter = self.adPatch;
    pvc.adView = self.contentV;
    [self.navigationController pushViewController:pvc animated:YES];
    
}


- (void)deallocAd {
    self.isLoaded = NO;
    [self.contentV removeFromSuperview];
    self.contentV = nil;
    if (self.adPatch) {
        self.adPatch.delegate = nil;
        self.adPatch = nil;
    }
}

/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    AlertIfNotMainThread
    self.isLoaded = YES;
    ///===================
    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功", __func__]];
}

/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description{
    AlertIfNotMainThread
    NSLog(@"贴片广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
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


- (void)fcAdSuccessSortTag:(NSString *)sortTag {
    AlertIfNotMainThread
    NSLog(@"选中了 rule '%@' %s", sortTag,__func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 选中了 rule '%@' ", __func__, sortTag]];
}

/// 广告曝光
-(void)fcAdExposured:(id)adapter{
    AlertIfNotMainThread
    NSLog(@"贴片广告曝光回调 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

/// 广告点击
- (void)fcAdClicked:(id)adapter{
    AlertIfNotMainThread
    NSLog(@"贴片广告点击 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击", __func__]];
}

/// 广告关闭回调
- (void)fcAdDidClose:(id)adapter{
    AlertIfNotMainThread
    NSLog(@"贴片广告关闭了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭了", __func__]];
    [self deallocAd];
}

-(void)dealloc {
    NSLog(@"贴片释放 %s", __func__);
    [self deallocAd];
}

@end
