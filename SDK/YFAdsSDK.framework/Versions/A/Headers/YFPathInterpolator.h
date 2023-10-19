//
//  YFPathInterpolator.h
//  Lottie
//
//  Created by brandon_withrow on 7/13/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import "YFValueInterpolator.h"
#import "YFPlatformCompat.h"
#import "YFBezierPath.h"
#import "YFValueDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFPathInterpolator : YFValueInterpolator

- (YFBezierPath *)pathForFrame:(NSNumber *)frame cacheLengths:(BOOL)cacheLengths;

@property (nonatomic, weak, nullable) id<LOTPathValueDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
