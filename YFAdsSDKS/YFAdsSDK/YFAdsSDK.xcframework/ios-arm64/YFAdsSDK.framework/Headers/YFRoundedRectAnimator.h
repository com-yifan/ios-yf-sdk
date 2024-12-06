//
//  YFRoundedRectAnimator.h
//  Lottie
//
//  Created by brandon_withrow on 7/19/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <YFAdsSDK/YFAnimatorNode.h>
#import <YFAdsSDK/YFShapeRectangle.h>

@interface YFRoundedRectAnimator : YFAnimatorNode

- (instancetype _Nonnull)initWithInputNode:(YFAnimatorNode *_Nullable)inputNode
                                shapeRectangle:(YFShapeRectangle *_Nonnull)shapeRectangle;


@end
