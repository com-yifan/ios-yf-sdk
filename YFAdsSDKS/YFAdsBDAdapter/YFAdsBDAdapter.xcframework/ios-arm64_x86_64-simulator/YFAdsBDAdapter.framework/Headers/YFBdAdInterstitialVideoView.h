
#import <YFAdsSDK/YFAdBaseCustomView.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFBdAdInterstitialVideoView : YFAdBaseCustomView
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(void)loadAdData:(id)object close:(void(^)(id))close;
-(void)show;
-(void)deallocShakeView;

@end
NS_ASSUME_NONNULL_END
