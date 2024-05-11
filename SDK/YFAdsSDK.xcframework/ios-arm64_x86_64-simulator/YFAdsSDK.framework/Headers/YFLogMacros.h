// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2023, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

// Disable legacy macros
#ifndef YF_LEGACY_MACROS
    #define YF_LEGACY_MACROS 0
#endif

#import "YFLog.h"

/**
 * The constant/variable/method responsible for controlling the current log level.
 **/
#ifndef LOG_LEVEL_DEF
    #define LOG_LEVEL_DEF yfLogLevel
#endif

/**
 * Whether async should be used by log messages, excluding error messages that are always sent sync.
 **/
#ifndef LOG_ASYNC_ENABLED
    #define LOG_ASYNC_ENABLED YES
#endif

/**
 * These are the two macros that all other macros below compile into.
 * These big multiline macros makes all the other macros easier to read.
 **/
#define LOG_MACRO(isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, ...) \
        [YFLog log : isAsynchronous                                     \
             level : lvl                                                \
              flag : flg                                                \
           context : ctx                                                \
              file : __FILE__                                           \
          function : fnct                                               \
              line : __LINE__                                           \
               tag : atag                                               \
            format : (frmt), ## __VA_ARGS__]

#define LOG_MACRO_TO_YFLog(YFLog, isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, ...) \
        [YFLog log : isAsynchronous                                     \
             level : lvl                                                \
              flag : flg                                                \
           context : ctx                                                \
              file : __FILE__                                           \
          function : fnct                                               \
              line : __LINE__                                           \
               tag : atag                                               \
            format : (frmt), ## __VA_ARGS__]

/**
 * Define version of the macro that only execute if the log level is above the threshold.
 * The compiled versions essentially look like this:
 *
 * if (logFlagForThisLogMsg & YFLogLevel) { execute log message }
 *
 * When LOG_LEVEL_DEF is defined as YFLogLevel.
 *
 * As shown further below, Lumberjack actually uses a bitmask as opposed to primitive log levels.
 * This allows for a great amount of flexibility and some pretty advanced fine grained logging techniques.
 *
 * Note that when compiler optimizations are enabled (as they are for your release builds),
 * the log messages above your logging threshold will automatically be compiled out.
 *
 * (If the compiler sees LOG_LEVEL_DEF/YFLogLevel declared as a constant, the compiler simply checks to see
 *  if the 'if' statement would execute, and if not it strips it from the binary.)
 *
 * We also define shorthand versions for asynchronous and synchronous logging.
 **/
#define LOG_MAYBE(async, lvl, flg, ctx, tag, fnct, frmt, ...) \
        do { if((lvl & flg) != 0) LOG_MACRO(async, lvl, flg, ctx, tag, fnct, frmt, ##__VA_ARGS__); } while(0)

#define LOG_MAYBE_TO_YFLog(YFLog, async, lvl, flg, ctx, tag, fnct, frmt, ...) \
        do { if((lvl & flg) != 0) LOG_MACRO_TO_YFLog(YFLog, async, lvl, flg, ctx, tag, fnct, frmt, ##__VA_ARGS__); } while(0)

/**
 * Ready to use log macros with no context or tag.
 **/
#define YFLogError(frmt, ...)   LOG_MAYBE(NO,                LOG_LEVEL_DEF, YFLogFlagError,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFLogWarn(frmt, ...)    LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFLogFlagWarning, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFLogInfo(frmt, ...)    LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFLogFlagInfo,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFLogDebug(frmt, ...)   LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFLogFlagDebug,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFLogVerbose(frmt, ...) LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define YFLogErrorToYFLog(YFLog, frmt, ...)   LOG_MAYBE_TO_YFLog(YFLog, NO,                LOG_LEVEL_DEF, YFLogFlagError,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFLogWarnToYFLog(YFLog, frmt, ...)    LOG_MAYBE_TO_YFLog(YFLog, LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFLogFlagWarning, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFLogInfoToYFLog(YFLog, frmt, ...)    LOG_MAYBE_TO_YFLog(YFLog, LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFLogFlagInfo,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFLogDebugToYFLog(YFLog, frmt, ...)   LOG_MAYBE_TO_YFLog(YFLog, LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFLogFlagDebug,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFLogVerboseToYFLog(YFLog, frmt, ...) LOG_MAYBE_TO_YFLog(YFLog, LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFLogFlagVerbose, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
