//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//



#import "YFAdBaseDelegate.h"

@protocol YFAdSplashDelegate <YFAdBaseDelegate>
@optional


/// 广告背景超时回调，背景超时后，后续仍会返回广告是否拉取成功，媒体可自行处理展示逻辑。如果通过loadAndShow方法唤起开屏，则背景消失后拉去成功也默认会展示
- (void)fcAdSplashBackViewTimeout:(UIView *)view;
#pragma 百度广告不支持该回调
/// 广告点击跳过
- (void)fcAdSplashOnAdSkipClicked;

/// 广告倒计时结束回调 百度广告不支持该回调
#pragma 百度广告不支持该回调
- (void)fcAdSplashOnAdCountdownToZero;

#pragma 仅优量汇支持
/// 广告即将关闭
- (void)fcAdSplashOnAdWillClose:(id)adapter;



@end


