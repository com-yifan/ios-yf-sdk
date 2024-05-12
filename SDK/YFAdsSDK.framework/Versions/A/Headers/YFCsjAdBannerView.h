
#import <UIKit/UIKit.h>
#if __has_include(<BUAdSDK/BUAdSDK.h>)
#import <BUAdSDK/BUAdSDK.h>
#import "YFAdInteractionType.h"
#import "YFAdView.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFCsjAdBannerView : UIView
@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong) UIButton *closeBtn;
@property (nonatomic, strong) UIView *subView;
@property (nonatomic, strong) UILabel *title;
@property (nonatomic, strong) UILabel *otherBtn;
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;

-(float)getViewHeight;
-(void)loadAdData:(BUNativeAd *)dataObject close: (void(^)(id))close;

@end

NS_ASSUME_NONNULL_END
#endif
