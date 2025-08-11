//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdConst.h>
#import <YFAdsSDK/YFAdReportModel.h>
#import <YFAdsSDK/YFAdUtils.h>
#import <YFAdsSDK/YFPrivateKit.h>
#import <YFAdsSDK/YFAdBaseAdapter.h>
#import <YFAdsSDK/YFBiddingAdInfo.h>

NS_ASSUME_NONNULL_BEGIN
/// 广告位基类
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

/// 是否已经超时请求
@property (nonatomic, assign) BOOL isRequestTimeout;
/// 是否底价过滤(返回填充但是底价过滤了)
@property (nonatomic, assign) BOOL isFloorPriceFilter;


- (instancetype)initWithSupplier:(id)supplier adspot:(id)adspot;

- (void)setAdTimeout:(NSTimeInterval)interval block:(dispatch_block_t)block;

- (void)supplierStateLoad;

- (void)loadAd;

- (void)loadAdSuccess:(YFAdEventModel *)supplier adapter:(YFAdBaseAdapter *)adapter ecpm:(NSInteger)ecpm;

- (void)loadAdFail:(YFAdEventModel *)supplier adapter:(YFAdBaseAdapter *)adapter error:(NSError *)error;

/// 流量填充
- (void)loadAllAdSucceed;

- (void)showAd;

- (void)showAdFromViewController:(UIViewController *)viewController;

- (void)removeAd;

- (void)deallocAdapter;

- (void)cancelDelay;

- (void)logWithTag:(NSString *)tag;

- (BOOL)isValid;

- (void)removeCustomRenderAd;
/// 自渲染竞价广告信息
- (nullable YFBiddingAdInfo *)biddingAdInfo;
/// 竞价成功
- (void)biddingWinWitnSecondWinner:(YFAdBaseAdPosition *)secondWinner;
/// 竞价失败
- (void)biddingFailWithWinner:(YFAdBaseAdPosition *)winner withSecondWinner:(YFAdBaseAdPosition *)secondWinner;

- (void)resetVC:(UIViewController*)VC;
@end

NS_ASSUME_NONNULL_END
