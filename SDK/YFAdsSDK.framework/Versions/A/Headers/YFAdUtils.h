//
//  YFAdUtils.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdUtils : NSObject
/// 工具类对象
+ (instancetype)shareInstance;
/// 获取当前网络状态
- (NSInteger)getNetworkType;
/// 获取当前时间戳
+ (double)getCurrentDate;
/// 获取IDFA 或者 UUID
+ (NSString *)getIDFAORUUID;
/// UUID
+ (NSString *)uuidString;

+ (UIColor *)colorWithHexString:(NSString *)hexString;
/// 图片地址
+(UIImage *)getImageURLWithName:(NSString *)imageName;

+ (UIViewController *)getCurrentViewController;

+ (nullable NSDictionary *)getConfDataWith:(NSString *)key;

+ (void)setConfDataWith:(NSString *)key data:(NSString *)jsonData;

+ (UIImage *)boxblurImage:(UIImage *)image withBlurNumber:(CGFloat)blur;

//绘制渐变色颜色的方法
+ (CAGradientLayer *)setGradualChangingColor:(UIView *)view fromColor:(NSString *)fromHexColorStr toColor:(NSString *)toHexColorStr;

// 设置关闭按钮
+ (CGSize)getCloseSizeByType:(NSInteger)type;
// 设置可点区域
+ (UIView *)setHotAreaView:(UIView *)superView containerSize:(CGSize)size type:(NSInteger)type;

// 设置插屏大小
+ (CGSize)getInsertSizeByType:(NSInteger)type;

+ (float)getScaleByType:(NSInteger)type;

+ (BOOL)getHiddenType:(NSInteger)type;

+ (BOOL)getVideoMuteType:(NSInteger)type;

@end

NS_ASSUME_NONNULL_END
