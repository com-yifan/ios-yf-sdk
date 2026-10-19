//
//  YFRewardedVideoModel.h
//  YFAdsSDK
//
//  Created by Erik on 2026/2/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFRewardedVideoModel : NSObject

@property (nonatomic, copy) NSString *userId;

@property (nonatomic, assign) NSInteger rewardCount;

@property (nonatomic, copy) NSString *rewardName;
/// 额外信息 json
@property (nonatomic, copy) NSString *extra;

@end

NS_ASSUME_NONNULL_END
