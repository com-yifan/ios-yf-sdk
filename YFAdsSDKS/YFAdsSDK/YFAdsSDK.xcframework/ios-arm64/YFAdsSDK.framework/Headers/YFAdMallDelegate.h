//
//  YFAdMallDelegate.h
//  YFAdsSDK
//
//  Created by Erik on 2025/11/1.
//

@class YFAdMall;

@protocol YFAdMallActionProtocol <NSObject>
@required
/// 隐藏红包浮窗
- (void)hideFloatIcon;
/// 显示红包浮窗
- (void)showFloatIcon;

@end

/// 商城回调
@protocol YFAdMallDelegate<NSObject>

@optional
/// 商城加载成功
/// - Parameter Mall: 加载器实例
- (void)fcAdMallOnAdLoadSuccess:(YFAdMall * _Nonnull)mall;

/// 商城加载失败
/// - Parameters:
///   - Mall: 加载器实例
///   - error: 错误
- (void)fcAdMallOnAdLoadFail:(YFAdMall * _Nonnull)mall withError:(NSError * _Nullable)error;

/// 商城页曝光【该曝光回调是指用户真实进入商城落地页的曝光，而非iCON或红包封面展示】
/// - Parameter Mall: 加载器实例
- (void)fcAdMallOnAdShow:(YFAdMall * _Nonnull)mall;

/// 商城页点击
/// - Parameter Mall: 加载器实例
- (void)fcAdMallOnAdClick:(YFAdMall * _Nonnull)mall;

/// 商城页关闭
/// - Parameter Mall: 加载器实例
- (void)fcAdMallOnAdClose:(YFAdMall * _Nonnull)mall;

@end
