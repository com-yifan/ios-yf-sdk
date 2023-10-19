//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#ifndef FCAdRewardVideoProtocol_h
#define FCAdRewardVideoProtocol_h
#import "YFAdBaseDelegate.h"
@protocol YFAdRewardVideoDelegate <YFAdBaseDelegate>
@optional

/// 广告视频缓存完成
- (void)fcAdRewardVideoOnAdVideoCached;

/// 广告视频播放完成
- (void)fcAdRewardVideoAdDidPlayFinish;

/// 广告到达激励时间
- (void)fcAdRewardVideoAdDidRewardEffective;

@end

#endif
