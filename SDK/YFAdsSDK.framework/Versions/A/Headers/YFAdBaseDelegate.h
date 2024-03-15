//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import "YFAdCommonDelegate.h"
@protocol YFAdBaseDelegate <YFAdCommonDelegate>

@optional

/// 获取自渲染数据
- (void)fcAdGetMediaRenderDataSuccess:(NSArray *)mediaRenders;
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
