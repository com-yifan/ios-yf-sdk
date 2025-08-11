//
//  YFJDSplashView2.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/9/12.
//

#import <YFAdsSDK/YFAdBaseSplashView.h>
#if __has_include(<JADYun/JADYun.h>)
#import <JADYun/JADYun.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFJDSplashView2 : YFAdBaseSplashView

-(void)loadAdData:(JADNativeAd *)dataObject;

@end

NS_ASSUME_NONNULL_END
#endif
