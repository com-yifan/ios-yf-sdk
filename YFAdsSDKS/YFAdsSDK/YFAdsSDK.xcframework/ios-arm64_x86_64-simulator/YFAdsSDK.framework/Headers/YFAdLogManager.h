//
//  YFAdLogManager.h
//  YFAdsSDK
//
//  Created by FC-0823 on 2023/12/1.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFCocoaLumberjack.h>

NS_ASSUME_NONNULL_BEGIN

//#define YF_LOG_ERROR(frmt, ...)   YFLogError((@"[%s]" "[line:%d] " frmt), __FUNCTION__, __LINE__, ##__VA_ARGS__)

// 自定义宏
//#define MY_ERROR_LOG(frmt, ...)       YFLogError(frmt, ##__VA_ARGS__)
//#define MY_WARING_LOG(frmt, ...)       YFLogWarn(frmt, ##__VA_ARGS__)
//#define MY_INFO_LOG(frmt, ...)       YFLogInfo(frmt, ##__VA_ARGS__)
//#define MY_DEBUG_LOG(frmt, ...)    YFLogDebug(frmt, ##__VA_ARGS__)
//#define MY_VERBOSE_LOG(frmt, ...)       YFLogVerbose(frmt, ##__VA_ARGS__)

//全局变量
static YFLogLevel yfLogLevel = YFLogLevelAll;

@interface YFAdLogManager : NSObject

+ (instancetype)sharedInstance;

///初始化logger
- (void)initLogger;

///去除控制台log
- (void)initLoggerWithoutOS;

///切换log等级
- (void)switchLogLevel:(YFLogLevel)logLevel;

///删除log文件
- (void)deleteLogFile;

///当前活跃的log文件路径
- (NSString *)currentFilePath;

@end

NS_ASSUME_NONNULL_END

