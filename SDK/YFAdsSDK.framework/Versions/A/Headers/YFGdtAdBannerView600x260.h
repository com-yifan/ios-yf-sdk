
#import <UIKit/UIKit.h>


#import "YFAdInteractionType.h"
#import "YFAdCustomModel.h"
#import "YFAdView.h"
@class YFGdtAdMediaView;
NS_ASSUME_NONNULL_BEGIN

@interface YFGdtAdBannerView600x260 : UIView
@property (nonatomic, strong) YFGdtAdMediaView *adInterView;
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(float)getViewHeight;
-(void)loadAdData:(id)dataObject close: (void(^)(id))close;

@end

NS_ASSUME_NONNULL_END

