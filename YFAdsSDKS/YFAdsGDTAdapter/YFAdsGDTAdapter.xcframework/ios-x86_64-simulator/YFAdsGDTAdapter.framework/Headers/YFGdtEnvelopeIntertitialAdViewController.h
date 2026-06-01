//
//  YFGdtEnvelopeIntertitialAdViewController.h
//  YFAdsSDK
//
//  Created by Erik on 2024/11/28.
//

#import <YFAdsSDK/YFEnvelopeIntertitialAdViewController.h>
#if __has_include(<GDTMobSDK/GDTUnifiedNativeAdView.h>)
#import <GDTMobSDK/GDTUnifiedNativeAdView.h>
#import <YFAdsGDTAdapter/YFGdtAdMediaView.h>

NS_ASSUME_NONNULL_BEGIN
/// 优量汇亿帆插屏3.0
@interface YFGdtEnvelopeIntertitialAdViewController : YFEnvelopeIntertitialAdViewController

@property (nonatomic, strong) YFGdtAdMediaView *adInterView;
/// 加载广告
-(void)loadAdData:(GDTUnifiedNativeAdDataObject *)dataObject close:(void(^)(id))close;

@end

NS_ASSUME_NONNULL_END
#endif
