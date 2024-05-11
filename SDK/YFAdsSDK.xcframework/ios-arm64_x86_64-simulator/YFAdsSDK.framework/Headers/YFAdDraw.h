//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import "YFAdBaseAdapter.h"
#import <UIKit/UIKit.h>
#import "YFAdSDKSetting.h"
#import "YFAdDrawDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFAdDraw : YFAdBaseAdapter
/// 广告方法回调代理
@property (nonatomic, weak) id<YFAdDrawDelegate> delegate;
/// 广告尺寸
@property (nonatomic, assign) CGSize adSize;
/// 横幅广告容器
@property(nonatomic, weak) UIView *adContainer;

/// 是否必须展示Logo 默认: NO 注意: 强制展示Logo可能会影响收益 !!!
@property (nonatomic, assign) BOOL showLogoRequire;
/// 广告Logo
@property(nonatomic, strong) UIImage *logoImage;
/// 广告条数
@property (nonatomic, assign) NSInteger count;

/// @param pID 广告位
/// @param viewController  viewController
/// @param size 尺寸
- (instancetype)initWithAdUnitID:(NSString *)pID adContainer:(UIView *)adContainer viewController:(UIViewController *)viewController adSize:(CGSize)size;




@end

NS_ASSUME_NONNULL_END
