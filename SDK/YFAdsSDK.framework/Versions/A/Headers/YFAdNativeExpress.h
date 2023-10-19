//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import "YFAdBaseAdapter.h"
#import <UIKit/UIKit.h>
#import "YFAdSdkConfig.h"
#import "YFAdNativeExpressDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFAdNativeExpress : YFAdBaseAdapter
/// 广告方法回调代理
@property (nonatomic, weak) id<YFAdNativeExpressDelegate> delegate;
/// 广告尺寸
@property (nonatomic, assign) CGSize adSize;
/// 横幅广告容器
@property(nonatomic, weak) UIView *adContainer;


/// @param pID 广告位
/// @param viewController  viewController
/// @param size 尺寸
- (instancetype)initWithAdUnitID:(NSString *)pID adContainer:(UIView *)adContainer viewController:(UIViewController *)viewController adSize:(CGSize)size;




@end

NS_ASSUME_NONNULL_END
