//
//  AppDelegate.m
//  YFAdsSDK
//
//  Created by Cheng455153666 on 02/27/2020.
//  Copyright (c) 2020 Cheng455153666. All rights reserved.
//

#import "AppDelegate.h"
#import "YFEnvironmentManager.h"
// 帧率监测
//#import <KMCGeigerCounter/KMCGeigerCounter.h>
// DEBUG
//#import <STDebugConsole.h>
//#import <STDebugConsoleViewController.h>
//#import <JPFPSStatus.h>

#import "ViewController.h"
#import "ZYHSplashAdManager.h"
#include <mach/task.h>
#include <mach/mach.h>
#import <Bugly/Bugly.h>
//#ifdef DEBUG
//#endif

#import <YFAdsSDK/YFAdAESEncrypt.h>

#import <FLAnimatedImage/FLAnimatedImageView.h>
#import <KSUAdDebugTool/KSAdDebugToolCommon.h>


@interface AppDelegate ()
@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    
//   #ifdef DEBUG
//   [[DoraemonManager shareInstance] installWithPid:@"2fcb6a782f07793120c752262aa52ef4"];//productId为在“平台端操作指南”中申请的产品id
//   #endif
    
    // 获取当前进程的任务
         task_vm_info_data_t vmInfo;
         mach_msg_type_number_t count = TASK_VM_INFO_COUNT;
         kern_return_t kernelReturn = task_info(mach_task_self(), TASK_VM_INFO, (task_info_t)&vmInfo, &count);
         
         if(kernelReturn == KERN_SUCCESS) {
             // 打印内存使用情况
             NSLog(@"Virtual Memory: %llu bytes", (unsigned long long)vmInfo.phys_footprint);
         } else {
             NSLog(@"Error with task_info(): %s", mach_error_string(kernelReturn));
         }
    
    //在UIApplicationDidFinishLaunching时初始化开屏广告,做到对业务层无干扰,当然你也可以直接在AppDelegate didFinishLaunchingWithOptions方法中初始化
    [[[ZYHSplashAdManager alloc]init] initAdSDK];


    [BUAdTestMeasurementConfiguration configuration].debugMode = YES;
    // 快手测试工具
    [KSAdDebugToolCommon sharedInstance].useDebugTool = YES;
//    // 帧率监测
//    [KMCGeigerCounter sharedGeigerCounter].enabled = YES;

    // 请现在 plist 文件中配置 NSUserTrackingUsageDescription
    /*
     <key>NSUserTrackingUsageDescription</key>
     <string>该ID将用于向您推送个性化广告</string>
     */
    // 项目需要适配http
    
    /*
     <key>NSAppTransportSecurity</key>
     <dict>
     <key>NSAllowsArbitraryLoads</key>
     <true/>
     </dict>
     */
    // 调试阶段尽量用真机, 以便获取idfa, 如果获取不到idfa, 则打开idfa开关
    // iphone 打开idfa 开关的的过程:设置 -> 隐私 -> 跟踪 -> 允许App请求跟踪

    return YES;
}
- (NSMutableString*)safeUrlBase64ENcode:(NSString*)base64Str
{
    NSMutableString * safeBase64Str = [[NSMutableString alloc]initWithString:base64Str];
      safeBase64Str = (NSMutableString * )[safeBase64Str stringByReplacingOccurrencesOfString:@"+"withString:@"-"];
      safeBase64Str = (NSMutableString * )[safeBase64Str stringByReplacingOccurrencesOfString:@"/"withString:@"_"];
      safeBase64Str = (NSMutableString * )[safeBase64Str stringByReplacingOccurrencesOfString:@"="withString:@""];
    return safeBase64Str;
    
}

@end

