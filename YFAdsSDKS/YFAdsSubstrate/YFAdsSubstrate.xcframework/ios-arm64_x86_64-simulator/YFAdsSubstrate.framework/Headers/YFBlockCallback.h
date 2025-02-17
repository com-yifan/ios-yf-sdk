//
//  LOTBlockCallback.h
//  Lottie
//
//  Created by brandon_withrow on 12/15/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <YFAdsSubstrate/YFValueDelegate.h>

/*!
 @brief A block that is used to change a Color value at keytime, the block is called continuously for a keypath while the animation plays.
 @param currentFrame The current frame of the animation in the parent compositions time space.
 @param startKeyFrame When the block is called, startFrame is the most recent keyframe for the keypath in relation to the current time.
 @param endKeyFrame When the block is called, endFrame is the next keyframe for the keypath in relation to the current time.
 @param interpolatedProgress A value from 0-1 that represents the current progress between keyframes. It respects the keyframes current easing curves.
 @param startColor The color from the previous keyframe in relation to the current time.
 @param endColor The color from the next keyframe in relation to the current time.
 @param interpolatedColor The color interpolated at the current time between startColor and endColor. This represents the keypaths current color for the current time.
 @return CGColorRef the color to set the keypath node for the current frame
 */
typedef CGColorRef _Nonnull (^YFColorValueCallbackBlock)(CGFloat currentFrame,
                                                          CGFloat startKeyFrame,
                                                          CGFloat endKeyFrame,
                                                          CGFloat interpolatedProgress,
                                                          CGColorRef _Nullable startColor,
                                                          CGColorRef _Nullable endColor,
                                                          CGColorRef _Nullable interpolatedColor);

/*!
 @brief A block that is used to change a Number value at keytime, the block is called continuously for a keypath while the animation plays.
 @param currentFrame The current frame of the animation in the parent compositions time space.
 @param startKeyFrame When the block is called, startFrame is the most recent keyframe for the keypath in relation to the current time.
 @param endKeyFrame When the block is called, endFrame is the next keyframe for the keypath in relation to the current time.
 @param interpolatedProgress A value from 0-1 that represents the current progress between keyframes. It respects the keyframes current easing curves.
 @param startValue The Number from the previous keyframe in relation to the current time.
 @param endValue The Number from the next keyframe in relation to the current time.
 @param interpolatedValue The Number interpolated at the current time between startValue and endValue. This represents the keypaths current Number for the current time.
 @return CGFloat the number to set the keypath node for the current frame
 */
typedef CGFloat (^YFNumberValueCallbackBlock)(CGFloat currentFrame,
                                               CGFloat startKeyFrame,
                                               CGFloat endKeyFrame,
                                               CGFloat interpolatedProgress,
                                               CGFloat startValue,
                                               CGFloat endValue,
                                               CGFloat interpolatedValue);
/*!
 @brief A block that is used to change a Point value at keytime, the block is called continuously for a keypath while the animation plays.
 @param currentFrame The current frame of the animation in the parent compositions time space.
 @param startKeyFrame When the block is called, startFrame is the most recent keyframe for the keypath in relation to the current time.
 @param endKeyFrame When the block is called, endFrame is the next keyframe for the keypath in relation to the current time.
 @param interpolatedProgress A value from 0-1 that represents the current progress between keyframes. It respects the keyframes current easing curves.
 @param startPoint The Point from the previous keyframe in relation to the current time.
 @param endPoint The Point from the next keyframe in relation to the current time.
 @param interpolatedPoint The Point interpolated at the current time between startPoint and endPoint. This represents the keypaths current Point for the current time.
 @return CGPoint the point to set the keypath node for the current frame.
 */
typedef CGPoint (^YFPointValueCallbackBlock)(CGFloat currentFrame,
                                              CGFloat startKeyFrame,
                                              CGFloat endKeyFrame,
                                              CGFloat interpolatedProgress,
                                              CGPoint startPoint,
                                              CGPoint endPoint,
                                              CGPoint interpolatedPoint);

/*!
 @brief A block that is used to change a Size value at keytime, the block is called continuously for a keypath while the animation plays.
 @param currentFrame The current frame of the animation in the parent compositions time space.
 @param startKeyFrame When the block is called, startFrame is the most recent keyframe for the keypath in relation to the current time.
 @param endKeyFrame When the block is called, endFrame is the next keyframe for the keypath in relation to the current time.
 @param interpolatedProgress A value from 0-1 that represents the current progress between keyframes. It respects the keyframes current easing curves.
 @param startSize The Size from the previous keyframe in relation to the current time.
 @param endSize The Size from the next keyframe in relation to the current time.
 @param interpolatedSize The Size interpolated at the current time between startSize and endSize. This represents the keypaths current Size for the current time.
 @return CGSize the size to set the keypath node for the current frame.
 */
typedef CGSize (^YFSizeValueCallbackBlock)(CGFloat currentFrame,
                                            CGFloat startKeyFrame,
                                            CGFloat endKeyFrame,
                                            CGFloat interpolatedProgress,
                                            CGSize startSize,
                                            CGSize endSize,
                                            CGSize interpolatedSize);

/*!
 @brief A block that is used to change a Path value at keytime, the block is called continuously for a keypath while the animation plays.
 @param currentFrame The current frame of the animation in the parent compositions time space.
 @param startKeyFrame When the block is called, startFrame is the most recent keyframe for the keypath in relation to the current time.
 @param endKeyFrame When the block is called, endFrame is the next keyframe for the keypath in relation to the current time.
 @param interpolatedProgress A value from 0-1 that represents the current progress between keyframes. It respects the keyframes current easing curves.
 @return UIBezierPath the path to set the keypath node for the current frame.
 */
typedef CGPathRef  _Nonnull (^YFPathValueCallbackBlock)(CGFloat currentFrame,
                                                         CGFloat startKeyFrame,
                                                         CGFloat endKeyFrame,
                                                         CGFloat interpolatedProgress);

/*!
 @brief YFColorValueCallback is wrapper around a YFColorValueCallbackBlock. This block can be used in conjunction with YFAnimationView setValueDelegate:forKeypath to dynamically change an animation's color keypath at runtime.
 */

@interface YFColorBlockCallback : NSObject <YFColorValueDelegate>

+ (instancetype _Nonnull)withBlock:(YFColorValueCallbackBlock _Nonnull )block NS_SWIFT_NAME(init(block:));

@property (nonatomic, copy, nonnull) YFColorValueCallbackBlock callback;

@end

/*!
 @brief YFNumberValueCallback is wrapper around a YFNumberValueCallbackBlock. This block can be used in conjunction with YFAnimationView setValueDelegate:forKeypath to dynamically change an animation's number keypath at runtime.
 */

@interface YFNumberBlockCallback : NSObject <YFNumberValueDelegate>

+ (instancetype _Nonnull)withBlock:(YFNumberValueCallbackBlock _Nonnull)block NS_SWIFT_NAME(init(block:));

@property (nonatomic, copy, nonnull) YFNumberValueCallbackBlock callback;

@end

/*!
 @brief YFPointValueCallback is wrapper around a YFPointValueCallbackBlock. This block can be used in conjunction with YFAnimationView setValueDelegate:forKeypath to dynamically change an animation's point keypath at runtime.
 */

@interface YFPointBlockCallback : NSObject <YFPointValueDelegate>

+ (instancetype _Nonnull)withBlock:(YFPointValueCallbackBlock _Nonnull)block NS_SWIFT_NAME(init(block:));

@property (nonatomic, copy, nonnull) YFPointValueCallbackBlock callback;

@end

/*!
 @brief YFSizeValueCallback is wrapper around a YFSizeValueCallbackBlock. This block can be used in conjunction with YFAnimationView setValueDelegate:forKeypath to dynamically change an animation's size keypath at runtime.
 */

@interface YFSizeBlockCallback : NSObject <YFSizeValueDelegate>

+ (instancetype _Nonnull)withBlock:(YFSizeValueCallbackBlock _Nonnull)block NS_SWIFT_NAME(init(block:));

@property (nonatomic, copy, nonnull) YFSizeValueCallbackBlock callback;

@end

/*!
 @brief YFPathValueCallback is wrapper around a YFPathValueCallbackBlock. This block can be used in conjunction with YFAnimationView setValueDelegate:forKeypath to dynamically change an animation's path keypath at runtime.
 */

@interface YFPathBlockCallback : NSObject <YFPathValueDelegate>

+ (instancetype _Nonnull)withBlock:(YFPathValueCallbackBlock _Nonnull)block NS_SWIFT_NAME(init(block:));

@property (nonatomic, copy, nonnull) YFPathValueCallbackBlock callback;

@end

