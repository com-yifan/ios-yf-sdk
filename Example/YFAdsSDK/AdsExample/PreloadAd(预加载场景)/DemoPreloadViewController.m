//
//  YFPreloadViewController.m
//  YFAdsDemo_Example
//
//  Created by Erik on 2024/12/20.
//  Copyright © 2024 Nanjing Fengchuan Yunju Infomation Technology Co., LTD. All rights reserved.
//

#import "DemoPreloadViewController.h"
#import "DemoPreloadTableViewCell.h"
#import <YFAdsSDK/YFAdRewardVideo.h>
#import <YFAdsSDK/YFAdInterstitial.h>
#import <YFAdsSDK/YFAdSplash.h>
#import <YFAdsSDK/YFAdBanner.h>
#import <YFAdsSDK/YFAdFusionBanner.h>
#import <YFAdsSDK/YFAdMediaRender.h>
#import <YFAdsSDK/YFAdFullScreenVideo.h>
#import <YFAdsSDK/YFAdDraw.h>
#import <YFAdsSDK/YFAdPatch.h>
#import <YFAdsSDK/YFNativeAd.h>
#import <YFAdsSDK/YFFullScreenVideoAd.h>
#import <YFAdsSDK/YFAdDraw.h>
#import <YFAdsSDK/YFAdDrawView.h>
#import <YFAdsSDK/YFAdPatch.h>
#import <YFAdsSDK/YFNativeAd.h>
#import <YFAdsSDK/YFAdNativeExpress.h>
#import <YFAdsSDK/YFAdNativeExpressView.h>

#import "DemoPresentViewController.h"
#import "DemoBannerChangeViewController.h"
#import "DemoDrawChangeViewController.h"
#import "DemoNativeSelfRenderView.h"
#import "DemoMediaRenderDetailViewController.h"
#import "DemoListFeedExpressChangeViewController.h"

#import "YFDataJsonManager.h"
#import "YFEnvironmentManager.h"
#import "JDStatusBarNotification.h"
#import "Demoutils.h"

// 加载提示视图宽高
#define ProgressViewWidth 60.0
#define ProgressViewHeight 60.0

// 预加载广告类型
typedef enum : NSUInteger {
    YFPreloadAdTypeRewardVideo,
    YFPreloadAdTypeIntertitial,
    YFPreloadAdTypeSplash,
    YFPreloadAdTypeBanner,
    YFPreloadAdTypeFusionBanner,
    YFPreloadAdTypeMediaRender,
    YFPreloadAdTypeFullScreen,
    YFPreloadAdTypeDraw,
    YFPreloadAdTypePatch,
    YFPreloadAdTypeNative
} YFPreloadAdType;

@interface DemoPreloadViewController ()<UITableViewDelegate, UITableViewDataSource, YFAdRewardVideoDelegate,YFAdInterstitialDelegate,YFAdSplashDelegate,YFAdBannerDelegate,YFAdFusionBannerDelegate,YFAdFusionBannerDelegate,YFAdMediaDelegate,YFAdFullScreenVideoDelegate,YFAdDrawDelegate,YFAdPatchDelegate,YFAdNativeExpressDelegate>

@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray *dataSource;
@property (nonatomic, assign) YFPreloadAdType preloadType;
// 激励视频
@property (nonatomic, strong) YFAdRewardVideo *rewardVideoAd;
// 插屏
@property (nonatomic, strong) YFAdInterstitial *interstitialAd;
// 开屏
@property (nonatomic, strong) YFAdSplash *splashAd;
// 横幅
@property (nonatomic, strong) YFAdBanner *bannerAd;
@property (nonatomic, strong) UIView *bannerContainer;
// 融合Banner
@property (nonatomic, strong) YFAdFusionBanner *fusionBannerAd;
@property (nonatomic, strong) UIView *fusionBannerContainer;
// 媒体自渲染
@property (nonatomic, strong) YFAdMediaRender *mediaRenderAd;
@property (nonatomic, strong) YFAdMedia *mediaAdData;
// 全屏视频
@property (nonatomic, strong) YFAdFullScreenVideo *fullScreenAd;
// draw视频流广告
@property (nonatomic, strong) YFAdDraw *drawAd;
@property (nonatomic, strong) NSMutableArray<YFAdDrawView *> *drawAdViews;
// 贴片广告
@property (nonatomic, strong) YFAdPatch *patchAd;
// 贴片广告容器
@property (nonatomic, strong) UIView *patchContainer;
// 信息流广告
@property (nonatomic, strong) YFAdNativeExpress *expressAd;
@property (nonatomic, strong) NSMutableArray *expressAdViews;
// 预加载是否成功
@property (nonatomic) bool isAdLoaded;
// 开屏广告背景视图
@property(strong,nonatomic)  UIImageView  *bgImageView;

@end

@implementation DemoPreloadViewController

#pragma mark - property

- (UITableView *)tableView {
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        [_tableView registerClass:[DemoPreloadTableViewCell class] forCellReuseIdentifier:NSStringFromClass([DemoPreloadTableViewCell class])];
    }
    return _tableView;
}

#pragma mark - life crycle

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    [self setupData];
    [self setupUI];
    
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    self.navigationController.navigationBar.barTintColor = [UIColor whiteColor];

}

- (void)dealloc {
    NSLog(@"释放广告加载器 %s",__func__);
    [self deallocAd];
}

- (void)deallocAd {
    self.splashAd = nil;
    self.rewardVideoAd = nil;
    self.interstitialAd = nil;
    self.bannerAd = nil;
    self.fusionBannerAd = nil;
    self.mediaRenderAd = nil;
    self.fullScreenAd = nil;
    self.patchAd = nil;
    self.drawAd = nil;
    self.expressAd = nil;
}

- (void)setupData {
    self.dataSource = @[
        @{
            @"title":@"加载激励视频广告",
            @"selector":@"preloadRewardVideoAd"
        },
        @{
            @"title":@"加载插屏广告",
            @"selector":@"preloadIntertitalAd"
        },
        @{
            @"title":@"加载开屏广告",
            @"selector":@"preloadSplashAd"
        },
        @{
            @"title":@"加载横幅广告",
            @"selector":@"preloadBannerAd"
        },
        @{
            @"title":@"加载融合Banner广告",
            @"selector":@"preloadFusionBannerAd"
        },
        @{
            @"title":@"加载媒体自渲染广告",
            @"selector":@"preloadMediaRenderAd"
        },
        @{
            @"title":@"加载全屏视频广告",
            @"selector":@"preloadFullScreenVideoAd"
        },
        @{
            @"title":@"加载视频流广告",
            @"selector":@"preloadDrawAd"
        },
        @{
            @"title":@"加载贴片广告",
            @"selector":@"preloadPatchAd"
        },
        @{
            @"title":@"加载信息流广告",
            @"selector":@"preloadNativeExpressAd"
        }
    ];
}

- (void)setupUI {
    [self setupNav];
    [self.view addSubview:self.tableView];
    self.tableView.frame = CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height - 120);
    self.textV.frame = CGRectMake(0, self.view.bounds.size.height - 120, self.view.bounds.size.width, 120);
}

- (void)setupNav {
    UIView * navView = [[UIView alloc]initWithFrame:CGRectMake(0, 0,200,40)];
    UIImageView * logoIV = [[ UIImageView alloc]initWithImage:[UIImage imageNamed:@"AppIcon"]];
    logoIV.frame = CGRectMake(0, 0, 40, 40);
    [navView addSubview:logoIV];

    UILabel * title = [[UILabel alloc]initWithFrame:CGRectZero];
    title.frame = CGRectMake(44+5, 0, 150, 40);
    title.font = [UIFont boldSystemFontOfSize:17];
    title.text = @"预加载广告";
    [navView addSubview:title];
  
    self.navigationItem.titleView = navView;
    UIBarButtonItem *rightBar = [[UIBarButtonItem alloc] initWithTitle:@"展示广告" style:UIBarButtonItemStylePlain target:self action:@selector(showPreloadAd)];
    self.navigationItem.rightBarButtonItem = rightBar;
}

#pragma mark - preload ads

/// 预加载激励视频
- (void)preloadRewardVideoAd {
    [JDStatusBarNotification showWithStatus:@"开始预加载激励视频广告" dismissAfter:1.5];
    // 初始化激励视频加载器
    _rewardVideoAd = [[YFAdRewardVideo alloc] initWithAdUnitID:[YFEnvironmentManager getREWARD_ID] viewController:self];
    // 激励视频方向
    _rewardVideoAd.adsShowDirection = YFAdsShowDirectionVertical;
    // 激励视频代理对象
    _rewardVideoAd.delegate = self;
    // 激励视频加载
    [_rewardVideoAd loadAd];
    _rewardVideoAd.userId = @"test";
    _rewardVideoAd.extra = @"test 1212321321";
    // 注意！！！设置根控制器一定是负责即将展示的最上层可见控制器，否则无法模态推出广告落地页，影响转化
//    [_rewardVideoAd setRootController:(nonnull UIViewController *)];
    [self loadAdWithState:AdState_Loading];
    self.preloadType = YFPreloadAdTypeRewardVideo;
}

/// 预加载插屏广告
- (void)preloadIntertitalAd {
    [JDStatusBarNotification showWithStatus:@"开始预加载插屏广告" dismissAfter:1.5];
    // 初始化插屏广告
    _interstitialAd = [[YFAdInterstitial alloc] initWithAdUnitID:[YFEnvironmentManager getINSERT_ID] viewController:self];
    // 设置插屏广告代理对象
    _interstitialAd.delegate = self;
    _isAdLoaded = false;
    // 加载插屏广告
    [_interstitialAd loadAd];
    [self loadAdWithState:AdState_Loading];
    self.preloadType = YFPreloadAdTypeIntertitial;
}

/// 预加载开屏广告
- (void)preloadSplashAd {
    [JDStatusBarNotification showWithStatus:@"开始预加载开屏广告" dismissAfter:1.5];
    // 初始化开屏广告加载器
    _splashAd = [[YFAdSplash alloc] initWithAdUnitID:[YFEnvironmentManager getHotSPLASH_ID] viewController:self];
    // 开屏广告代理
    _splashAd.delegate = self;
    // 是否展示logo
    _splashAd.showLogoRequire = YES;
    // 开屏广告超时时间
    _splashAd.timeout = 5;
    // 注意！！！设置根控制器一定是负责即将展示的最上层可见控制器，否则无法模态推出广告落地页，影响转化
//    [_splashAd setRootController:(nonnull UIViewController *)];
    // 加载开屏广告
    [_splashAd loadAd];
    self.preloadType = YFPreloadAdTypeSplash;
}

/// 预加载横幅广告
- (void)preloadBannerAd {
    [JDStatusBarNotification showWithStatus:@"开始预加载横幅广告" dismissAfter:1.5];
    // 横幅广告容器
    _bannerContainer = [[UIView alloc] initWithFrame:CGRectMake(0, self.view.frame.size.height / 2.0 ,self.view.frame.size.width,self.view.frame.size.height/ 2.0)];
    _bannerContainer.backgroundColor = UIColor.systemBlueColor;
    // 横幅广告初始化
    _bannerAd = [[YFAdBanner alloc] initWithAdUnitID:[YFEnvironmentManager getBANNER_ID] adContainer:_bannerContainer viewController:self];
    // 横幅广告代理对象
    _bannerAd.delegate = self;
    // 注意！！！设置根控制器一定是负责即将展示的最上层可见控制器，否则无法模态推出广告落地页，影响转化
//    [_bannerAd setRootController:(nonnull UIViewController *)];
    // 加载横幅广告
    [_bannerAd loadAndShowAd];
    self.preloadType = YFPreloadAdTypeBanner;
}

/// 预加载融合Banner广告
- (void)preloadFusionBannerAd {
    [JDStatusBarNotification showWithStatus:@"开始预加载融合Banner广告" dismissAfter:1.5];
    // 融合banner容器
    _fusionBannerContainer = [[UIView alloc] initWithFrame:CGRectMake(0, self.view.frame.size.height / 2.0 ,self.view.frame.size.width,self.view.frame.size.height/ 2.0)];
    // 融合banner初始化
    _fusionBannerAd = [[YFAdFusionBanner alloc] initWithAdUnitID:[YFEnvironmentManager getFusionBanner_ID] viewController:self];
    // 融合banner代理对象
    _fusionBannerAd.delegate = self;
    _fusionBannerAd.adCount = 1;
    // 融合banner期望宽度，高度会根据广告实际比例返回
    _fusionBannerAd.adWidth = self.view.bounds.size.width - 60 * 2;
    // 注意！！！设置根控制器一定是负责即将展示的最上层可见控制器，否则无法模态推出广告落地页，影响转化
//    [_fusionBannerAd    setRootController:(nonnull UIViewController *)];
    // 加载融合banner广告
    [_fusionBannerAd loadAndShowAd];
    self.preloadType = YFPreloadAdTypeFusionBanner;
}

/// 预加载媒体自渲染广告
- (void)preloadMediaRenderAd {
    [JDStatusBarNotification showWithStatus:@"开始预加载媒体自渲染广告" dismissAfter:1.5];
    // 初始化媒体自渲染广告 广告位ID需替换为运营同学提供id
    _mediaRenderAd = [[YFAdMediaRender alloc] initWithAdUnitID:@"d53d8fec49c544fd948f5eef5f805201" viewController:self];
    // 设置代理对象
    _mediaRenderAd.delegate = self;
    // 注意！！！设置根控制器一定是负责即将展示的最上层可见控制器，否则无法模态推出广告落地页，影响转化
//    [_mediaRenderAd setRootController:(nonnull UIViewController *)];
    // 媒体自渲染广告加载
    [_mediaRenderAd loadAndShowAd];
    self.preloadType = YFPreloadAdTypeMediaRender;
}

/// 预加载全屏视频广告
- (void)preloadFullScreenVideoAd {
    [JDStatusBarNotification showWithStatus:@"开始预加载全屏视频广告" dismissAfter:1.5];
    // 初始化全屏视频加载器
    _fullScreenAd = [[YFAdFullScreenVideo alloc] initWithAdUnitID:[YFEnvironmentManager getFULLSCREEN_ID] viewController:self];
    // 设置代理对象
    _fullScreenAd.delegate = self;
    // 注意！！！设置根控制器一定是负责即将展示的最上层可见控制器，否则无法模态推出广告落地页，影响转化
//    [_fullScreenAd setRootController:(nonnull UIViewController *)];
    // 加载全屏广告
    [_fullScreenAd loadAndShowAd];
    self.preloadType = YFPreloadAdTypeFullScreen;
}

/// 预加载视频流广告
- (void)preloadDrawAd {
    [JDStatusBarNotification showWithStatus:@"开始预加载视频流广告" dismissAfter:1.5];
    // 加载视频流广告
    _drawAd = [[YFAdDraw alloc] initWithAdUnitID:[YFEnvironmentManager getDRAW_ID] viewController:self adSize:CGSizeMake([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)];
    // 设置视频流广告代理对象
    _drawAd.delegate = self;
    // 加载视频流广告的数量
    _drawAd.count = 1;
    // 注意！！！设置根控制器一定是负责即将展示的最上层可见控制器，否则无法模态推出广告落地页，影响转化
//    [_drawAd setRootController:(nonnull UIViewController *)];
    // 加载视频流广告
    [_drawAd loadAndShowAd];
    self.preloadType = YFPreloadAdTypeDraw;
}

/// 预加载贴片广告
- (void)preloadPatchAd {
    [JDStatusBarNotification showWithStatus:@"开始预加载贴片广告" dismissAfter:1.5];
    // 贴片广告容器
    _patchContainer = [[UIView alloc] initWithFrame:CGRectMake(0, 100, self.view.bounds.size.width, self.view.bounds.size.width *5/32)];
    // 贴片广告
    _patchAd = [[YFAdPatch alloc] initWithAdUnitID:[YFEnvironmentManager getPATCH_ID] adContainer:_patchContainer viewController:self];
    // 贴片广告代理对象
    _patchAd.delegate = self;
    // 注意！！！设置根控制器一定是负责即将展示的最上层可见控制器，否则无法模态推出广告落地页，影响转化
//    [_patchAd setRootController:(nonnull UIViewController *)];
    // 加载贴片广告
    [_patchAd loadAndShowAd];
    self.preloadType = YFPreloadAdTypePatch;
}

/// 预加载信息流广告
- (void)preloadNativeExpressAd {
    [JDStatusBarNotification showWithStatus:@"开始预加载信息流广告" dismissAfter:1.5];
    // 信息流广告
    _expressAd = [[YFAdNativeExpress alloc] initWithAdUnitID:[YFEnvironmentManager getNATIVE_ID] adContainer:nil viewController:self adSize:CGSizeMake(self.view.bounds.size.width, (self.view.bounds.size.width) * 400.0 /600.0)];
    // 信息流广告加载数量
    _expressAd.count = 1;
    // 信息流广告代理
    _expressAd.delegate = self;
    // 注意！！！设置根控制器一定是负责即将展示的最上层可见控制器，否则无法模态推出广告落地页，影响转化
//    [_expressAd setRootController:(nonnull UIViewController *)];
    // 加载信息流广告
    [_expressAd loadAndShowAd];
    self.preloadType = YFPreloadAdTypeNative;
}

/// 展示预加载广告
- (void)showPreloadAd {
    // 展示预加载广告 跳转其他页面展示 将广告和加载器传给其他界面对象展示
    // 跳转其他控制器展示
    if (self.isAdLoaded) {
        switch (self.preloadType) {
                // 激励视频
            case YFPreloadAdTypeRewardVideo: {
                DemoPresentViewController *pvc = [[DemoPresentViewController alloc] init];
                pvc.adapter = self.rewardVideoAd;
                [self.navigationController pushViewController:pvc animated:YES];
                break;
            }
            case YFPreloadAdTypeIntertitial: {
                // 插屏广告
                DemoPresentViewController *pvc = [[DemoPresentViewController alloc] init];
                pvc.adapter = self.interstitialAd;
                [self.navigationController pushViewController:pvc animated:YES];
                break;
            }
            case YFPreloadAdTypeSplash: {
                // 开屏广告
                DemoPresentViewController *pvc = [[DemoPresentViewController alloc] init];
                pvc.adapter = self.splashAd;
                [self.navigationController pushViewController:pvc animated:YES];
                break;
            }
            case YFPreloadAdTypeBanner: {
                // 横幅广告
                DemoBannerChangeViewController *pvc = [[DemoBannerChangeViewController alloc] init];
                pvc.adapter = self.bannerAd;
                pvc.adView = self.bannerContainer;
                [self.navigationController pushViewController:pvc animated:YES];
                break;
            }
            case YFPreloadAdTypeFusionBanner: {
                //融合Banner
                DemoBannerChangeViewController *pvc = [[DemoBannerChangeViewController alloc] init];
                pvc.adapter = self.fusionBannerAd;
                pvc.adView = self.fusionBannerContainer;
                [self.navigationController pushViewController:pvc animated:YES];
                break;
            }
            case YFPreloadAdTypeMediaRender: {
                // 媒体自渲染
                DemoNativeSelfRenderView *selfRenderView = [[DemoNativeSelfRenderView alloc] initWithOffer:self.mediaAdData];
                NSMutableArray * clickableViews = [[NSMutableArray alloc] initWithCapacity:0];
                if(selfRenderView.mediaView){
                    [clickableViews addObject:selfRenderView.mediaView];
                }
                
                [clickableViews addObjectsFromArray:@[selfRenderView.ctaLabel,selfRenderView.titleLabel,selfRenderView.textLabel,selfRenderView.mainImageView,selfRenderView.iconImageView]];

                [self.mediaAdData registerContainer:selfRenderView withClickableViews:clickableViews];
                DemoMediaRenderDetailViewController *showVc = [[DemoMediaRenderDetailViewController alloc] initWithAdView:selfRenderView offer:self.mediaAdData];
                [self.navigationController pushViewController:showVc animated:YES];
                break;
            }
            case YFPreloadAdTypeFullScreen: {
                // 全屏视频广告
                DemoPresentViewController *pvc = [[DemoPresentViewController alloc] init];
                pvc.adapter = self.fullScreenAd;
                [self.navigationController pushViewController:pvc animated:YES];
                break;
            }
            case YFPreloadAdTypeDraw: {
                // draw视频流广告
                DemoDrawChangeViewController * pvc = [[DemoDrawChangeViewController alloc] init];
                pvc.adapter = self.drawAd;
                pvc.adViews = [self.drawAdViews copy];
                break;
            }
            case YFPreloadAdTypePatch: {
                // 贴片广告
                DemoBannerChangeViewController *pvc = [[DemoBannerChangeViewController alloc] init];
                pvc.adapter = self.patchAd;
                pvc.adView = self.patchContainer;
                [self.navigationController pushViewController:pvc animated:YES];
                break;
            }
            case YFPreloadAdTypeNative: {
                // 信息流广告
                DemoListFeedExpressChangeViewController * pvc = [[DemoListFeedExpressChangeViewController alloc] init];
                pvc.adRequestArray = [NSMutableArray arrayWithArray:@[self.expressAd]];
                pvc.arrViewsM = [self.expressAdViews copy];
                [self.navigationController pushViewController:pvc animated:YES];
                break;
            }
            default:
                break;
        }
    } else {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
    }
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataSource.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 60.0;
}

#pragma mark - UITableViewDelegate

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    DemoPreloadTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass([DemoPreloadTableViewCell class])];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    NSDictionary *dic = self.dataSource[indexPath.row];
    [cell setTitle:[NSString stringWithFormat:@"%@", dic[@"title"]]];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSDictionary *dic = self.dataSource[indexPath.row];
    NSString *selectorString = [NSString stringWithFormat:@"%@", dic[@"selector"]];
    // 调用预加载广告方法
    if ([self respondsToSelector:NSSelectorFromString(selectorString)]) {
        [self performSelector:NSSelectorFromString(selectorString)];
    }
}

#pragma mark  - YFAdCommonDelegate

/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    self.isAdLoaded = YES;
    [JDStatusBarNotification showWithStatus:@"预加载广告成功" dismissAfter:1.0];
    [self showProcessWithText:@"预加载广告成功"];
}

/// 广告数据加载失败
- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter description:(NSDictionary *)description {
    self.isAdLoaded = NO;
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
    [JDStatusBarNotification showWithStatus:@"预加载广告失败" dismissAfter:1.0];
    [self showProcessWithText:@"预加载广告失败"];
    [self deallocAd];
}

/// 广告曝光
- (void)fcAdExposured:(id)adapter  {
    NSLog(@"广告曝光回调 %s", __func__);
    [self showProcessWithText:@"预加载广告曝光"];
    self.isAdLoaded = NO;
}

/// 广告点击
- (void)fcAdClicked:(id)adapter  {
    NSLog(@"广告点击 %s", __func__);
    [self showProcessWithText:@"广告点击"];
}

/// 广告关闭了
- (void)fcAdDidClose:(id)adapter  {
    NSLog(@"广告关闭了 %s", __func__);
    [self showProcessWithText:@"广告关闭"];
    [self deallocAd];
}

/// 广告点击跳过
- (void)fcAdSplashOnAdSkipClicked{
    NSLog(@"广告点击了跳过 %s", __func__);
    [self deallocAd];
}

/// 广告倒计时结束回调 百度广告不支持该回调
- (void)fcAdSplashOnAdCountdownToZero{
    NSLog(@"广告倒计时结束 %s", __func__);
    [self deallocAd];
}

#pragma mark - YFAdFusionBannerDelegate 广告相关回调

/// 广告数据拉取成功
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdLoadSuccess:(NSArray<YFAdFusionBannerView *> * _Nullable)views {
    if (views.count > 0) {
        // 渲染成功才算做加载成功
        self.isLoaded = NO;
        /// 调用渲染方法，不调用无渲染相关回调
        for (YFAdFusionBannerView *bannerView in views) {
            [bannerView render];
        }
    } else {
        [JDStatusBarNotification showWithStatus:@"广告返回为空" dismissAfter:1.0];
        self.isAdLoaded = NO;
    }
}

/// 广告曝光
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdShow:(YFAdFusionBannerView * _Nullable)adView {
    [JDStatusBarNotification showWithStatus:@"融合Banner广告曝光" dismissAfter:1.0];
    [self showProcessWithText:@"融合Banner广告曝光"];
}

/// 广告点击
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdClicked:(YFAdFusionBannerView * _Nullable)adView {
    [JDStatusBarNotification showWithStatus:@"融合Banner广告点击" dismissAfter:1.0];
    [self showProcessWithText:@"融合Banner广告点击"];
}

/// 广告渲染成功
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdRenderSuccess:(YFAdFusionBannerView * _Nullable)adView {
    self.isAdLoaded = YES;
    [JDStatusBarNotification showWithStatus:@"融合Banner广告渲染成功" dismissAfter:1.0];
    [self showProcessWithText:@"融合Banner广告渲染成功"];
    [self.fusionBannerContainer addSubview:adView];
    self.fusionBannerContainer.frame = CGRectMake(0, self.view.frame.size.height / 2.0,adView.bounds.size.width, self.fusionBannerContainer.bounds.size.height);
}

/// 广告渲染失败
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdRenderFail:(YFAdFusionBannerView * _Nullable)adView {
    self.isAdLoaded = NO;
    [JDStatusBarNotification showWithStatus:@"融合Banner广告渲染失败" dismissAfter:1.0];
    [self showProcessWithText:@"融合Banner广告渲染失败"];
}

/// 广告被关闭
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdClosed:(YFAdFusionBannerView * _Nullable)adView {
    /// 可在此处理 fusionBanner 与其关联的广告视图，当全部广告关闭时，可释放fusionBanner加载器
    /// ...............
}

#pragma mark - YFAdNativeExpressDelegate

/// 广告数据拉取成功
- (void)fcAdNativeExpressOnAdLoadSuccess:(NSArray<YFAdNativeExpressView *> *)views {
    self.expressAdViews = [views mutableCopy];
    self.isLoaded = YES;
    [JDStatusBarNotification showWithStatus:@"信息流广告预加载成功" dismissAfter:1.0];
    [self showProcessWithText:@"信息流广告预加载成功"];
}


/// 广告曝光
- (void)fcAdNativeExpressOnAdShow:(YFAdNativeExpressView *)adView {
    [JDStatusBarNotification showWithStatus:@"信息流广告曝光" dismissAfter:1.0];
    [self showProcessWithText:@"信息流广告曝光"];
}

/// 广告点击
- (void)fcAdNativeExpressOnAdClicked:(YFAdNativeExpressView *)adView {
    [JDStatusBarNotification showWithStatus:@"信息流广告点击" dismissAfter:1.0];
    [self showProcessWithText:@"信息流广告点击"];
}

/// 广告渲染成功
/// 注意和广告数据拉取成功的区别  广告数据拉取成功, 但是渲染可能会失败
/// 广告加载失败 是广点通 穿山甲 mercury 在拉取广告的时候就全部失败了
/// 该回调的含义是: 比如: 广点通拉取广告成功了并返回了一组view  但是其中某个view的渲染失败了
/// 该回调会触发多次
- (void)fcAdNativeExpressOnAdRenderSuccess:(YFAdNativeExpressView *)adView {
    AlertIfNotMainThread
    /// 穿山上甲渲染成功之后返回高度
    if (([adView.expressView isKindOfClass:NSClassFromString(@"BUNativeExpressFeedVideoAdView")] ||
         [adView.expressView isKindOfClass:NSClassFromString(@"BUNativeExpressAdView")] ||
         [adView.expressView isKindOfClass:NSClassFromString(@"CSINativeExpressFeedVideoAdView")] ||
         [adView.expressView isKindOfClass:NSClassFromString(@"CSJNativeExpressAdView")])) {
        [adView setRootController:[UIViewController new]];
    }
    [JDStatusBarNotification showWithStatus:@"信息流广告渲染成功" dismissAfter:1.0];
    [self showProcessWithText:@"信息流广告渲染成功"];
    self.isAdLoaded = YES;
}

/// 广告渲染失败
/// 注意和广告加载失败的区别  广告数据拉取成功, 但是渲染可能会失败
/// 广告加载失败 是广点通 穿山甲 mercury 在拉取广告的时候就全部失败了
/// 该回调的含义是: 比如: 广点通拉取广告成功了并返回了一组view  但是其中某个view的渲染失败了
/// 该回调会触发多次
- (void)fcAdNativeExpressOnAdRenderFail:(YFAdNativeExpressView *)adView {
    [JDStatusBarNotification showWithStatus:@"信息流广告渲染失败" dismissAfter:1.0];
    [self showProcessWithText:@"信息流广告渲染失败"];
    self.isAdLoaded = NO;
}

/// 广告被关闭
- (void)fcAdNativeExpressOnAdClosed:(YFAdNativeExpressView *)adView {
    [adView.expressView removeFromSuperview];
}

#pragma mark - YFAdRewardVideoDelegate

/// 视频缓存成功
- (void)fcAdRewardVideoOnAdVideoCached {
    AlertIfNotMainThread
    NSLog(@"视频缓存成功 %s", __func__);
    [JDStatusBarNotification showWithStatus:@"视频缓存成功" dismissAfter:1.5];
    [self showProcessWithText:@"激励视频缓存成功"];
    self.isLoaded = YES;
}

/// 到达激励时间
- (void)fcAdRewardVideoAdDidRewardEffective {
    AlertIfNotMainThread
    NSLog(@"到达激励时间 %s", __func__);
    [JDStatusBarNotification showWithStatus:@"到达激励时间" dismissAfter:1.5];
    [self showProcessWithText:@"到达激励时间"];
}

#pragma mark - YFAdDrawDelegate

- (void)fcAdDrawOnAdLoadSuccess:(NSArray *)views {
    AlertIfNotMainThread
    self.drawAdViews = [views mutableCopy];
    self.isLoaded = YES;
    [JDStatusBarNotification showWithStatus:@"Draw广告加载成功" dismissAfter:1.5];
    [self showProcessWithText:@"Draw广告加载成功"];
}

/// 广告曝光
- (void)fcAdDrawOnAdShow:(YFAdDrawView *)adView {
    AlertIfNotMainThread
    NSLog(@"广告曝光 %s", __func__);
    [JDStatusBarNotification showWithStatus:@"Draw广告曝光" dismissAfter:1.5];
    [self showProcessWithText:@"Draw广告曝光"];
}

/// 广告点击
- (void)fcAdDrawOnAdClicked:(YFAdDrawView *)adView {
    AlertIfNotMainThread
    NSLog(@"广告点击 %s", __func__);
    [JDStatusBarNotification showWithStatus:@"Draw广告点击" dismissAfter:1.5];
    [self showProcessWithText:@"Draw广告点击"];
}

/// 广告渲染成功
/// 注意和广告数据拉取成功的区别  广告数据拉取成功, 但是渲染可能会失败
/// 广告加载失败 是广点通 穿山甲 mercury 在拉取广告的时候就全部失败了
/// 该回调的含义是: 比如: 广点通拉取广告成功了并返回了一组view  但是其中某个view的渲染失败了
/// 该回调会触发多次
- (void)fcAdDrawOnAdRenderSuccess:(YFAdDrawView *)adView {
    AlertIfNotMainThread
    NSLog(@"广告渲染成功 %s %@", __func__, adView);
    [JDStatusBarNotification showWithStatus:@"Draw广告渲染成功" dismissAfter:1.5];
    [self showProcessWithText:@"Draw广告渲染成功"];
}

/// 广告渲染失败
/// 注意和广告加载失败的区别  广告数据拉取成功, 但是渲染可能会失败
/// 广告加载失败 是广点通 穿山甲 mercury 在拉取广告的时候就全部失败了
/// 该回调的含义是: 比如: 广点通拉取广告成功了并返回了一组view  但是其中某个view的渲染失败了
/// 该回调会触发多次
- (void)fcAdDrawOnAdRenderFail:(YFAdDrawView *)adView {
    AlertIfNotMainThread
    NSLog(@"广告渲染失败 %s %@", __func__, adView);
    [JDStatusBarNotification showWithStatus:@"Draw广告渲染失败" dismissAfter:1.5];
    [self showProcessWithText:@"Draw广告渲染失败"];
    [_drawAdViews removeObject: adView];
}

/// 广告被关闭
- (void)fcAdDrawOnAdClosed:(YFAdDrawView *)adView {
    AlertIfNotMainThread
    //需要从tableview中删除
    NSLog(@"广告关闭 %s", __func__);
    [_drawAdViews removeObject: adView];
    [JDStatusBarNotification showWithStatus:@"Draw广告关闭" dismissAfter:1.5];
    [self showProcessWithText:@"Draw广告关闭"];
}


@end
