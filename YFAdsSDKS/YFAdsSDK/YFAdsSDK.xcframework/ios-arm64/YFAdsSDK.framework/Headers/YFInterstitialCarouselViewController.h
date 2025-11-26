//
//  YFInterstitialCarouselViewController.h
//  YFAdsSDK
//
//  Created by mamingkang on 2025/9/23.
//

#import <YFAdsSDK/YFAdBaseViewController.h>
#import <YFAdsSDK/YFAdInterstitial+TopPush.h>

NS_ASSUME_NONNULL_BEGIN
@protocol YFInterstitialCarouselDelegate <NSObject>

@required
/// 当前广告加载结束，2.0s后即将加载下一条广告（如有）
- (YFAdBaseAdPosition *)currentAdWillDisplayEnd;

/// 当前广告展示结束
- (void)currentAdDisplayEnd;

/// 新的广告开始结束
- (void)newAdDidShow;
@end

@interface YFInterstitialCarouselViewController : YFAdBaseViewController
// 当前轮播位置，默认0，广告展示出来后（未轮播显示第二个）即为1
@property (nonatomic, assign) NSInteger currentIndex;
@property (nonatomic, assign) NSInteger icc;
@property (nonatomic, assign) NSInteger ici;
@property (nonatomic, weak) id<YFInterstitialCarouselDelegate> delegate;

@property (nonatomic, weak) YFAdInterstitial *adSpot;

- (void)startCarousel;
- (void)cleanChildController;
- (void)showNextAdController:(UIViewController *)viewController;
- (void)showNextAdController:(UIViewController *)viewController inViewController:(nonnull UIViewController *)controller;
- (void)stopCarousel;
//- (void)addNotification;
@end

NS_ASSUME_NONNULL_END
