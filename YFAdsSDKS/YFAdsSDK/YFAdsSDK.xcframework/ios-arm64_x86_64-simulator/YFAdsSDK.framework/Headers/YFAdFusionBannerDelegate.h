//
//  YFAdFusionBannerDelegate.h
//  YFAdsSDK
//
//  Created by Erik on 2024/10/22.
//

#import <YFAdsSDK/YFAdBaseDelegate.h>
#import <YFAdsSDK/YFAdFusionBannerView.h>

@class YFAdFusionBanner;
@protocol YFAdFusionBannerDelegate <YFAdBaseDelegate>

@optional
/// 广告数据拉取成功
/// - Parameters:
///   - fusionBanner: 广告加载器
///   - views: 返回的广告视图
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdLoadSuccess:(NSArray<YFAdFusionBannerView *> * _Nullable)views;

/// 广告渲染成功（在此回调中获取广告视图来展示，此时广告视图宽高渲染完成，可根据广告视图宽高设置容器）
/// - Parameters:
///   - fusionBanner: 广告加载器
///   - adView: 广告视图
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdRenderSuccess:(YFAdFusionBannerView * _Nullable)adView;

/// 广告渲染失败（在此回调中移除渲染失败的广告）
/// - Parameters:
///   - fusionBanner: 广告加载器
///   - adView: 广告视图
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdRenderFail:(YFAdFusionBannerView * _Nullable)adView;

/// 广告曝光
/// - Parameters:
///   - fusionBanner: 广告加载器
///   - adView: 广告视图
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdShow:(YFAdFusionBannerView * _Nullable)adView;

/// 广告点击
/// - Parameters:
///   - fusionBanner: 广告加载器
///   - adView: 广告视图
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdClicked:(YFAdFusionBannerView * _Nullable)adView;

/// 广告被关闭
/// - Parameters:
///   - fusionBanner: 广告加载器
///   - adView: 广告视图
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdClosed:(YFAdFusionBannerView * _Nullable)adView;

/// 开发者自渲染广告类型视频相关回调
/// 自渲染广告视频缓存失败
/// - Parameters:
///   - fusionBanner: 广告加载器
///   - adView: 广告素材所属广告视图
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onVideoCacheFail:(YFAdFusionBannerView * _Nullable)adView;

/// 自渲染广告视频暂停
/// - Parameters:
///   - fusionBanner: 广告加载器
///   - adView: 广告素材所属广告视图
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onVideoPause:(YFAdFusionBannerView * _Nullable)adView;

/// 自渲染广告视频开始播放
/// - Parameters:
///   - fusionBanner: 广告加载器
///   - adView: 广告素材所属广告视图
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onVideoStartPlay:(YFAdFusionBannerView * _Nullable)adView;

/// 自渲染广告播放完成
/// - Parameters:
///   - fusionBanner: 广告加载器
///   - adView: 广告素材所属广告视图
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onVideoPlayFinish:(YFAdFusionBannerView * _Nullable)adView;

/// 自渲染广告播放进度，单位:s，因时间单位问题，可能会出现当前时间单位内重复回调问题
/// - Parameters:
///   - fusionBanner: 广告加载器
///   - adView: 广告素材所属广告视图
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner adView:(YFAdFusionBannerView * _Nullable)adView onVideoPlayProgress:(int)progress;


@end
