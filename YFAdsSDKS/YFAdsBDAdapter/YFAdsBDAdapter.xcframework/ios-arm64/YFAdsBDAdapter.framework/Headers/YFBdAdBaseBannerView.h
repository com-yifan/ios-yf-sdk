//
//  YFBdAdBaseBannerView.h
//  YFAdsBDAdapter
//
//  Created by Erik on 2025/1/2.
//

#import <YFAdsSDK/YFAdsSDK.h>
#if __has_include(<BaiduMobAdSDK/BaiduMobAdNativeAdView.h>)
#import <BaiduMobAdSDK/BaiduMobAdNativeAdView.h>
#import <BaiduMobAdSDK/BaiduMobAdNativeAdObject.h>
#import <BaiduMobAdSDK/BaiduMobAdNativeVideoView.h>
#import <BaiduMobAdSDK/BaiduMobAdNativeShakeView.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFBdBannerLoadConfiguration : NSObject

@property (nonatomic, weak, nullable) YFAdImageView *contentView;
@property (nonatomic, weak, nullable) UILabel *titleLabel;
@property (nonatomic, weak, nullable) UILabel *subtitleLabel;
@property (nonatomic, weak, nullable) YFAdsDetailButton *actionButton;
@property (nonatomic, weak, nullable) UILabel *actionLabel;
@property (nonatomic, weak, nullable) YFAdImageView *appIcon;
@property (nonatomic, weak, nullable) UIView *limitedClickableView;
@property (nonatomic, weak, nullable) UIView *closeCover;
@property (nonatomic, copy) NSArray<UIView *> *primaryClickableViews;
@property (nonatomic, copy) NSArray<UIView *> *chaThreeClickableViews;
@property (nonatomic, copy, nullable) void (^bindVideo)(BaiduMobAdNativeAdObject *object);
@property (nonatomic, copy, nullable) void (^bindNormal)(BaiduMobAdNativeAdObject *object);
@property (nonatomic, assign) BOOL includesCurrentMediaViews;
@property (nonatomic, assign) BOOL includesMainImageView;
@property (nonatomic, assign) BOOL alwaysIncludesActionButton;
@property (nonatomic, assign) BOOL includesActionAnimation;
@property (nonatomic, assign) BOOL loadsLightEffectBackground;
@property (nonatomic, assign) BOOL loadsAppIcon;
@property (nonatomic, assign) BOOL clearsSubtitle;
@property (nonatomic, assign) BOOL addsShakeView;

@end

/// 百度自渲染信息流广告基类
@interface YFBdAdBaseBannerView : YFAdBaseBannerTemplateView <BaiduMobAdNativeShakeViewDelegate> {
@protected
    YFAdEventModel *_eventModel;
}

@property (nonatomic, strong, nullable) BaiduMobAdNativeAdObject *object;
@property (nonatomic, strong, nullable) BaiduMobAdNativeVideoView *videoView;
@property (nonatomic, strong, nullable) BaiduMobAdNativeAdView *adView;
@property (nonatomic, strong, nullable) YFAdEventModel *eventModel;
@property (nonatomic, strong, readonly) YFAdMarkImageView *adLogo;
// 百度返回摇一摇组件
@property (nonatomic, strong, nullable) BaiduMobAdNativeShakeView *shakeView;

- (instancetype)initWithFrame:(CGRect)frame model:(id)model;
- (void)loadAdData:(id)object close:(void(^)(id))close;
- (nullable YFBdBannerLoadConfiguration *)yf_bannerLoadConfiguration;
- (void)yf_storeAdObject:(nullable BaiduMobAdNativeAdObject *)object close:(nullable void(^)(id))close;
- (void)yf_prepareForAdDataRefresh;
- (void)show;
- (void)close;
- (void)pauseVideo;
- (void)playVideo;
- (void)toAddShakeView;
- (void)trackImpression;
- (void)addTapWithView:(nullable UIView *)view;
- (void)yf_addTapWithView:(nullable UIView *)view target:(id)target action:(SEL)action;
- (void)yf_addTapWithViews:(NSArray<UIView *> *)views;
- (void)yf_addTapToCurrentMediaViewsIncludingMainImage:(BOOL)includesMainImage;
- (void)jump:(UITapGestureRecognizer *)sender;
- (void)yf_loadAdLogoForCurrentEvent;
- (BaiduMobAdNativeVideoView *)yf_newVideoViewWithFrame:(CGRect)frame
                                                object:(BaiduMobAdNativeAdObject *)object
                                              delegate:(nullable id)delegate;
- (BaiduMobAdNativeVideoView *)yf_attachVideoViewWithFrame:(CGRect)frame
                                                    object:(BaiduMobAdNativeAdObject *)object
                                                  delegate:(nullable id)delegate
                                               toContainer:(UIView *)container
                                               sendsToBack:(BOOL)sendsToBack;
- (BaiduMobAdNativeAdView *)yf_newNativeAdViewWithFrame:(CGRect)frame
                                   mainImageContentMode:(UIViewContentMode)contentMode
                                         clipsMainImage:(BOOL)clipsMainImage
                                        backgroundColor:(nullable UIColor *)backgroundColor;
- (void)yf_loadNativeAdView:(BaiduMobAdNativeAdView *)nativeAdView
                     object:(BaiduMobAdNativeAdObject *)object
       sendsMainImageToBack:(BOOL)sendsMainImageToBack
      beforeSuccessCallback:(nullable void (^)(void))beforeSuccessCallback;
- (BaiduMobAdNativeAdView *)yf_attachNativeAdViewWithFrame:(CGRect)frame
                                      mainImageContentMode:(UIViewContentMode)contentMode
                                            clipsMainImage:(BOOL)clipsMainImage
                                           backgroundColor:(nullable UIColor *)backgroundColor
                                                    object:(BaiduMobAdNativeAdObject *)object
                                               toContainer:(UIView *)container
                                               sendsToBack:(BOOL)sendsToBack
                                      sendsMainImageToBack:(BOOL)sendsMainImageToBack
                                     beforeSuccessCallback:(nullable void (^)(void))beforeSuccessCallback;
- (void)yf_loadLightEffectBackgroundWithURLString:(nullable NSString *)URLString
                                     intoImageView:(YFAdImageView *)imageView;
- (nullable UIView *)yf_shakeContainerView;
- (nullable YFAdsDetailButton *)yf_shakeDetailButton;
- (CGSize)yf_shakeViewSize;
- (BOOL)yf_canDisplayShakeView;
- (void)yf_addShakeViewToContainer:(UIView *)container size:(CGSize)size;
- (void)yf_removeShakeView;

@end

NS_ASSUME_NONNULL_END
#endif
