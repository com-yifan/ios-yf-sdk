//
//  YFAdsSDK.h>
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/11/26.
//

#import <Foundation/Foundation.h>

//! Project version number for YFAdsSDK.
FOUNDATION_EXPORT double YFAdsSDKVersionNumber;

//! Project version string for YFAdsSDK.
FOUNDATION_EXPORT const unsigned char YFAdsSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <YFAdsSDK/PublicHeader.h>
#import <YFAdsSDK/ADXNativeAd.h>
#import <YFAdsSDK/ADXNativeAdsManager.h>
#import <YFAdsSDK/ADXNativeMediaView.h>
#import <YFAdsSDK/NSArray+Addition.h>
#import <YFAdsSDK/NSData+YFAdd.h>
#import <YFAdsSDK/NSNumber+YFAdd.h>
#import <YFAdsSDK/NSString+YFAdd.h>
#import <YFAdsSDK/NSString+YFUrlEncode.h>
#import <YFAdsSDK/UIButton+YFEdge.h>
#import <YFAdsSDK/UIImage+YFImageEffects.h>
#import <YFAdsSDK/UILabel+YFEdge.h>
#import <YFAdsSDK/UITapGestureRecognizer+YFBlock.h>
#import <YFAdsSDK/UIView+ViewVisiable.h>
#import <YFAdsSDK/UIView+YFAutoLayout.h>
#import <YFAdsSDK/YFAd.h>
#import <YFAdsSDK/YFAdAESEncrypt.h>
#import <YFAdsSDK/YFAdBanner.h>
#import <YFAdsSDK/YFAdBannerDelegate.h>
#import <YFAdsSDK/YFAdBannerView600x100.h>
#import <YFAdsSDK/YFAdBannerView600x150.h>
#import <YFAdsSDK/YFAdBannerView600x260.h>
#import <YFAdsSDK/YFAdBannerViewN600x260.h>
#import <YFAdsSDK/YFAdBannerViewN600x260R.h>
#import <YFAdsSDK/YFAdBannerViewR600x150.h>
#import <YFAdsSDK/YFAdBannerViewR640x100.h>
#import <YFAdsSDK/YFAdBannerViewTDBP.h>
#import <YFAdsSDK/YFAdBaseAdPosition.h>
#import <YFAdsSDK/YFAdBaseAdapter.h>
#import <YFAdsSDK/YFAdBaseCustomView.h>
#import <YFAdsSDK/YFAdBaseDelegate.h>
#import <YFAdsSDK/YFAdBaseView.h>
#import <YFAdsSDK/YFAdCommonDelegate.h>
#import <YFAdsSDK/YFAdCustomModel.h>
#import <YFAdsSDK/YFAdDetailViewController.h>
#import <YFAdsSDK/YFAdDraw.h>
#import <YFAdsSDK/YFAdDrawDelegate.h>
#import <YFAdsSDK/YFAdDrawView.h>
#import <YFAdsSDK/YFAdEmptyAdapter.h>
#import <YFAdsSDK/YFAdEnvelopeVideoView.h>
#import <YFAdsSDK/YFAdFeedbackView.h>
#import <YFAdsSDK/YFAdFullScreenVideo.h>
#import <YFAdsSDK/YFAdFullScreenVideoDelegate.h>
#import <YFAdsSDK/YFAdFusionBanner.h>
#import <YFAdsSDK/YFAdFusionBannerDelegate.h>
#import <YFAdsSDK/YFAdFusionBannerView.h>
#import <YFAdsSDK/YFAdImage.h>
#import <YFAdsSDK/YFAdInteractionType.h>
#import <YFAdsSDK/YFAdInterstitial.h>
#import <YFAdsSDK/YFAdInterstitialDelegate.h>
#import <YFAdsSDK/YFAdInterstitialVideoView.h>
#import <YFAdsSDK/YFAdInterstitialViewProtocol.h>
#import <YFAdsSDK/YFAdMarkImageView.h>
#import <YFAdsSDK/YFAdMarkView.h>
#import <YFAdsSDK/YFAdMedia.h>
#import <YFAdsSDK/YFAdMediaDelegate.h>
#import <YFAdsSDK/YFAdMediaMetal.h>
#import <YFAdsSDK/YFAdMediaRender.h>

#import <YFAdsSDK/YFAdModel.h>
//#import <YFAdsSDK/NSObject+YFAdModel.h>
//#import <YFAdsSDK/YFAdClassInfo.h>

#import <YFAdsSDK/YFAdNative.h>
#import <YFAdsSDK/YFAdNativeAdExtraDataModel.h>
#import <YFAdsSDK/YFAdNativeExpress.h>
#import <YFAdsSDK/YFAdNativeExpressDelegate.h>
#import <YFAdsSDK/YFAdNativeExpressView.h>
#import <YFAdsSDK/YFAdPatch.h>
#import <YFAdsSDK/YFAdPatchDelegate.h>
#import <YFAdsSDK/YFAdReportModel.h>
#import <YFAdsSDK/YFAdResponseModel.h>
#import <YFAdsSDK/YFAdRewardModel.h>
#import <YFAdsSDK/YFAdRewardVideo.h>
#import <YFAdsSDK/YFAdRewardVideoDelegate.h>
#import <YFAdsSDK/YFAdSDKManager.h>
#import <YFAdsSDK/YFAdSDKSetting.h>
#import <YFAdsSDK/YFAdSplash.h>
#import <YFAdsSDK/YFAdSplashAdExtraDataModel.h>
#import <YFAdsSDK/YFAdSplashDelegate.h>
#import <YFAdsSDK/YFAdSupplierDelegate.h>
#import <YFAdsSDK/YFAdSupplierManager.h>
#import <YFAdsSDK/YFAdUtils.h>
#import <YFAdsSDK/YFAdView.h>
#import <YFAdsSDK/YFAdXBannerView.h>
#import <YFAdsSDK/YFAdXBannerView600x410.h>
#import <YFAdsSDK/YFAdXBannerViewB600x400.h>
#import <YFAdsSDK/YFAdsAnimationView.h>
#import <YFAdsSDK/YFAdsButton.h>
#import <YFAdsSDK/YFAdsCloseButton.h>
#import <YFAdsSDK/YFAdsCountButton.h>
#import <YFAdsSDK/YFAdsDetailButton.h>
#import <YFAdsSDK/YFAdxCustomExpressAdapter.h>

#import <YFAdsSDK/YFAppENVInfo.h>
#import <YFAdsSDK/YFBannerAdapter.h>
#import <YFAdsSDK/YFBannerView.h>

#import <YFAdsSDK/YFBlurImageView.h>


#import <YFAdsSDK/YFDownloadNetworkTool.h>
#import <YFAdsSDK/YFFullScreenVideoAd.h>
#import <YFAdsSDK/YFFusionBannerAdapter.h>
#import <YFAdsSDK/YFFullScreenVideoAdapter.h>

#import <YFAdsSDK/YFGlobalMotionActionHandler.h>
#import <YFAdsSDK/YFGlobalMotionManager.h>
#import <YFAdsSDK/YFGlobalMotionModel.h>

#import <YFAdsSDK/YFInterstitialAd.h>
#import <YFAdsSDK/YFInterstitialAdapter.h>
#import <YFAdsSDK/YFInterstitialView.h>
#import <YFAdsSDK/YFInvoker.h>

#import <YFAdsSDK/YFKit.h>
#import <YFAdsSDK/YFKitImpressionTimer.h>

#import <YFAdsSDK/YFManager.h>
#import <YFAdsSDK/YFMaterialMeta.h>
#import <YFAdsSDK/YFMotionManager.h>
#import <YFAdsSDK/YFNativeAd.h>
#import <YFAdsSDK/YFNativeAdsManager.h>
#import <YFAdsSDK/YFNativeExpressAdapter.h>
#import <YFAdsSDK/YFRequestModel.h>
#import <YFAdsSDK/YFRewardVideoAdapter.h>
#import <YFAdsSDK/YFRewardedVideoAd.h>
#import <YFAdsSDK/YFRouter.h>
#import <YFAdsSDK/YFSerialQueue.h>
#import <YFAdsSDK/YFSplashAdapter.h>
#import <YFAdsSDK/YFSplashAnimationView2.h>
#import <YFAdsSDK/YFSplashButton.h>
#import <YFAdsSDK/YFSplashEnum.h>
#import <YFAdsSDK/YFSplashEnvelopeView.h>
#import <YFAdsSDK/YFSplashView.h>
#import <YFAdsSDK/YFSplashView2.h>
#import <YFAdsSDK/YFTapBarAnimationView.h>
#import <YFAdsSDK/YFTouchReportView.h>
#import <YFAdsSDK/YFVideoAd.h>
#import <YFAdsSDK/YFVideoAdViewController.h>
#import <YFAdsSDK/YFWeakProxy.h>
#import <YFAdsSDK/YFAdBaseViewController.h>
#import <YFAdsSDK/YFEnvelopeIntertitialAdViewController.h>
#import <YFAdsSDK/YFAdEnvelopeIntertitialAdViewController.h>
#import <YFAdsSDK/YFForgroundTimer.h>
#import <YFAdsSDK/YFAdsIntertitialAdDelayTimer.h>
#import <YFAdsSDK/YFAdMediaProtocol.h>
#import <YFAdsSDK/YFVideoView.h>

#import <YFAdsSDK/YFPrivateKit.h>

/// >= 6.0.4.1 +++
#import <YFAdsSDK/YFAdapterDataModel.h>
#import <YFAdsSDK/NSString+Size.h>


//#import <YFAdsSDK/YFGradientView.h>
//#import <YFAdsSDK/NSObject+YFAdModel.h>
//#import <YFAdsSDK/UIApplication+YFAds.h>
//#import <YFAdsSDK/YFAdConst.h>
//#import <YFAdsSDK/YFAdError.h>
//#import <YFAdsSDK/YFAdLogManager.h>
//#import <YFAdsSDK/YFAdxDataManager.h>


///// log
//#import <YFAdsSDK/YFLog.h>
//
//// Main macros
//#import <YFAdsSDK/YFLogMacros.h>
//#import <YFAdsSDK/YFAssertMacros.h>
//
//// Capture ASL
//#import <YFAdsSDK/YFASLLogCapture.h>
//
//// Loggers
//#import <YFAdsSDK/YFLoggerNames.h>
//
//#import <YFAdsSDK/YFASLLogger.h>
//#import <YFAdsSDK/YFFileLogger.h>
//#import <YFAdsSDK/YFOSLogger.h>
//
//// Extensions
//#import <YFAdsSDK/YFContextFilterLogFormatter.h>
//#import <YFAdsSDK/YFContextFilterLogFormatter+Deprecated.h>
//#import <YFAdsSDK/YFDispatchQueueLogFormatter.h>
//#import <YFAdsSDK/YFMultiFormatter.h>
//#import <YFAdsSDK/YFFileLogger+Buffering.h>
////#import <YFAdsSDK/YFFileLogger+Internal.h>
//// etc
//#import <YFAdsSDK/YFAbstractDatabaseLogger.h>
//#import <YFAdsSDK/YFLog+LOGV.h>
//#import <YFAdsSDK/YFLegacyMacros.h>
