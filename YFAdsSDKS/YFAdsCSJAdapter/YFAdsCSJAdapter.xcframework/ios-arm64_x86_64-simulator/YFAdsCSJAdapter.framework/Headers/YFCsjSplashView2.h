//
//  YFCsjSplashView2.h
//  YFAdsCSJAdapter
//
//  Created by 麻明康 on 2025/5/29.
//

#import <YFAdsSDK/YFAdsSDK.h>
#import <YFAdsSDK/YFAdCustomModel.h>
#import <YFAdsSDK/YFAdBaseView.h>
#import <YFAdsSDK/YFAdView.h>
#import <YFAdsSDK/YFSplashButton.h>

#if __has_include(<BUAdSDK/BUAdSDK.h>)

NS_ASSUME_NONNULL_BEGIN

@interface YFCsjSplashView2 : YFAdBaseSplashView

@property (nonatomic, strong) BUNativeAdRelatedView * relatedView;
- (void)loadAdData:(BUNativeAd *)dataObject;

@end

NS_ASSUME_NONNULL_END

#endif
