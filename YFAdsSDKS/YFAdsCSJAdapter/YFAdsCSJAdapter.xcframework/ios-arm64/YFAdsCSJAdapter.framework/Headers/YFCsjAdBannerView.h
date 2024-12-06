
#import <YFAdsSDK/YFAdBaseCustomView.h>
#if __has_include(<BUAdSDK/BUAdSDK.h>)
#import <BUAdSDK/BUAdSDK.h>
#import <YFAdsSDK/YFAdInteractionType.h>
#import <YFAdsSDK/YFAdView.h>
#import <YFAdsSDK/YFAdsDetailButton.h>
#import <YFAdsSDK/YFAdsCloseButton.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFCsjAdBannerView : YFAdBaseCustomView
@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong) YFAdsCloseButton *closeBtn;
@property (nonatomic, strong) UIView *subView;
@property (nonatomic, strong) UILabel *title;
@property (nonatomic, strong) YFAdsDetailButton *otherBtn;

- (instancetype)initWithFrame:(CGRect)frame model:(id)model;
- (float)getViewHeight;
- (void)loadAdData:(BUNativeAd *)dataObject close: (void(^)(id))close;
/// 点击视频
@property(nonatomic,copy) void (^clickVideoBlk)(void);
@end

NS_ASSUME_NONNULL_END
#endif
