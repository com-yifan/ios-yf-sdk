
#import <UIKit/UIKit.h>
#import "YFAdBaseView.h"
#import "YFAdView.h"
#import "YFAdsDetailButton.h"
NS_ASSUME_NONNULL_BEGIN

@interface YFTxAdBannerView600x150 : YFAdBaseView

@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong) UIButton *closeBtn;
@property (nonatomic, strong) UIView *subView;
@property (nonatomic, strong) UILabel *title;
@property (nonatomic, strong) YFAdsDetailButton *otherBtn;

-(instancetype)initWithFrame:(CGRect)frame model:(id )model nativeAd:(id)nativeAd ;
-(float)getViewHeight;
-(void)loadAdData:(id)dataObject close: (void(^)(id))close;
- (void)setVideoMute;
@end

NS_ASSUME_NONNULL_END
