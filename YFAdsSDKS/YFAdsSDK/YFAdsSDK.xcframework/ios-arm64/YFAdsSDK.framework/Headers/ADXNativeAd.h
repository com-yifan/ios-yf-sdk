//
//  ADXNativeAd.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/9/5.
//  2024.11.12

#import <UIKit/UIKit.h>

#import <YFAdsSDK/YFAd.h>
#import <YFAdsSDK/YFAdInteractionType.h>
#import <YFAdsSDK/YFMaterialMeta.h>

NS_ASSUME_NONNULL_BEGIN


@class ADXNativeAd,YFAdEventModel;

@protocol ADXNativeAdDelegate <NSObject>
@optional

/**
 * NativeAd ad  render failed
 */
- (void)adxNativeAd:(ADXNativeAd *)nativeAd renderFailWithError:(NSError *_Nullable)error;

/**
 * NativeAd ad did visible
 */
- (void)adxNativeAdDidVisible:(ADXNativeAd *)nativeAd error:(nullable NSError *)error;
/**
 * NativeAd ad did click
 */
- (void)adxNativeAdDidClick:(ADXNativeAd *)nativeAd withView:(UIView *_Nullable)view;

/**
 * NativeAd ad did close
 */
- (void)adxNativeAdRenderSuccess:(ADXNativeAd *)nativeAd;

/**
 * NativeAd ad did close
 */
- (void)adxNativeAdDidClose:(ADXNativeAd *)nativeAd;

/**
 * NativeAd ad detail page did close
 */
- (void)adxNativeLandingPageDidClose:(ADXNativeAd *)nativeAd;

/**
 * NativeAd ad will enter background because open application
 */
- (void)adxNativeWillOpenOtherApp:(ADXNativeAd *)nativeAd;

/**
 * NativeAd ad will open landingpage 
 */
- (void)adxNativeWillOpenDetailPage:(ADXNativeAd *)nativeAd;


@end

@interface ADXNativeAd : NSObject

@property (nonatomic, weak) id<ADXNativeAdDelegate>delegate;
//广告是否已合法加载
@property (nonatomic, readonly) BOOL isValid;

@property(nonatomic,assign)NSUInteger ecpm;

@property(nonatomic, strong) YFMaterialMeta *materialModel;

- (instancetype)initWithPosId:(NSString *)posId eventModel:(YFAdEventModel *)eventModel;


@property (nonatomic, assign) BOOL autoClick;

@property (nonatomic, weak) UIView *containerView;

- (void)showFromViewController:(UIViewController *)viewController;


/**
 Register clickable views in native ads view.
 Interaction types can be configured on TikTok Audience Network.
 Interaction types include view video ad details page, make a call, send email, download the app, open the webpage using a browser,open the webpage within the app, etc.
 @param containerView : required.
                        container view of the native ad.
 @param clickableViews : optional.
                        Array of views that are clickable.
 */
- (void)registerContainer:(__kindof UIView *)containerView
       withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews;
@end

NS_ASSUME_NONNULL_END

