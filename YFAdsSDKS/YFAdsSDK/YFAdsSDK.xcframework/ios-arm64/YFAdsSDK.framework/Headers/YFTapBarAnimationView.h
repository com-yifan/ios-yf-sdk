//
//  YFTapBarAnimationView.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/27.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdBaseView.h>
#import <YFAdsSDK/YFSplashEnum.h>
#import <YFAdsSDK/YFMotionManager.h>

NS_ASSUME_NONNULL_BEGIN
@interface YFTapBarAnimationView : YFAdBaseView

@property(nonatomic, strong) YFMotionManager *motionManager;

- (instancetype)initWithFrame:(CGRect)frame model:(id)model;

- (instancetype)initModel:(id)model;
- (instancetype)initOtherplatformModel:(id)model;
- (instancetype)initGdtplatformModel:(id)model;
- (void)changeShakeToTap;
- (void)toStartMotion;
- (void)toStopMotion;

@property(nonatomic, copy) void (^toTapBarAnimatioShakeOrTwist)(YFMotionSensitivity motionSensitivity, YFMotionStyle motionStyle, YFMotionJump motionJump, CMAccelerometerData *_Nullable accelerometerData, CMDeviceMotion *_Nullable motion);


@end


NS_ASSUME_NONNULL_END
