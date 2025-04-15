//
//  YFSplashAnimationView3.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2025/3/4.
//

#import <YFAdsSDK/YFAdsSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFSplashAnimationView3 : YFAdBaseView
@property(nonatomic, strong) YFMotionManager *motionManager;

@property(nonatomic, copy) void (^toTapBarAnimatioShakeOrTwist)(YFMotionSensitivity motionSensitivity, YFMotionStyle motionStyle, YFMotionJump motionJump, CMAccelerometerData *_Nullable accelerometerData, CMDeviceMotion *_Nullable motion);


- (instancetype)initModel:(id)model;
- (instancetype)initOtherplatformModel:(id)model;

- (void)toStartMotion;
- (void)toStopMotion;

@end

NS_ASSUME_NONNULL_END
