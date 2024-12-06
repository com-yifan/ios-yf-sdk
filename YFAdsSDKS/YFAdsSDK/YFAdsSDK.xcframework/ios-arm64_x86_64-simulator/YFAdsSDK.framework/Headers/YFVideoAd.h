//
//  YFVideoAd.h
//  YFAdsSDK
//
//  Created by aiken on 2023/10/20.
//

#import <UIKit/UIKit.h>

@class YFAd, YFAdEventModel;
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, YFAdShowDirection) {
    YFAdShowDirection_Vertical = 0,     //竖屏
    YFAdShowDirection_Horizontal = 1,     //横屏
};

@interface YFVideoAd : NSObject


@property(nonatomic, assign) BOOL shouldMuted;
@property(nonatomic, assign) YFAdShowDirection showDirection;  //显示方向
@property(nonatomic, weak) UIViewController *rootViewController;

- (instancetype)initWithPosId:(NSString *)posId eventModel:(YFAdEventModel *)eventModel;

- (void)loadAdData;

- (BOOL)showAdFromRootViewController:(UIViewController *)rootViewController;

- (BOOL)showAdFromRootViewController:(UIViewController *)rootViewController direction:(YFAdShowDirection)direction DEPRECATED_ATTRIBUTE;

- (BOOL)showAdFromRootViewController:(UIViewController *)rootViewController showScene:(nullable NSString *)showScene;

- (BOOL)showAdFromRootViewController:(UIViewController *)rootViewController showScene:(nullable NSString *)showScene direction:(YFAdShowDirection)direction DEPRECATED_ATTRIBUTE;

/*
 这个是播放异常的时候,此方法不会自动调用，可以在
 - (void)rewardedVideoAdDidPlayFinish:(KSRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *_Nullable)error使用此方法
 */
- (void)closeVideoAdWhenPlayError;

@end

NS_ASSUME_NONNULL_END
