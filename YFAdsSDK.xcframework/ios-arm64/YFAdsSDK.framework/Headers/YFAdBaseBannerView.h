#import <YFAdsSDK/YFBannerView.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YFAdBannerMaterialSource) {
    YFAdBannerMaterialSourceAsset,
    YFAdBannerMaterialSourceTypedAsset,
};

typedef NS_ENUM(NSUInteger, YFAdBannerVideoDetection) {
    YFAdBannerVideoDetectionIsVideoAd,
    YFAdBannerVideoDetectionAssetType,
};

typedef NS_ENUM(NSUInteger, YFAdBannerClickStrategy) {
    YFAdBannerClickStrategyStandard,
    YFAdBannerClickStrategyTDBP,
};

/// YF/ADX Banner 模板只描述布局相关视图和少量历史行为差异。
@interface YFAdBannerLoadConfiguration : NSObject

@property (nonatomic, weak, nullable) UILabel *titleLabel;
@property (nonatomic, weak, nullable) UILabel *subtitleLabel;
@property (nonatomic, weak, nullable) YFAdsDetailButton *actionButton;
@property (nonatomic, weak, nullable) YFAdImageView *appIcon;
@property (nonatomic, weak, nullable) UIView *limitedClickableView;
@property (nonatomic, copy) NSArray<UIView *> *primaryClickableViews;
@property (nonatomic, copy) NSArray<UIView *> *alwaysClickableViews;
@property (nonatomic, assign) YFAdBannerMaterialSource materialSource;
@property (nonatomic, assign) YFAdBannerVideoDetection videoDetection;
@property (nonatomic, assign) YFAdBannerClickStrategy clickStrategy;
@property (nonatomic, assign) BOOL notifyFailureWithoutError;
@property (nonatomic, assign) BOOL registersClickGestures;
@property (nonatomic, assign) BOOL includesAreaInReportViews;
@property (nonatomic, assign) BOOL includesLogoInReportViews;
@property (nonatomic, assign) BOOL registersCloseCoverWhenSupported;
@property (nonatomic, assign) BOOL includesCloseCoverInReportViews;
@property (nonatomic, assign) BOOL removesFromSuperviewOnClose;
@property (nonatomic, assign) BOOL reportsVideoClose;
@property (nonatomic, assign) BOOL reportsVideoCloseBeforeDelegate;
@property (nonatomic, assign) BOOL reportsVideoCloseForEachURL;

@end

/// 亿帆自渲染 Banner 模板公共基类。
/// 统一模板间稳定复用的点击、滑动、视频上报处理和公共 UI 创建。
@interface YFAdBaseBannerView : YFBannerView

@property (nonatomic, strong, readonly) YFTouchReportView *reportView;
@property (nonatomic, strong, readonly) YFAdImageView *contentView;
@property (nonatomic, strong, readonly) YFAdImageView *contentbgView;
@property (nonatomic, strong, readonly) YFAdImageView *contentText;
@property (nonatomic, strong, readonly) YFAdsCloseButton *closeBtn;
@property (nonatomic, strong, readonly) UIView *subView;
@property (nonatomic, strong, readonly) YFAdImageView *adIcon;
@property (nonatomic, strong, readonly) UIView *adView;
@property (nonatomic, strong, readonly) YFAdMarkImageView *adLogo;
@property (nonatomic, strong, readonly) UIView *area;
@property (nonatomic, strong, readonly) UILabel *title;
@property (nonatomic, strong, readonly) UILabel *subTitle;
@property (nonatomic, strong, readonly) YFAdsDetailButton *otherBtn;
@property (nonatomic, strong, readonly) YFAdImageView *appIcon;

- (nullable YFAdBannerLoadConfiguration *)yf_bannerLoadConfiguration;

- (void)regiestClickableViews:(NSArray<UIView *> *)clickViews;
- (void)toAddPanEvent:(UIView *)view;
- (void)panAction:(UIPanGestureRecognizer *)pan;
- (void)toJumpEvent;
- (void)jumpEvent;

- (YFAdMarkImageView *)yf_newYfAdLogoView;
- (YFAdsCloseButton *)yf_newYfCloseButtonWithImageName:(NSString *)imageName;
- (YFTouchReportView *)yf_newYfReportView;

/// 模板可按需覆盖这些创建钩子，布局仍由具体模板负责。
- (YFAdImageView *)yf_createContentView;
- (YFAdImageView *)yf_createContentBackgroundView;
- (YFAdImageView *)yf_createContentTextView;
- (NSString *)yf_closeButtonImageName;
- (BOOL)yf_configuresHotAreaForDirectTap;

/// 公共文案控件的样式钩子；具体模板只需提供尺寸或颜色差异。
- (UIFont *)yf_titleFont;
- (UIColor *)yf_titleTextColor;
- (UIFont *)yf_subtitleFont;
- (UIColor *)yf_subtitleTextColor;
- (NSInteger)yf_subtitleNumberOfLines;
- (BOOL)yf_usesAlignedSubtitleLabel;
- (CGFloat)yf_detailButtonCornerRadius;
- (UIFont *)yf_detailButtonFont;
- (nullable UIColor *)yf_detailButtonBackgroundColor;
- (CGFloat)yf_appIconCornerRadius;

/// 统一加载 Banner 的视频封面、图片素材和模糊背景。
/// loadsVideoCover 由模板传入，保留历史上 isVideoAd/type 两种判断方式。
- (void)yf_bindDefaultMediaForMaterial:(YFMaterialMeta_new *)materialMeta
                       loadsVideoCover:(BOOL)loadsVideoCover
             notifyFailureWithoutError:(BOOL)notifyFailureWithoutError;
- (UIViewContentMode)yf_videoCoverContentMode;
- (BOOL)yf_shouldNotifyImageRenderSuccess;
- (void)yf_bindAdLogoForCurrentEvent;
- (void)close;

- (void)toLoadPlayVideo;
- (void)toSetPlayerManagerGaussian;
- (void)playClick;

- (void)yf_handleVideoCacheFail:(nullable NSError *)error;
- (void)yf_handleVideoClickAtPoint:(CGPoint)clickPoint screenPoint:(CGPoint)screenPoint;
- (void)yf_handleVideoPlayOneQuarter;
- (void)yf_handleVideoPlayOneHalf;
- (void)yf_handleVideoPlayerState:(YFPlayerState)videoPlayState;
- (void)yf_handleVideoReadyToPlay;

@end

NS_ASSUME_NONNULL_END
