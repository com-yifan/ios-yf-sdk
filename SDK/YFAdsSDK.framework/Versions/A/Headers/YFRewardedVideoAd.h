//
//  GDTUnifiedBannerView.h
//  GDTMobSDK
//
//  Created by nimomeng on 2019/3/1.
//  Copyright © 2019 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "YFVideoAd.h"

NS_ASSUME_NONNULL_BEGIN

@class YFRewardedVideoModel, YFRewardedVideoAd,YFMaterialMeta;

@protocol YFRewardedVideoAdDelegate <NSObject>

@optional
/**
 This method is called when video ad material loaded successfully.
 */
- (void)yfRewardedVideoAdDidLoad:(YFRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when video ad materia failed to load.
 @param error : the reason of error
 */
- (void)yfRewardedVideoAd:(YFRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *_Nullable)error;

/**
 This method is called when video render failed to load.
 @param error : the reason of error
 */
- (void)yfRewardedVideoAd:(YFRewardedVideoAd *)fullscreenVideoAd renderFailedWithError:(NSError *_Nullable)error;

/**
 This method is called when cached successfully.
 */
- (void)yfRewardedVideoAdVideoDidCache:(YFRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when video ad slot has been shown.
 */
- (void)yfRewardedVideoAdDidVisible:(YFRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when video ad is closed.
 */
- (void)yfRewardedVideoAdDidClose:(YFRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when video ad is clicked.
 */
- (void)yfRewardedVideoAdDidClick:(YFRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when video ad play completed or an error occurred.
 */
- (void)yfRewardedVideoAdDidPlayFinish:(YFRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when the video begin to play.
 */
- (void)yfRewardedVideoAdStartPlay:(YFRewardedVideoAd *)rewardedVideoAd;

/**
 This method is called when the user is rewarded.
 */
- (void)yfRewardedVideoAd:(YFRewardedVideoAd *)rewardedVideoAd hasReward:(BOOL)hasReward;

@end

@interface YFRewardedVideoAd : YFVideoAd

@property(nonatomic, strong) YFMaterialMeta *materialModel;

@property(nonatomic, strong) YFRewardedVideoModel *rewardedVideoModel;

@property(nonatomic, weak, nullable) id <YFRewardedVideoAdDelegate> delegate;

@property(nonatomic, assign) NSUInteger ecpm;

@property (nonatomic, assign) BOOL autoClick;

@property(nonatomic, readonly) BOOL isValid;

@end

NS_ASSUME_NONNULL_END
