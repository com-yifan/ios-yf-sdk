//
//  YFVideoAdViewController.h
//  YFAdsSDK
//
//  Created by FC-0823 on 2023/10/24.
//

#import <UIKit/UIKit.h>
#import "YFAdReportModel.h"
#import "YFMaterialMeta.h"

typedef NS_ENUM(NSInteger, YFVideoAdViewControllerType) {
    ///全屏视频
    YFVideoAdViewControllerTypeFullScreen,
    ///激励视频
    YFVideoAdViewControllerTypeReward,
};

NS_ASSUME_NONNULL_BEGIN
@class YFVideoAdViewController;
@protocol YFVideoAdViewControllerDelegate <NSObject>
@optional
/**
 This method is called when cached successfully.
 */
- (void)yfVideoAdVideoDidCache:(YFVideoAdViewController *)videoAdVC;
/**
 This method is called when video render failed
 */
- (void)yfVideoAd:(YFVideoAdViewController *)videoAdVC renderFailedWithError:(NSError *_Nullable)error;

/**
 This method is called when video ad slot has been shown.
 */
- (void)yfVideoAdDidVisible:(YFVideoAdViewController *)videoAdVC;

/**
 This method is called when video ad is closed.
 */
- (void)yfVideoAdDidClose:(YFVideoAdViewController *)videoAdVC;
/**
 This method is called when video ad is clicked.
 */
- (void)yfVideoAdDidClick:(YFVideoAdViewController *)videoAdVC;
/**
 This method is called when video ad play completed or an error occurred.
 */
- (void)yfVideoAdDidPlayFinish:(YFVideoAdViewController *)videoAdVC;
/**
 This method is called when the video begin to play.
 */
- (void)yfVideoAdStartPlay:(YFVideoAdViewController *)videoAdVC;
/**
 This method is called when the user is rewarded.
 */
- (void)yfVideoRewardedVideo:(YFVideoAdViewController *)videoAdVC hasReward:(BOOL)hasReward;

@end


@interface YFVideoAdViewController : UIViewController

@property(nonatomic, weak) id<YFVideoAdViewControllerDelegate> delegate;

@property (nonatomic, strong) YFAdEventModel *eventModel;

@property (nonatomic, strong) YFMaterialMeta *materialModel;

@property (nonatomic, assign) YFVideoAdViewControllerType videoType;

@property (nonatomic, assign) BOOL autoClick;

@end

NS_ASSUME_NONNULL_END
