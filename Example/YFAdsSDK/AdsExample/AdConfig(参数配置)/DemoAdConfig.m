//
//  DemoAdConfig.m
//  YFAdsDemo_Example
//
//  Created by 麻明康 on 2025/3/25.
//  Copyright © 2025 Nanjing Fengchuan Yunju Infomation Technology Co., LTD. All rights reserved.
//

#import "DemoAdConfig.h"


@implementation DemoAdConfig

+ (instancetype)sharedInstance {
    static DemoAdConfig *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        _earlyRetrunTime = 0;
    }
    return self;
}

- (BOOL)useSplashWindow {
    return [[NSUserDefaults standardUserDefaults] boolForKey:UseSplashWindowKey];
}

- (void)setUseSplashWindow:(BOOL)useSplashWindow {
    [[NSUserDefaults standardUserDefaults] setBool:useSplashWindow forKey:UseSplashWindowKey];
}

@end
