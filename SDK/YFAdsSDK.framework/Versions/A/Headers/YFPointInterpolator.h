//
//  YFPointInterpolator.h
//  Lottie
//
//  Created by brandon_withrow on 7/12/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import "YFValueInterpolator.h"
#import "YFValueDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFPointInterpolator : YFValueInterpolator

- (CGPoint)pointValueForFrame:(NSNumber *)frame;

@property (nonatomic, weak, nullable) id<LOTPointValueDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
