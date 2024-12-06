//
//  YFTransformInterpolator.h
//  Lottie
//
//  Created by brandon_withrow on 7/18/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFNumberInterpolator.h>
#import <YFAdsSDK/YFPointInterpolator.h>
#import <YFAdsSDK/YFSizeInterpolator.h>
#import <YFAdsSDK/YFKeyframe.h>
#import <YFAdsSDK/YFLayer.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFTransformInterpolator : NSObject

+ (instancetype)transformForLayer:(YFLayer *)layer;

- (instancetype)initWithPosition:(NSArray <YFKeyframe *> *)position
                        rotation:(NSArray <YFKeyframe *> *)rotation
                          anchor:(NSArray <YFKeyframe *> *)anchor
                           scale:(NSArray <YFKeyframe *> *)scale;

- (instancetype)initWithPositionX:(NSArray <YFKeyframe *> *)positionX
                        positionY:(NSArray <YFKeyframe *> *)positionY
                         rotation:(NSArray <YFKeyframe *> *)rotation
                           anchor:(NSArray <YFKeyframe *> *)anchor
                            scale:(NSArray <YFKeyframe *> *)scale;

@property (nonatomic, strong) YFTransformInterpolator * inputNode;

@property (nonatomic, readonly) YFPointInterpolator *positionInterpolator;
@property (nonatomic, readonly) YFPointInterpolator *anchorInterpolator;
@property (nonatomic, readonly) YFSizeInterpolator *scaleInterpolator;
@property (nonatomic, readonly) YFNumberInterpolator *rotationInterpolator;
@property (nonatomic, readonly) YFNumberInterpolator *positionXInterpolator;
@property (nonatomic, readonly) YFNumberInterpolator *positionYInterpolator;
@property (nonatomic, strong, nullable) NSString *parentKeyName;

- (CATransform3D)transformForFrame:(NSNumber *)frame;
- (BOOL)hasUpdateForFrame:(NSNumber *)frame;

@end

NS_ASSUME_NONNULL_END
