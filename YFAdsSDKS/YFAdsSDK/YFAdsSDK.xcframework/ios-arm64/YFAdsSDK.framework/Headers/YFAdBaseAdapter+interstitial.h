//
//  YFAdBaseAdapter+interstitial.h
//  YFAdsSDK
//
//  Created by mamingkang on 2025/9/20.
//

#import <YFAdsSDK/YFAdBaseAdapter.h>
#import <YFAdsSDK/YFInterstitialCarouselViewController.h>
#import <YFAdsSDK/YFInterstitialCarouselNavigationController.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFAdBaseAdapter (interstitial)<YFInterstitialCarouselDelegate>
@property (nonatomic, assign) NSInteger icc;
@property (nonatomic, assign) NSInteger ici;
@property (nonatomic, strong) YFInterstitialCarouselViewController *carouselViewController;
@property (nonatomic, strong) YFInterstitialCarouselNavigationController *carouselNav;
@property (nonatomic, strong, nullable) YFAdBaseAdPosition *nextPosition;
- (void)configInterstitialCarousel:(YFAdBaseAdPosition *)adapter;
@end

NS_ASSUME_NONNULL_END
