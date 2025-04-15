//
//  YFSourceDataTool.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2025/3/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 溯源工具
@interface YFSourceDataTool : NSObject
///// 溯源信息转String,支持传入多个model
//+(NSString *)stringFromSourceModel:(NSArray *)metaArray;
/// 上报溯源信息
+ (void)uploadTrace:(NSArray *)metaArray;
@end

NS_ASSUME_NONNULL_END
