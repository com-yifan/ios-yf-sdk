//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "YFAdConst.h"
#import "YFAdReportModel.h"
#import "YFAdUtils.h"
#import "YFPrivateKit.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFAdBaseAdPosition : NSObject
/// 标记渠道
@property (nonatomic, assign) NSInteger tag;
/// 广告价值
@property (nonatomic, assign) double ecpm;
/// 是否填充
@property (nonatomic, assign) BOOL fill;
/// 填充层级
@property (nonatomic, assign) NSInteger index;
/// 失效时间
@property (nonatomic, assign) double time;
/// 缓存时间
@property (nonatomic, assign) NSInteger timeout;
/// 头部竞价
@property (nonatomic, assign) NSInteger headBidding;

- (instancetype)initWithSupplier:(id)supplier adspot:(id)adspot;

- (void)setAdTimeout:(NSTimeInterval)interval block:(dispatch_block_t)block;

- (void)supplierStateLoad;

- (void)loadAd;

- (void)showAd;

- (void)removeAd;

- (void)deallocAdapter;

- (void)cancelDelay;

- (void)logWithTag:(NSString *)tag;

@end

NS_ASSUME_NONNULL_END
