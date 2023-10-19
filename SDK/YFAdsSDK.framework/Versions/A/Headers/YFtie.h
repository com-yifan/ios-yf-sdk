//
//  Lottie.h
//  Pods
//
//  Created by brandon_withrow on 1/27/17.
//
//  Dream Big.

#if __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif


//! Project version number for Lottie.
FOUNDATION_EXPORT double LottieVersionNumber;

//! Project version string for Lottie.
FOUNDATION_EXPORT const unsigned char LottieVersionString[];

#include <TargetConditionals.h>

#if TARGET_OS_IPHONE || TARGET_OS_SIMULATOR
#import "YFAnimationTransitionController.h"
#import "YFAnimatedSwitch.h"
#import "YFAnimatedControl.h"
#endif

#if TARGET_OS_IPHONE || TARGET_OS_SIMULATOR
#import "YFCacheProvider.h"
#endif

#import "YFAnimationView.h"
#import "YFAnimationCache.h"
#import "YFComposition.h"
#import "YFBlockCallback.h"
#import "YFInterpolatorCallback.h"
#import "YFValueCallback.h"
#import "YFValueDelegate.h"

