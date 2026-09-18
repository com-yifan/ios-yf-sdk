#import <YFAdsSDK/YFAdBaseBannerTemplateView.h>

#if __has_include(<KSAdSDK/KSAdSDK.h>)
#import <KSAdSDK/KSAdSDK.h>

@class YFAdEventModel;
@class YFAdMarkImageView;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YFKsBannerImageEffect) {
    YFKsBannerImageEffectLight,
    YFKsBannerImageEffectDark,
};

typedef NS_ENUM(NSUInteger, YFKsBannerTitleSource) {
    YFKsBannerTitleSourceAppOrProduct,
    YFKsBannerTitleSourceDescription,
};

/// KS Banner 的加载配置，模板保留布局和点击区域差异。
@interface YFKsBannerLoadConfiguration : NSObject

@property (nonatomic, weak) YFAdImageView *contentView;
@property (nonatomic, weak, nullable) YFAdImageView *mainImageView;
@property (nonatomic, weak, nullable) YFAdImageView *appIcon;
@property (nonatomic, weak, nullable) UILabel *titleLabel;
@property (nonatomic, weak, nullable) UILabel *subtitleLabel;
@property (nonatomic, weak, nullable) id actionTextView;
@property (nonatomic, weak, nullable) UIView *closeCover;
@property (nonatomic, weak, nullable) UIView *limitedClickableView;
@property (nonatomic, copy) NSArray<UIView *> *primaryClickableViews;
@property (nonatomic, copy) NSArray<UIView *> *broadClickableViews;
@property (nonatomic, copy) NSArray<UIView *> *chaThreeClickableViews;
@property (nonatomic, copy) NSArray<UIView *> *fallbackClickableViews;
@property (nonatomic, copy) NSArray<UIView *> *alwaysClickableViews;
@property (nonatomic, assign) YFKsBannerImageEffect imageEffect;
@property (nonatomic, assign) YFKsBannerTitleSource titleSource;
@property (nonatomic, assign) UIViewContentMode videoContentMode;
@property (nonatomic, assign) UIViewContentMode staticContentMode;
@property (nonatomic, assign) BOOL appliesContentMode;
@property (nonatomic, assign) BOOL includesVisibleMainImageInPrimary;
@property (nonatomic, assign) BOOL setStaticContentEffect;
@property (nonatomic, assign) BOOL disableVideoInteractionOutsideCha1;

@end

/// KS 自渲染 Banner 模板公共基类。
@interface YFKsBaseBannerView : YFAdBaseBannerTemplateView

@property (nonatomic, strong) YFAdEventModel *eventModel;
@property (nonatomic, strong) KSNativeAdRelatedView *relatedView;
@property (nonatomic, strong) KSNativeAd *nativeAd;
@property (nonatomic, strong, readonly) YFAdMarkImageView *adLogo;

- (instancetype)initWithFrame:(CGRect)frame model:(id)model;
- (void)loadAdData:(KSNativeAd *)dataObject close:(void(^)(id data))close;
- (nullable YFKsBannerLoadConfiguration *)yf_bannerLoadConfiguration;
- (void)close;
- (YFAdMarkImageView *)yf_newKsAdLogoView;
- (void)yf_loadAdLogoForCurrentEvent;
- (void)yf_registerCurrentAdWithClickableViews:(NSArray<UIView *> *)clickableViews;

@end

NS_ASSUME_NONNULL_END
#endif
