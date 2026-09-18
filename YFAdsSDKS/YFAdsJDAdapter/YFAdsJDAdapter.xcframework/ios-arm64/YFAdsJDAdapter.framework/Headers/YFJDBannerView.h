//
//  YFJDBannerView.h
//  YFAdsSDK
//
//  Created by feng on 2023/11/10.
//


#import <YFAdsSDK/YFAdBaseBannerTemplateView.h>
#import <YFAdsSDK/YFAdReportModel.h>
#import <YFAdsSDK/YFAdView.h>
#import <YFAdsSDK/YFAdsCloseButton.h>
#import <YFAdsSDK/YFVideoView.h>

#if __has_include(<JADYun/JADYun.h>)
#import <JADYun/JADYun.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YFJDBannerBackgroundEffect) {
    YFJDBannerBackgroundEffectDark,
    YFJDBannerBackgroundEffectLight,
};

/// JD Banner 模板加载配置。布局仍由具体模板创建，素材和注册由基类统一处理。
@interface YFJDBannerLoadConfiguration : NSObject

@property (nonatomic, weak) YFAdImageView *contentView;
@property (nonatomic, weak, nullable) YFAdImageView *backgroundView;
@property (nonatomic, weak, nullable) YFAdImageView *adIcon;
@property (nonatomic, weak, nullable) UILabel *titleLabel;
@property (nonatomic, weak, nullable) UILabel *subtitleLabel;
@property (nonatomic, weak, nullable) id actionTextView;
@property (nonatomic, weak) YFAdsCloseButton *closeButton;
@property (nonatomic, copy) NSArray<UIView *> *primaryClickableViews;
@property (nonatomic, copy) NSArray<UIView *> *broadClickableViews;
@property (nonatomic, copy) NSArray<UIView *> *fallbackClickableViews;
@property (nonatomic, copy) NSArray<UIView *> *alwaysClickableViews;
@property (nonatomic, assign) YFJDBannerBackgroundEffect backgroundEffect;
@property (nonatomic, assign) BOOL limitedClickUsesActionView;
@property (nonatomic, assign) BOOL includeVideoInPrimary;
@property (nonatomic, assign) BOOL includeVideoInBroad;
@property (nonatomic, assign) BOOL setAdIconForVideo;
@property (nonatomic, assign) BOOL setAdIconForStaticImage;

@end

@interface YFJDBannerView : YFAdBaseBannerTemplateView

@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong, nullable) YFVideoView *videoView;
@property (nonatomic, strong, nullable) JADNativeAd *nativeAd;
@property (nonatomic, strong) YFAdEventModel *eventModel;
@property (nonatomic, strong, readonly) YFAdMarkImageView *adLogo;

///是否播放完成
@property (nonatomic, assign) BOOL playFinished;

-(void)startMonitor;

-(void)toLoadPlayVideo;

- (void)closeAd;

- (void)playVideo;

- (instancetype)initWithFrame:(CGRect)frame model:(id)model viewController:(nullable UIViewController *)viewController;

- (void)loadAdData:(nullable JADNativeAd *)dataObject close:(nullable void (^)(id view))close;
- (nullable YFJDBannerLoadConfiguration *)yf_bannerLoadConfiguration;

- (YFAdMarkImageView *)yf_newJdAdLogoView;
- (void)yf_loadAdLogoForCurrentEvent;
- (void)yf_registerCurrentAdWithClickableViews:(NSArray<UIView *> *)clickableViews
                                   closeButton:(YFAdsCloseButton *)closeButton;

@end
NS_ASSUME_NONNULL_END
#endif
