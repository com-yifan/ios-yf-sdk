//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <Foundation/Foundation.h>


@class YFTouchLocModel;

@interface YFAdxDataManager : NSObject

+ (instancetype)shareInstance;

/// 获取ADX广告位数据
- (void)getAdxWithId:(NSString *)adID success:(void (^)(id))success fail:(void (^)(id))fail;


///上报事件，非点击事件touchModel传nil
- (void)reportEventWithUrl:(NSString *)reportUrl touchModel:(nullable YFTouchLocModel *)touchModel;


@end


