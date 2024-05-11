//
//  YFPathAnimator.h
//  Pods
//
//  Created by brandon_withrow on 6/27/17.
//
//

#import "YFAnimatorNode.h"
#import "YFShapePath.h"

@interface YFPathAnimator : YFAnimatorNode

- (instancetype _Nonnull)initWithInputNode:(YFAnimatorNode *_Nullable)inputNode
                                  shapePath:(YFShapePath *_Nonnull)shapePath;

@end
