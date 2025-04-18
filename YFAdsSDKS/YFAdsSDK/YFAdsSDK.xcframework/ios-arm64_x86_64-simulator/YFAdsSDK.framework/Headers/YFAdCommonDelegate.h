//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
// 策略相关的代理
@protocol YFAdCommonDelegate <NSObject>

@optional

///  获取数据成功
- (void)fcAdLoadSuccess:(id)adapter;
///  获取数据失败
- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description DEPRECATED_MSG_ATTRIBUTE(" 此方法将被替换为:- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter description:(NSDictionary *)description");
///  获取数据失败
- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter description:(NSDictionary *)description;
///  获取横幅数据失败
- (void)fcAdFailedWithError:(NSError *)error  contentView:(UIView *)view description:(NSDictionary *)description;


@end

NS_ASSUME_NONNULL_END
