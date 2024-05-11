//
//  YFShapeStar.h
//  Lottie
//
//  Created by brandon_withrow on 7/27/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YFKeyframe.h"

typedef enum : NSUInteger {
  LOTPolystarShapeNone,
  LOTPolystarShapeStar,
  LOTPolystarShapePolygon
} LOTPolystarShape;

@interface YFShapeStar : NSObject

- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary;

@property (nonatomic, readonly) NSString *keyname;
@property (nonatomic, readonly) YFKeyframeGroup *outerRadius;
@property (nonatomic, readonly) YFKeyframeGroup *outerRoundness;

@property (nonatomic, readonly) YFKeyframeGroup *innerRadius;
@property (nonatomic, readonly) YFKeyframeGroup *innerRoundness;

@property (nonatomic, readonly) YFKeyframeGroup *position;
@property (nonatomic, readonly) YFKeyframeGroup *numberOfPoints;
@property (nonatomic, readonly) YFKeyframeGroup *rotation;

@property (nonatomic, readonly) LOTPolystarShape type;

@end
