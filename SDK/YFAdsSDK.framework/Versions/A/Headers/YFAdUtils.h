//
//  YFAdUtils.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>
#import "YFSplashEnum.h"
#import "YFMaterialMeta.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFAdUtils : NSObject

/// 工具类对象
+ (instancetype)shareInstance;
/// 获取当前网络状态
- (NSInteger)getNetworkType;
/// 获取当前网络状态
- (NSInteger)getAdxNetworkType;
/// 获取当前时间戳
+ (double)getCurrentDate;
/// 获取IDFA 或者 UUID
+ (NSString *)getIDFAORUUID;
/// IDFA
+ (NSString *)getIDFA;
/// DeviceID
+ (NSString *)getDeviceID;
/// UUID
+ (NSString *)uuidString;

+ (NSString *)getPhoneIP;

+ (void)setPhoneIP:(NSString *)ip;

+ (NSString *)getEKey;

+ (void)setEKey:(NSString *)key;

+ (NSString *)getYFECPMWith:(NSString *)key;

+ (void)setYFECPM:(NSString *)key value:(NSString *)value;

+ (UIColor *)colorWithHexString:(NSString *)hexString;
/// 图片地址
+ (UIImage *)getImageURLWithName:(NSString *)imageName;

+ (UIViewController *)getCurrentViewController;

+ (nullable NSDictionary *)getConfDataWith:(NSString *)key;

+ (void)setConfDataWith:(NSString *)key data:(NSString *)jsonData;

// 设置关闭按钮
+ (CGSize)getCloseSizeByType:(NSInteger)type;
// 设置倒计时关闭
+ (CGSize)getCountCloseSizeByType:(NSInteger)type;
// 设置跳过倒计时按钮
+ (CGSize)getJumpSizeByType:(YFSplashState)type;

// 设置可点区域
+ (UIView *)setHotAreaView:(UIView *)superView containerSize:(CGSize)size type:(NSInteger)type;

+ (UIView *)setYFHotAreaView:(UIView *)superView containerSize:(CGSize)size type:(NSInteger)type;

// 设置插屏大小
+ (CGSize)getInsertSizeByType:(NSInteger)type;

+ (float)getScaleByType:(NSInteger)type;

+ (BOOL)getHiddenType:(NSInteger)type;

+ (BOOL)getVideoMuteType:(NSInteger)type;

+ (BOOL)suppportClickStyle:(NSInteger)is;

+ (BOOL)suppportSwipStyle:(NSInteger)is;

+ (NSDictionary*)getJsonData:(NSString *)fileName fileType:(NSString *)fileType;

+ (NSString*)getDeviceModel;

+ (NSInteger)randomNumber;

+ (void)toSaveDownTimer:(NSString*)time key:(NSString *)key;
+ (NSString *)toGetDownTimerKey:(NSString*)key;
+ (void)toRemoveDownTimerKey:(NSString*)key;
+ (CGFloat)getWidthWithTitle:(NSString *)title font:(UIFont *)font;
+ (NSURL *)toSartVideoDownload:(NSString*)videoUrl;
+ (BOOL)isNullToString:(id)string;
+ (BOOL)isViewExistInWindow:(UIViewController *)viewController;
// 系统启动时间
+ (NSString *)bootTimeInSec;
// 系统更新时间
+ (NSString *)getSysUpdate;
// 获取设备初始化时间
+ (NSString *)getSystemInitTime;
// boot 时间
+(NSString *)getBootTime;
// 系统更新标识
+(NSString *)getUpdateMark;



@end

NS_ASSUME_NONNULL_END
