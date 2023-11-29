//
//  YFJDBannerView.h
//  YFAdsSDK
//
//  Created by feng on 2023/11/10.
//

#import <UIKit/UIKit.h>
#if __has_include(<JADYun/JADYun.h>)
#import <JADYun/JADYun.h>
#import <JADYun/JADNativeAdData.h>
#import <JADYun/JADNativeAd.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFJDBannerView : UIView
-(void)showView:(UIView *)view;
- (void)loadAdData:(JADNativeAd *)dataObject;

@end


NS_ASSUME_NONNULL_END
#endif
