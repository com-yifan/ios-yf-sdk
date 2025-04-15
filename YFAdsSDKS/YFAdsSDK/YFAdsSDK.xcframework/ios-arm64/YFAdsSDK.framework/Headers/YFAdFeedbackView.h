
#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdInteractionType.h>

#import <YFAdsSDK/YFAdCustomModel.h>
#import <YFAdsSDK/YFAdBaseView.h>
#import <YFAdsSDK/YFAdView.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdFeedbackView : UIView
-(void)show;
@property (nonatomic, copy) void (^contentTapClick)(void);
@end

NS_ASSUME_NONNULL_END
