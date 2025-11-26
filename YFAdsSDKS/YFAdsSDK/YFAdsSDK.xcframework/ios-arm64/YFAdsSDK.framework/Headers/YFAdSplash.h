//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdBaseAdapter.h>
#import <YFAdsSDK/YFAdSDKSetting.h>
#import <YFAdsSDK/YFAdSplashDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdSplash : YFAdBaseAdapter

/// 广告方法回调代理
@property (nonatomic, weak) id<YFAdSplashDelegate> delegate;
/// 是否必须展示Logo 默认: NO 注意: 强制展示Logo可能会影响收益 !!!
@property (nonatomic, assign) BOOL showLogoRequire;
/// 广告Logo视图
@property(nonatomic, strong) UIView *bottomView;
/// 开屏占位视图
@property(nonatomic, strong) UIView *backgroundView DEPRECATED_MSG_ATTRIBUTE("此属性将废弃SDK不再管理开屏背景图，请参照DemoSplashViewController中bgImageView实现");

/// 广告Logo
@property(nonatomic, strong) UIImage *logoImage DEPRECATED_MSG_ATTRIBUTE("此方法即将下线，请使用@property(nonatomic, strong) UIView *bottomView;替换");
/// 广告占位图
@property(nonatomic, strong) UIImage *backgroundImage DEPRECATED_MSG_ATTRIBUTE("此方法即将下线，请使用@property(nonatomic, strong) UIView *backgroundView;替换");
/// 总超时时间单位秒
@property (nonatomic, assign) NSInteger timeout;

-(void)setCurrentViewController:(UIViewController *)viewController;

-(instancetype)initWithAdUnitID:(NSString *)pID viewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
