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



@end

NS_ASSUME_NONNULL_END
