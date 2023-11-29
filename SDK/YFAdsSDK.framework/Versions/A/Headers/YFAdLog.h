//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "YFAdSdkSetting.h"

@class YFAdLog;

#ifdef DEBUG
# define YFLog(fmt, ...) NSLog((@"[%s]" "[line:%d] " fmt), __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
# define YFLog(...);
#endif

#define EAD_LEVEL_FATAL_LOG(format,...)  [YFAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:YFAdLogLevel_Fatal]

#define EAD_LEVEL_ERROR_LOG(format,...)  [YFAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:YFAdLogLevel_Error]

#define EAD_LEVEL_WARING_LOG(format,...)  [YFAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:YFAdLogLevel_Warning]

#define EAD_LEVEL_INFO_LOG(format,...)  [YFAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:YFAdLogLevel_Info]

#define EAD_LEVEL_DEBUG_LOG(format,...)  [YFAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:YFAdLogLevel_Debug]

//#ifdef DEBUG
//#define GCLog(fmt, ...) NSLog((fmt), ##__VA_ARGS__);
//#else
//#define GCLog(...);


#define YFAdLog(format,...)  [YFAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__]]

#define FCAdLogJSONData(data)  [YFAdLog logJsonData:data]

NS_ASSUME_NONNULL_BEGIN


@interface YFAdLog : NSObject

// 日志输出方法
+ (void)customLogWithFunction:(const char *)function lineNumber:(int)lineNumber formatString:(NSString *)formatString level:(YFAdLogLevel)level;

+ (void)customLogWithFunction:(const char *)function lineNumber:(int)lineNumber formatString:(NSString *)formatString;

// 记录data类型数据
+ (void)logJsonData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
