
#import <YFAdsSDK/YFAdBaseCustomView.h>
#if __has_include(<BaiduMobAdSDK/BaiduMobAdNativeAdView.h>)

NS_ASSUME_NONNULL_BEGIN

@interface YFBdAdBannerView600x410 : YFAdBaseCustomView
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(void)loadAdData:(id)object close:(void(^)(id))close;
-(void)show;
- (void)pauseVideo;
- (void)playVideo;
- (void)trackImpression;

@end

NS_ASSUME_NONNULL_END
#endif
