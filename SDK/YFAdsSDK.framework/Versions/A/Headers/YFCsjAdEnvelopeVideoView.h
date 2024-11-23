
#import "YFAdBaseCustomView.h"
#if __has_include(<BUAdSDK/BUAdSDK.h>)
#import <BUAdSDK/BUAdSDK.h>
#import "YFAdInteractionType.h"
#import "YFAdView.h"
#import "YFCsjCustomExpressAdapter.h"
NS_ASSUME_NONNULL_BEGIN

@interface YFCsjAdEnvelopeVideoView : YFAdBaseCustomView
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(void)loadAdData:(BUNativeAd *)dataObject close: (void(^)(id))close;
/// 点击视频
@property(nonatomic,copy) void (^clickVideoBlk)(void);

@end

NS_ASSUME_NONNULL_END
#endif
