//
//  YFDeviceInfo.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2025/2/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFDeviceInfo : NSObject
+ (nonnull instancetype)sharedInstance;

@property (nonatomic, strong) NSString *device_type;
/// 手机型号（"iPhone13,1"）
@property (nonatomic, strong) NSString *device_model;
/// 设备型号（"N841AP"）
@property (nonatomic, strong) NSString *device_machine;
@property (nonatomic, strong) NSString *device_ID;
@property (nonatomic, strong) NSString *device_IDFA;
/// adx的idfa，无兜底
@property (nonatomic, strong) NSString *adx_IDFA;
@property (nonatomic, strong) NSString *device_systemVersion;
@property (nonatomic, strong) NSString *device_imsi;

/// 运营商信息，16以下系统可以获取到。示例：46001;
@property (nonatomic, strong) NSString *device_carrier;

/// 磁盘可用空间，单位：字节。每次调用都会重新获取
@property(nonatomic, copy) NSNumber *device_disk_available;

/// 磁盘总空间，单位：字节， 如“250685575168” (iOS 请求必须填)
@property(nonatomic, strong) NSNumber *device_disk_total;

/// 系统可用内存空间，单位：字节。每次调用都会重新获取
@property(nonatomic, strong) NSNumber *device_mem_available;

/// 系统总内存空间，单位：字节， 如“17179869184” ( iOS 请求必须填), 0表示发生错误无法正确获取
@property(nonatomic, strong) NSNumber *device_mem_total;

/// 设备名称
@property(nonatomic, strong) NSString *device_name;

/// 设备名称的 MD5 值，取小写 16 进制的结果，长度为 32 个字节，示例："e910dddb2748c36b47fcde5dd720eec1"  (iOS 请求必须填)
@property(nonatomic, copy) NSString *device_name_md5;

/// CPU 数⽬，示例: "4"(iOS 请求必须填)
@property(nonatomic, strong) NSNumber *device_cpu_num;

/// 屏幕尺寸 例:4.7 , 5.5 单位:英寸
@property(nonatomic) CGFloat device_screenSize;
/// 设备 ip v6地址；X:X:X:X:X:X:X:X(6段点分)，如ABCD:EF01:2345:6789:ABCD:EF01:2345:6789
@property(nonatomic, strong) NSString *device_ipv6;

/// 设备屏幕像素密度:286ppi
@property(nonatomic) NSUInteger device_ppi;

/// 苹果设备型号，如iPhone 15 Pro Max，iPad Pro 11-inch (M4)
@property(nonatomic, strong) NSString *apple_model;

/// caid 数组 可能为空
@property (nonatomic, strong, nullable) NSArray <NSDictionary *>*caidInfo;


/// 设备启动时间
@property (nonatomic, assign) time_t bootSecTime;


@end

NS_ASSUME_NONNULL_END
