//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import "YFAdBaseAdapter.h"

#import <UIKit/UIKit.h>

#import "YFAdSDKSetting.h"
#import "YFAdRewardVideoDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFAdRewardVideo : YFAdBaseAdapter
/// 广告方法回调代理
@property (nonatomic, weak) id<YFAdRewardVideoDelegate> delegate;
/// 用户ID
@property (nonatomic, copy) NSString *userId;
/// 拓展字段 json字符串
@property (nonatomic, copy) NSString *extra;

- (instancetype)initWithAdUnitID:(NSString *)pID viewController:(UIViewController *)viewController;        
@end

NS_ASSUME_NONNULL_END
