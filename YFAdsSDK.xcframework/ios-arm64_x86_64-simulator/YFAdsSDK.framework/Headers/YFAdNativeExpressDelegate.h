//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <YFAdsSDK/YFAdBaseDelegate.h>
#import <YFAdsSDK/YFAdMediaDelegate.h>
#import <YFAdsSDK/YFAdSplashDelegate.h>

@class YFAdNativeExpressView;
@protocol YFAdNativeExpressDelegate <YFAdBaseDelegate,YFAdMediaDelegate,YFAdSplashDelegate>
@optional
/// 广告数据拉取成功
- (void)fcAdNativeExpressOnAdLoadSuccess:(nullable NSArray<YFAdNativeExpressView *> *)views;

/// 广告曝光
- (void)fcAdNativeExpressOnAdShow:(nullable YFAdNativeExpressView *)adView;

/// 广告点击
- (void)fcAdNativeExpressOnAdClicked:(nullable YFAdNativeExpressView *)adView;

/// 广告渲染成功
- (void)fcAdNativeExpressOnAdRenderSuccess:(nullable YFAdNativeExpressView *)adView;

/// 广告渲染失败
- (void)fcAdNativeExpressOnAdRenderFail:(nullable YFAdNativeExpressView *)adView;

/// 广告被关闭 (注: 百度广告(百青藤), 不支持该回调, 若使用百青藤,则该回到功能请自行实现)
- (void)fcAdNativeExpressOnAdClosed:(nullable YFAdNativeExpressView *)adView;

@end
