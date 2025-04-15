
#import <YFAdsSDK/YFAdBaseCustomView.h>
NS_ASSUME_NONNULL_BEGIN
@interface YFJDAdInterstitialVideoView : YFAdBaseCustomView
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(void)loadAdData:(id)dataObject close:(nonnull void (^)(id _Nonnull))close;
-(void)closeAd;
- (void)show;
@end

NS_ASSUME_NONNULL_END
