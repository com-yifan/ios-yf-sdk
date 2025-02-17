//
//  YFAdMediaProtocol.h
//  YFAdsSDK
//
//  Created by Erik on 2025/1/8.
//
#import <UIKit/UIKit.h>

@class YFAdMedia;
@protocol YFAdMediaProtocol <NSObject>
@required
/// 注册可点击
- (void)registerContainer:(UIView *_Nonnull)containerView withClickableViews:(NSArray<UIView *> *_Nullable)clickableViews adMedia:(YFAdMedia *_Nonnull)media;
/// 取消注册
- (void)unregisterViewWithAdMedia:(YFAdMedia *_Nonnull)media;
/// 视频静音
- (void)muteEnable:(BOOL)enable adMedia:(YFAdMedia *_Nonnull)media;
/// 暂停视频
- (void)pauseVideoWithAdMedia:(YFAdMedia *_Nonnull)media;
/// 恢复播放
- (void)resumeVideoWithAdMedia:(YFAdMedia *_Nonnull)media;
/// 现在播放时长
- (CGFloat)currentPlayTimeWithAdMedia:(YFAdMedia *_Nonnull)media;
/// 更新视频播放器尺寸
- (void)updateVideoViewFrame:(CGRect)frame adMedia:(YFAdMedia *_Nonnull)media;
/// 检测视频播放视图状态
- (void)trackAdViewImpressionWithAdMedia:(YFAdMedia *_Nonnull)media;
@end
