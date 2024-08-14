
#import <UIKit/UIKit.h>
#import "YFAdInteractionType.h"

#import "YFAdCustomModel.h"
#import "YFAdBaseView.h"
#import "YFAdView.h"

NS_ASSUME_NONNULL_BEGIN


@interface YFAdMarkImageView : YFAdBaseView

@property (nonatomic, strong) YFAdImageView *adLogo;

- (void)loadAdLogoType:(NSInteger)type;
- (void)loadAdLogo:(NSString *)logo;
- (void)loadAdLogoImage:(UIImage *)logoImage;

@end

NS_ASSUME_NONNULL_END
