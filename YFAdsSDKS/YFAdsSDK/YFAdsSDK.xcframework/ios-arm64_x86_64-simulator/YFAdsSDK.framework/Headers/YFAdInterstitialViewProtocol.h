//
//  YFAdInterstitialViewProtocol.h
//  YFAdsSDK
//
//  Created by FC-0823 on 2023/10/26.
//

#import <Foundation/Foundation.h>

@protocol YFAdInterstitialViewProtocol <NSObject>
@optional

/**
 * interstitial ad render failed
 */
- (void)yfInterstitialAdViewRenderFailWithError:(NSError *_Nullable)error;

/**
 * interstitial ad did visible
 */
- (void)yfInterstitialAdViewDidVisible;

/**
 * interstitial ad did click
 */
- (void)yfInterstitialAdViewDidClick:(BOOL)autoClick;

/**
 * interstitial ad did close
 */
- (void)yfInterstitialAdViewViewDidClose;


@end

