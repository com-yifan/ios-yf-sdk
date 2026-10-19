//
//  YFRequestModel.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/19.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFRequestModel : NSObject


//流量源 ID (由 SSP 平台生成) 必传
@property(nonatomic, copy) NSString *rID;
//公共信息
//流量源 ID (由 SSP 平台生成) 必传
@property(nonatomic, copy) NSString *app_id;
//广告位 ID (由 SSP 平台生成) 必传
@property(nonatomic, copy) NSString *pid;
//标识是否移动流量:( 1:移动流量，0:pc)默认=1  必传
@property(nonatomic, assign) NSUInteger is_mobile;
///*
// 0:只支持 http 协议
// 1:只支持 https 协议
// 2:http、https 协议都支持（不传默认此值）
// */
//@property(nonatomic, assign) NSUInteger secure;
/*
 性别:(-1:未知、01:男、10:女)
 */
@property(nonatomic, assign) NSUInteger gender;

@property(nonatomic, assign) NSUInteger bidfloor;
// 位数字出生年
@property(nonatomic, copy) NSString *yob;

//用户感兴趣关键词多个用英文逗号隔(Get 请求需做 urlencode)

@property(nonatomic, copy) NSString *keywords;
//国家:使用 ISO 3166-1\Alpha-2 标准  必须
@property(nonatomic, copy) NSString *country;

//设备的语言设置:使用 ISO 639-1\Alpha-2 标准
@property(nonatomic, copy) NSString *language;

// 禁止投放行业的 ID(多个用英文逗号”,” 分隔，例 如”deny_cats=123,456” ID 由 SSP 平台
@property(nonatomic, copy) NSString *deny_cats;

// 禁止投放的创意 ID(多个用英文逗号”,” 分隔，例如”deny_cids=123,456” 注：此 ID 为 SSP 平台 ID
@property(nonatomic, copy) NSString *deny_cids;

// 禁止投放的广告主 ID(多个用英文逗号”,” 分隔，例如” deny_ader_ids =123,456” 注：此 ID 为 SSP 平台 ID)
@property(nonatomic, copy) NSString *deny_ader_ids;

// SDK版本号
@property (nonatomic, assign) NSString *sdkVer;

/*
 扩展 字段， json 字符 串（必须 且只做一 次urlencode）
 Json 结构如：{"features": [{"value": ["1"], "key": "hap"},{"value": ["xxx"], "key":
 */
@property(nonatomic, copy) NSString *ext;

/*PC 流量参数信息
//当前页(Get 请求需做 urlencode)  必传
@property(nonatomic,copy)NSString *src;
//来源上一页(Get 请求需做 urlencode)
@property(nonatomic,copy)NSString *ref;
//客户端 ip, server to server 对接此字段必填
@property(nonatomic,copy)NSString *ip;
//当 需 要 返 回 jsonp 数 据 时 可 以 传 入 此 字 段callback=func，返回的应答格式为 func(json 数据
 @property(nonatomic,copy)NSString *callback;
//PC 流量参数信息 结束
 */

//3.3 移动流量参数信息
//应用包名(ios 填写 Bundle ID) 必传
@property(nonatomic, copy) NSString *app_package;

@property(nonatomic, copy) NSString *device_model;
@property(nonatomic, copy) NSString *device_machine;

//苹果应用市场的应用 ID
@property(nonatomic, copy) NSString *appstore_id;

//APP 应用名称
@property(nonatomic, copy) NSString *app_name;
//App 应用本身版本
@property(nonatomic, copy) NSString *app_ver;
//GPS 纬度(-90 ~ 90)
@property(nonatomic, copy) NSString *device_geo_lat;
//GPS 经度(-180 ~ 180)
@property(nonatomic, copy) NSString *device_geo_lon;
////安卓设备 IMEI 无需填写
//@property(nonatomic,copy)NSString *device_imei;
///*
// OAID:Android Q 系统无法再获取到 IMEI 作为安卓设备唯一标识，移动联盟推出 OAID 作为设备
// 唯一标识。OAID(Open Anonymous ID )是由中国信通院联合
// 华为、小米、OPPO、VIVO 共同推出的设备识别
// 字段。即开放匿名 ID，只能用于广告场景（禁
// 止使用在其他场景）
// 安卓设备 imei,oaid 不能同时为空  无需填写
// */
//@property(nonatomic,copy)NSString *device_oaid;

////oaid 原始值 md5 加密后的值
//@property(nonatomic,copy)NSString *device_oaidmd5;

//安卓系统为 android id, ios 则为 idfa（原始值或md5 加密后的值）） 必传
@property(nonatomic, copy) NSString *device_adid;
//阿里巴巴匿名设备标识，需集成阿里 SDK 获取
@property(nonatomic, copy) NSString *device_ali_aaid;
// 中广协
@property(nonatomic, copy) NSString *device_dbid;
//Y（IOS 无 IDFA 时建议填写，安卓无需填写）拼多多广告 ID
@property(nonatomic, copy) NSString *device_paid;

//苹果设备唯一标识号; 安卓系统不必填写
@property(nonatomic, copy) NSString *device_openueid;

//os idfv for iOS(>=iOS6) 安卓系统不必填写
@property(nonatomic, copy) NSString *device_idfv;
//设备屏幕像素密度:286ppi
@property(nonatomic, assign) NSUInteger device_ppi;
/*
 屏幕分辨率值如:3.0. Android 平台参考:DisplayMetrics.density,
 iOS 平台参考:UIScreen.scale
 */
@property(nonatomic, copy) NSString *device_density;
//MAC 地址(00:23:5A:15:99:42)
@property(nonatomic, copy) NSString *device_mac;

//Y 操作系统版本(8.0.1)
@property(nonatomic, copy) NSString *device_type_os;


//Android API level (iOS 不填)
//@property(nonatomic,copy)NSString *device_apiLeve;
//电量百分比（0~100）
@property(nonatomic, copy) NSString *device_battery_level;
//Y 设备类型(-1:未知, 0:phone, 1:pad, 2:pc, 3:tv，4:wap，5:户外广告屏)
@property(nonatomic, assign) NSUInteger device_type;
//Y 设备品牌、生产厂商("HUAWEI"、"Apple" 、"Xiaomi")
@property(nonatomic, copy) NSString *device_brand;

@property(nonatomic, assign) NSUInteger device_width;

@property(nonatomic, assign) NSUInteger device_height;


/*
 网络运营商代码取值：
 -1：未知
 46000：中国移动，
 46001：中国联通，
 46003：中国电信
 */
@property(nonatomic, copy) NSString *device_carrier;

//Y 网络类型:(-1:未知，1:WIFI，2:4G，3:3G，4:2G, 6：5G）
@property(nonatomic, assign) NSUInteger device_network;
//Y Android/iOS/WP/Others 字符串，注意大小写
@property(nonatomic, copy) NSString *device_os;
//Y 客户端 ip(必须是外网可访问 IP，客户端直接发起请求此字段必须不传，服务器发起请求必须传客户端外网 IP)
@property(nonatomic, copy) NSString *device_ip;

//User-Agent(GET 请求须且只做一次 urlencode)必须 是 标 准 Webview UA 而非自定义 UA
@property(nonatomic, copy) NSString *device_ua;
//Y 横竖屏（-1:未知，1:横屏，0:竖屏）
@property(nonatomic, assign) NSUInteger device_orientation;
//Y 手机 rom 的版本号
@property(nonatomic, copy) NSString *device_rom_version;

//Y 华为 HMS Core 版本号
//@property(nonatomic,copy)NSString *device_hmscore;

//Y 厂商应用商店版本号（vovi、小米、华为、oppo 等厂商应用商店）
//@property(nonatomic,copy)NSString *device_appstore_ver;
// 系统启动标识，原始传输
@property(nonatomic, copy) NSString *device_boot_mark;
// 系统更新标识，原始传输
@property(nonatomic, copy) NSString *device_update_mark;
// 系统更新时间(iOS 14 以上系统)
@property(nonatomic, copy) NSString *device_sys_update;
// 系统初始化时间(iOS 14 以上系统)
@property(nonatomic, copy) NSString *device_sys_init;
// 手机系统编译时间（毫秒时间戳）
@property(nonatomic, copy) NSString *device_syscmp_time;
// 系统启动时间（毫秒时间戳）
@property(nonatomic, copy) NSString *device_boot_time;
// 无级网 SSID 名称
@property(nonatomic, copy) NSString *device_ssid;
// WIFI 路由器 MAC 地址
@property(nonatomic, copy) NSString *device_wifi_mac;
// 已安装应用包名，多个用英文逗号分隔，为避免特 殊 字 符 影 响 ， 建 议 请 求 前 对 值 做 一 下urlencode
@property(nonatomic, copy) NSString *installed_app;
// 是否支持小程序；0：不支持；1：支持
@property (nonatomic, assign) int support_wx;
// Android 设备是否 ROOT。1--是, 0--否/ 未知(默认)
//@property(nonatomic,assign)NSUInteger device_isroot;

/// 磁盘可用空间，单位：字节
@property(nonatomic, copy) NSNumber *device_disk_available;

/// 磁盘总空间，单位：字节， 如“250685575168” (iOS 请求必须填)
@property(nonatomic, copy) NSNumber *device_disk_total;

/// 系统可用内存空间，单位：字节。每次调用都会重新获取
@property(nonatomic, copy) NSNumber *device_mem_available;

/// 系统总内存空间，单位：字节， 如“17179869184” ( iOS 请求必须填)
@property(nonatomic, copy) NSNumber *device_mem_total;

/// 设备名称的 MD5 值，取小写 16 进制的结果，长度为 32 个字节，示例："e910dddb2748c36b47fcde5dd720eec1"  (iOS 请求必须填)
@property(nonatomic, copy) NSString *device_name;

/// CPU 数⽬，示例: "4"(iOS 请求必须填)
@property(nonatomic, copy) NSNumber *device_cpu_num;

@property(nonatomic, copy) NSNumber *device_screenSize;

@end


/// 广告类型
typedef NS_ENUM(NSUInteger, YFAdRequestAdType) {
    YFAdRequestAdTypeUnknow = 0,
    YFAdRequestAdTypeSplash = 1,
    YFAdRequestAdTypeNative = 2,
    YFAdRequestAdTypeIntertitial = 3,
    YFAdRequestAdTypeBanner = 4,
    YFAdRequestAdTypeDraw = 5,
    YFAdRequestAdTypeFullScreen = 6,
    YFAdRequestAdTypeRewardVod = 7,
    YFAdRequestAdTypePatch = 8
};

/// 流量类型
typedef NS_ENUM(NSUInteger, YFAdRequestAppFlowType) {
    /// app流量
    YFAdRequestAppFlowTypeApp = 1,
    /// 快应用
    YFAdRequestAppFlowTypeMiniApp = 2,
    /// 快游戏
    YFAdRequestAppFlowTypeMiniGame = 3,
};

/// 坐标系类型
typedef NS_ENUM(NSUInteger, YFAdRequestDeviceGeoType) {
    YFAdRequestDeviceGeoTypeMars = 0,
    YFAdRequestDeviceGeoTypeWGS84 = 1,
};

/// 设备类型
typedef NS_ENUM(NSInteger, YFAdRequestDeviceType) {
    /// 未知
    YFAdRequestDeviceTypeUnknow = -1,
    /// 手机
    YFAdRequestDeviceTypePhone = 0,
    /// 平板
    YFAdRequestDeviceTypePad = 1,
    /// PC
    YFAdRequestDeviceTypePC  = 2,
    /// TV
    YFAdRequestDeviceTypeTV  = 3,
    /// WAP
    YFAdRequestDeviceTypeWAP = 4,
    /// 户外广告屏
    YFAdRequestDeviceTypeAdScreen = 5
};

/// 网络类型
typedef NS_ENUM(NSInteger, YFAdRequestDeviceNetworkType) {
    /// 未知
    YFAdRequestDeviceNetworkTypeUnknow = -1,
    /// WiFi
    YFAdRequestDeviceNetworkTypeWiFi = 1,
    /// 2G
    YFAdRequestDeviceNetworkType2G = 2,
    /// 3G
    YFAdRequestDeviceNetworkType3G = 3,
    /// 4G
    YFAdRequestDeviceNetworkType4G = 4,
    /// 5G
    YFAdRequestDeviceNetworkType5G = 5
};


/// 屏幕方向
typedef NS_ENUM(NSInteger, YFAdRequestDeviceOrientationType) {
    /// 未知
    YFAdRequestDeviceOrientationTypeUnknow = -1,
    /// 竖屏
    YFAdRequestDeviceOrientationTypePortrait = 0,
    /// 横屏
    YFAdRequestDeviceOrientationTypeLandscape = 1,
};

@class YFRequestAdModel;
@class YFRequestAppModel;
@class YFRequestDeviceModel;
@class YFRequestUserModel;
@class YFRequestDeviceDbid;

@interface YFRequestModel_New : NSObject<YFAdModel>
/// 是否需要https 1:https;2:http;3:均可
@property (nonatomic, assign) NSUInteger secure;
/// 是否支持微信 默认0 不限制
@property (nonatomic, assign) NSUInteger supportwx;
/// 广告请求
@property (nonatomic, strong) YFRequestAdModel *ad;
/// 应用信息
@property (nonatomic, strong) YFRequestAppModel *app;
/// 设备信息
@property (nonatomic, strong) YFRequestDeviceModel *device;
/// 用户信息
@property (nonatomic, strong) YFRequestUserModel *user;
/// 最大超时时间
@property (nonatomic, assign) NSUInteger maxTimeoutMS;

@end


@interface YFRequestAdModel: NSObject<YFAdModel>
/// 广告位id
@property (nonatomic, copy) NSString *adId;
/// 出价底价,不填默认为1 单位：分
@property (nonatomic, assign) NSUInteger bidfloor;
/// 广告类型
@property (nonatomic, assign) YFAdRequestAdType adtype;
/// 广告位宽度
@property (nonatomic, assign) NSUInteger width;
/// 广告位高度
@property (nonatomic, assign) NSUInteger height;

@end

@interface YFRequestAppModel: NSObject<YFAdModel>
/// 应用id
@property (nonatomic, copy) NSString *appId;
/// 应用名称
@property (nonatomic, copy) NSString *name;
/// 应用包名
@property (nonatomic, copy) NSString *bundle;
/// 应用版本
@property (nonatomic, copy) NSString *ver;
/// 苹果商店id
@property (nonatomic, copy) NSString *appstoreid;
/// 流量类型
@property (nonatomic, assign) YFAdRequestAppFlowType flowType;
/// SDK版本
@property (nonatomic, copy) NSString *sdkVer;

@end


@interface YFRequestDeviceModel : NSObject<YFAdModel>
/// 国家 'CN'仅支持CN
@property (nonatomic, copy) NSString *country;
/// 语言 zh-Hans-CN
@property (nonatomic, copy) NSString *language;
/// ipv4地址
@property (nonatomic, copy) NSString *ip;
/// ipv6地址
@property (nonatomic, copy) NSString *ipv6;
/// 纬度
@property (nonatomic, assign) NSNumber *lat;
/// 精度
@property (nonatomic, assign) NSNumber *lon;
/// 坐标类型
@property (nonatomic, assign) YFAdRequestDeviceGeoType geotype;
/// IMEI号
@property (nonatomic, copy) NSString *imei;
/// 广信通id
@property (nonatomic, copy) NSArray<YFRequestDeviceDbid *> *dbIds;
/// open_u_uid
@property (nonatomic, copy) NSString *openUeid;
/// idfv
@property (nonatomic, copy) NSString *idfv;
@property (nonatomic, copy) NSString *idfa;
/// 屏幕每英寸像素数目,eg:300, 256
@property (nonatomic, assign) NSUInteger ppi;
/// 设备密度
@property (nonatomic, copy) NSString *densit;
/// 系统 ANDROID or IOS
@property (nonatomic, copy) NSString *os;
/// 操作系统三段式或两段式版本号
@property (nonatomic, copy) NSString *osv;
/// 设备MAC地址
@property (nonatomic, copy) NSString *mac;
/// 设备电量 0-100
@property (nonatomic, assign) NSUInteger batterylevel;
/// 设备类型
@property (nonatomic, assign) YFAdRequestDeviceType type;
/// 品牌
@property (nonatomic, copy) NSString *brand;
/// 设备型号
@property (nonatomic, copy) NSString *model;
/// 设备屏幕宽度
@property (nonatomic, assign) NSUInteger width;
/// 设备屏幕高度
@property (nonatomic, assign) NSUInteger height;
/// 移动设备 imsi。如果imsi取不到值，中国移动：传 46000 中国联通：传46001中国电信：传46003
@property (nonatomic, assign) NSInteger imsi;
/// 网络运营商代码：46000
@property (nonatomic, copy) NSString *carrier;
/// 网络类型
@property (nonatomic, assign) YFAdRequestDeviceNetworkType network;
/// UA
@property (nonatomic, copy) NSString *ua;
/// 设备方向
@property (nonatomic, assign) YFAdRequestDeviceOrientationType orientation;
/// 应用商店版本号
@property (nonatomic, copy) NSString *appstorever;
/// 系统启动标识
@property (nonatomic, copy) NSString *bootmark;
/// 系统更新标识
@property (nonatomic, copy) NSString *updatemark;
/// 设备号
@property (nonatomic, copy) NSString *hardwaremachine;
/// 系统更新时间
@property (nonatomic, copy) NSString *sysupdatetime;
/// 设备初始化时间
@property (nonatomic, copy) NSString *sysinittime;
/// 设备启动时间
@property (nonatomic, copy) NSString *startuptime;
/// 系统编译时间
@property (nonatomic, copy) NSString *syscmptime;
/// 已安装列表
@property (nonatomic, copy) NSString *installedapps;
/// cpu核数
@property (nonatomic, assign) NSUInteger cpunum;
/// 设备名称
@property (nonatomic, copy) NSString *name;
/// 屏幕尺寸 4.7
@property (nonatomic, assign) NSNumber *screensize;
/// 设备内存
@property (nonatomic, assign) NSInteger memtotal;
/// 总存储空间
@property (nonatomic, assign) NSInteger disktotal;
/// 时区
@property (nonatomic, copy) NSString *timezone;
/// 拼多多id
@property (nonatomic, copy) NSString *paid;

@end

@interface YFRequestUserModel : NSObject<YFAdModel>
/// 出生年份
@property (nonatomic, assign) NSUInteger yob;
/// 性别
@property (nonatomic, assign) NSUInteger gender;

@end

/// 广信通id
@interface YFRequestDeviceDbid: NSObject<YFAdModel>

@property (nonatomic, copy) NSString *dbId;
@property (nonatomic, copy) NSString *dbIdVer;

@end



NS_ASSUME_NONNULL_END
