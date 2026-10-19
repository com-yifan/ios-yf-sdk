//
//  YFAdTopPushDelegate.h
//  YFAdsSDK
//
//  Created by Erik on 2025/9/17.
//

@class YFAdTopPush;

/// 顶推广告回调
@protocol YFAdTopPushDelegate<NSObject>

@optional
/// 顶推广告加载成功
/// - Parameter topPush: 加载器实例
- (void)fcAdTopPushOnAdLoadSuccess:(YFAdTopPush * _Nonnull)topPush;

/// 顶推广告加载失败
/// - Parameters:
///   - topPush: 加载器实例
///   - error: 错误
- (void)fcAdTopPushOnAdLoadFail:(YFAdTopPush * _Nonnull)topPush withError:(NSError * _Nullable)error;

/// 顶推广告渲染成功 建议在此回调展示
/// - Parameter topPush: 加载器实例
- (void)fcAdTopPushOnAdRenderSuccess:(YFAdTopPush * _Nonnull)topPush;

/// 顶推广告渲染失败
/// - Parameter topPush: 加载器实例
- (void)fcAdTopPushOnAdRenderFail:(YFAdTopPush * _Nonnull)topPush;

/// 顶推广告曝光
/// - Parameter topPush: 加载器实例
- (void)fcAdTopPushOnAdShow:(YFAdTopPush * _Nonnull)topPush;

/// 顶推广告点击
/// - Parameter topPush: 加载器实例
- (void)fcAdTopPushOnAdClick:(YFAdTopPush * _Nonnull)topPush;

/// 顶推广告关闭
/// - Parameter topPush: 加载器实例
- (void)fcAdTopPushOnAdClose:(YFAdTopPush * _Nonnull)topPush;


/// 顶推落地页关闭
/// - Parameter topPush: 加载器实例
- (void)fcAdTopPushOnAdDetailPageClose:(YFAdTopPush * _Nonnull)topPush;

@end
