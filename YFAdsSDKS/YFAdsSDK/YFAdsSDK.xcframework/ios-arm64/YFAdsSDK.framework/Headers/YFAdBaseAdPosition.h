//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdConst.h>
#import <YFAdsSDK/YFAdReportModel.h>
#import <YFAdsSDK/YFAdUtils.h>
#import <YFAdsSDK/YFPrivateKit.h>
#import <YFAdsSDK/YFAdBaseAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdBaseAdPosition : NSObject
/// 标记渠道
@property (nonatomic, assign) NSInteger tag;
/// 广告价值
@property (nonatomic, assign) NSInteger ecpm;
/// 底价
@property (nonatomic, assign) NSInteger floorPrice;
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

@property (nonatomic, assign) BOOL isLayerTimeout;


- (instancetype)initWithSupplier:(id)supplier adspot:(id)adspot;

- (void)setAdTimeout:(NSTimeInterval)interval block:(dispatch_block_t)block;

- (void)supplierStateLoad;

- (void)loadAd;

- (void)loadAdSuccess:(YFAdEventModel *)supplier adapter:(YFAdBaseAdapter *)adapter ecpm:(NSInteger)ecpm;

- (void)loadAdFail:(YFAdEventModel *)supplier adapter:(YFAdBaseAdapter *)adapter error:(NSError *)error;

- (void)showAd;

- (void)removeAd;

- (void)deallocAdapter;

- (void)cancelDelay;

- (void)logWithTag:(NSString *)tag;

- (BOOL)isValid;

- (void)removeCustomRenderAd;


@end

NS_ASSUME_NONNULL_END
