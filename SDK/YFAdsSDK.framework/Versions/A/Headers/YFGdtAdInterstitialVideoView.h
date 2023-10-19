
#import <UIKit/UIKit.h>


#import "YFAdInteractionType.h"
#import "YFAdCustomModel.h"
#import "YFAdView.h"
#import "YFGdtAdMediaView.h"


NS_ASSUME_NONNULL_BEGIN

@interface YFGdtAdInterstitialVideoView : UIView

-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
@property (nonatomic, strong) YFGdtAdMediaView *adInterView;
-(void)loadAdData:(id)unifiedNativeDataObject;
-(void)show;
@end

NS_ASSUME_NONNULL_END
