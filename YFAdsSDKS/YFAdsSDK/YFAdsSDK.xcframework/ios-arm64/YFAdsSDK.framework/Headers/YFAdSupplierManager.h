//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdResponseModel.h>
#import <YFAdsSDK/YFAdConst.h>

NS_ASSUME_NONNULL_BEGIN
@class  YFAdResponseModel;
@class  FCAdWaterfall;
@class YFAdBaseAdPosition;
@protocol FCAdSupplierManagerDelegate <NSObject>

/// 加载策略Model成功
- (void)fcAdSupplierManagerLoadSuccess:(id)model;
/// 加载策略Model失败
- (void)fcAdSupplierManagerLoadError:(NSError *)error;
/// 返回下一个渠道的参数
- (void)fcAdSupplierLoadSuppluer:(FCAdWaterfall *)model error:(nullable NSError *)error;
/// 被选中的选择的sort标志
- (void)fcAdSupplierManagerLoadSortTag:(NSString *)tag;
/// 流量填充，竞价流程完成
- (void)fcAdSupplierManagerFill:(id)adapter;
/// 展示广告
- (void)fcAdSupplierManagerShow:(id)adapter;
/// 竞价回调 YFAdEventModel
- (void)fcAdSupplierBidding:(YFAdBaseAdPosition *)adapter isSucceed:(BOOL)succeed fristSuceess:(YFAdBaseAdPosition *)frist secondSuceess:(YFAdBaseAdPosition *)second adns:(NSArray *)adns;

@end


@interface YFAdSupplierManager : NSObject

/// 数据加载回调
@property(nonatomic, weak) id <FCAdSupplierManagerDelegate> delegate;

/// 数据管理对象
+ (instancetype)manager;
/// 流量请求时间
@property (nonatomic, assign) double frt;

@property (nonatomic, copy) NSString * rID;

/// 初始数据
- (void)loadDataWithDic:(NSDictionary *)jsonDic;

/// 单层广告数据
- (void)loadCrossParallelSupplier:(id)model;

/// 调用展示当前已填充广告的最优层，无需等待亿帆SDK执行完成整体逻辑
- (void)takeResultImmediately;
@end

NS_ASSUME_NONNULL_END
