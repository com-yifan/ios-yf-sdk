//
//  YFStrokeRenderer.h
//  Lottie
//
//  Created by brandon_withrow on 7/17/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <YFAdsSDK/YFRenderNode.h>
#import <YFAdsSDK/YFShapeStroke.h>

@interface YFStrokeRenderer : YFRenderNode

- (instancetype _Nonnull)initWithInputNode:(YFAnimatorNode *_Nullable)inputNode
                                shapeStroke:(YFShapeStroke *_Nonnull)stroke;


@end
