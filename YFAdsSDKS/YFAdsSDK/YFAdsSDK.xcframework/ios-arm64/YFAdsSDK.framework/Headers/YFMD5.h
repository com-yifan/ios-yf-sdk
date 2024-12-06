//
//  YFMD5.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/11/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFMD5 : NSObject
NSString * yfmd5 (NSString *string,...);
+ (NSString *)md5:(NSString *)string;
@end

NS_ASSUME_NONNULL_END
