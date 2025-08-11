//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//



#import <YFAdsSDK/YFAdBaseDelegate.h>

@protocol YFAdSplashDelegate <YFAdBaseDelegate>
@optional


/// 广告背景超时回调，背景超时后，后续仍会返回广告是否拉取成功，媒体可自行处理展示逻辑。如果通过loadAndShow方法唤起开屏，则背景消失后拉去成功也默认会展示
- (void)fcAdSplashBackViewTimeout:(UIView *)view;

/// !!!: 广告点击跳过。仅部分联盟样式支持,不可在此回调释放广告，会导致无法关闭、收不到fcAdDidClose:回调等问题
- (void)fcAdSplashOnAdSkipClicked;

/// !!!: 广告倒计时结束回调。仅部分联盟样式支持,不可在此回调释放广告，会导致无法关闭、收不到fcAdDidClose:回调等问题
- (void)fcAdSplashOnAdCountdownToZero;

/// !!!: 广告即将关闭,仅部分联盟样式支持,不可在此回调释放广告，会导致无法关闭、收不到fcAdDidClose:回调等问题
- (void)fcAdSplashOnAdWillClose:(id)adapter;



@end


