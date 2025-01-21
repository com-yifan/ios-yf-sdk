//
//  LOTValueCallback.h
//  Lottie
//
//  Created by brandon_withrow on 12/15/17.
//  Copyright © 2017 Airbnb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <YFAdsSDK/YFValueDelegate.h>

/*!
 @brief YFColorValueCallback is a container for a CGColorRef. This container is a LOTColorValueDelegate that always returns the colorValue property to its animation delegate.
 @discussion YFColorValueCallback is used in conjunction with YFAnimationView setValueDelegate:forKeypath to set a color value of an animation property.
 */

@interface YFColorValueCallback : NSObject <YFColorValueDelegate>

+ (instancetype _Nonnull)withCGColor:(CGColorRef _Nonnull)color NS_SWIFT_NAME(init(color:));

@property (nonatomic, nonnull) CGColorRef colorValue;

@end

/*!
 @brief YFNumberValueCallback is a container for a CGFloat value. This container is a LOTNumberValueDelegate that always returns the numberValue property to its animation delegate.
 @discussion YFNumberValueCallback is used in conjunction with YFAnimationView setValueDelegate:forKeypath to set a number value of an animation property.
 */

@interface YFNumberValueCallback : NSObject <YFNumberValueDelegate>

+ (instancetype _Nonnull)withFloatValue:(CGFloat)numberValue NS_SWIFT_NAME(init(number:));

@property (nonatomic, assign) CGFloat numberValue;

@end

/*!
 @brief YFPointValueCallback is a container for a CGPoint value. This container is a LOTPointValueDelegate that always returns the pointValue property to its animation delegate.
 @discussion YFPointValueCallback is used in conjunction with YFAnimationView setValueDelegate:forKeypath to set a point value of an animation property.
 */

@interface YFPointValueCallback : NSObject <YFPointValueDelegate>

+ (instancetype _Nonnull)withPointValue:(CGPoint)pointValue;

@property (nonatomic, assign) CGPoint pointValue;

@end

/*!
 @brief YFSizeValueCallback is a container for a CGSize value. This container is a LOTSizeValueDelegate that always returns the sizeValue property to its animation delegate.
 @discussion YFSizeValueCallback is used in conjunction with YFAnimationView setValueDelegate:forKeypath to set a size value of an animation property.
 */

@interface YFSizeValueCallback : NSObject <YFSizeValueDelegate>

+ (instancetype _Nonnull)withPointValue:(CGSize)sizeValue NS_SWIFT_NAME(init(size:));

@property (nonatomic, assign) CGSize sizeValue;

@end

/*!
 @brief YFPathValueCallback is a container for a CGPathRef value. This container is a LOTPathValueDelegate that always returns the pathValue property to its animation delegate.
 @discussion YFPathValueCallback is used in conjunction with YFAnimationView setValueDelegate:forKeypath to set a path value of an animation property.
 */

@interface YFPathValueCallback : NSObject <YFPathValueDelegate>

+ (instancetype _Nonnull)withCGPath:(CGPathRef _Nonnull)path NS_SWIFT_NAME(init(path:));

@property (nonatomic, nonnull) CGPathRef pathValue;

@end
