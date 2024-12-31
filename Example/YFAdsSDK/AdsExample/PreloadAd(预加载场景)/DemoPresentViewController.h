//
//  DemoPresentViewController.h
//  YFAdsSDK_Example
//
//  Created by jiangchao on 2023/12/25.
//  Copyright © 2023 Cheng455153666. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdBaseAdapter.h>
#import "DemoBaseViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface DemoPresentViewController :  DemoBaseViewController

@property (nonatomic, strong) YFAdBaseAdapter *adapter;


@end

NS_ASSUME_NONNULL_END
