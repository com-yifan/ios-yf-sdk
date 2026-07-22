#import <YFAdsJDAdapter/YFJDBannerView.h>

#if __has_include(<JADYun/JADYun.h>)
NS_ASSUME_NONNULL_BEGIN

@interface YFJDAdBannerViewTextOverlay : YFJDBannerView

- (instancetype)initWithFrame:(CGRect)frame model:(id)model viewController:(UIViewController *)viewController;
- (void)loadAdData:(JADNativeAd *)dataObject close:(void(^)(id data))close;

@end

NS_ASSUME_NONNULL_END
#endif
