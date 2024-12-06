//
//  YFLayerGroup.h
//  Pods
//
//  Created by Brandon Withrow on 2/16/17.
//
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@class YFLayer;
@class YFAssetGroup;

@interface YFLayerGroup : NSObject

- (instancetype)initWithLayerJSON:(NSArray *)layersJSON
                   withAssetGroup:(YFAssetGroup * _Nullable)assetGroup
                    withFramerate:(NSNumber *)framerate;

@property (nonatomic, readonly) NSArray <YFLayer *> *layers;

- (YFLayer *)layerModelForID:(NSNumber *)layerID;
- (YFLayer *)layerForReferenceID:(NSString *)referenceID;

@end

NS_ASSUME_NONNULL_END
