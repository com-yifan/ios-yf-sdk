//
//  YFArrayInterpolator.h
//  Lottie
//
//  Created by brandon_withrow on 7/27/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <YFAdsSDK/YFValueInterpolator.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFArrayInterpolator : YFValueInterpolator

- (NSArray *)numberArrayForFrame:(NSNumber *)frame;

@end

NS_ASSUME_NONNULL_END
