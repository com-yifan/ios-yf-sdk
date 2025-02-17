//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <Foundation/Foundation.h>

@class YFTouchLocModel;

NS_ASSUME_NONNULL_BEGIN

@interface YFAdxDataManager : NSObject

+ (instancetype)shareInstance;

/// 获取ADX广告位数据
- (void)getAdxWithId:(NSString *)adID ecpm:(NSUInteger)ecpm rID:(NSString *)rID success:(void (^)(id))success fail:(void (^)(id,NSError *))fail;

///上报事件，非点击事件touchModel传nil
- (void)reportEventWithUrl:(NSString *)reportUrl touchModel:(nullable YFTouchLocModel *)touchModel;




/// 获取ADX广告位数据，避免ua不一致
- (void)getAdxWithId:(NSString *)adID ecpm:(NSUInteger)ecpm rID:(NSString *)rID ua:(nullable NSString *)ua success:(void (^)(id))success fail:(void (^)(id,NSError *))fail;
///上报事件，非点击事件touchModel传nil，可配置ua，避免与getAdxWithId的ua不一致
- (void)reportEventWithUrl:(NSString *)reportUrl touchModel:(nullable YFTouchLocModel *)touchModel ua:(nullable NSString *)ua;

/////上传log日志文件
//- (void)uploadLogFile:(NSString *)filePath;

@end

NS_ASSUME_NONNULL_END


