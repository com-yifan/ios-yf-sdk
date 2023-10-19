//
//  YFRenderGroup.h
//  Lottie
//
//  Created by brandon_withrow on 6/27/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import "YFRenderNode.h"

@interface YFRenderGroup : YFRenderNode

- (instancetype _Nonnull)initWithInputNode:(YFAnimatorNode * _Nullable)inputNode
                                   contents:(NSArray * _Nonnull)contents
                                    keyname:(NSString * _Nullable)keyname;

@property (nonatomic, strong, readonly) CALayer * _Nonnull containerLayer;

@end


