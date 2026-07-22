#import <YFAdsSDK/YFAdBaseCustomView.h>

#if __has_include(<GDTMobSDK/GDTUnifiedNativeAdView.h>)
#import <YFAdsGDTAdapter/YFGdtAdMediaView.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFGdtAdBannerViewTextOverlay : YFAdBaseCustomView

@property (nonatomic, strong) YFGdtAdMediaView *adInterView;

- (instancetype)initWithFrame:(CGRect)frame model:(id)model;
- (void)loadAdData:(id)dataObject close:(void(^)(id data))close;
- (void)resetVC:(UIViewController *)VC;

@end

NS_ASSUME_NONNULL_END
#endif
