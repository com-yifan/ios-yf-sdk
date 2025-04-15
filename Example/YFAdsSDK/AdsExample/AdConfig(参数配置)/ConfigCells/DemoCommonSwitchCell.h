//
//  DemoCommonSwitchCell.h
//  YFAdsDemo_Example
//
//  Created by Erik on 2025/3/26.
//  Copyright © 2025 Nanjing Fengchuan Yunju Infomation Technology Co., LTD. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DemoCommonSwitchCell : UITableViewCell

@property (nonatomic, copy) void(^switchStateChanged)(BOOL state);

- (void)updateTitle:(NSString *)title;
- (void)updateSwitchState:(BOOL)isOn;

@end

NS_ASSUME_NONNULL_END
