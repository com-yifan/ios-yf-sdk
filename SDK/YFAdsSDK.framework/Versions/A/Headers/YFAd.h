//
//  YFAd.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/18.
//



#import <Foundation/Foundation.h>

#import "YFAdInteractionType.h"

NS_ASSUME_NONNULL_BEGIN

@protocol YFAdProtocol <NSObject>

@optional
@property (nonatomic, strong) NSObject *this_is_an_update_mark;
// 单位:分，只有视频资源下载成功后，这个才可能有值
@property(nonatomic, readonly) NSInteger ecpm;
/// 媒体用来获取部分信息的字典
@property(nonatomic, readonly) NSDictionary *mediaExtraInfo;

/**
 * @brief 设置竞价价格，单位（分）
 * @param ecpm 竞价价格
 */
- (void)setBidEcpm:(NSInteger)ecpm;

/**
 * @brief 设置竞价价格，单位（分）
 * @param ecpm              竞价价格
 * @param highestLossEcpm   最大竞价失败方出价
 */
- (void)setBidEcpm:(NSInteger)ecpm
   highestLossEcpm:(NSInteger)highestLossEcpm;

@end

@interface YFAd : NSObject <YFAdProtocol>

/// ad interaction type, avaliable after ad load
@property(nonatomic, assign, readonly) YFAdInteractionType interactionType;
/// ad material type, avaliable after ad load
@property(nonatomic, assign, readonly) YFAdMaterialType materialType;
/**
 server bidding load ad data
*/
- (void)loadAdDataWithResponse:(NSDictionary *)response;

@end

NS_ASSUME_NONNULL_END

