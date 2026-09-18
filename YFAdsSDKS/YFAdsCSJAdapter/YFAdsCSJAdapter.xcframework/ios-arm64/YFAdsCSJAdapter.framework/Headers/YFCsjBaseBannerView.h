#import <YFAdsSDK/YFAdBaseBannerTemplateView.h>

#if __has_include(<BUAdSDK/BUAdSDK.h>)
#import <BUAdSDK/BUAdSDK.h>
#import <YFAdsSDK/YFAdMarkImageView.h>
#import <YFAdsSDK/YFAdReportModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YFCsjBannerImageEffect) {
    YFCsjBannerImageEffectNone,
    YFCsjBannerImageEffectLight,
    YFCsjBannerImageEffectLightNoCompress,
};

/// CSJ Banner 的加载差异配置。模板只提供视图引用、点击区域和媒体尺寸。
@interface YFCsjBannerLoadConfiguration : NSObject

@property (nonatomic, weak) YFAdImageView *contentView;
@property (nonatomic, weak, nullable) YFAdImageView *imageView;
@property (nonatomic, weak, nullable) YFAdImageView *appIcon;
@property (nonatomic, weak, nullable) UILabel *titleLabel;
@property (nonatomic, weak, nullable) UILabel *subtitleLabel;
@property (nonatomic, weak, nullable) id actionTextView;
@property (nonatomic, weak, nullable) UIView *closeCover;
@property (nonatomic, weak, nullable) UIView *limitedClickableView;
@property (nonatomic, copy) NSArray<UIView *> *primaryClickableViews;
@property (nonatomic, copy) NSArray<UIView *> *alwaysClickableViews;
@property (nonatomic, assign) CGRect canvasFrame;
@property (nonatomic, assign) CGRect canvasMediaFrame;
@property (nonatomic, assign) CGRect portraitCanvasMediaFrame;
@property (nonatomic, assign) YFCsjBannerImageEffect videoBackgroundEffect;
@property (nonatomic, assign) YFCsjBannerImageEffect staticBackgroundEffect;
@property (nonatomic, assign) BOOL appendMediaClickableView;
@property (nonatomic, assign) BOOL resizeStaticCanvas;
@property (nonatomic, assign) BOOL setStaticContentImage;
@property (nonatomic, assign) BOOL disableMediaForCha3;
@property (nonatomic, assign) BOOL gmVideoSucceedsWithoutImage;

@end

/// CSJ 自渲染 Banner 模板公共基类。
/// 只收敛同联盟稳定公共状态和生命周期，具体布局、点击区域、视频渲染仍由各模板类处理。
@interface YFCsjBaseBannerView : YFAdBaseBannerTemplateView

@property (nonatomic, strong) YFAdEventModel *eventModel;
@property (nonatomic, strong) BUNativeAdRelatedView *relatedView;
@property (nonatomic, strong) BUNativeAd *dataObject;
@property (nonatomic, strong, readonly) YFAdMarkImageView *adLogo;

- (instancetype)initWithFrame:(CGRect)frame model:(id)model;
- (void)loadAdData:(BUNativeAd *)dataObject close:(void(^)(id data))close;
- (nullable YFCsjBannerLoadConfiguration *)yf_bannerLoadConfiguration;
- (BOOL)yf_refreshDataObject:(BUNativeAd *)dataObject;
- (void)close;
- (YFAdMarkImageView *)yf_newCsjAdLogoView;
- (void)yf_loadAdLogoForCurrentDataObject;
- (void)yf_appendMediaClickableViewToViews:(NSMutableArray<UIView *> *)views;
- (void)yf_registerCurrentAdWithClickableViews:(NSArray<UIView *> *)clickableViews;
- (void)yf_disableCurrentMediaInteractionInContentView:(UIView *)contentView;

@end

NS_ASSUME_NONNULL_END
#endif
