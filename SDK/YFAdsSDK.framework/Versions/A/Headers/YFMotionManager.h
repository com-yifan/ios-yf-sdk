//
//  YFMotionManager.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/19.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>
#import "YFSplashEnum.h"

@interface YFMotionManager : NSObject
+ (nonnull instancetype)sharedManager;

//开始摇一摇或摇一摇监听 支持灵敏度
- (void)toStartShakeOrTwist:(YFMotionSensitivity)shakeMotion motionStyle:(YFMotionStyle)style motionJump:(void (^ _Nullable)(YFMotionJump))motionJump;

- (void)stopMotionManager:(YFMotionManageRoute)route;

@end


