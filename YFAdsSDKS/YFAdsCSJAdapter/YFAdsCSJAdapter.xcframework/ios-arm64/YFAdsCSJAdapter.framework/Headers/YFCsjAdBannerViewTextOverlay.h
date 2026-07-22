#import <YFAdsSDK/YFAdBaseCustomView.h>

#if __has_include(<BUAdSDK/BUAdSDK.h>)
#import <BUAdSDK/BUAdSDK.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFCsjAdBannerViewTextOverlay : YFAdBaseCustomView

@property (nonatomic, copy, nullable) void (^clickVideoBlk)(void);

- (instancetype)initWithFrame:(CGRect)frame model:(id)model;
- (void)loadAdData:(BUNativeAd *)dataObject close:(void(^)(id data))close;

@end

NS_ASSUME_NONNULL_END
#endif
