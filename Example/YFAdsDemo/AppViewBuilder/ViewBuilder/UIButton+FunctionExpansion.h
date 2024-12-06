//
//  UIButton+FunctionExpansion.h
//  Twideo
//
//  Created by 麻明康 on 2023/9/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIButton (FunctionExpansion)
+(UIButton *)buttonWithFrame:(CGRect)rect
                       title:(nullable NSString *)title
                  titleColor:(nullable UIColor *)color
             backgroundColor:(nullable UIColor *)backgroundColor
                        font:(nullable UIFont *)font
                 normalImage:(nullable UIImage *)normalImage
            highlightedImage:(nullable UIImage*)highlightedImage
             backgroundImage:(nullable UIImage *)backgroundImage
                      target:(id)target
                    selector:(SEL)selector;

@end

NS_ASSUME_NONNULL_END
