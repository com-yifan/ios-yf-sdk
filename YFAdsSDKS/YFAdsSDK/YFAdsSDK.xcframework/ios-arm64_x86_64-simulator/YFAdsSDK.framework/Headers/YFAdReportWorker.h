//
//  YFAdReportWorker.h
//  YFAdsSDK
//
//  Created by Erik on 2026/1/26.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFMaterialMeta.h>
#import <YFAdsSDK/YFTouchReportView.h>
@class YFAdSubAdConfig;

NS_ASSUME_NONNULL_BEGIN

@interface YFAdReportWorker : NSObject

- (instancetype)initWithData:(YFMaterialMeta_new *)data;
/// 保存当前广告的配置快照，避免缓存复用或外部修改影响后续事件。
- (instancetype)initWithData:(YFMaterialMeta_new *)data subAdConfig:(nullable YFAdSubAdConfig *)subAdConfig;

/// 本地展示时机，不发送监测请求。
- (void)notifyPrimaryDisplay;

/// 上报dp唤起成功
- (void)reportDeeplinkSucceedWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// deeplink检测应用已安装
- (void)reportDeeplinkInstalledWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// deeplink检测应用未安装
- (void)reportDeeplinkUnInstalledWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// deepLink开始唤醒监测数组
- (void)reportDeeplinkStartWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// deeplink 唤醒失败
- (void)reportDeeplinkFailedWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 曝光监测地址数组（支持宏替换
- (void)reportExposureWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 点击监测地址数组（支持宏替换
- (void)reportClickWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 音/视频广告（播放开始时上报）；主广告配置曝光监测时，若先于曝光调用则延后上报一次。
/// 等待该开始事件的后续播放回调按原顺序补报，并更新曝光时间、尺寸及广告坐标。
- (void)reportPlayStartWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 音/视频广告（播放四分之一时上报
- (void)reportPlayOneQuarterWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 音/视频广告（播放一半时上报
- (void)reportPlayOneHalfWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 音/视频广告（播放75%时上报
- (void)reportPlayThreeQuarterWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 音/视频广告（用户点击暂停按钮时上报
- (void)reportPlayPauseWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 音/视频广告（被暂停或被停止之后，主动继续播放时上报）
- (void)reportPlayResumeWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 播放结束事件
- (void)reportPlayEndWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 音/视频广告（用户点击跳过按钮时上报）
- (void)reportPlaySkipWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 音/视频广告（用户主动关闭声音时上报）
- (void)reportPlayMuteWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 音/视频广告（用户主动打开声音时上报
- (void)reportPlayUnmuteWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 音/视频广告（关闭时上报
- (void)reportPlayCloseWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 视频广告（全屏播放时上报
- (void)reportPlayFullScreenWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 视频广告（退出全屏时上报
- (void)reportPlayExitFullScreenWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 下载类广告（下载开始时上报）
- (void)reportDownloadStartWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 下载类广告（下载成功时上报
- (void)reportDownloadSuccessWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 下载类广告（安装完成并打开应用时上报
- (void)reportInstallWithAppOpenWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 下载类广告（安装开始时上报
- (void)reportInstallStartWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 下载类广告（安装成功时上报
- (void)reportInstallSuccessWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 用户主动关闭上报
- (void)reportUserCloseWithTouchModel:(nullable YFTouchLocModel *)touchModel;
/// 竞胜通知
- (void)reportBiddingWinWithTouchModel:(nullable YFTouchLocModel *)touchModel;

@end

NS_ASSUME_NONNULL_END
