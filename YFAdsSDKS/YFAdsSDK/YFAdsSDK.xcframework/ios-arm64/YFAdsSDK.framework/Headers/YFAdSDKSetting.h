//
//  FCAdSDKConfig.h
//  advancelib
//
//  Created by allen on 2019/9/12.
//  Copyright © 2019 Bayescom. All rights reserved.
//  2024.11.11

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

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
/// 自定义参数
@property (nonatomic, copy) NSDictionary *customDefine;
/// 自定义流量分组，填写真实的uid，保证与所开发app后端的用户id对应。具体联系商务
@property (nonatomic, copy) NSDictionary *userDefine;
///控制台日志输出开关, 默认开启
@property (nonatomic, assign) BOOL logEnable;

/// 自定义IDFA，格式需与IDFA格式相同，xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
@property (nonatomic, copy) NSString * customIDFA;
/// 是否开启定位 默认开启
@property (nonatomic, assign) BOOL useLocation;
//  GPS 纬度(-90 ~ 90)
@property(nonatomic, copy) NSString *device_geo_lat;
/// GPS 经度(-180 ~ 180)
@property(nonatomic, copy) NSString *device_geo_lon;
/// 用户ID
@property(nonatomic, copy) NSString *userId;

/// api.yfanads.com/api/v1/ads/app
@property (nonatomic, copy) NSString *fc_data_url;

/// api.yfanads.com/api/v2/ads/adsc
@property (nonatomic, copy) NSString *fc_conf_url;

/// tracker.yfanads.com/api/v2/ads/batchUpload
@property (nonatomic, copy) NSString *fc_upload_url;

/// adx-data.yfanads.com/v1/r
@property (nonatomic, copy) NSString *yf_conf_url;

/// log.yfanads.com/ads/v1/upload/log?sign=
@property (nonatomic, copy) NSString *yf_log_url;

@property (nonatomic, assign, readonly) BOOL logSwitch;

@property(nonatomic, assign) NSTimeInterval updateLoctionTime;

@end

NS_ASSUME_NONNULL_END
