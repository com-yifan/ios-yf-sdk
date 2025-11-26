//
//  YFAdUtils.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFSplashEnum.h>
#import <YFAdsSDK/YFMaterialMeta.h>
#import <YFAdsSDK/YFAdReportModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdUtils : NSObject

/// 工具类对象
+ (instancetype)shareInstance;
/// 获取当前网络状态
- (NSInteger)getNetworkType;
/// 获取当前网络状态
- (NSInteger)getAdxNetworkType;

+ (UIWindow *)getCurrentWindow;
+ (UIWindow *)getCurrentWindow_New;

/// 获取当前控制器
+ (UIViewController *)getCurrentVC;

/// 6.0.7.0获取当前控制器方法。
+ (UIViewController *)getCurrentVC_New;

/// 6.0.7.0获取当前带控制器的window方法。
+ (UIWindow *)getCurrentWindowWithRootVC_New;

/// 获取当前窗口根控制器
+ (UIViewController *)getCurrentRootVC;

/// 获取KeyWindow根控制器
+ (UIViewController *)getKeyRootVC;

/// 根据传入的控制器获取当前最合适用于展示广告的控制器（插屏）。可能直接返回，也可能获取当前控制器。
+ (UIViewController *)getAvaliableShowAdVCFromVC:(UIViewController *)viewController;

+ (UIWindow *)getKeyWindow;

+ (UIViewController *)getCurrentVCFrom:(UIViewController *)vc;
/// 获取当前时间戳
+ (double)getCurrentDate;
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
+ (BOOL)enableAdxCb;
+ (BOOL)enableAdnCb:(YFAdnType)adn;
/// 事件上报条数
+ (NSInteger)eventReportNum;
// 设置关闭按钮
+ (CGSize)getCloseSizeByType:(NSInteger)type;
// 设置倒计时关闭
+ (CGSize)getCountCloseSizeByType:(NSInteger)type;

+ (CGSize)getNewCountCloseSizeByType:(NSInteger)type;
// 设置跳过倒计时按钮
+ (CGSize)getJumpSizeByType:(YFSplashState)type;

// 设置可点区域
+ (UIView *)setHotAreaView:(UIView *)superView containerSize:(CGSize)size type:(NSInteger)type;

+ (UIView *)setYFHotAreaView:(UIView *)superView containerSize:(CGSize)size type:(NSInteger)type;

// 设置插屏大小
+ (CGSize)getInsertSizeByType:(NSInteger)type;

/// 插屏2.0尺寸取整
+ (CGSize)getInsertRoundSizeByType:(NSInteger)type;

+ (CGSize)getNewInsertSizeByType:(NSInteger)type;

+ (CGSize)getIconSizeByType:(NSInteger)type;

+ (CGSize)getNewCloseSizeByType:(NSInteger)type;

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
+ (NSString *)getBootTime;
// 系统更新标识
+ (NSString *)getUpdateMark;
// 缩放比
+ (float)scale;
/// 时间是否过期
+ (BOOL)isTimeValid:(YFAdEventModel *)event;
/// 创建视图抖动效果
+ (void)shakeAnimationForView:(UIView *)view;

/// 是否配置了开启京东检测
@property (nonatomic) BOOL jdTrackOpen;
///  UA
/// 是否需要过滤京东广告
+ (BOOL)needFilterJdAd;

+ (NSString *)getUserAgent;

+ (void)setUserAgent;

+ (NSString *)yfEncodeURIComponent:(NSString *)urlStr;

/// 获取当前时间：精度 天
+ (NSString *)getCurrentDay;

///. 获取当前时间：精度 小时
+ (NSString *)getCurrentHour;

/// 获取当前时间：精度 秒
+ (NSString *)getCurrentTime;
/// 是否iPad
+ (BOOL)isiPad;
/// 设备是否全屏
+ (BOOL)isDeviceFullScreen;

/// 当前时间增加minuteOffset分钟
/// @param minuteOffset  增加的分钟数，为负数则为减少
+(NSString *)getCurrentTimeMinuteOffset:(NSInteger)minuteOffset;

/// 判断当前时间是否大于禁止请求的时间
/// - `NSOrderedAscending`: A小于B
/// - `NSOrderedSame`: A 等于 B
/// - `NSOrderedDescending`: A 大于 B
/// @param timeA 时间A
/// @param timeB 时间B
+(NSComparisonResult)compareTimeA:(NSString*)timeA withTimeB:(NSString*)timeB;
@end

NS_ASSUME_NONNULL_END
