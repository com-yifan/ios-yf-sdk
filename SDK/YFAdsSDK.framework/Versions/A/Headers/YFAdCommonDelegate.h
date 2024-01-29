//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//
NS_ASSUME_NONNULL_BEGIN
// 策略相关的代理
@protocol YFAdCommonDelegate <NSObject>

@optional

///  获取数据成功
- (void)fcAdLoadSuccess:(id)adapter;
///  获取数据失败
- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description;
- (void)fcAdFailedWithError:(NSError *)error contentView:(UIView *)view description:(NSDictionary *)description;

@end

NS_ASSUME_NONNULL_END
