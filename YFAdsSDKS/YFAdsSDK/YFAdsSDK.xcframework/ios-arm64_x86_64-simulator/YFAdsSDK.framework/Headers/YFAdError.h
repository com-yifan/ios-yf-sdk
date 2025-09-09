//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

///  系统 10000  开屏 20000  横幅 30000  全屏视频 40000  信息流 50000 激励视频 60000  插屏 70000
///
///   穿上甲 1 快手  2  百度 3   优量汇 4    亿帆 5  京东 9  Gromore6 tanx 7
///
typedef NS_ENUM(NSUInteger, YFAdErrorCode) {
    YFAdErrorCode_101    = 101,
    YFAdErrorCode_102    = 102,
    YFAdErrorCode_103    = 103,
    YFAdErrorCode_104    = 104,
    YFAdErrorCode_105    = 105,
    YFAdErrorCode_110    = 110,
    YFAdErrorCode_111    = 111,
    YFAdErrorCode_112    = 112,
    YFAdErrorCode_113    = 113,
    YFAdErrorCode_114    = 114,
    YFAdErrorCode_116    = 116,
    
    
    YFAdErrorCode_10000  = 10000,
    YFAdErrorCode_10001  = 10001,
    YFAdErrorCode_10002  = 10002,
    YFAdErrorCode_10003  = 10003,
    YFAdErrorCode_10004  = 10004,
    YFAdErrorCode_10005  = 10005,
    YFAdErrorCode_10006  = 10006,
    YFAdErrorCode_10007  = 10007,
    YFAdErrorCode_10008  = 10008,
    YFAdErrorCode_10009  = 10009,
    YFAdErrorCode_10010  = 10010,
    YFAdErrorCode_10011  = 10011,
    YFAdErrorCode_10012  = 10012,
    YFAdErrorCode_10013  = 10013,
    YFAdErrorCode_10014  = 10014,
    YFAdErrorCode_10015  = 10015,

    //快手
    YFAdErrorCode_12001  = 12001,
    YFAdErrorCode_12002  = 12002,
    YFAdErrorCode_12003  = 12003,
    
    //百度
    YFAdErrorCode_13001  = 13001,
    YFAdErrorCode_13002  = 13002,
    YFAdErrorCode_13003  = 13003,
    YFAdErrorCode_13004  = 13004,
    
    //京东
    YFAdErrorCode_19001  = 19001,
    YFAdErrorCode_19002  = 19002,
    
    //亿帆
    YFAdErrorCode_15001  = 15001,
    YFAdErrorCode_15002  = 15002,
    YFAdErrorCode_15003  = 15003,
    YFAdErrorCode_15004  = 15004,
    YFAdErrorCode_15005  = 15005,
    YFAdErrorCode_15006  = 15006,
    YFAdErrorCode_15007  = 15007,

    //穿山甲
    YFAdErrorCode_11001 = 11001,
    YFAdErrorCode_11002 = 11002,
    YFAdErrorCode_11003 = 11003,
    YFAdErrorCode_11004 = 11004,
    YFAdErrorCode_11005 = 11005,
    YFAdErrorCode_11006 = 11006,
    YFAdErrorCode_11007 = 11007,
    
    //Gromore
    YFAdErrorCode_16001 = 16001,
    YFAdErrorCode_16002 = 16002,
    YFAdErrorCode_16003 = 16003,
    YFAdErrorCode_16004 = 16004,
    YFAdErrorCode_16005 = 16005,
    YFAdErrorCode_16006 = 16006,
    YFAdErrorCode_16007 = 16007,
    YFAdErrorCode_16008 = 16008,
    YFAdErrorCode_16009 = 16009,


    //优量汇
    YFAdErrorCode_14001 = 14001,
    YFAdErrorCode_14002 = 14002,
    YFAdErrorCode_14003 = 14003,
    
    // Tanx
    YFAdErrorCode_17001 = 17001,
    YFAdErrorCode_17002 = 17002,
    
    // AY
    YFAdErrorCode_18001 = 18001,
    
};

@interface YFAdError : NSObject

@property (nonatomic, assign) YFAdErrorCode code;
@property (nonatomic, copy) NSString *desc;
@property (nonatomic, strong) id obj;

+ (instancetype)errorWithCode:(YFAdErrorCode)code;

+ (instancetype)errorWithCode:(YFAdErrorCode)code obj:(nullable id)obj;

- (NSError *)toNSError;

@end

NS_ASSUME_NONNULL_END
