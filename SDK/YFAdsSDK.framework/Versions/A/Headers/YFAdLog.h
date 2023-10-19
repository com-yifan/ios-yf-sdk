//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "YFAdSdkConfig.h"

@class YFAdLog;



#define EAD_LEVEL_FATAL_LOG(format,...)  [FCAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:FCAdLogLevel_Fatal]

#define EAD_LEVEL_ERROR_LOG(format,...)  [YFAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:FCAdLogLevel_Error]

#define EAD_LEVEL_WARING_LOG(format,...)  [FCAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:FCAdLogLevel_Warning]

#define EAD_LEVEL_INFO_LOG(format,...)  [YFAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:FCAdLogLevel_Info]

#define EAD_LEVEL_DEBUG_LOG(format,...)  [FCAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:FCAdLogLevel_Debug]


#define YFAdLog(format,...)  [YFAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__]]

#define FCAdLogJSONData(data)  [YFAdLog logJsonData:data]

NS_ASSUME_NONNULL_BEGIN


@interface YFAdLog : NSObject

// 日志输出方法
+ (void)customLogWithFunction:(const char *)function lineNumber:(int)lineNumber formatString:(NSString *)formatString level:(FCAdLogLevel)level;

+ (void)customLogWithFunction:(const char *)function lineNumber:(int)lineNumber formatString:(NSString *)formatString;

// 记录data类型数据
+ (void)logJsonData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
