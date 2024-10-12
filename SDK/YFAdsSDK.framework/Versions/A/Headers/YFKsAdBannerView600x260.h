
#import "YFAdBaseCustomView.h"

#if __has_include(<KSAdSDK/KSAdSDK.h>)
#import <KSAdSDK/KSAdSDK.h>
#import "YFAdInteractionType.h"
#import "YFAdCustomModel.h"
#import "YFAdBaseView.h"
#import "YFAdView.h"
#import "YFAdsCloseButton.h"

NS_ASSUME_NONNULL_BEGIN


@interface YFKsAdBannerView600x260 : YFAdBaseCustomView

@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong) YFAdImageView *mainImageView;
@property (nonatomic, strong) YFAdsCloseButton *closeBtn;
@property (nonatomic, strong) UIView *subView;
@property (nonatomic, strong) UILabel *title;
@property (nonatomic, strong) UILabel *otherBtn;

-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(float)getViewHeight;
-(void)loadAdData:(KSNativeAd *)dataObject close: (void(^)(id))close;

@end

NS_ASSUME_NONNULL_END
#endif
