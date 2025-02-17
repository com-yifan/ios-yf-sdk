//
//  YFVideoView.h
//  YFAdsSDK
//
//  Created by Erik on 2025/1/10.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

typedef NS_ENUM(NSInteger, YFPlayerState) {
    YFPlayerStateInitial = 0,//初始化状态
    YFPlayerStateBuffering = 1,//缓冲中
    YFPlayerStatePlaying = 2,//播放中
    YFPlayerStatePaused = 3,//播放暂停
    YFPlayerStateStopped = 4,//播放停止
    YFPlayerStateError = 5,//播放出错
    YFPlayerStateFinish = 6,//播放完成
};

NS_ASSUME_NONNULL_BEGIN

@protocol YFVideoViewPlayerDelegate;

@interface YFVideoView : UIView

/**
 播放状态
 */
@property (nonatomic ,assign) YFPlayerState videoPlayState;

/**
 总时长，当准备播放回调时才能获取
 */
@property (nonatomic, assign) CGFloat totalDuration;

/**
 播放
 */
- (void)play;

/**
 暂停
 */
- (void)pause;

/**
 是否静音,返回当前是否为静音状态
 */
- (BOOL)setPlayOrMute;

/**
 设置播放视图frame,可以使用autolayout
 */
- (void)updateVideoFrame:(CGRect)newframe;

/**
 初始化player
 */
- (void)initPlayer;

/**
 重置player时间
 */
- (void)resetPlayerTime;

/**
 当前播放时间
 */
- (CGFloat)currentPlayerTime;

/**
 设置静音
 */
@property (nonatomic, assign) BOOL defaultPlayMute;

/**
 显示进度条,默认不展示
 */
@property (nonatomic, assign) BOOL showProgressView;

/**
 是否正在播放
 */
@property (nonatomic, assign, readonly) BOOL isPlaying;


- (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame  NS_UNAVAILABLE;
/**
 推荐初始化方法
 @prama frame 视图大小
 @prama defaultPlayMute 默认播放静音YES/非静音NO
 @prama videoUrlString 播放地址
 */
- (instancetype)initWithFrame:(CGRect)frame defaultPlayMute:(BOOL)defaultPlayMute videoUrlString:(NSString *)videoUrlString coverUrl:(NSString *)coverUrl endCardUlrString:(nullable NSString *)endCardUrlString delegate:(id<YFVideoViewPlayerDelegate>)videoDelegate;


@end

@protocol YFVideoViewPlayerDelegate <NSObject>

- (void)videoViewPlayerState:(YFPlayerState)videoPlayState withVideoView:(YFVideoView *)videoView withError:(NSError * _Nullable)error;

- (void)videoViewReadyToPlay:(YFVideoView *)videoView;

- (void)videoViewDidClick:(YFVideoView *)videoView withClickPoint:(CGPoint)clickPoint withScreenClickPoint:(CGPoint)screenClickPoint;

- (void)videoViewPlayerLifeTime:(NSUInteger)time videoDuration:(NSUInteger)duration withVideoView:(YFVideoView *)videoView;

- (void)videoViewCacheVideoFinish:(YFVideoView *)videoView;

- (void)videoViewCacheFail:(YFVideoView *)videoView withError:(NSError * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
