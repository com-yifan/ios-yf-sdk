
#import <YFAdsSDK/YFAdBaseCustomView.h>


#if __has_include(<KSAdSDK/KSAdSDK.h>)
#import <YFAdsSDK/YFAdInteractionType.h>

#import <YFAdsSDK/YFAdCustomModel.h>
#import <YFAdsSDK/YFAdBaseView.h>
#import <YFAdsSDK/YFAdView.h>
#import <KSAdSDK/KSAdSDK.h>
NS_ASSUME_NONNULL_BEGIN

@class YFKsAdInterstitialView;


@interface YFKsAdInterstitialView : YFAdBaseCustomView

@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong) UIButton *closeBtn;
@property (nonatomic, strong) UIView *subView;
@property (nonatomic, strong) UILabel *title;
@property (nonatomic, strong) UILabel *otherBtn;

-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
- (void)loadAdData:(KSNativeAd *)nativeAd;
@end

NS_ASSUME_NONNULL_END
#endif
