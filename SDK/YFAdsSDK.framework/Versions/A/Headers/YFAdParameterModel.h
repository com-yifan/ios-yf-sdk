//
//  YFAdParameterModel.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdParameterModel : NSObject

/// unix时间戳
@property (nonatomic, assign) NSInteger activationTime;
/// 广告位ID，聚合的广告位ID
@property (nonatomic, copy) NSString *adID;
/// 应用ID
@property (nonatomic, copy) NSString *appID;
/// 应用版本
@property (nonatomic, copy, readonly) NSString *appVersion;
/// 渠道，支持输入多个枚举值，需用英文逗号隔开。
@property (nonatomic, copy) NSString *channel;
/// json格式，支持格式：支持大小写字母、数字、下划线、连词符，不支持中文；base64编
@property (nonatomic, retain) NSDictionary *customDefine;
/// 设备品牌，可选项：HUAWEI,OPPO,VIVO,XIAOMI,APPLE,SAMSUNG等24个品牌手机。可多选，多选使用逗号分隔
@property (nonatomic, copy, readonly) NSString *deviceBrand;
/// 设备ID， 输入多个值时，需用英文逗号隔开； 支持IDFA、OAID、IMEI或其他自定义可标识该设备id
@property (nonatomic, copy) NSString *deviceID;
///// idfaFlag
//@property (nonatomic, assign, readonly) NSInteger idfaFlag;

/// 设备类型，仅支持IOS系统，可供选择包括：Iphone、ipad
@property (nonatomic, copy) NSString *deviceType;
/// 1表示wifi,2表示2G，3表示3G，4表示4G，5表示5G
@property (nonatomic, assign,readonly) NSInteger netType;
/// 聚合SDK版本
@property (nonatomic, copy,readonly) NSString *sdkVersion;
/// 安卓或者IOS系统版本
@property (nonatomic, copy,readonly) NSString *systemVersion;
///  配置版本号
@property (nonatomic, assign) NSInteger resourceVersion;
/// idfa
@property (nonatomic, copy) NSString *idfa;

@end

NS_ASSUME_NONNULL_END
