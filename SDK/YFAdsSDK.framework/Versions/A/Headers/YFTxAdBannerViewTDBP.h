
#import "YFAdBaseCustomView.h"


#import "YFAdBaseView.h"
#import "YFAdView.h"
#import "YFAdsCloseButton.h"

NS_ASSUME_NONNULL_BEGIN


@interface YFTxAdBannerViewTDBP : YFAdBaseCustomView

@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong) YFAdsCloseButton *closeBtn;
@property (nonatomic, strong) UIView *subView;
@property (nonatomic, strong) UILabel *title;
@property (nonatomic, strong) UILabel *otherBtn;

-(instancetype)initWithFrame:(CGRect)frame model:(id)model nativeAd:(id)nativeAd ;
-(float)getViewHeight;
-(void)loadAdData:(id)dataObject close: (void(^)(id))close;
- (void)setVideoMute;
@end

NS_ASSUME_NONNULL_END
