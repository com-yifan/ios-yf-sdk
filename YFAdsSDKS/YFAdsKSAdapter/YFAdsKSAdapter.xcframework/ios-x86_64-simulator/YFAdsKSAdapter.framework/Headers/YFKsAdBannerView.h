
#import <YFAdsKSAdapter/YFKsBaseBannerView.h>

#if __has_include(<KSAdSDK/KSAdSDK.h>)
#import <KSAdSDK/KSAdSDK.h>
#import <YFAdsSDK/YFAdInteractionType.h>
#import <YFAdsSDK/YFAdCustomModel.h>
#import <YFAdsSDK/YFAdBaseView.h>
#import <YFAdsSDK/YFAdView.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFKsAdBannerView : YFKsBaseBannerView
-(float)getViewHeight;

@end

NS_ASSUME_NONNULL_END
#endif
