//
//  DemoDrawAdCell.h
//  YFAdsSDK_Example
//
//  Created by jiangchao on 2024/1/13.
//  Copyright © 2024 Cheng455153666. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class YFAdDrawView;
@interface DemoDrawAdCell : UITableViewCell
- (void)refreshWithDrawAd:(YFAdDrawView *)drawAd;
@end

NS_ASSUME_NONNULL_END
