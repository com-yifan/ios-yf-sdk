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
// 唯一标识
@property (nonatomic, assign) NSUInteger tag;
// 渠道标识 1 穿山甲；2 优量汇；3 百度 4快手  5 亿帆 9 京东  adx 12 14 Tanx
@property (nonatomic, assign) NSUInteger identifier;
// 是否有效
-(BOOL) isValid;

@property (nonatomic) BOOL valid;

- (void)setRootController:(UIViewController *)rootController;

- (void)render;

@end

NS_ASSUME_NONNULL_END
