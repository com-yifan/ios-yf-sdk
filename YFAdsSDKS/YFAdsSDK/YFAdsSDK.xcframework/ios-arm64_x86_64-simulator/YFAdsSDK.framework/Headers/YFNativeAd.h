//
//  YFNativeAd.h
//  YFAdsSDK
//
//  Created by aiken on 2023/10/20.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAd.h>
#import <YFAdsSDK/YFMaterialMeta.h>
#import <YFAdsSDK/YFAdInteractionType.h>

NS_ASSUME_NONNULL_BEGIN


@class YFNativeAd;

@protocol YFNativeAdDelegate <NSObject>

@optional

/**
 This method is called when native ad material loaded successfully.
 当成功加载本地广告材料时，会调用此方法。
 */
- (void)nativeAdDidLoad:(YFNativeAd *)nativeAd;

/**
 This method is called when native ad materia failed to load.
 当加载本地广告材料失败时，会调用此方法。
 @param error : the reason of error
 */
- (void)nativeAd:(YFNativeAd *)nativeAd didFailWithError:(NSError *_Nullable)error;

/**
 This method is called when native ad show everytime. Please don‘t use for exposure count. Please use 'nativeAdDidShow' for exposure count.
 每次显示本地广告时都会调用此方法。请不要用于曝光计数。请使用“nativeAdDidShow”进行曝光计数。
 */
- (void)nativeAdDidBecomeVisible:(YFNativeAd *)nativeAd;

/**
 This method is called when native ad is clicked.
 单击本机广告时会调用此方法。
 */
- (void)nativeAdDidClick:(YFNativeAd *)nativeAd withView:(UIView *_Nullable)view;

/**
This method is called when another controller has been showed.
@param interactionType : open appstore in app or open the webpage or view video ad details page.
*/
- (void)nativeAdDidShowOtherController:(YFNativeAd *)nativeAd interactionType:(YFAdInteractionType)interactionType;

/**
 This method is called when another controller has been closed.
 @param interactionType : open appstore in app or open the webpage or view video ad details page.
 */
- (void)nativeAdDidCloseOtherController:(YFNativeAd *)nativeAd interactionType:(YFAdInteractionType)interactionType;

/**
 This method is called when native ad show. Each ad is called back only once
 */
- (void)nativeAdDidShow:(YFNativeAd *)nativeAd;

/**
 This method is called when native ad ready to play.
 */
- (void)nativeAdVideoReadyToPlay:(YFNativeAd *)nativeAd;

/**
 This method is called when native ad start play finished.
 */
- (void)nativeAdVideoStartPlay:(YFNativeAd *)nativeAd;

/**
 This method is called when native ad play finished.
 */
- (void)nativeAdVideoPlayFinished:(YFNativeAd *)nativeAd;

/**
 This method is called when native ad play error.
 */
- (void)nativeAdVideoPlayError:(YFNativeAd *)nativeAd;

/**
 This method is called when native ad play pause,including system-induced and user-induced pauses
 */
- (void)nativeAdVideoPause:(YFNativeAd *)nativeAd;

/**
 This method is called when native ad play resume,including system resume and user resume.This method is not called when the video starts playing for the first time.
 */
- (void)nativeAdVideoResume:(YFNativeAd *)nativeAd;

@end

@interface YFNativeAd : YFAd

/**
 Ad material.
 */
@property(nonatomic, strong, readonly, nullable) YFMaterialMeta *data;

/**
 The delegate for receiving state change messages.
 The delegate is not limited to viewcontroller.
 The delegate can be set to any object which conforming to <YFNativeAdDelegate>.
 */
@property(nonatomic, weak, readwrite, nullable) id <YFNativeAdDelegate> delegate;

/**
 required.
 Root view controller for handling ad actions.
 Action method includes 'pushViewController' and 'presentViewController'.
 */
@property(nonatomic, weak, readwrite) UIViewController *rootViewController;

/**
 Register clickable views in native ads view.
 Interaction types can be configured on TikTok Audience Network.
 Interaction types include view video ad details page, make a call, send email, download the app, open the webpage using a browser,open the webpage within the app, etc.
 @param containerView : required.
 container view of the native ad.
 @param clickableViews : optional.
 Array of views that are clickable.
 */
- (void)registerContainer:(__kindof UIView *)containerView withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews;

/*
 Similar to the registerContainer:withClickableViews:, the only difference is that the containerView can choose whether it is clickable or not
 */
- (void)registerContainer:(__kindof UIView *)containerView withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews containerClickable:(BOOL)isClickable;

/**
 Unregister ad view from the native ad.
 */
- (void)unregisterView;


- (id)initWithPosId:(NSString *)posId;

/**
 Actively request nativeAd datas.
 */
- (void)loadAdData;

- (void)reportVideoStartPlay;

- (void)reportVideoEndPlay;

@end

NS_ASSUME_NONNULL_END
