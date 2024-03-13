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


/// 初始化GroMore方法，不初始化将无法使用GroMore的相关功能
/// @param appId 在GroMore注册的应用ID
/// @param config 初始化配置回调
+ (void)setupSDKWithAppId:(NSString *)appId config:(YFAdSDKSetting*(^)(YFAdSDKSetting *))config;

/// 获取初始化时使用的应用ID
+ (NSString *)appID;

/// 配置用户分组信息，可随时更新，但用户分组信息更新将触发配置重新加载，请谨慎使用
/// @param userInfo 分组信息
//+ (void)setUserInfoForSegment:(nonnull ABUUserInfoForSegment *)userInfo;
//
///// 获取当前主题模式
//+ (ABUAdSDKThemeStatus)themeStatus;

/// 获取各类补充信息
+ (NSDictionary *)getGMSDKExtraInfo;

/// 获取配置是否已经加载
+ (BOOL)configDidLoad;

/// SDK init后更新extraDeviceMap，主要用于初始化时开发者自己的参数还未生成，需后续传入；！！！该接口会覆盖初始化传入的extraDeviceMap，开发者需自己做增量处理
/// @param extraDeviceMap 额外信息
+ (void)updateExtraDeviceMap:(NSDictionary *)extraDeviceMap;

/// 设置广告主题，扩展暗黑模式
//+ (void)setThemeStatus:(ABUAdSDKThemeStatus)themeStatus;

/// 设置自定义IDFA，格式需与IDFA格式相同，xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx，
+ (void)setCustomIDFA:(nonnull NSString *)customIDFA;



@end

NS_ASSUME_NONNULL_END
