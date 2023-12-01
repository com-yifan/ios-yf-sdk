//
//  ZFOrentationObserver.h
//  ZFPlayer
//
// Copyright (c) 2016年 任子丰 ( http://github.com/renzifeng )
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <UIKit/UIKit.h>
#import "YFPlayerView.h"

NS_ASSUME_NONNULL_BEGIN

/// Full screen mode
typedef NS_ENUM(NSUInteger, YFFullScreenMode) {
    YFFullScreenModeAutomatic,  // Determine full screen mode automatically
    YFFullScreenModeLandscape,  // Landscape full screen mode
    YFFullScreenModePortrait    // Portrait full screen Model
};

/// Portrait full screen mode.
typedef NS_ENUM(NSUInteger, YFPortraitFullScreenMode) {
    YFPortraitFullScreenModeScaleToFill,    // Full fill
    YFPortraitFullScreenModeScaleAspectFit  // contents scaled to fit with fixed aspect. remainder is transparent
};

/// Player view mode
typedef NS_ENUM(NSUInteger, YFRotateType) {
    YFRotateTypeNormal,         // Normal
    YFRotateTypeCell            // Cell
};

/**
 Rotation of support direction
 */
typedef NS_OPTIONS(NSUInteger, YFInterfaceOrientationMask) {
    YFInterfaceOrientationMaskUnknow = 0,
    YFInterfaceOrientationMaskPortrait = (1 << 0),
    YFInterfaceOrientationMaskLandscapeLeft = (1 << 1),
    YFInterfaceOrientationMaskLandscapeRight = (1 << 2),
    YFInterfaceOrientationMaskPortraitUpsideDown = (1 << 3),
    YFInterfaceOrientationMaskLandscape = (YFInterfaceOrientationMaskLandscapeLeft | YFInterfaceOrientationMaskLandscapeRight),
    YFInterfaceOrientationMaskAll = (YFInterfaceOrientationMaskPortrait | YFInterfaceOrientationMaskLandscape | YFInterfaceOrientationMaskPortraitUpsideDown),
    YFInterfaceOrientationMaskAllButUpsideDown = (YFInterfaceOrientationMaskPortrait | YFInterfaceOrientationMaskLandscape),
};

/// This enumeration lists some of the gesture types that the player has by default.
typedef NS_OPTIONS(NSUInteger, YFDisablePortraitGestureTypes) {
    YFDisablePortraitGestureTypesNone         = 0,
    YFDisablePortraitGestureTypesTap          = 1 << 0,
    YFDisablePortraitGestureTypesPan          = 1 << 1,
    YFDisablePortraitGestureTypesAll          = (YFDisablePortraitGestureTypesTap | YFDisablePortraitGestureTypesPan)
};

@protocol YFPortraitOrientationDelegate <NSObject>

- (void)yf_orientationWillChange:(BOOL)isFullScreen;

- (void)yf_orientationDidChanged:(BOOL)isFullScreen;

- (void)zf_interationState:(BOOL)isDragging;

@end

@interface YFOrientationObserver : NSObject

/// update the rotateView and containerView.
- (void)updateRotateView:(YFPlayerView *)rotateView
           containerView:(UIView *)containerView;

/// Container view of a full screen state player.
@property (nonatomic, strong, readonly, nullable) UIView *fullScreenContainerView;

/// Container view of a small screen state player.
@property (nonatomic, weak) UIView *containerView;

/// The block invoked When player will rotate.
@property (nonatomic, copy, nullable) void(^orientationWillChange)(YFOrientationObserver *observer, BOOL isFullScreen);

/// The block invoked when player rotated.
@property (nonatomic, copy, nullable) void(^orientationDidChanged)(YFOrientationObserver *observer, BOOL isFullScreen);

/// Full screen mode, the default landscape into full screen
@property (nonatomic) YFFullScreenMode fullScreenMode;

@property (nonatomic, assign) YFPortraitFullScreenMode portraitFullScreenMode;

/// rotate duration, default is 0.30
@property (nonatomic) NSTimeInterval duration;

/// If the full screen.
@property (nonatomic, readonly, getter=isFullScreen) BOOL fullScreen;

/// Lock screen orientation
@property (nonatomic, getter=isLockedScreen) BOOL lockedScreen;

/// The fullscreen statusbar hidden.
@property (nonatomic, assign) BOOL fullScreenStatusBarHidden;

/// default is  UIStatusBarStyleLightContent.
@property (nonatomic, assign) UIStatusBarStyle fullScreenStatusBarStyle;

/// defalut is UIStatusBarAnimationSlide.
@property (nonatomic, assign) UIStatusBarAnimation fullScreenStatusBarAnimation;

@property (nonatomic, assign) CGSize presentationSize;

/// default is YFDisablePortraitGestureTypesAll.
@property (nonatomic, assign) YFDisablePortraitGestureTypes disablePortraitGestureTypes;

/// The current orientation of the player.
/// Default is UIInterfaceOrientationPortrait.
@property (nonatomic, readonly) UIInterfaceOrientation currentOrientation;

/// Whether allow the video orientation rotate.
/// default is YES.
@property (nonatomic, assign) BOOL allowOrientationRotation;

/// The support Interface Orientation,default is YFInterfaceOrientationMaskAllButUpsideDown
@property (nonatomic, assign) YFInterfaceOrientationMask supportInterfaceOrientation;

/// Add the device orientation observer.
- (void)addDeviceOrientationObserver;

/// Remove the device orientation observer.
- (void)removeDeviceOrientationObserver;

/// Enter the fullScreen while the YFFullScreenMode is YFFullScreenModeLandscape.
- (void)rotateToOrientation:(UIInterfaceOrientation)orientation animated:(BOOL)animated;

/// Enter the fullScreen while the YFFullScreenMode is YFFullScreenModeLandscape.
- (void)rotateToOrientation:(UIInterfaceOrientation)orientation animated:(BOOL)animated completion:(void(^ __nullable)(void))completion;

/// Enter the fullScreen while the YFFullScreenMode is YFFullScreenModePortrait.
- (void)enterPortraitFullScreen:(BOOL)fullScreen animated:(BOOL)animated;

/// Enter the fullScreen while the YFFullScreenMode is YFFullScreenModePortrait.
- (void)enterPortraitFullScreen:(BOOL)fullScreen animated:(BOOL)animated completion:(void(^ __nullable)(void))completion;

/// FullScreen mode is determined by YFFullScreenMode.
- (void)enterFullScreen:(BOOL)fullScreen animated:(BOOL)animated;

/// FullScreen mode is determined by YFFullScreenMode.
- (void)enterFullScreen:(BOOL)fullScreen animated:(BOOL)animated completion:(void (^ _Nullable)(void))completion;

@end

NS_ASSUME_NONNULL_END


