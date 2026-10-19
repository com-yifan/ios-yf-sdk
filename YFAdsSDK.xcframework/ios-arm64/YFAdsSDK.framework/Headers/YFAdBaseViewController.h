//
//  YFAdBaseViewController.h
//  YFAdsSDK
//
//  Created by Erik on 2024/11/26.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 控制器基类
@interface YFAdBaseViewController : UIViewController
/// 屏幕旋转动画中或已完成动画
- (void)viewWillTransitionDuringOrAfterAnimation;
/// 屏幕旋转动画结束
- (void)viewWillTransitionAfterAnimation;
/// 屏幕旋转
- (void)orientationDidChanged;
/// 更新window尺寸布局
- (void)updateLayoutWith:(CGSize)size;
@end

NS_ASSUME_NONNULL_END
