//
//  YFAdBaseBannerTemplateView.h
//  YFAdsSDK
//
//  Created by Codex on 2026/8/17.
//

#import <YFAdsSDK/YFAdBaseCustomView.h>
#import <YFAdsSDK/YFAdReportModel.h>
#import <YFAdsSDK/YFAdView.h>
#import <YFAdsSDK/YFAdsCloseButton.h>
#import <YFAdsSDK/YFAdsDetailButton.h>
#import <YFAdsSDK/YFAdMarkImageView.h>

NS_ASSUME_NONNULL_BEGIN

/// 自渲染/模板 Banner 视图公共基类。
/// 这里只沉淀跨联盟稳定复用的能力，避免改动现有模板的布局、曝光、摇一摇和视频播放逻辑。
@interface YFAdBaseBannerTemplateView : YFAdBaseCustomView

@property (nonatomic, strong, nullable, readonly) id yf_templateModel;
@property (nonatomic, copy, nullable, readonly) void (^yf_closeCallback)(id view);
@property (nonatomic, strong, readonly) UIView *yf_textOverlayMaskView;
@property (nonatomic, strong, readonly) UILabel *yf_textOverlayTitleLabel;

- (instancetype)initWithFrame:(CGRect)frame model:(id)model;

- (void)yf_setupWithModel:(nullable id)model;
- (void)show;
/// 适配器在返回模板前显式启用本地曝光计时；旧适配器保留初始化计时。
- (void)yf_prepareCloseCoverForExposure;
/// 由基类本地曝光监测调用，仅首次启动本模板关闭按钮的遮罩计时。
- (void)yf_templateDidExpose;
- (void)yf_storeCloseBlock:(nullable void (^)(id view))close;
- (void)yf_performCloseCallback;
- (void)yf_showInCurrentWindow;
- (void)yf_prepareBannerFrameWithOriginalFrame:(CGRect)frame height:(CGFloat)height backgroundColor:(nullable UIColor *)backgroundColor;
- (CGRect)yf_bannerFrameWithOriginalFrame:(CGRect)frame height:(CGFloat)height;
- (CGFloat)yf_bannerHeightWithWidth:(CGFloat)width minWidth:(CGFloat)minWidth widthRatio:(CGFloat)widthRatio heightRatio:(CGFloat)heightRatio;
- (CGFloat)yf_bannerHeightWithWidth:(CGFloat)width minWidth:(CGFloat)minWidth widthRatio:(CGFloat)widthRatio heightRatio:(CGFloat)heightRatio extraHeight:(CGFloat)extraHeight preferredHeight:(CGFloat)preferredHeight;
- (CGFloat)yf_heightForSixToFourTemplate;
- (CGFloat)yf_heightFor600x260Template;
- (CGFloat)yf_heightFor600x150Template;
- (CGFloat)yf_heightFor600x100Template;
- (CGFloat)yf_heightFor640x100Template;
- (CGFloat)yf_heightForTDBPTemplate;
- (CGFloat)yf_currentFrameHeight;

- (YFAdImageView *)yf_newImageView;
- (YFAdImageView *)yf_newInteractiveImageView;
- (YFAdImageView *)yf_newImageContainerWithBackgroundColor:(nullable UIColor *)backgroundColor;
- (YFAdImageView *)yf_newRoundedImageContainerWithCornerRadius:(CGFloat)cornerRadius backgroundColor:(nullable UIColor *)backgroundColor;
- (YFAdImageView *)yf_newImageViewWithContentMode:(UIViewContentMode)contentMode backgroundColor:(nullable UIColor *)backgroundColor;
- (YFAdImageView *)yf_newAppIconWithCornerRadius:(CGFloat)cornerRadius;
- (UIView *)yf_newWhiteSubView;
- (UIView *)yf_newClearSubView;
- (UIView *)yf_newBlackMaskViewWithAlpha:(CGFloat)alpha;
- (UILabel *)yf_newLabelWithFont:(UIFont *)font textColor:(UIColor *)textColor;
- (UILabel *)yf_newPlainLabelWithFont:(UIFont *)font textColor:(UIColor *)textColor;
- (UILabel *)yf_newBannerTitleLabelWithTextColor:(UIColor *)textColor;
- (UILabel *)yf_newBannerTitleLabelWithFont:(nullable UIFont *)font textColor:(UIColor *)textColor;
- (UILabel *)yf_newBannerClippedTitleLabelWithFont:(UIFont *)font textColor:(UIColor *)textColor;
- (UILabel *)yf_newBannerSubtitleLabelWithFont:(UIFont *)font textColor:(UIColor *)textColor numberOfLines:(NSInteger)numberOfLines;
- (UILabel *)yf_newBannerAlignedSubtitleLabelWithFont:(UIFont *)font textColor:(UIColor *)textColor numberOfLines:(NSInteger)numberOfLines;
- (UILabel *)yf_newBannerActionLabelWithCornerRadius:(CGFloat)cornerRadius font:(UIFont *)font backgroundColor:(UIColor *)backgroundColor textColor:(UIColor *)textColor;
- (UILabel *)yf_newTextOverlayTitleLabel;
- (YFAdsCloseButton *)yf_newCloseButtonWithEventModel:(nullable YFAdEventModel *)eventModel target:(nullable id)target action:(nullable SEL)action;
- (YFAdsCloseButton *)yf_newCloseButtonWithEventModel:(nullable YFAdEventModel *)eventModel target:(nullable id)target action:(nullable SEL)action imageName:(NSString *)imageName edge:(CGFloat)edge;
- (YFAdsDetailButton *)yf_newDetailButtonWithEventModel:(nullable YFAdEventModel *)eventModel;
- (YFAdsDetailButton *)yf_newDetailButtonWithEventModel:(nullable YFAdEventModel *)eventModel scale:(CGFloat)scale;
- (YFAdsDetailButton *)yf_newDetailButtonWithEventModel:(nullable YFAdEventModel *)eventModel scale:(CGFloat)scale backgroundColor:(nullable UIColor *)backgroundColor;
- (YFAdsDetailButton *)yf_newDetailButtonWithEventModel:(nullable YFAdEventModel *)eventModel cornerRadius:(CGFloat)cornerRadius font:(nullable UIFont *)font backgroundColor:(nullable UIColor *)backgroundColor shouldSizeToFit:(BOOL)shouldSizeToFit;
- (YFAdMarkImageView *)yf_newAdLogoView;
- (YFAdMarkImageView *)yf_newAdLogoViewWithTraceProvider:(nullable NSArray *(^)(void))traceProvider;
- (void)yf_loadAdLogoView:(YFAdMarkImageView *)adLogo eventModel:(YFAdEventModel *)eventModel;
- (void)yf_appendCloseCoverView:(nullable UIView *)closeCover
                    eventModel:(nullable YFAdEventModel *)eventModel
              toClickableViews:(NSMutableArray<UIView *> *)clickableViews;
- (void)yf_resetImageViewForRefresh:(nullable YFAdImageView *)imageView;

- (void)yf_setupAdMediaContainer:(UIView *)mediaView;

/// 文字浮层模板的公共框架。联盟子类只负责素材视图和点击注册。
- (void)yf_prepareTextOverlayFrameFromFrame:(CGRect)frame;
- (void)yf_setupTextOverlayChromeWithLogoView:(YFAdMarkImageView *)logoView
                                  closeButton:(YFAdsCloseButton *)closeButton
                                    eventModel:(nullable YFAdEventModel *)eventModel;
- (void)yf_layoutTextOverlayChromeWithLogoView:(YFAdMarkImageView *)logoView
                                   closeButton:(YFAdsCloseButton *)closeButton;
- (void)yf_refreshTextOverlayLayout;
- (void)yf_resetTextOverlayRenderState;
- (void)yf_completeTextOverlayRender:(BOOL)success error:(nullable NSError *)error;
- (NSMutableArray<UIView *> *)yf_textOverlayClickableViewsWithEventModel:(nullable YFAdEventModel *)eventModel
                                                  primaryClickableViews:(NSArray<UIView *> *)primaryClickableViews
                                                    overlayClickableView:(nullable UIView *)overlayClickableView
                                                              closeCover:(nullable UIView *)closeCover;

@end

NS_ASSUME_NONNULL_END
