#import <YFAdsSDK/YFAdBaseBannerView.h>

NS_ASSUME_NONNULL_BEGIN

/// 原生视频 Banner 模板公共基类，统一转发 YFVideoViewPlayerDelegate 事件。
@interface YFAdBaseVideoBannerView : YFAdBaseBannerView <YFVideoViewPlayerDelegate>

@end

NS_ASSUME_NONNULL_END
