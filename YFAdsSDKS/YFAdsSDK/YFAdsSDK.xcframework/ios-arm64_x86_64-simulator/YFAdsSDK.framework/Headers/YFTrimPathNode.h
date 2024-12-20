//
//  YFTrimPathNode.h
//  Lottie
//
//  Created by brandon_withrow on 7/21/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <YFAdsSDK/YFAnimatorNode.h>
#import <YFAdsSDK/YFShapeTrimPath.h>

@interface YFTrimPathNode : YFAnimatorNode

- (instancetype _Nonnull)initWithInputNode:(YFAnimatorNode *_Nullable)inputNode
                                  trimPath:(YFShapeTrimPath *_Nonnull)trimPath;

@end
