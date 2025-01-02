//
//  YFKeyframe.h
//  Pods
//
//  Created by brandon_withrow on 7/10/17.
//
//

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import <YFAdsSDK/YFPlatformCompat.h>
#import <YFAdsSDK/YFBezierData.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFKeyframe : NSObject

- (instancetype)initWithKeyframe:(NSDictionary *)keyframe;
- (instancetype)initWithValue:(id)value;
- (void)remapValueWithBlock:(CGFloat (^)(CGFloat inValue))remapBlock;
- (YFKeyframe *)copyWithData:(id)data;

@property (nonatomic, readonly) NSNumber *keyframeTime;
@property (nonatomic, readonly) BOOL isHold;
@property (nonatomic, readonly) CGPoint yf_inTangent;
@property (nonatomic, readonly) CGPoint yf_outTangent;
@property (nonatomic, readonly) CGPoint yf_spatialInTangent;
@property (nonatomic, readonly) CGPoint yf_spatialOutTangent;

@property (nonatomic, readonly) CGFloat yf_floatValue;
@property (nonatomic, readonly) CGPoint yf_pointValue;
@property (nonatomic, readonly) CGSize yf_sizeValue;
@property (nonatomic, readonly) UIColor *yf_colorValue;
@property (nonatomic, readonly, nullable) YFBezierData *pathData;
@property (nonatomic, readonly) NSArray *yf_arrayValue;

@end

@interface YFKeyframeGroup : NSObject

- (instancetype)initWithData:(id)data;

- (void)remapKeyframesWithBlock:(CGFloat (^)(CGFloat inValue))remapBlock;

@property (nonatomic, readonly) NSArray<YFKeyframe *> *keyframes;

@end

NS_ASSUME_NONNULL_END
