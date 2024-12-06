//
//  YFCsjEnvelopeIntertitialAdViewController.h
//  YFAdsSDK
//
//  Created by Erik on 2024/11/26.
//

#import <YFAdsSDK/YFEnvelopeIntertitialAdViewController.h>
#if __has_include(<BUAdSDK/BUAdSDK.h>)
#import <BUAdSDK/BUAdSDK.h>
NS_ASSUME_NONNULL_BEGIN
/// 穿山甲亿帆插屏3.0
@interface YFCsjEnvelopeIntertitialAdViewController : YFEnvelopeIntertitialAdViewController
/// 加载广告
-(void)loadAdData:(BUNativeAd *)dataObject close:(void(^)(id))close;

@end

NS_ASSUME_NONNULL_END
#endif
