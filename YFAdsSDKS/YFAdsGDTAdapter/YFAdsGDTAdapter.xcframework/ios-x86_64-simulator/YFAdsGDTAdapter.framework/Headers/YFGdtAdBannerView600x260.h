
#import <YFAdsSDK/YFAdBaseCustomView.h>
#if __has_include( <GDTMobSDK/GDTUnifiedNativeAdView.h>)

#import <YFAdsSDK/YFAdInteractionType.h>
#import <YFAdsSDK/YFAdCustomModel.h>
#import <YFAdsSDK/YFAdView.h>
@class YFGdtAdMediaView;
NS_ASSUME_NONNULL_BEGIN

@interface YFGdtAdBannerView600x260: YFAdBaseCustomView
@property (nonatomic, strong) YFGdtAdMediaView *adInterView;
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(float)getViewHeight;
-(void)loadAdData:(id)dataObject close: (void(^)(id))close;
- (void)resetVC:(UIViewController*)VC;

@end

NS_ASSUME_NONNULL_END

#endif