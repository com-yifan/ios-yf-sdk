//
//  DemoAdConfig.h
//  YFAdsDemo_Example
//
//  Created by 麻明康 on 2025/3/25.
//  Copyright © 2025 Nanjing Fengchuan Yunju Infomation Technology Co., LTD. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define UseSplashWindowKey @"UseSplashWindowKey"

@interface DemoAdConfig : NSObject

/// 强制提前返回时间，单位秒，0为不开启
@property (nonatomic, assign) NSInteger earlyRetrunTime;
/// 是否使用切换window加载开屏
@property (nonatomic, assign) BOOL useSplashWindow;

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
