//
//  YFAdsSubstrate.h
//  YFAdsSubstrate
//
//  Created by 麻明康 on 2025/1/3.
//

#import <Foundation/Foundation.h>

//! Project version number for YFAdsSubstrate.
FOUNDATION_EXPORT double YFAdsSubstrateVersionNumber;

//! Project version string for YFAdsSubstrate.
FOUNDATION_EXPORT const unsigned char YFAdsSubstrateVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <YFAdsSubstrate/PublicHeader.h>

//实际应该只有这几个需要开放
#import <YFAdsSubstrate/UIColor+YFExpanded.h>

#import <YFAdsSubstrate/NSData+YF_ImageContentType.h>
#import <YFAdsSubstrate/YF_SDImageCache.h>
#import <YFAdsSubstrate/YF_SDWebImageCompat.h>
#import <YFAdsSubstrate/YF_SDWebImageDownloaderOperation.h>
#import <YFAdsSubstrate/YF_SDWebImageManager.h>
#import <YFAdsSubstrate/YF_SDWebImageDownloader.h>
#import <YFAdsSubstrate/YF_SDWebImageOperation.h>
#import <YFAdsSubstrate/YF_SDWebImageDecoder.h>
#import <YFAdsSubstrate/YF_SDWebImagePrefetcher.h>
#import <YFAdsSubstrate/UIButton+YF_WebCache.h>
#import <YFAdsSubstrate/UIImage+YF_GIF.h>
#import <YFAdsSubstrate/UIImage+YF_MultiFormat.h>
#import <YFAdsSubstrate/UIImage+YF_WebP.h>
#import <YFAdsSubstrate/UIImageView+YF_HighlightedWebCache.h>
#import <YFAdsSubstrate/UIImageView+YF_WebCache.h>
#import <YFAdsSubstrate/UIView+YF_WebCacheOperation.h>
//#import <YFAdsSubstrate/YFAdAPConst.h>


#import <YFAdsSubstrate/YFAnimationTransitionController.h>
#import <YFAdsSubstrate/YFAnimatedSwitch.h>
#import <YFAdsSubstrate/YFAnimatedControl.h>

#import <YFAdsSubstrate/YFCacheProvider.h>

#import <YFAdsSubstrate/YFAnimationView.h>
#import <YFAdsSubstrate/YFAnimationCache.h>
#import <YFAdsSubstrate/YFComposition.h>
#import <YFAdsSubstrate/YFBlockCallback.h>
#import <YFAdsSubstrate/YFInterpolatorCallback.h>
#import <YFAdsSubstrate/YFValueCallback.h>
#import <YFAdsSubstrate/YFValueDelegate.h>

#import <YFAdsSubstrate/YFAnimationView_Compat.h>
#import <YFAdsSubstrate/YFKeypath.h>

#import <YFAdsSubstrate/YFCocoaLumberjack.h>

////下面这些实际不需要放在头文件
//#import <YFAdsSubstrate/YFMaskContainer.h>
//#import <YFAdsSubstrate/YFShapeGradientFill.h>
//#import <YFAdsSubstrate/YFTrimPathNode.h>
//#import <YFAdsSubstrate/YFMask.h>
//#import <YFAdsSubstrate/YFKeyframe.h>
//#import <YFAdsSubstrate/YFTransformInterpolator.h>
//#import <YFAdsSubstrate/YFLayerContainer.h>
//#import <YFAdsSubstrate/YFAnimatorNode.h>
//#import <YFAdsSubstrate/YFPlatformCompat.h>
//#import <YFAdsSubstrate/YFPathInterpolator.h>
//#import <YFAdsSubstrate/YFShapeStroke.h>
//#import <YFAdsSubstrate/YFGradientFillRender.h>
//#import <YFAdsSubstrate/YFFillRenderer.h>
//#import <YFAdsSubstrate/YFAnimationView_Internal.h>
//#import <YFAdsSubstrate/YFPolystarAnimator.h>
//#import <YFAdsSubstrate/YFShapeFill.h>
//#import <YFAdsSubstrate/YFtie.h>
//#import <YFAdsSubstrate/YFShapeGroup.h>
//#import <YFAdsSubstrate/YFLayer.h>
//#import <YFAdsSubstrate/YFShapeRepeater.h>
//#import <YFAdsSubstrate/YFCircleAnimator.h>
//#import <YFAdsSubstrate/YFModels.h>
//#import <YFAdsSubstrate/YFShapeCircle.h>
//#import <YFAdsSubstrate/YFShapePath.h>
//#import <YFAdsSubstrate/YFColorInterpolator.h>
//#import <YFAdsSubstrate/YFArrayInterpolator.h>
//#import <YFAdsSubstrate/YFShapeStar.h>
//#import <YFAdsSubstrate/YFAssetGroup.h>
//#import <YFAdsSubstrate/YFShapeRectangle.h>
//#import <YFAdsSubstrate/YFRenderNode.h>
//#import <YFAdsSubstrate/CGGeometry+YFAdditions.h>
//#import <YFAdsSubstrate/YFCompositionContainer.h>
//#import <YFAdsSubstrate/YFPointInterpolator.h>
//#import <YFAdsSubstrate/YFPathAnimator.h>
//#import <YFAdsSubstrate/YFValueInterpolator.h>
//#import <YFAdsSubstrate/YFSizeInterpolator.h>
//#import <YFAdsSubstrate/YFRoundedRectAnimator.h>
//#import <YFAdsSubstrate/YFShapeTrimPath.h>
//#import <YFAdsSubstrate/YFBezierData.h>
//#import <YFAdsSubstrate/YFLayerGroup.h>
//#import <YFAdsSubstrate/YFStrokeRenderer.h>
//#import <YFAdsSubstrate/YFBezierPath.h>
//#import <YFAdsSubstrate/YFRadialGradientLayer.h>
//#import <YFAdsSubstrate/YFRenderGroup.h>
//#import <YFAdsSubstrate/YFRepeaterRenderer.h>
//#import <YFAdsSubstrate/YFNumberInterpolator.h>
//#import <YFAdsSubstrate/YFHelpers.h>
//#import <YFAdsSubstrate/YFAsset.h>
//#import <YFAdsSubstrate/YFShapeTransform.h>
//#import <YFAdsSubstrate/YFPolygonAnimator.h>
