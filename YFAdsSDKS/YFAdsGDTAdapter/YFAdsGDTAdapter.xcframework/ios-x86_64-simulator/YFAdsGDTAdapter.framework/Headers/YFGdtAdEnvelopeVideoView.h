
#import <YFAdsSDK/YFAdBaseCustomView.h>
#if __has_include( <GDTMobSDK/GDTUnifiedNativeAdView.h>)


#import <YFAdsSDK/YFAdInteractionType.h>
#import <YFAdsSDK/YFAdCustomModel.h>
#import <YFAdsSDK/YFAdView.h>
#import <YFAdsGDTAdapter/YFGdtAdMediaView.h>


NS_ASSUME_NONNULL_BEGIN

@interface YFGdtAdEnvelopeVideoView : YFAdBaseCustomView

-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
@property (nonatomic, strong) YFGdtAdMediaView *adInterView;

-(void)loadAdData:(id)dataObject close: (void(^)(id))close;

@end

NS_ASSUME_NONNULL_END
#endif
