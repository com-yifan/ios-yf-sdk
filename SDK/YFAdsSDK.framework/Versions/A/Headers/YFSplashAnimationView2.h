//
//  YFSplashAnimationView2.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/9/22.
//

#import <UIKit/UIKit.h>
#import "YFAdBaseView.h"
#import "YFSplashEnum.h"
#import "YFMotionManager.h"
#import "YFAnimationView.h"
NS_ASSUME_NONNULL_BEGIN

@interface YFSplashAnimationView2 : YFAdBaseView
@property(nonatomic, strong) YFMotionManager *motionManager;
@property(nonatomic, strong) YFAnimationView *lotAnimationTap;
@property(nonatomic, strong) YFAnimationView *lotAnimationBar;
@property(nonatomic, strong) UILabel *word;
@property(nonatomic, strong) UILabel *subword;

@property(nonatomic, strong) NSString *lotAnimationTapStr;
@property(nonatomic, strong) NSString *lotAnimationBarStr;
@property(nonatomic, copy) void (^toTapBarAnimatioShakeOrTwist)(YFMotionSensitivity motionSensitivity, YFMotionStyle motionStyle, YFMotionJump motionJump);

- (instancetype)initModel:(id)model;
- (instancetype)initOtherplatformModel:(id)model;
- (instancetype)initGdtplatformModel:(id)model;
- (void)toStartMotion;
- (void)toStopMotion;
-(void)reloadUI:(id)model;
@end

NS_ASSUME_NONNULL_END