//
//  YFGlobalMotionManager.h
//  AFNetworking
//
//  Created by 麻明康 on 2024/10/21.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>
#import <YFAdsSDK/YFSplashEnum.h>
#import <YFAdsSDK/YFGlobalMotionModel.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFGlobalMotionManager : NSObject

+ (instancetype)sharedManager;

// 广告注册和注销
//- (void)registerAdView:(UIView <YFGlobalMotionActionHandler>*)adView;
//- (void)unregisterAdView:(UIView <YFGlobalMotionActionHandler>*)adView;
//
//// 尝试开始监控，需要adView被添加到scrollView的子视图中才能被成功添加检测。实际监控的是scrollView的contentOffSet
//- (BOOL)tryAddObseverForView:(UIView <YFGlobalMotionActionHandler>*)adView;

// 广告注册和注销
- (void)registerGlobalModel:(YFGlobalMotionModel *)model;
- (void)unregisterGlobalModel:(YFGlobalMotionModel *)model;

// 尝试开始监控，需要adView被添加到scrollView的子视图中才能被成功添加检测。实际监控的是scrollView的contentOffSet
- (BOOL)tryAddObseverForModel:(YFGlobalMotionModel *)model;

// 外部视图生命周期刷新当前可响应状态，常用于模板信息流滚动复用场景。
- (void)updateGlobalModel:(YFGlobalMotionModel *)model visible:(BOOL)visible;



@end

NS_ASSUME_NONNULL_END
