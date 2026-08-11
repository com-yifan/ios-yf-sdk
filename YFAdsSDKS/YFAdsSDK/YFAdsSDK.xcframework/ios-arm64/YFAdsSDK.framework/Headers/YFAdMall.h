//
//  YFAdMall.h
//  YFAdsSDK
//
//  Created by Erik on 2025/11/1.
//

#import <YFAdsSDK/YFAdBaseAdapter.h>
#import <YFAdsSDK/YFAdMallDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdMall : YFAdBaseAdapter

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithAdUnitID:(NSString *)pID withViewController:(UIViewController *)viewController NS_UNAVAILABLE;
/// 初始化商城广告
/// - Parameters:
///   - pID: 广告位ID
- (instancetype)initWithAdUnitID:(NSString *)pID;

/// 广告方法回调代理
@property (nonatomic, weak) id<YFAdMallDelegate> delegate;
/// 是否自定义商城页入口，默认NO，使用SDK内入口样式
@property (nonatomic, assign) BOOL customEntry;
/// 优惠券类型；未获取到优惠券信息时为YFAdMallCouponTypeUnknown
@property (nonatomic, assign, readonly) YFAdMallCouponType couponType;
/// 优惠券金额/折扣信息；无金额信息时为@"0"
@property (nonatomic, copy, readonly) NSString *couponAmount;

/// 加载广告
- (void)loadAd;
/// 展示广告；当customEntry = YES时，则直接展示穿山甲商城页
- (void)showAd;
/// 加载并展示广告；当customEntry = YES时，则直接展示穿山甲商城页
- (void)loadAndShowAd;

/// 暂时隐藏和显示浮窗icon，customEntry=NO有效
- (void)hideFloatIcon;
- (void)showFloatIcon;

- (void)showAdFromViewController:( UIViewController * _Nullable)viewController NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
