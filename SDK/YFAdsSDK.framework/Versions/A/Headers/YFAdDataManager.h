//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdDataManager : NSObject
/// 数据管理对象
+ (instancetype)shareInstance;
/// 获取广告位数据
- (void)getAdsWithId:(NSString *)adID success:(void(^)(id))success fail:(void(^)(id))fail;
/// 上报数据
-(void)report:(NSArray *)events success:(void(^)(id))success fail:(void(^)(id))fail;

@end

NS_ASSUME_NONNULL_END
