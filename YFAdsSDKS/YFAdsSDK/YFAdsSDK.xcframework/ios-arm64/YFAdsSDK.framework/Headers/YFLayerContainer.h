//
//  YFLayerContainer.h
//  Lottie
//
//  Created by brandon_withrow on 7/18/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <YFAdsSDK/YFPlatformCompat.h>
#import <YFAdsSDK/YFLayer.h>
#import <YFAdsSDK/YFLayerGroup.h>
#import <YFAdsSDK/YFKeypath.h>
#import <YFAdsSDK/YFValueDelegate.h>

@class LOTValueCallback;

@interface YFLayerContainer : CALayer

- (instancetype _Nonnull)initWithModel:(YFLayer * _Nullable)layer
                 inLayerGroup:(YFLayerGroup * _Nullable)layerGroup;

@property (nonatomic,  readonly, strong, nullable) NSString *layerName;
@property (nonatomic, nullable) NSNumber *currentFrame;
@property (nonatomic, readonly, nonnull) NSNumber *timeStretchFactor;
@property (nonatomic, assign) CGRect viewportBounds;
@property (nonatomic, readonly, nonnull) CALayer *wrapperLayer;
@property (nonatomic, readonly, nonnull) NSDictionary *valueInterpolators;

- (void)displayWithFrame:(NSNumber * _Nonnull)frame;
- (void)displayWithFrame:(NSNumber * _Nonnull)frame forceUpdate:(BOOL)forceUpdate;

- (void)searchNodesForKeypath:(YFKeypath * _Nonnull)keypath;

- (void)setValueDelegate:(id<YFValueDelegate> _Nonnull)delegate
              forKeypath:(YFKeypath * _Nonnull)keypath;

@end
