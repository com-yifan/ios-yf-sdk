
#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdInteractionType.h>

#import <YFAdsSDK/YFAdCustomModel.h>
#import <YFAdsSDK/YFAdBaseView.h>
#import <YFAdsSDK/YFAdView.h>

NS_ASSUME_NONNULL_BEGIN


@interface YFAdMarkImageView : YFAdBaseView

@property (nonatomic, strong) YFAdImageView *adLogo;

- (void)loadAdLogoType:(NSInteger)type;
- (void)loadAdxCircleLogo;
- (void)loadAdLogo:(NSString *)logo;
- (void)loadAdLogoImage:(UIImage *)logoImage;
// TODO: from mk --- 很多没有加长按溯源，可能需要加一下
@property (nonatomic, copy) void (^longTapClick)(void);

@end

NS_ASSUME_NONNULL_END
