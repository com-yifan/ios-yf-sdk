#import <YFAdsBDAdapter/YFBdAdBaseBannerView.h>

#if __has_include(<BaiduMobAdSDK/BaiduMobAdNativeAdView.h>)
#import <BaiduMobAdSDK/BaiduMobAdNativeAdObject.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFBdAdBannerViewTextOverlay : YFBdAdBaseBannerView

- (instancetype)initWithFrame:(CGRect)frame model:(id)model;
- (void)loadAdData:(BaiduMobAdNativeAdObject *)object close:(void(^)(id data))close;

@end

NS_ASSUME_NONNULL_END
#endif
