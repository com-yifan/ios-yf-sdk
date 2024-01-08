//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//
NS_ASSUME_NONNULL_BEGIN
// 策略相关的代理
@protocol YFAdCommonDelegate <NSObject>

@optional

///  拉取数据成功
- (void)fcAdLoadSuccess:(id)adapter;

- (void)fcAdSuccessSortTag:(NSString *)sortTag;
/// 失败
/// @param error 聚合SDK的错误
/// @param description 每个渠道的错误详情, 部分情况下为nil  key的命名规则: 渠道名-index
- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description;

- (void)fcAdFailedWithError:(NSError *)error contentView:(UIView *)view description:(NSDictionary *)description;
/// 内部渠道开始加载时调用
- (void)fcAdSupplierWillLoad:(id)adapter;
/// 展示处理之后的广告
- (void)fcAdShowSuppluer:(id)adapter;

@end

NS_ASSUME_NONNULL_END
