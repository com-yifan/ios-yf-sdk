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

#import <Foundation/Foundation.h>

// Disable legacy macros
#ifndef YF_LEGACY_MACROS
    #define YF_LEGACY_MACROS 0
#endif

#import <YFAdsSubstrate/YFLog.h>

NS_ASSUME_NONNULL_BEGIN

// Custom key set on messages sent to ASL
extern const char* const kYFASLKeyYFLog;

// Value set for kYFASLKeyYFLog
extern const char* const kYFASLYFLogValue;

/**
 * This class provides a logger for the Apple System Log facility.
 *
 * As described in the "Getting Started" page,
 * the traditional NSLog() function directs its output to two places:
 *
 * - Apple System Log
 * - StdErr (if stderr is a TTY) so log statements show up in Xcode console
 *
 * To duplicate NSLog() functionality you can simply add this logger and a tty logger.
 * However, if you instead choose to use file logging (for faster performance),
 * you may choose to use a file logger and a tty logger.
 **/
API_DEPRECATED("Use YFOSLogger instead", macosx(10.4,10.12), ios(2.0,10.0), watchos(2.0,3.0), tvos(9.0,10.0))
@interface YFASLLogger : YFAbstractLogger <YFLogger>

/**
 *  Singleton method
 *
 *  @return the shared instance
 */
@property (nonatomic, class, readonly, strong) YFASLLogger *sharedInstance;

// Inherited from YFAbstractLogger

// - (id <YFLogFormatter>)logFormatter;
// - (void)setLogFormatter:(id <YFLogFormatter>)formatter;

@end

NS_ASSUME_NONNULL_END
