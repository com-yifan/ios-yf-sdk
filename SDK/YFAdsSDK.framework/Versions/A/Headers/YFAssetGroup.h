//
//  YFAssetGroup.h
//  Pods
//
//  Created by Brandon Withrow on 2/17/17.
//
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@class YFAsset;
@class YFLayerGroup;
@interface YFAssetGroup : NSObject
@property (nonatomic, readwrite) NSString * _Nullable rootDirectory;
@property (nonatomic, readonly, nullable) NSBundle *assetBundle;

- (instancetype _Nonnull)initWithJSON:(NSArray * _Nonnull)jsonArray
                      withAssetBundle:(NSBundle *_Nullable)bundle
                        withFramerate:(NSNumber * _Nonnull)framerate;

- (void)buildAssetNamed:(NSString * _Nonnull)refID withFramerate:(NSNumber * _Nonnull)framerate;

- (void)finalizeInitializationWithFramerate:(NSNumber * _Nonnull)framerate;

- (YFAsset * _Nullable)assetModelForID:(NSString * _Nonnull)assetID;

@end
