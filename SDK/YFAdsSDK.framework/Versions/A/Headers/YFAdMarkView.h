
#import <UIKit/UIKit.h>
#import "YFAdInteractionType.h"

#import "YFAdCustomModel.h"
#import "YFAdBaseView.h"
#import "YFAdView.h"

NS_ASSUME_NONNULL_BEGIN


@interface YFAdMarkView : YFAdBaseView

@property (nonatomic, strong) YFAdImageView *adLogo;
@property (nonatomic, strong) UILabel *adDesc;
@property (nonatomic, strong) UIImageView *downArrow;
- (void)loadAdData:(NSString *)title logo:(NSString *)logo;
- (void)loadAdData:(NSString *)title logoImage:(UIImage *)logoImage;
@end

NS_ASSUME_NONNULL_END
