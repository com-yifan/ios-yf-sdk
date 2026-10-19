//
//  YFAppENVInfo.h
//  YFAdsSDK_Example
//
//  Created by 麻明康 on 2024/8/21.
//  Copyright © 2024 Cheng455153666. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, YF_AppStatus){
    YF_AppStatus_ConfigIncomplete, //  媒体未配置LSApplicationQueriesSchemes
    YF_AppStatus_NotInstalled, //  未安装
    YF_AppStatus_Installed, //  已未安装
};


typedef NSString *YF_Scheme NS_STRING_ENUM;
//FOUNDATION_EXPORT NSString * const YF_Scheme_JD;
FOUNDATION_EXPORT NSString * const YF_Scheme_Taptap;
FOUNDATION_EXPORT NSString * const YF_Scheme_Taobao;
FOUNDATION_EXPORT NSString * const YF_Scheme_Cydia;
FOUNDATION_EXPORT NSString * const YF_Scheme_Meituan;
FOUNDATION_EXPORT NSString * const YF_Scheme_Pinduoduo;
FOUNDATION_EXPORT NSString * const YF_Scheme_Weixin;
FOUNDATION_EXPORT NSString * const YF_Scheme_Douyin;
FOUNDATION_EXPORT NSString * const YF_Scheme_Zhifubao;

/// APP环境监测
@interface YFAppENVInfo : NSObject

/// 返回app安装状态
/// - Parameter scheme: app的urlscheme，可以使用YF_Scheme也可传入自定义字符串
+ (YF_AppStatus)getAppStatus:(nonnull YF_Scheme)scheme;
+ (void)logNeededAppStatus;
+ (NSArray *)getInstalledAppListArray;
+ (YF_AppStatus)getAppStatusByBundleName:(nonnull NSString *)bundleName;

@end

NS_ASSUME_NONNULL_END
