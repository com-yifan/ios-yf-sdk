
#import <YFAdsSDK/YFAdBaseCustomView.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFBdAdBannerViewN600x260 : YFAdBaseCustomView
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(void)loadAdData:(id)object close:(void(^)(id))close;
-(void)show;
- (void)pauseVideo;
- (void)playVideo;
- (void)trackImpression;

@end

NS_ASSUME_NONNULL_END
