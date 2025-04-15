//
//  ADXNativeAdsManager.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/9/5.
//

#import <UIKit/UIKit.h>

#import <YFAdsSDK/YFAd.h>
#import <YFAdsSDK/YFAdInteractionType.h>
#import <YFAdsSDK/YFMaterialMeta.h>
#import <YFAdsSDK/ADXNativeAd.h>
NS_ASSUME_NONNULL_BEGIN


@class ADXNativeAdsManager,YFAdEventModel;

@protocol ADXNativeAdsManagerDelegate <NSObject>
@optional
/**
 * interstitial ad data loaded
 */
- (void)adxNativeAdsManagerDidLoad:(ADXNativeAdsManager *)adsManager nativeAds:(NSArray<ADXNativeAd *> *_Nullable)nativeAdDataArray;

/**
 * interstitial ad  load failed
 */
- (void)adxNativeAdsManager:(ADXNativeAdsManager *)adsManager loadFailWithError:(NSError *_Nullable)error;


///**
// * interstitial ad  render failed
// */
//- (void)adxNativeAdsManager:(ADXNativeAdsManager *)nativeAd renderFailWithError:(NSError *_Nullable)error;
//
///**
// * interstitial ad did visible
// */
//- (void)adxNativeAdsManagerDidVisible:(ADXNativeAdsManager *)nativeAd;
///**
// * interstitial ad did click
// */
//- (void)adxNativeAdsManagerDidClick:(ADXNativeAdsManager *)nativeAd;
//
///**
// * interstitial ad did close
// */
//- (void)adxNativeAdsManagerDidClose:(ADXNativeAdsManager *)nativeAd;

@end

@interface ADXNativeAdsManager : UIView

@property (nonatomic, weak) id<ADXNativeAdsManagerDelegate>delegate;
//广告是否已合法加载
@property (nonatomic, readonly) BOOL isValid;
//是否开启声音
@property (nonatomic, assign) BOOL videoSoundEnabled;

@property(nonatomic,assign)NSUInteger ecpm;

@property(nonatomic, strong) YFMaterialMeta *materialModel;

//@property(nonatomic, strong) YFInterstitialView *adView;

- (instancetype)initWithPosId:(NSString *)posId eventModel:(YFAdEventModel *)eventModel;


@property (nonatomic, assign) BOOL autoClick;

- (void)showFromViewController:(UIViewController *)viewController;

- (void)loadAdData;

/**
 Register clickable views in native ads view.
 Interaction types can be configured on TikTok Audience Network.
 Interaction types include view video ad details page, make a call, send email, download the app, open the webpage using a browser,open the webpage within the app, etc.
 @param containerView : required.
                        container view of the native ad.
 @param clickableViews : optional.
                        Array of views that are clickable.
 */
//- (void)registerContainer:(__kindof UIView *)containerView
//       withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews;
@end

NS_ASSUME_NONNULL_END

