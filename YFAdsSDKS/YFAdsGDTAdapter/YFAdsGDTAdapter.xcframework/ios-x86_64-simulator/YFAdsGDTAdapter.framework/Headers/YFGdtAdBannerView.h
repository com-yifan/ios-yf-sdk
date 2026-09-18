
#import <YFAdsGDTAdapter/YFGdtBaseBannerView.h>
#if __has_include( <GDTMobSDK/GDTUnifiedNativeAdView.h>)

#import <YFAdsSDK/YFAdInteractionType.h>
#import <YFAdsSDK/YFAdCustomModel.h>
#import <YFAdsSDK/YFAdView.h>
#import <YFAdsGDTAdapter/YFGdtAdMediaView.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFGdtAdBannerView: YFGdtBaseBannerView
@property (nonatomic, strong) YFGdtAdMediaView *adInterView;
-(float)getViewHeight;
@end

NS_ASSUME_NONNULL_END
#endif
