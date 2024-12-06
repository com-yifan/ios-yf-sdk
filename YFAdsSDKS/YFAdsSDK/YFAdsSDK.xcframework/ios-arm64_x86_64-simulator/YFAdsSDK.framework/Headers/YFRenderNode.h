//
//  YFRenderNode.h
//  Pods
//
//  Created by brandon_withrow on 6/27/17.
//
//

#import <YFAdsSDK/YFAnimatorNode.h>

@interface YFRenderNode : YFAnimatorNode

@property (nonatomic, readonly, strong) CAShapeLayer * _Nonnull outputLayer;

- (NSDictionary * _Nonnull)actionsForRenderLayer;

@end
