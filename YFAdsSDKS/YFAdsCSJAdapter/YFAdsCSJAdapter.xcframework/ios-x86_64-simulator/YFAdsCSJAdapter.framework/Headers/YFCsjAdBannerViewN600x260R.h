
#import <YFAdsSDK/YFAdBaseCustomView.h>
#if __has_include(<BUAdSDK/BUAdSDK.h>)
#import <BUAdSDK/BUAdSDK.h>
#import <YFAdsSDK/YFAdInteractionType.h>
#import <YFAdsSDK/YFAdView.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFCsjAdBannerViewN600x260R : YFAdBaseCustomView

-(instancetype)initWithFrame:(CGRect)frame model:(id)model;

-(float)getViewHeight;
-(void)loadAdData:(BUNativeAd *)dataObject close: (void(^)(id))close;
/// 点击视频
@property(nonatomic,copy) void (^clickVideoBlk)(void);

@end

NS_ASSUME_NONNULL_END
#endif
