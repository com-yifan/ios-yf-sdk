//
//  YFKsEnvelopeIntertitialAdViewController.h
//  YFAdsSDK
//
//  Created by Erik on 2024/11/29.
//

#import <YFAdsSDK/YFEnvelopeIntertitialAdViewController.h>
#if __has_include(<KSAdSDK/KSAdSDK.h>)
#import <KSAdSDK/KSAdSDK.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFKsEnvelopeIntertitialAdViewController : YFEnvelopeIntertitialAdViewController
- (instancetype)initWithData:(KSNativeAd *)dataObject eventModel:(YFAdEventModel *)model;
/// 加载广告
-(void)loadAdData:(KSNativeAd *)nativeAd close:(void(^)(id))close;
@end

NS_ASSUME_NONNULL_END

#endif
