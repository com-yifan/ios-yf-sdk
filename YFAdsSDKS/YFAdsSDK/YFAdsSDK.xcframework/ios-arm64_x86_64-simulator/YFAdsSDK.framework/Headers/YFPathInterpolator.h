//
//  YFPathInterpolator.h
//  Lottie
//
//  Created by brandon_withrow on 7/13/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <YFAdsSDK/YFValueInterpolator.h>
#import <YFAdsSDK/YFPlatformCompat.h>
#import <YFAdsSDK/YFBezierPath.h>
#import <YFAdsSDK/YFValueDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFPathInterpolator : YFValueInterpolator

- (YFBezierPath *)pathForFrame:(NSNumber *)frame cacheLengths:(BOOL)cacheLengths;

@property (nonatomic, weak, nullable) id<YFPathValueDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
