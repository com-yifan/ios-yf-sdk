//
//  YFShapePath.h
//  LottieAnimator
//
//  Created by Brandon Withrow on 12/15/15.
//  Copyright © 2015 Brandon Withrow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFKeyframe.h>

@interface YFShapePath : NSObject

- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary;

@property (nonatomic, readonly) NSString *keyname;
@property (nonatomic, readonly) BOOL closed;
@property (nonatomic, readonly) NSNumber *index;
@property (nonatomic, readonly) YFKeyframeGroup *shapePath;

@end
