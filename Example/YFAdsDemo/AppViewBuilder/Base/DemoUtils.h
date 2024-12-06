//
//  BayesUtils.h
//  advancelib
//
//  Created by allen on 2019/9/18.
//  Copyright © 2019 Bayescom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DemoUtils : NSObject
+ (void)showToast:(NSString *)text;
+ (void)showToast:(NSString *)text inView:(UIView *)superView;
//获取时间戳（毫秒）
+ (NSString *)getTimestampSince1970;

/// 当前时间增加minuteOffset秒钟
/// @param minuteOffset  增加的分钟数，为负数则为减少
+(NSString *)getCurrentTimeSecondsOffset:(NSInteger)secondsOffset;

/// 判断A时间是否大于B的时间
/// @return 默认返回NSOrderedAscending（A小于B）；NSOrderedSame（A等于B）；NSOrderedDescending（A大于B）；
/// @param timeA 时间A
/// @param timeB 时间B
+(NSComparisonResult)compareTimeA:(NSString*)timeA withTimeB:(NSString*)timeB;

+(UIWindow *)getCurrentWindow;

/// 获取当前控制器
+(UIViewController *)getCurrentVC;

/// 获取当前窗口根控制器
+(UIViewController *)getCurrentRootVC;

/// 获取KeyWindow根控制器
+(UIViewController *)getKeyRootVC;

+(UIWindow *)getKeyWindow;
@end

NS_ASSUME_NONNULL_END
