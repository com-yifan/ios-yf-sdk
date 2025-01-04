
#import <YFAdsSDK/YFAdBaseCustomView.h>


#import <YFAdsSDK/YFAdInteractionType.h>

#import <YFAdsSDK/YFAdCustomModel.h>
#import <YFAdsSDK/YFAdBaseView.h>
#import <YFAdsSDK/YFAdView.h>

NS_ASSUME_NONNULL_BEGIN

@class YFTxAdInterstitialVideoView;

@protocol YFTxAdInterstitialVideoViewDelegate <NSObject>
@optional

@end

@interface YFTxAdInterstitialVideoView : YFAdBaseCustomView

@property (nonatomic, weak) id<YFTxAdInterstitialVideoViewDelegate> delegate;
-(instancetype)initWithFrame:(CGRect)frame model:(id)model nativeAd:(id)nativeAd viewController:(UIViewController *)viewController;
-(void)loadAdData:(id)dataObject close: (void(^)(id))close;
- (void)setVideoMute;
@end

NS_ASSUME_NONNULL_END
