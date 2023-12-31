//
//  YFAnimatedControl.h
//  Lottie
//
//  Created by brandon_withrow on 8/25/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YFAnimationView;
@class YFComposition;

@interface YFAnimatedControl : UIControl

// This class is a base class that is intended to be subclassed

/**
 * Map a specific animation layer to a control state. 
 * When the state is set all layers will be hidden except the specified layer.
 **/

- (void)setLayerName:(NSString * _Nonnull)layerName forState:(UIControlState)state;

@property (nonatomic, strong, readonly, nonnull) YFAnimationView *animationView;
@property (nonatomic, strong, nullable) YFComposition *animationComp;

@end
