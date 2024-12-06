//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <Foundation/Foundation.h>

#define YF_CONF_URL @"http://adx-data.yfanads.com/v1/r"
#define YF_LOG_URL @"http://log.yfanads.com/ads/v1/upload/log?sign="

NS_ASSUME_NONNULL_BEGIN

@interface YFAdDataManager : NSObject
/// 数据管理对象
+(instancetype)shareInstance;
/// 配置数据
-(void)getConfigurationWith:(NSString *)adID success: (void(^)(id))success fail: (void(^)(id))fail;
/// 获取广告位数据
-(void)getAdsWithId:(NSString *)adID reqID:(NSString *)reqID  success:(void(^)(id))success fail:(void(^)(id))fail;
/// 上报数据
-(void)report:(NSArray *)events success:(void(^)(id))success fail:(void(^)(id))fail;

-(void)uploadLogFile:(NSString *)filePath completionHandler:(void (^)(void))completionHandler;

@end

NS_ASSUME_NONNULL_END
