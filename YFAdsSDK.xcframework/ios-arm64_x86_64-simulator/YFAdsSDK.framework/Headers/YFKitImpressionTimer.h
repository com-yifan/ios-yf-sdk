//
//  YFKitImpressionTimer.h
//  YFKitAdsSDK
//
//  Created by Erik on 2024/10/21.
//

#import <UIKit/UIKit.h>

static inline BOOL YFKitViewIsVisible(UIView *view);
static inline BOOL YFKitViewHasHiddenAncestor(UIView *view);
static inline BOOL YFKitViewIntersectsParentWindow(UIView *view);
static inline BOOL YFKitViewIntersectsParentWindowWithPercent(UIView *view, CGFloat percentVisible);
static inline UIWindow * YFKitViewGetParentWindow(UIView *view);

@protocol YFKitImpressionTimerDelegate <NSObject>

- (void)viewWillLogImpression:(UIView *)view;

@end

NS_ASSUME_NONNULL_BEGIN

@interface YFKitImpressionTimer : NSObject

@property (nonatomic, weak) id<YFKitImpressionTimerDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
初始化一个视图的监听对象, 然后回调给外部该视图是否达到展示要求

@param requiredSecondsForImpression 展示时间 [0, infinite]
@param requiredViewVisibilityPixels 展示像素 [0, infinite]
*/
- (instancetype)initWithRequiredSecondsForImpression:(NSTimeInterval)requiredSecondsForImpression requiresViewVisibilityPixels:(CGFloat)requiredViewVisibilityPixels NS_DESIGNATED_INITIALIZER;

/**
初始化一个视图的监听对象, 然后回调给外部该视图是否达到展示要求

@param requiredSecondsForImpression 展示时间 [0, infinite]
@param visibilityPercentage 视图展示比例 [0, 1], 1代表100%
*/
- (instancetype)initWithRequiredSecondsForImpression:(NSTimeInterval)requiredSecondsForImpression requiredViewVisibilityPercentage:(CGFloat)visibilityPercentage NS_DESIGNATED_INITIALIZER;

- (void)startTrackingView:(UIView *)adView;

@end

NS_ASSUME_NONNULL_END
