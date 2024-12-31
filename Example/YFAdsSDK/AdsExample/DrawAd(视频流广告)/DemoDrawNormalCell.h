//
//  DemoDrawNormalCell.h
//

#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface DemoDrawNormalCell : UITableViewCell
@property (nonatomic, strong, nullable) UILabel *titleLabel;
@property (nonatomic, strong, nullable) UILabel *descriptionLabel;
@property (nonatomic, strong, nullable) UIImageView *headImg;
+ (CGFloat)cellHeight;
- (void)refreshUIAtIndex:(NSUInteger)index;

@end


NS_ASSUME_NONNULL_END
