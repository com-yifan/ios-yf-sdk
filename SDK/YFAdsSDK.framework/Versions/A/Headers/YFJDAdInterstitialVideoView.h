
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@interface YFJDAdInterstitialVideoView : UIView
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(void)loadAdData:(id)dataObject close:(nonnull void (^)(id _Nonnull))close;

@end

NS_ASSUME_NONNULL_END
