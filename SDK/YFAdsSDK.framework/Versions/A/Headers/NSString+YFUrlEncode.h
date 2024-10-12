//
//  NSString+YFUrlEncode.h
//  DSPSDK
//
//  Created by 麻明康 on 2023/7/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (YFUrlEncode)
-(NSString *)URLEncodedString;
-(NSString *)URLDecodedString;
@end

NS_ASSUME_NONNULL_END
