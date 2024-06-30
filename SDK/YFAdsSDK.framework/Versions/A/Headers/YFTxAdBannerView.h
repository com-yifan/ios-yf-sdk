
#import <UIKit/UIKit.h>
#import "YFAdBaseView.h"
NS_ASSUME_NONNULL_BEGIN

@interface YFTxAdBannerView : YFAdBaseView

-(instancetype)initWithFrame:(CGRect)frame model:(id)model nativeAd:(id)nativeAd;
-(float)getViewHeight;
-(void)loadAdData:(id)dataObject close: (void(^)(id))close;
- (void)setVideoMute;
@end

NS_ASSUME_NONNULL_END
