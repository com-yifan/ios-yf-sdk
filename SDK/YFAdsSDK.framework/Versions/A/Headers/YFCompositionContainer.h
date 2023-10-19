//
//  YFCompositionContainer.h
//  Lottie
//
//  Created by brandon_withrow on 7/18/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import "YFLayerContainer.h"
#import "YFAssetGroup.h"

@interface YFCompositionContainer : YFLayerContainer

- (instancetype _Nonnull)initWithModel:(YFLayer * _Nullable)layer
                          inLayerGroup:(YFLayerGroup * _Nullable)layerGroup
                        withLayerGroup:(YFLayerGroup * _Nullable)childLayerGroup
                       withAssestGroup:(YFAssetGroup * _Nullable)assetGroup;

- (nullable NSArray *)keysForKeyPath:(nonnull YFKeypath *)keypath;

- (CGPoint)convertPoint:(CGPoint)point
         toKeypathLayer:(nonnull YFKeypath *)keypath
        withParentLayer:(CALayer *_Nonnull)parent;

- (CGRect)convertRect:(CGRect)rect
       toKeypathLayer:(nonnull YFKeypath *)keypath
      withParentLayer:(CALayer *_Nonnull)parent;

- (CGPoint)convertPoint:(CGPoint)point
       fromKeypathLayer:(nonnull YFKeypath *)keypath
        withParentLayer:(CALayer *_Nonnull)parent;

- (CGRect)convertRect:(CGRect)rect
     fromKeypathLayer:(nonnull YFKeypath *)keypath
      withParentLayer:(CALayer *_Nonnull)parent;

- (void)addSublayer:(nonnull CALayer *)subLayer
    toKeypathLayer:(nonnull YFKeypath *)keypath;

- (void)maskSublayer:(nonnull CALayer *)subLayer
     toKeypathLayer:(nonnull YFKeypath *)keypath;

@property (nonatomic, readonly, nonnull) NSArray<YFLayerContainer *> *childLayers;
@property (nonatomic, readonly, nonnull)  NSDictionary *childMap;

@end
