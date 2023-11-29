
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@interface YFJDAdInterstitialVideoView : UIView
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(void)loadAdData:(id)dataObject close: (void(^)(id))close;
-(void)show;
@end

NS_ASSUME_NONNULL_END
