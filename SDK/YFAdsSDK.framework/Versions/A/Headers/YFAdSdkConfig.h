//
//  FCAdSDKConfig.h
//  advancelib
//
//  Created by allen on 2019/9/12.
//  Copyright © 2019 Bayescom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



typedef NS_ENUM(NSInteger,FCAdLogLevel) {
    FCAdLogLevel_None  = 0, // 不打印
    FCAdLogLevel_Fatal,
    FCAdLogLevel_Error,
    FCAdLogLevel_Warning,
    FCAdLogLevel_Info,
    FCAdLogLevel_Debug,
};

extern NSString *const AdvanceSdkVersion;

extern NSString *const SDK_TAG_GDT;
extern NSString *const SDK_TAG_CSJ;
extern NSString *const SDK_TAG_KS;
extern NSString *const SDK_TAG_BAIDU;

extern NSString *const FCAdSDKTypeAdName;
extern NSString *const FCAdSDKTypeAdNameSplash;
extern NSString *const FCAdSDKTypeAdNameBanner;
extern NSString *const FCAdSDKTypeAdNameInterstitial;
extern NSString *const FCAdSDKTypeAdNameFullScreenVideo;
extern NSString *const FCAdSDKTypeAdNameNativeExpress;
extern NSString *const FCAdSDKTypeAdNameRewardVideo;



@interface FCAdSDKConfig : NSObject
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
@property (nonatomic, assign) FCAdLogLevel level;

/// 自定义IDFA，格式需与IDFA格式相同，xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
@property (nonatomic, copy) NSString * customIDFA;

@end

NS_ASSUME_NONNULL_END
