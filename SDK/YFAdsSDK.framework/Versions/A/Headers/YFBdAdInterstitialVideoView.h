
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFBdAdInterstitialVideoView : UIView
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(void)loadAdData:(id)object close:(void(^)(id))close;
-(void)show;
-(void)deallocShakeView;

@end
NS_ASSUME_NONNULL_END
