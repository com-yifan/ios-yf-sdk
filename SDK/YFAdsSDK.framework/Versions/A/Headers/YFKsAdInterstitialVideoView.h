
#import "YFAdBaseCustomView.h"


#if __has_include(<KSAdSDK/KSAdSDK.h>)
#import "YFAdInteractionType.h"

#import "YFAdCustomModel.h"
#import "YFAdBaseView.h"
#import "YFAdView.h"
#import <KSAdSDK/KSAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class YFKsAdInterstitialVideoView;

@protocol YFKsAdInterstitialVideoViewDelegate <NSObject>
@optional

@end

@interface YFKsAdInterstitialVideoView : YFAdBaseCustomView

@property (nonatomic, weak) id<YFKsAdInterstitialVideoViewDelegate> delegate;
-(instancetype)initWithFrame:(CGRect)frame model:(id)model viewController:(UIViewController *)viewController;
-(void)loadAdData:(KSNativeAd *)dataObject close: (void(^)(id))close;

@end

NS_ASSUME_NONNULL_END
#endif
