
#import <YFAdsSDK/YFAdBaseCustomView.h>
#import <YFAdsSDK/YFAdBaseView.h>
#import <YFAdsSDK/YFAdView.h>
#import <YFAdsSDK/YFAdsDetailButton.h>
#import <YFAdsSDK/YFAdsCloseButton.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFTxAdBannerViewR600x150 : YFAdBaseCustomView

@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong) YFAdsCloseButton *closeBtn;
@property (nonatomic, strong) UIView *subView;
@property (nonatomic, strong) UILabel *title;
@property (nonatomic, strong) YFAdsDetailButton *otherBtn;

-(instancetype)initWithFrame:(CGRect)frame model:(id )model nativeAd:(id)nativeAd ;
-(float)getViewHeight;
-(void)loadAdData:(id)dataObject close: (void(^)(id))close;
- (void)setVideoMute;
@end

NS_ASSUME_NONNULL_END
