//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, YFAdErrorCode) {
    YFAdErrorCode_101    =    101,
    YFAdErrorCode_102    =    102,
    YFAdErrorCode_103    =    103,
    YFAdErrorCode_104    =    104,
    YFAdErrorCode_105    =    105,
    YFAdErrorCode_110    =    110,
    YFAdErrorCode_111    =    111,
    YFAdErrorCode_112    =    112,
    YFAdErrorCode_113    =    113,
    YFAdErrorCode_114    =    114,
    YFAdErrorCode_115    =    115,
    YFAdErrorCode_116    =    116
};

@interface YFAdError : NSObject

+ (instancetype)errorWithCode:(YFAdErrorCode)code;

+ ( instancetype)errorWithCode:(YFAdErrorCode)code obj:(nullable id)obj;

- (NSError *)toNSError;

@end

NS_ASSUME_NONNULL_END
