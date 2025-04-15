//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <YFAdsSDK/YFAdBaseDelegate.h>
@protocol YFAdRewardVideoDelegate <YFAdBaseDelegate>
@optional

/// 广告视频缓存完成
- (void)fcAdRewardVideoOnAdVideoCached;

/// 广告视频缓存失败，部分联盟支持
- (void)fcAdRewardVideoOnAdVideoCachedFailWithError:(NSError *)error;

/// 广告展示失败，部分联盟支持
- (void)fcAdRewardVideoShowFailWithError:(NSError *)error;

/// 广告视频播放完成
- (void)fcAdRewardVideoAdDidPlayFinish;

/// 广告到达激励时间
- (void)fcAdRewardVideoAdDidRewardEffective;

@end

