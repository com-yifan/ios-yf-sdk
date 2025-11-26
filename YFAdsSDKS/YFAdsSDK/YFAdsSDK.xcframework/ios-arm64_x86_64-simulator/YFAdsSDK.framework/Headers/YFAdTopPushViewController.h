//
//  YFAdTopPushViewController.h
//  YFAdsSDK
//
//  Created by Erik on 2025/9/19.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdTopPushAdInfoProtocol.h>
#import <YFAdsSDK/YFAdTopPushView.h>

NS_ASSUME_NONNULL_BEGIN

@protocol YFAdTopPushViewControllerDelegate <NSObject>

- (void)topPushViewClose:(BOOL)userAction;
- (void)topPushViewRenderFail;
- (void)topPushViewRenderSuccess;
- (void)topPushViewDidShow;
- (void)topPushViewControllerChanged:(UIViewController *)viewController;
- (void)topPushViewDidExpourse;
@end

@interface YFAdTopPushViewController : UIViewController

@property (nonatomic, weak) id<YFAdTopPushViewControllerDelegate> delegate;
@property (nonatomic, strong, readonly) UIView *adView;

- (instancetype)initWithTopPushView:(YFAdTopPushView *)adView;
- (void)loadData;
- (void)show;
- (void)startTimer;
- (void)pauseTimer;
- (void)resumeTimer;
- (void)setDetailVc:(UIViewController *)detailVc;
// 展示
- (void)showAdFromWindow;
// 关闭
- (void)hideTopPushViewWithAnime:(BOOL)on;
- (void)hideTopPushViewWithAnime:(BOOL)anime time:(NSInteger)time;

@end

NS_ASSUME_NONNULL_END
