//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdNativeExpressView : NSObject
- (instancetype)initWithViewController:(UIViewController *)controller;
// 信息流view
@property (nonatomic, strong) UIView *expressView;
// 亿帆模版
@property (nonatomic, assign) BOOL isYFView;

@property (nonatomic, assign) NSUInteger tag;
// 渠道标识
 @property (nonatomic, assign) NSUInteger identifier;

- (void)render;

@end

NS_ASSUME_NONNULL_END
