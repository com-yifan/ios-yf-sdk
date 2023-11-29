//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "YFAdResponseModel.h"

NS_ASSUME_NONNULL_BEGIN
@class  YFAdResponseModel;
@class  FCAdWaterfall;
@protocol FCAdSupplierManagerDelegate <NSObject>

/// 加载策略Model成功
- (void)fcAdSupplierManagerLoadSuccess:(id)model;
/// 加载策略Model失败
- (void)fcAdSupplierManagerLoadError:(NSError *)error;
/// 返回下一个渠道的参数
- (void)fcAdSupplierLoadSuppluer:(FCAdWaterfall *)model error:(nullable NSError *)error;
/// 被选中的选择的sort标志
- (void)fcAdSupplierManagerLoadSortTag:(NSString *)tag;
/// 展示广告
- (void)fcAdSupplierManagerShow:(id)adapter;

@end


@interface YFAdSupplierManager : NSObject

/// 数据加载回调
@property(nonatomic, weak) id <FCAdSupplierManagerDelegate> delegate;

/// 数据管理对象
+ (instancetype)manager;
/// 流量请求时间
@property (nonatomic, assign) double frt;
/// 初始数据
- (void)loadDataWithDic:(NSDictionary *)jsonDic;

/// 单层广告数据
- (void)loadCrossParallelSupplier:(id)model;

/// 加载下个渠道
- (void)loadNextSupplierIfHas;

@end

NS_ASSUME_NONNULL_END
