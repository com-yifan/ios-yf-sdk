//
//  YFAdEnvelopeIntertitialAdViewController.h
//  YFAdsSDK
//
//  Created by Erik on 2024/12/3.
//

#import <YFAdsSDK/YFEnvelopeIntertitialAdViewController.h>
#import <YFAdsSDK/YFAdReportModel.h>
#import <YFAdsSDK/YFAdInterstitialViewProtocol.h>
#import <YFAdsSDK/YFMaterialMeta.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdEnvelopeIntertitialAdViewController : YFEnvelopeIntertitialAdViewController

@property(nonatomic, weak) id<YFAdInterstitialViewProtocol> delegate;

- (instancetype)initWithNativeAd:(YFMaterialMeta *)nativeAd model:(YFAdEventModel *)model;

- (void)show;
@end

NS_ASSUME_NONNULL_END
