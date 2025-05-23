//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//



#import <YFAdsSDK/YFAdReportModel.h>

@class YFAdResponseModel;
@class YFAdReportModel;
@class YFAdBaseAdPosition;
NS_ASSUME_NONNULL_BEGIN

@protocol YFAdSupplierDelegate <NSObject>

@optional

/// 加载策略Model成功
- (void)fcAdBaseAdapterLoadSuccess:(id)model;
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
/// 广告请求完成上报流量填充
- (void)fcAdBaseAdapterFill:(YFAdBaseAdPosition *)adapter;
/// 竞价回调 YFAdEventModel
- (void)fcAdBaseAdapterBidding:(YFAdBaseAdPosition *)adapter isSucceed:(BOOL)succeed fristSuceess:(YFAdBaseAdPosition *)frist secondSuceess:(YFAdBaseAdPosition *)second adns:(NSArray *)adns;

@end

NS_ASSUME_NONNULL_END
