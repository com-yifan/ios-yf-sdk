//
//  YFKeyframe.h
//  Pods
//
//  Created by brandon_withrow on 7/10/17.
//
//

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import "YFPlatformCompat.h"
#import "YFBezierData.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFKeyframe : NSObject

- (instancetype)initWithKeyframe:(NSDictionary *)keyframe;
- (instancetype)initWithValue:(id)value;
- (void)remapValueWithBlock:(CGFloat (^)(CGFloat inValue))remapBlock;
- (YFKeyframe *)copyWithData:(id)data;

@property (nonatomic, readonly) NSNumber *keyframeTime;
@property (nonatomic, readonly) BOOL isHold;
@property (nonatomic, readonly) CGPoint inTangent;
@property (nonatomic, readonly) CGPoint outTangent;
@property (nonatomic, readonly) CGPoint spatialInTangent;
@property (nonatomic, readonly) CGPoint spatialOutTangent;

@property (nonatomic, readonly) CGFloat floatValue;
@property (nonatomic, readonly) CGPoint pointValue;
@property (nonatomic, readonly) CGSize sizeValue;
@property (nonatomic, readonly) UIColor *colorValue;
@property (nonatomic, readonly, nullable) YFBezierData *pathData;
@property (nonatomic, readonly) NSArray *arrayValue;

@end

@interface YFKeyframeGroup : NSObject

- (instancetype)initWithData:(id)data;

- (void)remapKeyframesWithBlock:(CGFloat (^)(CGFloat inValue))remapBlock;

@property (nonatomic, readonly) NSArray<YFKeyframe *> *keyframes;

@end

NS_ASSUME_NONNULL_END
