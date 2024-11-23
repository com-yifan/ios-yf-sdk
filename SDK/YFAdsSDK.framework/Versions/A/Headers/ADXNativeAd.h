//
//  ADXNativeAd.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/9/5.
//  2024.11.23

#import <UIKit/UIKit.h>

#import "YFAd.h"
#import "YFAdInteractionType.h"
#import "YFMaterialMeta.h"

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
- (void)adxNativeAdDidVisible:(ADXNativeAd *)nativeAd;
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


@end

@interface ADXNativeAd : NSObject

@property (nonatomic, weak) id<ADXNativeAdDelegate>delegate;
//广告是否已合法加载
@property (nonatomic, readonly) BOOL isValid;
////是否开启声音
//@property (nonatomic, assign) BOOL videoMute;

@property(nonatomic,assign)NSUInteger ecpm;

@property(nonatomic, strong) YFMaterialMeta *materialModel;

//@property(nonatomic, strong) YFInterstitialView *adView;

- (instancetype)initWithPosId:(NSString *)posId eventModel:(YFAdEventModel *)eventModel;


@property (nonatomic, assign) BOOL autoClick;

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

