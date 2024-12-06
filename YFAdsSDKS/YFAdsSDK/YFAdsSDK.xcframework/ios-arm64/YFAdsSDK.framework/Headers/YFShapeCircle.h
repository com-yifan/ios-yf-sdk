//
//  YFShapeCircle.h
//  LottieAnimator
//
//  Created by Brandon Withrow on 12/15/15.
//  Copyright © 2015 Brandon Withrow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFKeyframe.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFShapeCircle : NSObject

- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary;

@property (nonatomic, readonly) NSString *keyname;
@property (nonatomic, readonly) YFKeyframeGroup *position;
@property (nonatomic, readonly) YFKeyframeGroup *size;
@property (nonatomic, readonly) BOOL reversed;

@end

NS_ASSUME_NONNULL_END
