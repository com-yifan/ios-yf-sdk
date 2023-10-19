//
//  YFShapeTrimPath.h
//  LottieAnimator
//
//  Created by brandon_withrow on 7/26/16.
//  Copyright © 2016 Brandon Withrow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YFKeyframe.h"

@interface YFShapeTrimPath : NSObject

- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary;

@property (nonatomic, readonly) NSString *keyname;
@property (nonatomic, readonly) LOTKeyframeGroup *start;
@property (nonatomic, readonly) LOTKeyframeGroup *end;
@property (nonatomic, readonly) LOTKeyframeGroup *offset;

@end
