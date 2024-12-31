//
//  YFAdDataCenterManager.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdSDKSetting.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdSDKManager : NSObject

+ (instancetype)shareInstance;
/// SDK 版本
@property (nonatomic,copy,readonly) NSString *SDKVersion;

/// 初始化(新)
+ (void)setupSDKWithAppId:(NSString *)appId;

/// 初始化
+ (void)setupSDKWithAppId:(NSString *)appId config:(YFAdSDKSetting*(^)(YFAdSDKSetting *))config DEPRECATED_MSG_ATTRIBUTE(" 此方法将被替换为:+setupSDKWithAppId");;

/// 应用ID
+ (NSString *)appID;


///  Debug
+ (BOOL)isDebug;



/// SDK init后更新extraDeviceMap，主要用于初始化时开发者自己的参数还未生成，需后续传入；！！！该接口会覆盖初始化传入的cunstomDefine，开发者需自己做增量处理
+ (void)updateExtraInfo:(NSDictionary *)customDefine;

/// SDK init后更新userDefine，主要用于初始化时开发者自己的参数还未生成，需后续传入；！！！该接口会覆盖初始化传入的cunstomDefine，开发者需自己做增量处理
+ (void)updateUserDefine:(NSDictionary *)userDefine;

/// 设置自定义IDFA，格式需与IDFA格式相同，xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx，
+ (void)setCustomIDFA:(nonnull NSString *)customIDFA;


/// 设备环境相较于初始化SDK时发生变化后调用，一般不需要调用
+ (void)syncDeviceInfo;
@end

NS_ASSUME_NONNULL_END
