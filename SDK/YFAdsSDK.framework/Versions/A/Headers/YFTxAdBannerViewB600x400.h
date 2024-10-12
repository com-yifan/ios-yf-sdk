
#import "YFAdBaseCustomView.h"
#import "YFAdBaseView.h"
NS_ASSUME_NONNULL_BEGIN

@interface YFTxAdBannerViewB600x400 : YFAdBaseCustomView

-(instancetype)initWithFrame:(CGRect)frame model:(id)model nativeAd:(id)nativeAd;
-(float)getViewHeight;
-(void)loadAdData:(id)dataObject close: (void(^)(id))close;
- (void)setVideoMute;
@end

NS_ASSUME_NONNULL_END


