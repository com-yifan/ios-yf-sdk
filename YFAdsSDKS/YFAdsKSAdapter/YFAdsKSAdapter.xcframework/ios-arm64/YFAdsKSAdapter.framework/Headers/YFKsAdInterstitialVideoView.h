
#import <YFAdsSDK/YFAdBaseCustomView.h>


#if __has_include(<KSAdSDK/KSAdSDK.h>)
#import <YFAdsSDK/YFAdInteractionType.h>

#import <YFAdsSDK/YFAdCustomModel.h>
#import <YFAdsSDK/YFAdBaseView.h>
#import <YFAdsSDK/YFAdView.h>
#import <KSAdSDK/KSAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class YFKsAdInterstitialVideoView;

@protocol YFKsAdInterstitialVideoViewDelegate <NSObject>
@optional

@end

@interface YFKsAdInterstitialVideoView : YFAdBaseCustomView

@property (nonatomic, weak) id<YFKsAdInterstitialVideoViewDelegate> delegate;
-(instancetype)initWithFrame:(CGRect)frame model:(id)model viewController:(UIViewController *)viewController;
-(void)loadAdData:(KSNativeAd *)dataObject close: (void(^)(id))close;

@end

NS_ASSUME_NONNULL_END
#endif
