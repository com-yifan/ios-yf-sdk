//
//  YFAdResponseModel.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>
@class YFAdEventModel;
NS_ASSUME_NONNULL_BEGIN

@interface YFAdRewardModel : NSObject

/// 广告位ID
@property (nonatomic, copy) NSString * adID;
/// 应用ID
@property (nonatomic, copy) NSString * appID;
/// 联盟广告位ID
@property (nonatomic, copy) NSString * adnAdID;
/// 联盟应用ID
@property (nonatomic, copy) NSString * adnAppID;
/// 广告位类型ID
@property (nonatomic, copy) NSString * adnID;
/// 激励视频ID
@property (nonatomic, copy) NSString * devID;
///  APP方用户自定义参数  json
@property (nonatomic, copy) NSString * extra;


///  用户ID
+(YFAdRewardModel *)eventToReward:(YFAdEventModel *)model;


@end

NS_ASSUME_NONNULL_END
