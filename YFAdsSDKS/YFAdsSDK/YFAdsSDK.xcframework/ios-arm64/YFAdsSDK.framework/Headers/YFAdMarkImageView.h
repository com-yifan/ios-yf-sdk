
#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdInteractionType.h>

#import <YFAdsSDK/YFAdCustomModel.h>
#import <YFAdsSDK/YFAdBaseView.h>
#import <YFAdsSDK/YFAdView.h>

NS_ASSUME_NONNULL_BEGIN


@interface YFAdMarkImageView : YFAdBaseView

@property (nonatomic, strong) YFAdImageView *adLogo;

@property (nonatomic, copy) void (^longTapClick)(void);

- (void)loadAdLogoType:(NSInteger)type;
- (void)loadAdxCircleLogo;
- (void)loadAdLogo:(NSString *)logo;
- (void)loadAdLogoImage:(UIImage *)logoImage;
- (void)closeFeedback;

@end

NS_ASSUME_NONNULL_END
