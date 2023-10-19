//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#ifndef FCAdCommonDelegate_h
#define FCAdCommonDelegate_h

// 策略相关的代理
@protocol YFAdCommonDelegate <NSObject>

@optional

/// 成功加载 并返回 加载的队列的标识
- (void)fcAdSuccessSortTag:(NSString *_Nullable)sortTag;
/// 失败
/// @param error 聚合SDK的错误
/// @param description 每个渠道的错误详情, 部分情况下为nil  key的命名规则: 渠道名-index
- (void)fcAdFailedWithError:(NSError * _Nullable)error description:(NSDictionary * _Nullable)description;
/// 内部渠道开始加载时调用
- (void)fcAdSupplierWillLoad:(NSString * _Nullable)supplierId;
/// 展示处理之后的广告
- (void)fcAdShowSuppluer:(nullable id)adapter;

@end

#endif
