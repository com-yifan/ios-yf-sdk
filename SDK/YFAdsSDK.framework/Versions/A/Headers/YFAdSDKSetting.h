//
//  FCAdSDKConfig.h
//  advancelib
//
//  Created by allen on 2019/9/12.
//  Copyright © 2019 Bayescom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



typedef NS_ENUM(NSInteger,YFAdLogLevel) {
    YFAdLogLevel_None  = 0, // 不打印
    YFAdLogLevel_Fatal,
    YFAdLogLevel_Error,
    YFAdLogLevel_Warning,
    YFAdLogLevel_Info,
    YFAdLogLevel_Debug,
};

extern NSString *const AdvanceSdkVersion;

extern NSString *const SDK_TAG_GDT;
extern NSString *const SDK_TAG_CSJ;
extern NSString *const SDK_TAG_KS;
extern NSString *const SDK_TAG_BAIDU;
extern NSString *const SDK_TAG_YF;
extern NSString *const SDK_TAG_JD;

extern NSString *const YFAdSDKTypeAdName;
extern NSString *const YFAdSDKTypeAdNameSplash;
extern NSString *const YFAdSDKTypeAdNameBanner;
extern NSString *const YFAdSDKTypeAdNameInterstitial;
extern NSString *const YFAdSDKTypeAdNameFullScreenVideo;
extern NSString *const YFAdSDKTypeAdNameNativeExpress;
extern NSString *const YFAdSDKTypeAdNameRewardVideo;



@interface YFAdSDKSetting : NSObject
/// SDK版本
+ (NSString *)sdkVersion;

+ (instancetype)shareInstance;
/// 设置扩展设备信息，如不了解该功能，请勿使用。 如@"[{\"device_id\":\"62271333038\"}]"
@property (nonatomic, copy) NSDictionary *extraDeviceMap;

/// 控制台log级别
/// 0 不打印
/// 1 打印fatal
/// 2 fatal + error
/// 3 fatal + error + warning
/// 4 fatal + error + warning + info
/// 5 全部打印
@property (nonatomic, assign) YFAdLogLevel level;
/// 自定义IDFA，格式需与IDFA格式相同，xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
@property (nonatomic, copy) NSString * customIDFA;
//  GPS 纬度(-90 ~ 90)
@property(nonatomic, copy) NSString *device_geo_lat;
/// GPS 经度(-180 ~ 180)
@property(nonatomic, copy) NSString *device_geo_lon;
/// 用户ID
@property(nonatomic, copy) NSString *userId;

@property (nonatomic, copy) NSString *fc_conf_url;

@property (nonatomic, copy) NSString *fc_upload_url;

@property (nonatomic, copy) NSString *yf_conf_url;

@end

NS_ASSUME_NONNULL_END
