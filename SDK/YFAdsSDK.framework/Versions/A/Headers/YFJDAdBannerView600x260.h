
#import <UIKit/UIKit.h>
#if __has_include(<JADYun/JADYun.h>)
#import <JADYun/JADYun.h>
#import <JADYun/JADNativeAdData.h>
#import <JADYun/JADNativeAd.h>
#import "YFAdInteractionType.h"
#import "YFAdView.h"
#import "YFJDBannerView.h"

NS_ASSUME_NONNULL_BEGIN
@interface YFJDAdBannerView600x260 : YFJDBannerView
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(float)getViewHeight;
-(void)loadAdData:(JADNativeAd *)dataObject;
@end
NS_ASSUME_NONNULL_END
#endif
