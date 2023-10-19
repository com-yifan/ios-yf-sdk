//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#ifndef FCAdSupplierDelegate_h
#define FCAdSupplierDelegate_h
#import "YFAdReportModel.h"

@class YFAdResponseModel;
@class FCAdWaterfall;
@class YFAdReportModel;
@protocol YFAdSupplierDelegate <NSObject>

@optional

/// 加载策略Model成功
- (void)fcAdBaseAdapterLoadSuccess:(nonnull FCAdWaterfall *)model;
/// 加载策略Model失败
- (void)fcAdBaseAdapterLoadError:(nullable NSError *)error;
/// 加载的 sortTag
- (void)fcAdBaseAdapterLoadSortTag:(NSString *_Nullable)sortTag;
/// 加载并展示
- (void)fcAdBaseAdapterLoadAndShow;

/// 返回下一个渠道的参数
/// @param supplier 被加载的渠道
/// @param error 异常信息
- (void)fcAdBaseAdapterLoadSuppluer:(nullable YFAdEventModel *)supplier error:(nullable NSError *)error;

@end

#endif
