#import <YFAdsSDK/YFAdBaseBannerTemplateView.h>

#if __has_include(<GDTMobSDK/GDTUnifiedNativeAdView.h>)
#import <YFAdsGDTAdapter/YFGdtAdMediaView.h>

@class YFAdEventModel;
@class YFAdMarkImageView;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YFGdtBannerImageEffect) {
    YFGdtBannerImageEffectLightNoCompress,
    YFGdtBannerImageEffectDark,
};

typedef NS_ENUM(NSUInteger, YFGdtBannerMediaPlacement) {
    YFGdtBannerMediaPlacementInsertAtBack,
    YFGdtBannerMediaPlacementSendToBack,
};

/// GDT Banner 模板只需描述视图绑定、点击区域和少量层级差异。
@interface YFGdtBannerLoadConfiguration : NSObject

@property (nonatomic, weak) YFGdtAdMediaView *mediaView;
@property (nonatomic, weak) YFAdImageView *contentView;
@property (nonatomic, weak, nullable) YFAdImageView *imageView;
@property (nonatomic, weak, nullable) YFAdImageView *appIcon;
@property (nonatomic, weak, nullable) UILabel *titleLabel;
@property (nonatomic, weak, nullable) UILabel *subtitleLabel;
@property (nonatomic, weak, nullable) id actionTextView;
@property (nonatomic, weak, nullable) UIView *closeCover;
@property (nonatomic, weak, nullable) UIView *limitedClickableView;
@property (nonatomic, copy) NSArray<UIView *> *primaryClickableViews;
@property (nonatomic, copy) NSArray<UIView *> *nonLimitedClickableViews;
@property (nonatomic, copy) NSArray<UIView *> *broadClickableViews;
@property (nonatomic, copy) NSArray<UIView *> *chaThreeClickableViews;
@property (nonatomic, copy) NSArray<UIView *> *alwaysClickableViews;
@property (nonatomic, assign) YFGdtBannerImageEffect imageEffect;
@property (nonatomic, assign) YFGdtBannerMediaPlacement mediaPlacement;
@property (nonatomic, assign) BOOL createsBackgroundClickableView;
@property (nonatomic, assign) BOOL configuresUserControl;
@property (nonatomic, assign) BOOL respectsInteractionStyle;
@property (nonatomic, assign) BOOL loadsAdLogo;

@end

/// GDT 自渲染 Banner 模板公共基类。
@interface YFGdtBaseBannerView : YFAdBaseBannerTemplateView

@property (nonatomic, strong) YFAdEventModel *eventModel;
@property (nonatomic, strong) id dataObject;
@property (nonatomic, strong, readonly) YFAdMarkImageView *logoView;

- (instancetype)initWithFrame:(CGRect)frame model:(id)model;
- (void)loadAdData:(id)dataObject close:(void(^)(id data))close;
- (nullable YFGdtBannerLoadConfiguration *)yf_bannerLoadConfiguration;
- (void)close;
- (void)resetVC:(UIViewController *)viewController;
- (YFGdtAdMediaView *)yf_newGdtAdMediaViewWithBackgroundColor:(UIColor *)backgroundColor;
- (YFAdMarkImageView *)yf_newGdtAdLogoView;
- (void)yf_loadAdLogoForCurrentEvent;
- (void)yf_registerCurrentAdWithClickableViews:(NSArray<UIView *> *)clickableViews;

@end

NS_ASSUME_NONNULL_END
#endif
