//
//  YFAdDataCenterManager.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>
#import "YFAdSDKSetting.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFAdSDKManager : NSObject

+ (instancetype)shareInstance;
/// SDK 版本
@property (nonatomic,copy,readonly) NSString *SDKVersion;

/// 初始化
+ (void)setupSDKWithAppId:(NSString *)appId config:(YFAdSDKSetting*(^)(YFAdSDKSetting *))config;

/// 应用ID
+ (NSString *)appID;


/// SDK init后更新extraDeviceMap，主要用于初始化时开发者自己的参数还未生成，需后续传入；！！！该接口会覆盖初始化传入的cunstomDefine，开发者需自己做增量处理
+ (void)updateExtraInfo:(NSDictionary *)customDefine;

/// 设置自定义IDFA，格式需与IDFA格式相同，xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx，
+ (void)setCustomIDFA:(nonnull NSString *)customIDFA;



@end

NS_ASSUME_NONNULL_END
