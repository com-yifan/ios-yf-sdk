//
//  YFIntertitialWithTopPushManager.h
//  YFAdsSDK
//
//  Created by Erik on 2026/2/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFIntertitialWithTopPushManager : NSObject

+ (instancetype)sharedInstance;

/// 加载顶推填充后展示
/// - Parameters:
///   - adId: 顶推广告位id
///   - rID: 插屏requestID
///   - delayTime: 延迟展示
- (void)loadTopPushAndShowWithAdId:(NSString *)adId rID:(NSString *)rID delayShowTime:(NSInteger)delayTime;

/// 加载顶推
/// - Parameters:
///   - adId: 顶推广告位id
///   - rID: 插屏requestID
///   - delayTime: 延迟展示时间
- (void)loadTopPushWithAdId:(NSString *)adId rID:(NSString *)rID delayShowTime:(NSInteger)delayTime;

/// 展示顶推
/// - Parameter rID: 插屏requestID
- (void)showTopPushWithrID:(NSString *)rID;

/// 移除所有已请求且未调用展示的广告，在插屏关闭回调中清除
- (void)removeAllUselessTopPush;

/// 移除对应rID请求标识 移除可再次发起请求
- (void)clearRequestTagWithrID:(NSString *)rId;

@end

NS_ASSUME_NONNULL_END
