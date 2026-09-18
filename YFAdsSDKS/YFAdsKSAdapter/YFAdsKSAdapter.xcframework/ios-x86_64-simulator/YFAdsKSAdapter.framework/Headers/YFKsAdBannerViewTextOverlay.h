#import <YFAdsKSAdapter/YFKsBaseBannerView.h>

#if __has_include(<KSAdSDK/KSAdSDK.h>)
#import <KSAdSDK/KSAdSDK.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFKsAdBannerViewTextOverlay : YFKsBaseBannerView

- (instancetype)initWithFrame:(CGRect)frame model:(id)model;
- (void)loadAdData:(KSNativeAd *)dataObject close:(void(^)(id data))close;

@end

NS_ASSUME_NONNULL_END
#endif
