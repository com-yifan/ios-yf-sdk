//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import "YFAdCommonDelegate.h"
// 策略相关的代理
@protocol YFAdBaseDelegate <YFAdCommonDelegate>

@optional
/// 广告曝光成功
- (void)fcAdExposured;
/// 广告点击回调
- (void)fcAdClicked;
/// 广告数据请求成功后调用
- (void)fcAdUnifiedViewDidLoad;
/// 广告关闭的回调
- (void)fcAdDidClose;

/// 广告关闭的回调
- (void)fcAdDidCloseWithView:(UIView *)view;

@end
