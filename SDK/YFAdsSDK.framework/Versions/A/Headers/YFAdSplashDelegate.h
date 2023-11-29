//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//



#import "YFAdBaseDelegate.h"
@protocol YFAdSplashDelegate <YFAdBaseDelegate>
@optional
/// 广告点击跳过
#pragma 百度广告不支持该回调
- (void)fcAdSplashOnAdSkipClicked;

/// 广告倒计时结束回调 百度广告不支持该回调
#pragma 百度广告不支持该回调
- (void)fcAdSplashOnAdCountdownToZero;

@end


