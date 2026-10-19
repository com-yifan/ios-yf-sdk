//
//  YFAdParameterModel.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdInteractionType.h>
#import <YFAdsSDK/YFAdImage.h>
#import <YFAdsSDK/YFAdBaseAdapter.h>
#import <YFAdsSDK/YFAdNative.h>
#import <YFAdsSDK/YFAdMediaProtocol.h>

@class YFAdMediaMetal;

NS_ASSUME_NONNULL_BEGIN

@protocol YFAdMediaDelegate;

@interface YFAdMedia : NSObject
/// 源数据
@property (nonatomic, strong, readonly) YFAdNative *data;
/// 承载视频播放器视图，如果是视频类广告则必须添加容器内
@property (nonatomic, strong, nullable) UIView *mediaView;

@property (nonatomic, weak, readwrite, nullable) id<YFAdMediaDelegate> delegate;
/// 广告控制器需传入最上层可展示控制器
@property (nonatomic, weak, readwrite) UIViewController *rootViewController;
/// 注册可点击
- (void)registerContainer:(UIView *)containerView withClickableViews:(NSArray<UIView *> *_Nullable)clickableViews;
/// 取消注册
- (void)unregisterView;

/// 开始检测广告展示状态，视频类素材在展示时必须调用该方法
- (void)trackVideoViewImpression;
/// 更新视频播放器尺寸
- (void)updateVideoViewFrame:(CGRect)frame;
/// 视频静音
- (void)muteEnable:(BOOL)enable;
/// 现在视频播放时长
- (CGFloat)currentPlayTime;
/// 暂停视频
- (void)pauseVideo;
/// 恢复播放
- (void)resumeVideo;

- (id)initWithObject:(id)object adNative:(id)adNative adapter:(YFAdBaseAdPosition<YFAdMediaProtocol> * _Nonnull)adapter;

- (id)initWithObject:(id)object adNative:(id)adNative ksView:(UIView *)view adapter:(YFAdBaseAdPosition<YFAdMediaProtocol> * _Nonnull)adapter;

- (id)initWithObject:(id)object adNative:(id)adNative adxView:(UIView *)view adapter:(YFAdBaseAdPosition<YFAdMediaProtocol> * _Nonnull)adapter;

@end


NS_ASSUME_NONNULL_END
