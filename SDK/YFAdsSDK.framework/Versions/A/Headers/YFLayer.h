//
//  YFLayer.h
//  LottieAnimator
//
//  Created by Brandon Withrow on 12/14/15.
//  Copyright © 2015 Brandon Withrow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YFPlatformCompat.h"
#import "YFKeyframe.h"

@class YFShapeGroup;
@class YFMask;
@class YFAsset;
@class YFAssetGroup;

typedef enum : NSInteger {
  LOTLayerTypePrecomp,
  LOTLayerTypeSolid,
  LOTLayerTypeImage,
  LOTLayerTypeNull,
  LOTLayerTypeShape,
  LOTLayerTypeUnknown
} LOTLayerType;

typedef enum : NSInteger {
  LOTMatteTypeNone,
  LOTMatteTypeAdd,
  LOTMatteTypeInvert,
  LOTMatteTypeUnknown
} LOTMatteType;

NS_ASSUME_NONNULL_BEGIN

@interface YFLayer : NSObject

- (instancetype)initWithJSON:(NSDictionary *)jsonDictionary
              withAssetGroup:(YFAssetGroup * _Nullable)assetGroup
               withFramerate:(NSNumber *)framerate;

@property (nonatomic, readonly) NSString *layerName;
@property (nonatomic, readonly, nullable) NSString *referenceID;
@property (nonatomic, readonly) NSNumber *layerID;
@property (nonatomic, readonly) LOTLayerType layerType;
@property (nonatomic, readonly, nullable) NSNumber *parentID;
@property (nonatomic, readonly) NSNumber *startFrame;
@property (nonatomic, readonly) NSNumber *inFrame;
@property (nonatomic, readonly) NSNumber *outFrame;
@property (nonatomic, readonly) NSNumber *timeStretch;
@property (nonatomic, readonly) CGRect layerBounds;

@property (nonatomic, readonly, nullable) NSArray<YFShapeGroup *> *shapes;
@property (nonatomic, readonly, nullable) NSArray<YFMask *> *masks;

@property (nonatomic, readonly, nullable) NSNumber *layerWidth;
@property (nonatomic, readonly, nullable) NSNumber *layerHeight;
@property (nonatomic, readonly, nullable) UIColor *solidColor;
@property (nonatomic, readonly, nullable) YFAsset *imageAsset;

@property (nonatomic, readonly) YFKeyframeGroup *opacity;
@property (nonatomic, readonly, nullable) YFKeyframeGroup *timeRemapping;
@property (nonatomic, readonly) YFKeyframeGroup *rotation;
@property (nonatomic, readonly, nullable) YFKeyframeGroup *position;

@property (nonatomic, readonly, nullable) YFKeyframeGroup *positionX;
@property (nonatomic, readonly, nullable) YFKeyframeGroup *positionY;

@property (nonatomic, readonly) YFKeyframeGroup *anchor;
@property (nonatomic, readonly) YFKeyframeGroup *scale;

@property (nonatomic, readonly) LOTMatteType matteType;

@end

NS_ASSUME_NONNULL_END
