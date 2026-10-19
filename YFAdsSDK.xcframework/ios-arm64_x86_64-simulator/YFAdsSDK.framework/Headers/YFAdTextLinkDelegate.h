//
//  YFAdTextLinkDelegate.h
//  YFAdsSDK
//
//  Created by Codex on 2026/4/9.
//

@class YFAdTextLink;
@class YFAdTextLinkView;

/// 文字链广告回调
@protocol YFAdTextLinkDelegate <NSObject>

@optional
/// 文字链广告加载成功
- (void)fcAdTextLinkOnAdLoadSuccess:(YFAdTextLink * _Nonnull)textLink adView:(YFAdTextLinkView * _Nullable)adView;

/// 文字链广告加载失败
- (void)fcAdTextLinkOnAdLoadFail:(YFAdTextLink * _Nonnull)textLink withError:(NSError * _Nullable)error;

/// 文字链广告渲染成功
- (void)fcAdTextLinkOnAdRenderSuccess:(YFAdTextLink * _Nonnull)textLink adView:(YFAdTextLinkView * _Nullable)adView;

/// 文字链广告渲染失败
- (void)fcAdTextLinkOnAdRenderFail:(YFAdTextLink * _Nonnull)textLink adView:(YFAdTextLinkView * _Nullable)adView;

/// 文字链广告曝光
- (void)fcAdTextLinkOnAdShow:(YFAdTextLink * _Nonnull)textLink adView:(YFAdTextLinkView * _Nullable)adView;

/// 文字链广告点击
- (void)fcAdTextLinkOnAdClick:(YFAdTextLink * _Nonnull)textLink adView:(YFAdTextLinkView * _Nullable)adView;

/// 文字链广告关闭
- (void)fcAdTextLinkOnAdClose:(YFAdTextLink * _Nonnull)textLink adView:(YFAdTextLinkView * _Nullable)adView;

/// 文字链落地页关闭
- (void)fcAdTextLinkOnAdDetailPageClose:(YFAdTextLink * _Nonnull)textLink adView:(YFAdTextLinkView * _Nullable)adView;

@end
