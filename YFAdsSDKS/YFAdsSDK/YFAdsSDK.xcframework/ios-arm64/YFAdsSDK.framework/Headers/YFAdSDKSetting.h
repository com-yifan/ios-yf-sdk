//
//  FCAdSDKConfig.h
//  advancelib
//
//  Created by allen on 2019/9/12.
//  Copyright © 2019 Bayescom. All rights reserved.
//  2024.11.11

// tag 6.0.4.5(build:01)
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const AdvanceSdkVersion;

//经过测试的联盟SDK版本号，带在日志里打印
extern NSString *const Adapted_Version_GDT;
extern NSString *const Adapted_Version_CSJ;
extern NSString *const Adapted_Version_KS;
extern NSString *const Adapted_Version_BD;
extern NSString *const Adapted_Version_JD;
extern NSString *const Adapted_Version_AY;
//extern NSString *const Adapted_Version_TX;

extern NSString *const SDK_TAG_GDT;
extern NSString *const SDK_TAG_CSJ;
extern NSString *const SDK_TAG_KS;
extern NSString *const SDK_TAG_BAIDU;
extern NSString *const SDK_TAG_YF;
extern NSString *const SDK_TAG_JD;
extern NSString *const SDK_TAG_GROMORE;
extern NSString *const SDK_TAG_AY;

extern NSString *const YFAdSDKTypeAdName;
extern NSString *const YFAdSDKTypeAdNameSplash;
extern NSString *const YFAdSDKTypeAdNameBanner;
extern NSString *const YFAdSDKTypeAdNameInterstitial;
extern NSString *const YFAdSDKTypeAdNameFullScreenVideo;
extern NSString *const YFAdSDKTypeAdNameNativeExpress;
extern NSString *const YFAdSDKTypeAdNameRewardVideo;



@interface YFAdSDKSetting : NSObject
// MARK: - SDK主要参数
/// SDK版本
+ (NSString *)sdkVersion;

+ (instancetype)shareInstance;
/// 用户扩展字段，主用于分组管理。举例： {“c1”: 1,"c2":"yifan","c3":"male","c4": 3.15,"c5": "xxxxx"}
@property (nonatomic, copy) NSDictionary *customDefine;
/// 用户自定义参数，主用于uid定位排查问题。举例：{“UserID”: "xxxxxxx"}
@property (nonatomic, copy) NSDictionary *userDefine;
/////控制台日志输出开关, 默认开启 ---> 此接口已弃用，日志打印请联系运营后台打开日志输出
//@property (nonatomic, assign) BOOL logEnable;

/// 是否允许SDK内部对AVAudioSession的category进行设置，默认允许。SDK内部默认使用AVAudioSessionCategoryAmbient。
@property(nonatomic, assign) BOOL allowAudioSetting;

/// 自定义IDFA，格式需与IDFA格式相同，xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
@property (nonatomic, copy) NSString * customIDFA;
/// 是否开启定位 默认开启
@property (nonatomic, assign) BOOL useLocation;
//  GPS 纬度(-90 ~ 90)
@property(nonatomic, copy) NSString *device_geo_lat;
/// GPS 经度(-180 ~ 180)
@property(nonatomic, copy) NSString *device_geo_lon;
/// ⚠️ 已废弃，请使用 userDefine 替代
@property(nonatomic, copy) NSString *userId __deprecated_msg("请使用 userDefine 替代");




// MARK: - 其它参数

/// api.yfanads.com/api/v1/ads/app
@property (nonatomic, copy) NSString *fc_data_url;

/// api.yfanads.com/api/v2/ads/adsc
@property (nonatomic, copy) NSString *fc_conf_url;

/// tracker.yfanads.com/api/v2/ads/batchUpload
@property (nonatomic, copy) NSString *fc_upload_url;

/// tracker.yfanads.com/api/v1/ads/trace
@property (nonatomic, copy) NSString *fc_trace_url;

/// adx-data.yfanads.com/v1/r
@property (nonatomic, copy) NSString *yf_conf_url;

/// adx-data.yfanads.com/v1/r
@property (nonatomic, copy) NSString *yf_info_url;

/// log.yfanads.com/ads/v1/upload/log?sign=
@property (nonatomic, copy) NSString *yf_log_url;

@property (nonatomic, assign, readonly) BOOL logSwitch;

@property(nonatomic, assign) NSTimeInterval updateLoctionTime;

/// 设置是否允许SDK限制个性化推荐。true限制个性化推荐(关闭个性化推荐)，false不限制(开启个性化推荐)。默认为false开启个性化推荐
@property (nonatomic, assign) BOOL limitPersonal;

@property (nonatomic, assign) BOOL crashRecord;

@property (nonatomic, assign) BOOL shakeAdEnable;

@end

NS_ASSUME_NONNULL_END
