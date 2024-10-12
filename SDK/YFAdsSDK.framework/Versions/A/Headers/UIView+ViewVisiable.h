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
@property(nonatomic,copy)void (^toPlayClick)(void);
@end

NS_ASSUME_NONNULL_END
