//
//  YFJdEnvelopeIntertitialAdViewController.h
//  YFAdsSDK
//
//  Created by Erik on 2024/12/2.
//

#import <YFAdsSDK/YFEnvelopeIntertitialAdViewController.h>
#if __has_include(<JADYun/JADYun.h>)
#import <JADYun/JADYun.h>
NS_ASSUME_NONNULL_BEGIN
@interface YFJdEnvelopeIntertitialAdViewController : YFEnvelopeIntertitialAdViewController
- (instancetype)initWithData:(JADNativeAd *)dataObject eventModel:(YFAdEventModel *)model;
/// 加载广告
-(void)loadAdData:(JADNativeAd *)dataObject close:(void(^)(id))close;
@end

NS_ASSUME_NONNULL_END

#endif
