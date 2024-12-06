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

@end
