//
//  YFAdDataCenterManager.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 数据中心 增删改查
@interface YFAdDataCenterManager : NSObject

+ (instancetype)shareInstance;

+(NSArray *)getBannerViews;

+(void)addBannerObject:(id)view;


@end

NS_ASSUME_NONNULL_END
