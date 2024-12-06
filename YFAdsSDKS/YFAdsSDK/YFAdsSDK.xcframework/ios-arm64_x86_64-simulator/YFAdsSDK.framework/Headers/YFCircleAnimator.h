//
//  YFCircleAnimator.h
//  Lottie
//
//  Created by brandon_withrow on 7/19/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <YFAdsSDK/YFAnimatorNode.h>
#import <YFAdsSDK/YFShapeCircle.h>

@interface YFCircleAnimator : YFAnimatorNode

- (instancetype _Nonnull)initWithInputNode:(YFAnimatorNode *_Nullable)inputNode
                                  shapeCircle:(YFShapeCircle *_Nonnull)shapeCircle;

@end
