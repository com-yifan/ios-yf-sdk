//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <YFAdsSDK/YFAdCommonDelegate.h>
#import <YFAdsSDK/YFAdMediaMetal.h>

@class YFAdBaseAdPosition;
@protocol YFAdBaseDelegate <YFAdCommonDelegate>

@optional

/// 获取自渲染数据
- (void)fcAdGetMediaRenderDataSuccess:(NSArray *)mediaRenders;
/// 广告关闭Controller 的回调
- (void)fcAdDidCloseOtherController:(id)adapter
                            interactionType:(YFAdInteractionType)interactionType;
/// 广告曝光成功
- (void)fcAdExposured:(id)adapter;
/// 广告点击回调
- (void)fcAdClicked:(id)adapter;
/// 广告关闭的回调
- (void)fcAdDidClose:(id)adapter;
/// 广告落地页关闭的回调
- (void)fcAdDidDetailPageClose:(id)adapter;
/// 广告关闭的回调  （横幅使用）
- (void)fcAdDidCloseWithView:(UIView *)view;

@end
