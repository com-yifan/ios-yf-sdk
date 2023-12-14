//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <Foundation/Foundation.h>

//#define FC_DEV_SHENGCH 0

//#if FC_DEV_SHENGCH
//
//#define FC_CONF_URL @"http://114.55.33.104:8080/api/v1/ads/adsc"
//#define FC_UPLOAD_URL @"http://114.55.33.104:8081/api/v1/ads/batchUpload"
//#define YF_CONF_URL @"http://117.50.154.35/client/req_ad"
//#define YF_LOG_URL @"http://47.96.237.187:9090/ads/v1/upload/log?sign="
//#else

#define FC_CONF_URL @"http://api.yfanads.com/api/v1/ads/adsc"
#define FC_UPLOAD_URL @"http://tracker.yfanads.com/api/v1/ads/batchUpload"
#define YF_CONF_URL @"http://api.lzkqmx.com/client/req_ad"
#define YF_LOG_URL @"http://logyfanads.com/ads/v1/upload/log?sign="

//#endif

NS_ASSUME_NONNULL_BEGIN

@interface YFAdDataManager : NSObject
/// 数据管理对象
+(instancetype)shareInstance;
/// 获取广告位数据
-(void)getAdsWithId:(NSString *)adID success:(void(^)(id))success fail:(void(^)(id))fail;
/// 上报数据
-(void)report:(NSArray *)events success:(void(^)(id))success fail:(void(^)(id))fail;

- (void)uploadLogFile:(NSString *)filePath;

@end

NS_ASSUME_NONNULL_END
