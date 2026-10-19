//
//  YFSplashEnum.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/18.
//

typedef NS_ENUM(NSInteger, YFSplashState) {
    YFSplashState_Unknow,//未知
    YFSplashState_min,// 最小
    YFSplashState_Small,// 小
    YFSplashState_Normal,// 标准
    YFSplashState_Big,//大
    YFSplashState_Max,//最大
};
typedef NS_ENUM(NSInteger, YFSplashLocation) {
    YFSplashLocation_Unknow,//未知
    YFSplashLocation_Right,// 右边
    YFSplashLocation_Left,//左边
};

//typedef NS_ENUM(NSInteger, YFMotionManageRoute) {
//    YFMotionManager_Gravimeter,// 重力计
//    YFMotionManager_Gyroscope,// 陀螺仪
//    YFMotionManager_Accelerometer,// 加速度计
//};

typedef NS_OPTIONS(NSUInteger, YFMotionManageRoute) {
    YFMotionManager_none           = 0,
    YFMotionManager_Gravimeter     = 1 << 0,    // 重力计
    YFMotionManager_Gyroscope      = 1 << 1,    // 陀螺仪
    YFMotionManager_Accelerometer  = 1 << 2,    // 加速度计
};

typedef NS_ENUM(NSInteger, YFMotionSensitivity) {
    YFMotionSensitivity_Normal,//合规阀值
    YFMotionManager_middle,// 中度灵敏阀值
    YFMotionManager_high,// 高度灵敏阀值
};

typedef NS_ENUM(NSInteger, YFMotionStyle) {
    YFMotionStyle_Shake,//摇一摇
    YFMotionStyle_Twist,//扭一扭
};

typedef NS_ENUM(NSInteger, YFMotionJump) {
    YFMotionJump_False,//不可以跳过
    YFMotionJump_True,//可以跳过
    YFMotionJump_Unknow,//当前设备不支持
};

