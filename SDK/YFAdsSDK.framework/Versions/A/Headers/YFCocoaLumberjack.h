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

/**
 * Welcome to CocoaLumberjack!
 *
 * The project page has a wealth of documentation if you have any questions.
 * https://github.com/CocoaLumberjack/CocoaLumberjack
 *
 * If you're new to the project you may wish to read "Getting Started" at:
 * Documentation/GettingStarted.md
 *
 * Otherwise, here is a quick refresher.
 * There are three steps to using the macros:
 *
 * Step 1:
 * Import the header in your implementation or prefix file:
 *
 * #import "CocoaLumberjack.h>
 *
 * Step 2:
 * Define your logging level in your implementation file:
 *
 * // Log levels: off, error, warn, info, verbose
 * static const YFLogLevel YFLogLevel = YFLogLevelVerbose;
 *
 * Step 2 [3rd party frameworks]:
 *
 * Define your LOG_LEVEL_DEF to a different variable/function than YFLogLevel:
 *
 * // #undef LOG_LEVEL_DEF // Undefine first only if needed
 * #define LOG_LEVEL_DEF myLibLogLevel
 *
 * Define your logging level in your implementation file:
 *
 * // Log levels: off, error, warn, info, verbose
 * static const YFLogLevel myLibLogLevel = YFLogLevelVerbose;
 *
 * Step 3:
 * Replace your NSLog statements with YFLog statements according to the severity of the message.
 *
 * NSLog(@"Fatal error, no dohickey found!"); -> YFLogError(@"Fatal error, no dohickey found!");
 *
 * YFLog works exactly the same as NSLog.
 * This means you can pass it multiple variables just like NSLog.
 **/

#import <Foundation/Foundation.h>

//! Project version number for CocoaLumberjack.
FOUNDATION_EXPORT double CocoaLumberjackVersionNumber;

//! Project version string for CocoaLumberjack.
FOUNDATION_EXPORT const unsigned char CocoaLumberjackVersionString[];

// Disable legacy macros
#ifndef YF_LEGACY_MACROS
    #define YF_LEGACY_MACROS 0
#endif

// Core
#import "YFLog.h"

// Main macros
#import "YFLogMacros.h"
#import "YFAssertMacros.h"

// Capture ASL
#import "YFASLLogCapture.h"

// Loggers
#import "YFLoggerNames.h"

#import "YFASLLogger.h"
#import "YFFileLogger.h"
#import "YFOSLogger.h"

// Extensions
#import "YFContextFilterLogFormatter.h"
#import "YFContextFilterLogFormatter+Deprecated.h"
#import "YFDispatchQueueLogFormatter.h"
#import "YFMultiFormatter.h"
#import "YFFileLogger+Buffering.h"

// etc
#import "YFAbstractDatabaseLogger.h"
#import "YFLog+LOGV.h"
#import "YFLegacyMacros.h"
