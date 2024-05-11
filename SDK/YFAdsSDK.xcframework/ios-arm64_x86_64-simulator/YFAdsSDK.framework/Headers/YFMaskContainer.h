//
//  YFMaskContainer.h
//  Lottie
//
//  Created by brandon_withrow on 7/19/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import "YFMask.h"

@interface YFMaskContainer : CALayer

- (instancetype _Nonnull)initWithMasks:(NSArray<YFMask *> * _Nonnull)masks;

@property (nonatomic, strong, nullable) NSNumber *currentFrame;

@end
