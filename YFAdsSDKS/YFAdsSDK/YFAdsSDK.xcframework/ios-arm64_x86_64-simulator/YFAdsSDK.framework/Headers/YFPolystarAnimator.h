//
//  YFPolystarAnimator.h
//  Lottie
//
//  Created by brandon_withrow on 7/27/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <YFAdsSDK/YFAnimatorNode.h>
#import <YFAdsSDK/YFShapeStar.h>

@interface YFPolystarAnimator : YFAnimatorNode

- (instancetype _Nonnull)initWithInputNode:(YFAnimatorNode *_Nullable)inputNode
                             shapeStar:(YFShapeStar *_Nonnull)shapeStar;

@end
