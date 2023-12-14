//
//  YFShapeRepeater.h
//  Lottie
//
//  Created by brandon_withrow on 7/28/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YFKeyframe.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFShapeRepeater : NSObject

- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary;

@property (nonatomic, readonly) NSString *keyname;
@property (nonatomic, readonly, nullable) YFKeyframeGroup *copies;
@property (nonatomic, readonly, nullable) YFKeyframeGroup *offset;
@property (nonatomic, readonly, nullable) YFKeyframeGroup *anchorPoint;
@property (nonatomic, readonly, nullable) YFKeyframeGroup *scale;
@property (nonatomic, readonly, nullable) YFKeyframeGroup *position;
@property (nonatomic, readonly, nullable) YFKeyframeGroup *rotation;
@property (nonatomic, readonly, nullable) YFKeyframeGroup *startOpacity;
@property (nonatomic, readonly, nullable) YFKeyframeGroup *endOpacity;

@end

NS_ASSUME_NONNULL_END
