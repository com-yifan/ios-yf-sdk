
#import "YFAdBaseCustomView.h"
#if __has_include(<BUAdSDK/BUAdSDK.h>)
#import <BUAdSDK/BUAdSDK.h>
#import "YFAdInteractionType.h"
#import "YFAdView.h"
#import "YFAdsDetailButton.h"
#import "YFAdsCloseButton.h"


NS_ASSUME_NONNULL_BEGIN

@interface YFCsjAdBannerView600x410 : YFAdBaseCustomView
@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong) YFAdsCloseButton *closeBtn;
@property (nonatomic, strong) UIView *subView;
@property (nonatomic, strong) UILabel *title;
@property (nonatomic, strong) YFAdsDetailButton *otherBtn;
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;

-(float)getViewHeight;
-(void)loadAdData:(BUNativeAd *)dataObject close: (void(^)(id))close;

@end

NS_ASSUME_NONNULL_END
#endif
