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
#import "YFAnimationView.h"


@interface YFAdsAnimationView : YFAdBaseView

@property(nonatomic, strong) YFMotionManager *motionManager;
@property(nonatomic, strong) YFAnimationView *lotAnimationTap;
@property(nonatomic, strong) YFAnimationView *lotAnimationBar;
@property(nonatomic, strong) UILabel *word;
@property(nonatomic, strong) UILabel *subword;

@property(nonatomic, strong) NSString *lotAnimationTapStr;
@property(nonatomic, strong) NSString *lotAnimationBarStr;
@property(nonatomic, copy) void (^toTapBarAnimatioShakeOrTwist)(YFMotionSensitivity motionSensitivity, YFMotionStyle motionStyle, YFMotionJump motionJump);

- (instancetype)initWithFrame:(CGRect)frame model:(id)model;
- (instancetype)initOtherplatformModel:(id)model;
- (instancetype)initGdtplatformModel:(id)model;
- (void)toStartMotion;
- (void)toStopMotion;
-(void)reloadUI:(id)model;


@end

