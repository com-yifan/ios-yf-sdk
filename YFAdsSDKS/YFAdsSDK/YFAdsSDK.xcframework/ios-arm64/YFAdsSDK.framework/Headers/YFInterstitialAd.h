//
//  GDTUnifiedBannerView.h
//  GDTMobSDK
//
//  Created by nimomeng on 2019/3/1.
//  Copyright © 2019 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <YFAdsSDK/YFAd.h>
#import <YFAdsSDK/YFAdInteractionType.h>

NS_ASSUME_NONNULL_BEGIN


@class YFInterstitialAd,YFAdEventModel,YFMaterialMeta;

@protocol YFInterstitialAdDelegate <NSObject>
@optional
/**
 * interstitial ad data loaded
 */
- (void)yfInterstitialAdDidLoad:(YFInterstitialAd *)interstitialAd;

/**
 * interstitial ad  load failed
 */
- (void)yfInterstitialAd:(YFInterstitialAd *)interstitialAd loadFailWithError:(NSError *_Nullable)error;

/**
 * interstitial ad  render failed
 */
- (void)yfInterstitialAd:(YFInterstitialAd *)interstitialAd renderFailWithError:(NSError *_Nullable)error;

/**
 * interstitial ad did visible
 */
- (void)yfInterstitialAdDidVisible:(YFInterstitialAd *)interstitialAd;
/**
 * interstitial ad did click
 */
- (void)yfInterstitialAdDidClick:(YFInterstitialAd *)interstitialAd;

/**
 * interstitial ad did close
 */
- (void)yfInterstitialAdDidClose:(YFInterstitialAd *)interstitialAd;

@end

@interface YFInterstitialAd : UIView

@property (nonatomic, weak) id<YFInterstitialAdDelegate>delegate;
//广告是否已合法加载
@property (nonatomic, readonly) BOOL isValid;
//是否开启声音
@property (nonatomic, assign) BOOL videoSoundEnabled;

@property(nonatomic,assign)NSUInteger ecpm;

@property(nonatomic, strong) YFMaterialMeta *materialModel;

@property (nonatomic, assign) BOOL autoClick;


- (instancetype)initWithPosId:(NSString *)posId eventModel:(YFAdEventModel *)eventModel;

- (void)loadAdData;

- (void)removeAd;

- (void)showFromViewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END

