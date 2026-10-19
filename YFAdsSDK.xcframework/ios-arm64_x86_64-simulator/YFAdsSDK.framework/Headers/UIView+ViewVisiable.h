//
//  UIView+ViewVisiable.h
//  DSPSDK
//
//  Created by 麻明康 on 2024/3/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (ViewVisiable)
- (BOOL)isViewVisible;
- (BOOL)isSubViewVisible;

/// 是否100%在屏幕中
- (BOOL)inScreenFull;

/// 是否有一部分在屏幕中
- (BOOL)inScreenPart;

@end

NS_ASSUME_NONNULL_END
