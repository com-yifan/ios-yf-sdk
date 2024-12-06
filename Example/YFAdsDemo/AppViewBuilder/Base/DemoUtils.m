//
//  BayesUtils.m
//  advancelib
//
//  Created by allen on 2019/9/18.
//  Copyright © 2019 Bayescom. All rights reserved.
//


#import "DemoUtils.h"

@implementation DemoUtils

+ (void)showToast:(NSString *)text {
    [DemoUtils showToast:text inView:[UIApplication sharedApplication].windows.lastObject];
}

+ (void)showToast:(NSString *)text inView:(UIView *)superView {
    if (!superView) {
        return;
    }
    CGSize labelSize = [text sizeWithAttributes:@{NSFontAttributeName:[UIFont systemFontOfSize:20.f]}];
    UILabel *label = [[UILabel alloc] init];
    label.font = [UIFont systemFontOfSize:18.f];
    label.text = text;
    label.textAlignment = NSTextAlignmentCenter;
    label.layer.cornerRadius = labelSize.height/4;
    label.layer.masksToBounds = YES;
    label.backgroundColor = [UIColor colorWithRed:38/255.f green:187/255.f blue:251/255.f alpha:1.f];
    label.textColor = [UIColor whiteColor];
    label.frame = CGRectMake((superView.bounds.size.width - labelSize.width)/2, (superView.bounds.size.height-labelSize.height-100), labelSize.width, labelSize.height);
    [superView addSubview:label];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [label removeFromSuperview];
    });
}

+(UIViewController *)getCurrentVC{
    UIViewController *vc = [DemoUtils getCurrentWindow].rootViewController;
    UIViewController *currentShowingVC = [DemoUtils getCurrentVCFrom:vc];
    return currentShowingVC;
}

+(UIViewController *)getCurrentRootVC{
    UIViewController *vc = [DemoUtils getCurrentWindow].rootViewController;
    UIViewController *currentShowingVC = [DemoUtils getPresentedVCFrom:vc];
    return currentShowingVC;
}

+(UIViewController *)getKeyRootVC{
    return [DemoUtils getKeyWindow].rootViewController;
}

+(UIWindow *)getCurrentWindow {
    if([[UIApplication sharedApplication] respondsToSelector:@selector(windows)]&&[[UIApplication sharedApplication] windows].count){
        NSArray *windows = [UIApplication sharedApplication].windows;
        for (UIWindow *window in [windows reverseObjectEnumerator]) {
            if ([window isKindOfClass:[UIWindow  class]]&&window.isKeyWindow)
                return window;
        }
    }
    
    if([[[UIApplication sharedApplication] delegate] respondsToSelector:@selector(window)]&&[[[UIApplication sharedApplication] delegate] window]){
        return [[[UIApplication sharedApplication] delegate] window];
    }
    
    if (@available(iOS 13.0,*)) {
        NSSet<UIScene*>* connectedScenes = [UIApplication sharedApplication].connectedScenes;
        for (UIScene* scene in connectedScenes) {
            if (scene.activationState == UISceneActivationStateForegroundActive && [scene isKindOfClass:[UIWindowScene class]]) {
                UIWindowScene* windowScene = (UIWindowScene*)scene;
                for (UIWindow* window in windowScene.windows) {
                    if ([window isKindOfClass:[UIWindow  class]]&&window.isKeyWindow)
                        return window;
                }
            }
        }
        return [UIApplication sharedApplication].windows.lastObject;
    }
    return [UIApplication sharedApplication].keyWindow;
}

+ (UIWindow *)getKeyWindow {
    if([[[UIApplication sharedApplication] delegate] respondsToSelector:@selector(window)]&&[[[UIApplication sharedApplication] delegate] window]){
        return [[[UIApplication sharedApplication] delegate] window];
    }
    
    if (@available(iOS 13.0,*)) {
        NSArray *arr = [[[UIApplication sharedApplication] connectedScenes] allObjects];
        UIWindowScene *windowScene = (UIWindowScene *)arr[0];
        
        UIWindow *mainWindow = [windowScene valueForKeyPath:@"delegate.window"];
        if(mainWindow) return mainWindow;
        return [UIApplication sharedApplication].windows.firstObject;
    }
    
    return [UIApplication sharedApplication].keyWindow;
}

+(UIViewController *)getPresentedVCFrom:(UIViewController *)vc{
    if ([vc presentedViewController]) { //注要优先判断vc是否有弹出其他视图，如有则当前显示的视图肯定是在那上面
        // 当前视图是被presented出来的
        UIViewController *nextRootVC = [vc presentedViewController];
        vc = [DemoUtils getPresentedVCFrom:nextRootVC];
    }
    return vc;
}


//注意考虑几种特殊情况：①A present B, B present C，参数vc为A时候的情况
/* 完整的描述请参见文件头部 */
+(UIViewController *)getCurrentVCFrom:(UIViewController *)vc{
    //方法1：递归方法 Recursive method
    UIViewController *currentShowingVC;
    if ([vc presentedViewController]) { //注要优先判断vc是否有弹出其他视图，如有则当前显示的视图肯定是在那上面
        // 当前视图是被presented出来的
        UIViewController *nextRootVC = [vc presentedViewController];
        currentShowingVC = [DemoUtils getCurrentVCFrom:nextRootVC];
        
    } else if ([vc isKindOfClass:[UITabBarController class]]) {
        // 根视图为UITabBarController
        UIViewController *nextRootVC = [(UITabBarController *)vc selectedViewController];
        currentShowingVC = [DemoUtils getCurrentVCFrom:nextRootVC];

    } else if ([vc isKindOfClass:[UINavigationController class]]){
        // 根视图为UINavigationController
        UIViewController *nextRootVC = [(UINavigationController *)vc visibleViewController];
        currentShowingVC = [DemoUtils getCurrentVCFrom:nextRootVC];

    } else {
        // 根视图为非导航类
        currentShowingVC = vc;
    }
    
    return currentShowingVC;
}

/// 当前时间增加secondsOffset秒钟
/// @param secondsOffset  增加的分钟数，为负数则为减少
+(NSString *)getCurrentTimeSecondsOffset:(NSInteger)secondsOffset
{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateStyle:NSDateFormatterMediumStyle];
    [formatter setTimeStyle:NSDateFormatterShortStyle];
    [formatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"]; // ----------设置你想要的格式,hh与HH的区别:分别表示12小时制,24小时制
    //设置时区,这个对于时间的处理有时很重要
    NSTimeZone* timeZone = [NSTimeZone timeZoneWithName:@"Asia/Beijing"];
    [formatter setTimeZone:timeZone];
    
    NSDate *datenow = [NSDate date];
    NSCalendar *calendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    NSDateComponents *components = [[NSDateComponents alloc] init];
    NSUInteger unitFlags = NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay | NSCalendarUnitHour | NSCalendarUnitMinute | NSCalendarUnitSecond;
    components = [calendar components:unitFlags fromDate:datenow];
    [components setSecond:([components second]+secondsOffset)];
    NSDate *resultDate = [calendar dateFromComponents:components];
    return [formatter stringFromDate:resultDate];
}

/// 判断A时间是否大于B的时间
/// @return 默认返回NSOrderedAscending（A小于B）；NSOrderedSame（A等于B）；NSOrderedDescending（A大于B）；
/// @param timeA 时间A
/// @param timeB 时间B
+(NSComparisonResult)compareTimeA:(NSString*)timeA withTimeB:(NSString*)timeB{
    NSComparisonResult result = NSOrderedAscending;
    if (!timeA||!timeB) {
        return result;
    }
    
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateStyle:NSDateFormatterMediumStyle];
    [formatter setTimeStyle:NSDateFormatterShortStyle];
    [formatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"]; // ----------设置你想要的格式,hh与HH的区别:分别表示12小时制,24小时制
    //设置时区,这个对于时间的处理有时很重要
    NSTimeZone* timeZone = [NSTimeZone timeZoneWithName:@"Asia/Beijing"];
    [formatter setTimeZone:timeZone];
    
    NSDate*dt01 = [[NSDate alloc]init];
    NSDate*dt02 = [[NSDate alloc]init];
    
    dt01 = [formatter dateFromString:timeA];
    dt02 = [formatter dateFromString:timeB];
    
    return [dt01 compare:dt02];
}


//获取时间戳（字符串）
+ (NSString *)getTimestampSince1970{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateStyle:NSDateFormatterMediumStyle];
    [formatter setTimeStyle:NSDateFormatterShortStyle];
    [formatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"]; // ----------设置你想要的格式,hh与HH的区别:分别表示12小时制,24小时制
    //设置时区,这个对于时间的处理有时很重要
    NSTimeZone* timeZone = [NSTimeZone timeZoneWithName:@"Asia/Beijing"];
    [formatter setTimeZone:timeZone];
    
    NSDate *datenow = [NSDate date];
    return [formatter stringFromDate:datenow];
}

@end
