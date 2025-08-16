//
//  YFRequestModel.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/19.
//

#import <Foundation/Foundation.h>

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
/// 当前版本已去除此字段获取
@property(nonatomic, copy) NSString *device_caid;
//Y（IOS 无 IDFA 时建议填写，安卓无需填写）拼多多广告 ID
@property(nonatomic, copy) NSString *device_paid;

//苹果设备唯一标识号; 安卓系统不必填写
@property(nonatomic, copy) NSString *device_openudid;

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

NS_ASSUME_NONNULL_END
