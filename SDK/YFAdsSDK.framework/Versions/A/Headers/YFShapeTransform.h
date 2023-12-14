//
//  YFShapeTransform.h
//  LottieAnimator
//
//  Created by Brandon Withrow on 12/15/15.
//  Copyright © 2015 Brandon Withrow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
#import "YFKeyframe.h"

@interface YFShapeTransform : NSObject

- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary;

@property (nonatomic, readonly) NSString *keyname;
@property (nonatomic, readonly) YFKeyframeGroup *position;
@property (nonatomic, readonly) YFKeyframeGroup *anchor;
@property (nonatomic, readonly) YFKeyframeGroup *scale;
@property (nonatomic, readonly) YFKeyframeGroup *rotation;
@property (nonatomic, readonly) YFKeyframeGroup *opacity;

@end
