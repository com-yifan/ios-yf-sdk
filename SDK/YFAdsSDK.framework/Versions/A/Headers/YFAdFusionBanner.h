//
//  YFAdFusionBanner.h
//  YFAdsSDK
//
//  Created by Erik on 2024/10/21.
//

#import "YFAdBaseAdapter.h"
#import "YFAdFusionBannerDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/// 融合Banner广告（混出信息流&banner广告）
@interface YFAdFusionBanner : YFAdBaseAdapter

@property (nonatomic, weak) id<YFAdFusionBannerDelegate> delegate;
/// 期望的广告宽度；必传
@property (nonatomic, assign) CGFloat adWidth;
/// banner自动刷新时间，单位: 秒；仅融合banner中横幅类型支持，信息流无效
@property(nonatomic, assign) int refreshInterval;
/// 期望返回的广告条数（可能存在失败的情况，所以实际返回小于等于该值，默认1条，最多3条）
@property (nonatomic, assign) int adCount;

/// 初始化广告加载器
/// - Parameters:
///   - pID: 广告位id
///   - viewController: 广告展示控制器(建议传入最上层可见控制器)
- (instancetype)initWithAdUnitID:(NSString *)pID
                  viewController:(nonnull UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
