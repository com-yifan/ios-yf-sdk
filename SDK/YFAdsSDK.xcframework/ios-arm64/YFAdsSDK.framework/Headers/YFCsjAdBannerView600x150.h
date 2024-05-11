
#import <UIKit/UIKit.h>
#if __has_include(<BUAdSDK/BUAdSDK.h>)
#import <BUAdSDK/BUAdSDK.h>
#import "YFAdInteractionType.h"
#import "YFAdView.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFCsjAdBannerView600x150 : UIView

-(instancetype)initWithFrame:(CGRect)frame model:(id)model;

-(float)getViewHeight;
-(void)loadAdData:(BUNativeAd *)dataObject close: (void(^)(id))close;

@end

NS_ASSUME_NONNULL_END
#endif
