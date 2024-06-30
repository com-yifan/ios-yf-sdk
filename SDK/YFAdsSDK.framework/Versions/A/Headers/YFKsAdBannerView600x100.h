
#import <UIKit/UIKit.h>

#if __has_include(<KSAdSDK/KSAdSDK.h>)
#import <KSAdSDK/KSAdSDK.h>
#import "YFAdInteractionType.h"
#import "YFAdCustomModel.h"
#import "YFAdBaseView.h"
#import "YFAdView.h"
NS_ASSUME_NONNULL_BEGIN


@interface YFKsAdBannerView600x100 : YFAdBaseView

@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong) UIButton *closeBtn;
@property (nonatomic, strong) UIView *subView;
@property (nonatomic, strong) UILabel *title;
@property (nonatomic, strong) UILabel *otherBtn;

-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(float)getViewHeight;
-(void)loadAdData:(KSNativeAd *)dataObject close: (void(^)(id))close;

@end

NS_ASSUME_NONNULL_END
#endif
