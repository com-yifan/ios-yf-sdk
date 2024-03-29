//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YFAdBaseAdapter.h"
#import "YFAdSDKSetting.h"
#import "YFAdSplashDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFAdSplash : YFAdBaseAdapter

/// 广告方法回调代理
@property (nonatomic, weak) id<YFAdSplashDelegate> delegate;

/// 是否必须展示Logo 默认: NO 注意: 强制展示Logo可能会影响收益 !!!
@property (nonatomic, assign) BOOL showLogoRequire;

/// 广告Logo
@property(nonatomic, strong) UIImage *logoImage;

/// 广告占位图
@property(nonatomic, strong) UIImage *backgroundImage;

/// 总超时时间单位秒
@property (nonatomic, assign) NSInteger timeout;


- (instancetype)initWithAdUnitID:(NSString *)pID viewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
