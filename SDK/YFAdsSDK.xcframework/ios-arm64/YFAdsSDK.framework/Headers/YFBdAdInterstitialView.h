
#import <UIKit/UIKit.h>
#import "YFAdInteractionType.h"
#import "YFAdView.h"
#import "YFAdMarkView.h"

NS_ASSUME_NONNULL_BEGIN


@interface BdAdInterView : UIView
@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong) YFAdImageView *adImage;
@property (nonatomic, strong) YFAdImageView *bdImage;
@property (nonatomic, strong) YFAdMarkView *adLogo;

@property (nonatomic, strong) UIButton *closeBtn;
@property (nonatomic, strong) UIView *subView;
@property (nonatomic, strong) UILabel *title;
@property (nonatomic, strong) UILabel *otherBtn;

@end

@interface YFBdAdInterstitialView : UIView
@property (nonatomic, strong) BdAdInterView *adInterView;
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(void)loadAdData:(id)object;
-(void)show;
@end
NS_ASSUME_NONNULL_END
