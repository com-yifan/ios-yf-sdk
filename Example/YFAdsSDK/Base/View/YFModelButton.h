//
//  ATModelButton.h


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFModelButton : UIButton

@property (nonatomic, strong) UIImageView *image;

@property (nonatomic, strong) UILabel *modelLabel;

- (void)setButtonIsSelectBoard;

- (void)setSelectColor:(UIColor *)color;

- (void)setNormalColor:(UIColor *)color;

@end

NS_ASSUME_NONNULL_END
