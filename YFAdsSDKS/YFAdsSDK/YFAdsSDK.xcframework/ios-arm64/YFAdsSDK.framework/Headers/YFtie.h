//
//  Lottie.h
//  Pods
//
//  Created by brandon_withrow on 1/27/17.
//
//  Dream Big.


#import <Foundation/Foundation.h>

//! Project version number for Lottie.
FOUNDATION_EXPORT double LottieVersionNumber;

//! Project version string for Lottie.
FOUNDATION_EXPORT const unsigned char LottieVersionString[];

#include <TargetConditionals.h>

#if TARGET_OS_IPHONE || TARGET_OS_SIMULATOR
#import <YFAdsSDK/YFAnimationTransitionController.h>
#import <YFAdsSDK/YFAnimatedSwitch.h>
#import <YFAdsSDK/YFAnimatedControl.h>
#endif

#if TARGET_OS_IPHONE || TARGET_OS_SIMULATOR
#import <YFAdsSDK/YFCacheProvider.h>
#endif

#import <YFAdsSDK/YFAnimationView.h>
#import <YFAdsSDK/YFAnimationCache.h>
#import <YFAdsSDK/YFComposition.h>
#import <YFAdsSDK/YFBlockCallback.h>
#import <YFAdsSDK/YFInterpolatorCallback.h>
#import <YFAdsSDK/YFValueCallback.h>
#import <YFAdsSDK/YFValueDelegate.h>

