//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

///  系统 10000  开屏 20000  横幅 30000  全屏视频 40000  信息流 50000 激励视频 60000  插屏 70000
///
///   穿上甲 1 快手  2  百度 3   优量汇 4    亿帆 5  京东 9
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
    YFAdErrorCode_115    = 115,
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
    
    YFAdErrorCode_13001  = 13001,
    YFAdErrorCode_13002  = 13002,
    YFAdErrorCode_13003  = 13003,
    
    //京东
    YFAdErrorCode_19001  = 19001,
    YFAdErrorCode_19002  = 19002,
    
    //亿帆
    YFAdErrorCode_15001  = 15001,
    YFAdErrorCode_15002  = 15002,
    
   
    //穿山甲
    YFCSJErrorCode_11001 = 11001,
    YFCSJErrorCode_11002 = 11002,
    YFCSJErrorCode_11003 = 11003,
    YFCSJErrorCode_11004 = 11004,
    YFCSJErrorCode_11005 = 11005,
    YFCSJErrorCode_11006 = 11006,
    YFCSJErrorCode_11007 = 11007,
    
    //优量汇
    YFGDTErrorCode_41001 = 41001,
    YFGDTErrorCode_41002 = 41002,
    YFGDTErrorCode_41003 = 41003,
    YFGDTErrorCode_41004 = 41004,
    YFGDTErrorCode_41005 = 41005,
    YFGDTErrorCode_41006 = 41006,
    YFGDTErrorCode_41007 = 41007,
    
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
