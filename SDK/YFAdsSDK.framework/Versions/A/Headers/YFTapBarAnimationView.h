//
//  YFTapBarAnimationView.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/27.
//

#import <UIKit/UIKit.h>
#import "YFAdBaseView.h"
#import "YFSplashEnum.h"
#import "YFMotionManager.h"


@interface YFTapBarAnimationView : YFAdBaseView

@property(nonatomic, strong) YFMotionManager *motionManager;

- (instancetype)initWithFrame:(CGRect)frame model:(id)model;

- (instancetype)initModel:(id)model;
- (instancetype)initOtherplatformModel:(id)model;
- (instancetype)initGdtplatformModel:(id)model;
- (void)toStartMotion;

@property(nonatomic, copy) void (^toTapBarAnimatioShakeOrTwist)(YFMotionSensitivity motionSensitivity, YFMotionStyle motionStyle, YFMotionJump motionJump);


@end


