//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import "YFAdBaseAdapter.h"
#import <UIKit/UIKit.h>
#import "YFAdSDKSetting.h"
#import "YFAdNativeExpressDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFAdNativeExpress : YFAdBaseAdapter
/// 广告方法回调代理
@property (nonatomic, weak) id<YFAdNativeExpressDelegate> delegate;
/// 广告尺寸
@property (nonatomic, assign) CGSize adSize;
/// 广告是否失效
//@property (nonatomic, assign) BOOL isValid;

@property (nonatomic, assign) float paddingLeftRight;

/// 横幅广告容器
@property(nonatomic, weak) UIView *adContainer;

/// 是否必须展示Logo 默认: NO 注意: 强制展示Logo可能会影响收益 !!!
@property (nonatomic, assign) BOOL showLogoRequire;
/// 广告Logo视图
@property(nonatomic, strong) UIView *bottomView;
/// 开屏占位视图
@property(nonatomic, strong) UIView *backgroundView;

/// 广告Logo
@property(nonatomic, strong) UIImage *logoImage DEPRECATED_MSG_ATTRIBUTE("此方法即将下线，请使用@property(nonatomic, strong) UIView *bottomView;替换");
/// 广告占位图
@property(nonatomic, strong) UIImage *backgroundImage DEPRECATED_MSG_ATTRIBUTE("此方法即将下线，请使用@property(nonatomic, strong) UIView *backgroundView;替换");
/// 广告条数
@property (nonatomic, assign) NSInteger count;

/// @param pID 广告位
/// @param viewController  viewController
/// @param size 尺寸
- (instancetype)initWithAdUnitID:(NSString *)pID adContainer:(nullable UIView *)adContainer viewController:(UIViewController *)viewController adSize:(CGSize)size;




@end

NS_ASSUME_NONNULL_END
