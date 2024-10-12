
#import "YFAdBaseCustomView.h"
#if __has_include( <GDTMobSDK/GDTUnifiedNativeAdView.h>)


#import "YFAdInteractionType.h"
#import "YFAdCustomModel.h"
#import "YFAdView.h"
#import "YFGdtAdMediaView.h"


NS_ASSUME_NONNULL_BEGIN

@interface YFGdtAdEnvelopeVideoView : YFAdBaseCustomView

-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
@property (nonatomic, strong) YFGdtAdMediaView *adInterView;

-(void)loadAdData:(id)dataObject close: (void(^)(id))close;

@end

NS_ASSUME_NONNULL_END
#endif
