//
//  YFAdTopPushView.h
//  YFAdsSDK
//
//  Created by Erik on 2025/9/17.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdView.h>
#import <YFAdsSDK/YFAdTopPushAdInfoProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol YFAdTopPushViewDelegate <NSObject>

- (void)topPushViewRenderSuccess;
- (void)topPushViewRenderFailWithError:(nullable NSError *)error noImageUrl:(BOOL)noImageUrl;
- (void)topPushViewClose:(BOOL)userAction;
- (void)topPushViewDidShow;
- (void)topPushViewDidExpourse;
- (void)topPushViewControllerChanged:(UIViewController *)viewController;

@end

@interface YFAdTopPushView : UIView

@property (nonatomic, weak) id<YFAdTopPushViewDelegate> delegate;
@property (nonatomic, strong) YFAdImageView *iconView;
@property (nonatomic, strong) YFAdImageView *imageBackView;
@property (nonatomic, weak, readonly) UIViewController *beforeClickVc;
@property (nonatomic, assign) YFAdTopPushOpenDirection openDirection;
@property (nonatomic, assign) BOOL useMainWindowForBottomLayout;

- (instancetype)initWithModel:(id<YFAdTopPushAdInfoProtocol>)model;
- (void)logoLongTapAction;
- (YFAdnType)adnType;
- (CGSize)videoSize;
- (NSArray *)clickItems;
- (BOOL)isVideoAd;
- (void)startTimer;
- (void)pauseTimer;
- (void)resumeTimer;
- (void)loadData;
- (void)showInWindow:(UIWindow *)window;
// 关闭
- (void)hideTopPushViewWithAnime:(BOOL)on;
- (void)hideTopPushViewWithAnime:(BOOL)anime time:(NSInteger)time;
// 恢复播放视频
- (void)resumePlay;

@end

NS_ASSUME_NONNULL_END
