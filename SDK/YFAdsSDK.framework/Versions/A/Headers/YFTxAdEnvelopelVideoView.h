
#import "YFAdBaseCustomView.h"


#import "YFAdInteractionType.h"

#import "YFAdCustomModel.h"
#import "YFAdBaseView.h"
#import "YFAdView.h"

NS_ASSUME_NONNULL_BEGIN


@interface YFTxAdEnvelopelVideoView : YFAdBaseCustomView

-(instancetype)initWithFrame:(CGRect)frame model:(id)model nativeAd:(id)nativeAd viewController:(UIViewController *)viewController;
-(void)loadAdData:(id)dataObject close: (void(^)(id))close;
- (void)setVideoMute;
@end

NS_ASSUME_NONNULL_END
