//
//  ADXNativeMediaView.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/9/4.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFMaterialMeta.h>
#import <YFAdsSDK/ADXNativeAd.h>
NS_ASSUME_NONNULL_BEGIN
@class ADXNativeMediaView;
@protocol ADXNativeMediaViewDelegate <NSObject>

@optional

/**
 视频准备开始播放
 
 @param videoView self
 */
- (void)nativeVideoAdDidStartPlaying:(ADXNativeMediaView *)videoView;

/**
 视频暂停播放
 
 @param videoView self
 */
- (void)nativeVideoAdDidPause:(ADXNativeMediaView *)videoView;

/**
 视频重播
 
 @param videoView self
 */
- (void)nativeVideoAdDidReplay:(ADXNativeMediaView *)videoView;

/**
 视频播放完成

 @param videoView self
 */
- (void)nativeVideoAdDidComplete:(ADXNativeMediaView *)videoView;

/**
 视频播放失败

 @param videoView self
 */
- (void)nativeVideoAdDidFailed:(ADXNativeMediaView *)videoView;

/**
 视频首帧播放
 
 @param videoView self
 */
- (void)nativeVideoAdDidReadyForDisplay:(ADXNativeMediaView *)videoView;

/**
 视频播放进度单位
 
 @param videoView self
 @param progress 当前播放时间，单位毫秒
 */
- (void)nativeVideoAd:(ADXNativeMediaView* )videoView playProgress:(CGFloat)progress;

@end


@interface ADXNativeMediaView : UIView
//是否开启声音
@property (nonatomic, assign) BOOL videoMute;
///是否播放完成
@property (nonatomic, assign) BOOL playFinished;
// 代理
@property (nonatomic, weak) id<ADXNativeMediaViewDelegate> delegate;
/**
 初始化方法

 @param frame videoView尺寸
 @param object YFMaterialMeta
 @return ADXNativeMediaView
 */
- (instancetype)initWithFrame:(CGRect)frame andObject:(YFMaterialMeta *)object;

- (instancetype)initWithSupplier:(YFAdEventModel*)eventModel;

- (void)refreshData:(ADXNativeAd *)nativeAd;
// 暂停
- (void)pauseVideo;
// 恢复播放
- (void)resumeVideo;
/// 开始播放
- (void)startPlay;
/// 毫秒
- (CGFloat)currentPlayTime;

/// 跟踪曝光
- (void)trackImpression;

@end

NS_ASSUME_NONNULL_END
