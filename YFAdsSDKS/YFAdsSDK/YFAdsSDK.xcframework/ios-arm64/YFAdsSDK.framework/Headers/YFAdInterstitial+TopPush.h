//
//  YFAdInterstitial+TopPush.h
//  YFAdsSDK
//
//  Created by mamingkang on 2025/9/24.
//

#import <YFAdsSDK/YFAdInterstitial.h>
#import <YFAdsSDK/YFAdTopPush.h>
#import <YFAdsSDK/YFAdTopPushDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@class YFAdTopPush;

/// 顶推广告回调
@protocol YFAssociationTopPushDelegate<NSObject>

@optional
/// 顶推广告加载成功
/// - Parameter topPush: 加载器实例
- (void)fcAssociationTopPushOnAdLoadSuccess:(YFAdTopPush * _Nonnull)topPush;

/// 顶推广告加载失败
/// - Parameters:
///   - topPush: 加载器实例
///   - error: 错误
- (void)fcAssociationTopPushOnAdLoadFail:(YFAdTopPush * _Nonnull)topPush withError:(NSError * _Nullable)error;

/// 顶推广告渲染成功 建议在此回调展示
/// - Parameter topPush: 加载器实例
- (void)fcAssociationTopPushOnAdRenderSuccess:(YFAdTopPush * _Nonnull)topPush;

/// 顶推广告渲染失败
/// - Parameter topPush: 加载器实例
- (void)fcAssociationTopPushOnAdRenderFail:(YFAdTopPush * _Nonnull)topPush;

/// 顶推广告曝光
/// - Parameter topPush: 加载器实例
- (void)fcAssociationTopPushOnAdShow:(YFAdTopPush * _Nonnull)topPush;

/// 顶推广告点击
/// - Parameter topPush: 加载器实例
- (void)fcAssociationTopPushOnAdClick:(YFAdTopPush * _Nonnull)topPush;

/// 顶推广告关闭
/// - Parameter topPush: 加载器实例
- (void)fcAssociationTopPushOnAdClose:(YFAdTopPush * _Nonnull)topPush;

/// 顶推落地页关闭
/// - Parameter topPush: 加载器实例
- (void)fcAssociationTopPushOnAdDetailPageClose:(YFAdTopPush * _Nonnull)topPush;
@end


@interface YFAdInterstitial (TopPush)<YFAdTopPushDelegate>
@property (nonatomic, weak) id<YFAssociationTopPushDelegate> associationDelegate;
@property (nonatomic, strong) YFAdTopPush *topPush;
@property (nonatomic) BOOL topPushRenderSuccess;
@property (nonatomic, strong) NSString *association_pid;
- (void)tryLoadAssociationAd;
@end

NS_ASSUME_NONNULL_END
