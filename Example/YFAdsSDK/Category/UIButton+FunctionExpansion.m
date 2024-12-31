//
//  UIButton+FunctionExpansion.m
//  Twideo
//
//  Created by 麻明康 on 2023/9/1.
//

#import "UIButton+FunctionExpansion.h"

@implementation UIButton (FunctionExpansion)
//初始化button
+(UIButton *)buttonWithFrame:(CGRect)rect title:(nullable NSString *)title titleColor:(nullable UIColor *)color backgroundColor:(nullable UIColor *)backgroundColor font:(nullable UIFont *)font normalImage:(nullable UIImage *)normalImage highlightedImage:(nullable UIImage*)highlightedImage backgroundImage:(nullable UIImage *)backgroundImage target:(id)target selector:(SEL)selector{
    //右侧按钮
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.frame = rect;
    if (title) [btn setTitle:title forState:UIControlStateNormal];
    if (color) [btn setTitleColor:color forState:UIControlStateNormal];
    if (backgroundColor) [btn setBackgroundColor:backgroundColor];
    if (font) btn.titleLabel.font = font;
    btn.titleLabel.textAlignment = NSTextAlignmentCenter;
    if(normalImage) [btn setImage:normalImage forState:UIControlStateNormal];
    if(highlightedImage) [btn setImage:highlightedImage forState:UIControlStateHighlighted];
    if(backgroundImage) [btn setBackgroundImage:backgroundImage forState:UIControlStateNormal];
    [btn addTarget:target action:selector forControlEvents:UIControlEventTouchUpInside];
    return btn;
}



@end
