//
//  YFGradientFillRender.h
//  Lottie
//
//  Created by brandon_withrow on 7/27/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import "YFRenderNode.h"
#import "YFShapeGradientFill.h"

@interface YFGradientFillRender : YFRenderNode

- (instancetype _Nonnull)initWithInputNode:(YFAnimatorNode *_Nullable)inputNode
                          shapeGradientFill:(YFShapeGradientFill *_Nonnull)fill;

@end
