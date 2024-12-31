//
//  YFBdEnvelopeIntertitialAdViewController.h
//  YFAdsSDK
//
//  Created by Erik on 2024/11/29.
//

#import <YFAdsSDK/YFEnvelopeIntertitialAdViewController.h>
#if __has_include(<BaiduMobAdSDK/BaiduMobAdNativeAdObject.h>)
#import <BaiduMobAdSDK/BaiduMobAdNativeAdObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFBdEnvelopeIntertitialAdViewController : YFEnvelopeIntertitialAdViewController

/// 加载广告
-(void)loadAdData:(BaiduMobAdNativeAdObject *)dataObject close:(void(^)(id))close;
- (void)toAddShakeOrSlideView;
- (void)deallocSlideView;
@end

NS_ASSUME_NONNULL_END

#endif
