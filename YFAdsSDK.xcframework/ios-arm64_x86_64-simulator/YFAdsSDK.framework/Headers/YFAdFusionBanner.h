//
//  YFAdFusionBanner.h
//  YFAdsSDK
//
//  Created by Erik on 2024/10/21.
//

#import <YFAdsSDK/YFAdBaseAdapter.h>
#import <YFAdsSDK/YFAdFusionBannerDelegate.h>

NS_ASSUME_NONNULL_BEGIN

/// 融合Banner广告（混出信息流&banner广告&自渲染广告）
@interface YFAdFusionBanner : YFAdBaseAdapter

@property (nonatomic, weak) id<YFAdFusionBannerDelegate> delegate;
/// 期望的广告宽度[必传]
@property (nonatomic, assign) CGFloat adWidth;
/// 期望的广告高度；文字浮层模板生效。宽高任一为0时默认按2:1比例计算，最小返回尺寸为80x50
@property (nonatomic, assign) CGFloat adHeight;
/// banner自动刷新时间，单位: 秒；仅融合banner中横幅类型支持，信息流无效
@property(nonatomic, assign) int refreshInterval;
/// 期望返回的广告条数（可能存在失败的情况，所以实际返回小于等于该值，默认1条，最多3条）
@property (nonatomic, assign) int adCount;
/// 开发者自渲染期望返回的mediaView的尺寸
@property (nonatomic, assign) CGRect videoViewFrame;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithAdUnitID:(NSString *)pID NS_UNAVAILABLE;

/// 初始化广告加载器
/// - Parameters:
///   - pID: 广告位id
///   - viewController: 广告展示控制器(建议传入最上层可见控制器)
- (instancetype)initWithAdUnitID:(NSString *)pID
                  viewController:(nonnull UIViewController *)viewController;

/// 加载广告
- (void)loadAndShowAd;
- (void)loadAd NS_UNAVAILABLE;
- (void)showAd NS_UNAVAILABLE;
- (void)loadAdSucceed NS_UNAVAILABLE;

/// 文字浮层模板统一尺寸计算
+ (CGSize)textOverlayTemplateSizeWithAdWidth:(CGFloat)adWidth adHeight:(CGFloat)adHeight;

@end

NS_ASSUME_NONNULL_END
