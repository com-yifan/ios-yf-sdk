//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <YFAdsSDK/YFAdBaseDelegate.h>
#import <YFAdsSDK/YFAdMediaDelegate.h>

@class YFAdDrawView;

@protocol YFAdDrawDelegate <YFAdBaseDelegate,YFAdMediaDelegate>
@optional
/// 广告数据拉取成功
- (void)fcAdDrawOnAdLoadSuccess:(nullable NSArray<YFAdDrawView *> *)views;

/// 广告曝光
- (void)fcAdDrawOnAdShow:(nullable YFAdDrawView *)adView;

/// 广告点击
- (void)fcAdDrawOnAdClicked:(nullable YFAdDrawView *)adView;

/// 广告渲染成功
- (void)fcAdDrawOnAdRenderSuccess:(nullable YFAdDrawView *)adView;

/// 广告渲染失败
- (void)fcAdDrawOnAdRenderFail:(nullable YFAdDrawView *)adView;

/// 广告被关闭
- (void)fcAdDrawOnAdClosed:(nullable YFAdDrawView *)adView;

@end
