//
//  YFMotionManager.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/19.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>
#import <YFAdsSDK/YFSplashEnum.h>

@class UIView;

@interface YFMotionManager : NSObject
+ (nonnull instancetype)sharedManager;

//开始摇一摇或摇一摇监听 支持灵敏度
- (void)toStartShakeOrTwist:(YFMotionSensitivity)shakeMotion motionStyle:(YFMotionStyle)style model:model motionJump:(void (^ _Nullable)(YFMotionJump jump, CMAccelerometerData *_Nullable accelermotion, CMDeviceMotion *_Nullable motion) )motionJump;

- (void)stopMotionManager:(YFMotionManageRoute)route;

// 带 owner 的监听栈：后注册的上层广告优先生效，释放后自动恢复下层广告。
- (void)toStartShakeOrTwist:(YFMotionSensitivity)shakeMotion motionStyle:(YFMotionStyle)style model:model owner:(id _Nullable)owner motionJump:(void (^ _Nullable)(YFMotionJump jump, CMAccelerometerData *_Nullable accelermotion, CMDeviceMotion *_Nullable motion) )motionJump;
- (void)pauseMotionManager:(YFMotionManageRoute)route owner:(id _Nullable)owner;
- (void)stopMotionManager:(YFMotionManageRoute)route owner:(id _Nullable)owner;
- (void)refreshMotionOwner:(id _Nullable)owner;
- (BOOL)canRespondToMotionForOwner:(id _Nullable)owner;
- (BOOL)canRespondToSplashAdView:(UIView *_Nullable)view;
- (BOOL)consumeSplashAdViewResponse:(UIView *_Nullable)view;

@end
