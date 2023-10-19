//
//  UIButton+EnlargeEdge.h
//  EnlargeButtonEdge

#import <UIKit/UIKit.h>

#import <objc/runtime.h>


@interface UIButton (Edge)

/**
 *  @author hj, 06.27 2016 20:06
 *
 *  同时向按钮的四个方向延伸响应面积
 *
 *  @param size 间距
 */
- (void)setEdge:(CGFloat) size;

/**
 *  @author hj, 06.27 2016 20:06
 *
 *  向按钮的四个方向延伸响应面积
 *
 *  @param top    上间距
 *  @param left   左间距
 *  @param bottom 下间距
 *  @param right  右间距
 */
- (void)setEdgeWithTop:(CGFloat) top left:(CGFloat) left bottom:(CGFloat) bottom right:(CGFloat) right;

@end
