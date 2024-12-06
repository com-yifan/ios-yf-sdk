
#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdInteractionType.h>

#import <YFAdsSDK/YFAdCustomModel.h>
#import <YFAdsSDK/YFAdBaseView.h>
#import <YFAdsSDK/YFAdView.h>

NS_ASSUME_NONNULL_BEGIN


@interface YFAdMarkView : YFAdBaseView

@property (nonatomic, strong) YFAdImageView *adLogo;
@property (nonatomic, strong) UILabel *adDesc;
@property (nonatomic, strong) UIImageView *downArrow;
- (void)loadAdData:(NSString *)title logo:(NSString *)logo;
- (void)loadAdData:(NSString *)title logoImage:(UIImage *)logoImage;
@end

NS_ASSUME_NONNULL_END
