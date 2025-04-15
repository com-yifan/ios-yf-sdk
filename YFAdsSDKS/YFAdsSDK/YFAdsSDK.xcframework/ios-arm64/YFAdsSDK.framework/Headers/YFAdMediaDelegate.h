//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//



#import <YFAdsSDK/YFAdBaseDelegate.h>
@class YFAdMedia;

@protocol YFAdMediaDelegate <YFAdBaseDelegate>
@optional

/// 自渲染广告曝光
- (void)mediaAdExposure:(YFAdMedia *)mediaAd;

/// 自渲染广告渲染成功
- (void)mediaAdRenderSuccess:(YFAdMedia *)mediaAd;

/// 自渲染广告渲染失败
- (void)mediaAdRenderFail:(YFAdMedia *)mediaAd;

/// 自渲染广告点击
- (void)mediaAdDidClick:(YFAdMedia *)mediaAd;

/// 自渲染广告视频缓存失败
- (void)mediaAdVideoCacheFail:(YFAdMedia *)mediaAd error:(NSError *)error;

/// 自渲染广告视频暂停
- (void)mediaAdVideoPause:(YFAdMedia *)mediaAd;

/// 自渲染广告视频开始播放
- (void)mediaAdVideoStartPlay:(YFAdMedia *)mediaAd;

/// 自渲染广告播放完成
- (void)mediaAdVideoPlayFinished:(YFAdMedia *)mediaAd;

/// 自渲染广告播放进度，单位:s，因时间单位问题，可能会出现当前时间单位内重复回调问题
- (void)mediaAdVideoPlayProgress:(int)progress;


@end


