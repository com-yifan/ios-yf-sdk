
#import <UIKit/UIKit.h>
#import "YFAdInteractionType.h"
#import "YFAdView.h"
#import "YFAdMarkView.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFBdAdInterstitialVideoView : UIView
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(void)loadAdData:(id)object;
-(void)show;
@end
NS_ASSUME_NONNULL_END
