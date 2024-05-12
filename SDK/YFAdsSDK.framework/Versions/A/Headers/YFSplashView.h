//
//  YFSplashView.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/18.
//

#import <UIKit/UIKit.h>

#import "YFAdBaseView.h"
#import "YFAdView.h"
#import "YFAdMarkView.h"
#import "YFAnimationView.h"
#import "YFAdInteractionType.h"
#import "YFSplashEnum.h"
#import "YFAdInteractionType.h"
#import "YFAdInteractionType.h"
#import "YFAdSplashAdExtraDataModel.h"
#import "YFMotionManager.h"
#import "YFMaterialMeta.h"
#import "YFAdReportModel.h"
#import "YFPlayerView.h"
#import "YFTapBarAnimationView.h"
#import "YFAdError.h"




NS_ASSUME_NONNULL_BEGIN


@class YFSplashView;

@protocol YFSplashAdViewDelegate <NSObject>
@optional

/**
 * splash ad request done
 * 请求完成
 */
- (void)yfsplashAdDidLoad:(YFSplashView *)splashAdView;

/**
 * splash ad (material) failed to load
 * 加载失败
 * YFAdError
 */
- (void)yfsplashAd:(YFSplashView *)splashAdView didFailWithError:(NSError *)error;

/**
 *
 * 广告渲染失败
 */
- (void)yfsplashNativeExpressOnAdRenderFail:(YFSplashView *)splashAdView error:(NSError *)error;

/**
 * splash ad did visible
 * 已经展示
 */
- (void)yfsplashAdDidVisible:(YFSplashView *)splashAdView;

/**
 * splash ad video begin play
 * for video ad only
 * 视频准备播放
 */
- (void)yfsplashAdVideoDidBeginPlay:(YFSplashView *)splashAdView;

/**
 * splash ad clicked
 *点击YFSplashView事件触发
 */
- (void)yfsplashAdDidClick:(YFSplashView *)splashAdView;

/**
 * splash ad skipped
 * @param showDuration  splash show duration (no subsequent callbacks, remove & release KSSplashAdView here)
 * 中途跳过
 */
- (void)yfsplashAd:(YFSplashView *)splashAdView didSkip:(NSTimeInterval)showDuration;

/**
 * splash ad did enter conversion view controller
 *开屏转入视图控制器
 */
- (void)yfsplashAdDidOpenConversionVC:(YFSplashView *)splashAdView interactionType:(YFAdInteractionType)interactType;

/**
 * splash ad close conversion viewcontroller or jump with deeplink
 * 跳转deeplink
 *
 */
- (void)yfsplashAdDidCloseConversionVC:(YFSplashView *)splashAdView interactionType:(YFAdInteractionType)interactType;

/**
 * splash ad play finished & auto dismiss (no subsequent callbacks, remove & release KSSplashAdView here)
 * 开屏关闭和自动消失触发
 */
- (void)yfsplashAdDidAutoDismiss:(YFSplashView *)splashAdView;

- (void)yfsplashAdBecomeActive:(YFSplashView *)splashAdView;

@end

@interface YFSplashView : YFAdBaseView


@property(nonatomic, weak) id <YFSplashAdViewDelegate> delegate;
@property(nonatomic, weak) UIViewController *rootViewController;
/// max timeout interval, default is 5
@property(nonatomic, assign) NSTimeInterval timeoutInterval;
@property(nonatomic, assign,readonly) BOOL autoClick;
/// ad interaction type, avaliable after ksad_splashAdContentDidLoad:
@property(nonatomic, assign, readonly) YFAdInteractionType interactionType;
/// ad material type, avaliable after ksad_splashAdContentDidLoad:
@property(nonatomic, assign, readonly) YFAdMaterialType materialType;
@property(nonatomic, assign) BOOL isvalid;
@property(nonatomic, assign) NSUInteger ecpm;

- (id)initWithPosId:(NSString *)posId model:(id)model;

//-(void)toSetYFAdEventModel:(YFAdEventModel *)eventModel;
//屏蔽摇一摇/是否屏蔽扭一扭/是否屏蔽手势滑动转化
- (void)setExtraData:(YFAdSplashAdExtraDataModel *)extraDataModel;

// load ad data
- (void)loadAdData;

//-(void)show ;
- (void)showInView:(UIView *)view;



@end

NS_ASSUME_NONNULL_END

