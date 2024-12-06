//
//  YFTxEnvelopeIntertitialAdViewController.h
//  YFAdsSDK
//
//  Created by Erik on 2024/12/3.
//

#import <YFAdsSDK/YFEnvelopeIntertitialAdViewController.h>
#if __has_include(<TanxSDK/TanxSDK.h>)
#import <TanxSDK/TanxSDK.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFTxEnvelopeIntertitialAdViewController : YFEnvelopeIntertitialAdViewController

- (instancetype)initWithData:(TXAdFeedBinder *)nativeAd eventModel:(YFAdEventModel *)model;
/// 加载广告
-(void)loadAdData:(TXAdFeedBinder *)nativeAd close:(void(^)(id))close;

@end

NS_ASSUME_NONNULL_END

#endif
