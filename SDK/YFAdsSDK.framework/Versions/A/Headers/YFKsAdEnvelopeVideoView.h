
#import <UIKit/UIKit.h>


#if __has_include(<KSAdSDK/KSAdSDK.h>)
#import "YFAdInteractionType.h"

#import "YFAdCustomModel.h"
#import "YFAdBaseView.h"
#import "YFAdView.h"
#import <KSAdSDK/KSAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFKsAdEnvelopeVideoView : YFAdBaseView

-(instancetype)initWithFrame:(CGRect)frame model:(id)model viewController:(UIViewController *)viewController;
-(void)loadAdData:(KSNativeAd *)dataObject close: (void(^)(id))close;

@end

NS_ASSUME_NONNULL_END
#endif
