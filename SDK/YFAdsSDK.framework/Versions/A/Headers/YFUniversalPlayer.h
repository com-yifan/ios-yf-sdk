//
//  YFSplashPlayView.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/23.
//

#import <UIKit/UIKit.h>
#import "YFPlayer.h"
#import "YFAVPlayerManager.h"
#import "YFAVPlayerManager.h"
#import "YFPlayerControlView.h"
#import "YFPlayerControlView.h"

@class YFUniversalPlayer;
NS_ASSUME_NONNULL_BEGIN

@protocol YFUniversalDelegate <NSObject>
@optional
/**
 * splash ad request done
 * 请求完成
 */
- (void)yfplayerPlayFailederror:(id)error;

- (void)yfplayerDidToEnd;

- (void)yfplayerReadyToPlay:(NSURL *)assetURL;

- (void)yfplayerPrepareToPlay:(NSURL *)assetURL;

- (void)yfplayerPlayTimeChanged:(NSTimeInterval)currentTime duration:(NSTimeInterval)duration;

- (void)yfplayerBufferTimeChanged:(NSTimeInterval)bufferTime;

- (void)yfplayerPlayStateChanged:(YFPlayerPlaybackState)playState;

- (void)yfplayerLoadStateChanged:(YFPlayerLoadState)loadState;

- (void)yfpresentationSizeChanged:(CGSize)size;
@end

@interface YFUniversalPlayer : NSObject
+ (nonnull instancetype)sharedinstance;

@property(nonatomic, weak) id <YFUniversalDelegate> delegate;
@property(nonatomic, strong) YFAVPlayerManager *playerManager;
@property(nonatomic, strong) UIImage *bgImage;

- (void)toSetPlayUrl:(NSString *)playUrl;
//设置音量
- (void)toSetVolume:(float)volume;
//设置屏幕适配模式
- (void)toSetScreen:(YFPlayerScalingMode)playScalingModel;

- (instancetype)initView:(UIView *)view;

- (void)stop;

@end

NS_ASSUME_NONNULL_END
