

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdImage : NSObject
// image address URL
@property (nonatomic, copy) NSString *imageURL;

@property (nonatomic, strong, nullable) UIImage *image;

// image width
@property (nonatomic, assign) float width;

// image height
@property (nonatomic, assign) float height;
@end

NS_ASSUME_NONNULL_END
