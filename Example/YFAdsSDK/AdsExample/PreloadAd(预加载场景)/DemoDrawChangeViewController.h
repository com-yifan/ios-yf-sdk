//
//  DemoDrawViewController.h
//  Example
//
//  Created by CherryKing on 2019/11/21.
//  Copyright © 2019 CherryKing. All rights reserved.
//

#import "DemoBaseViewController.h"
#import <YFAdsSDK/YFAdBaseAdapter.h>
NS_ASSUME_NONNULL_BEGIN

@interface DemoDrawChangeViewController : DemoBaseViewController
@property (nonatomic, strong) NSMutableArray *adViews;
@property (nonatomic, strong) YFAdBaseAdapter *adapter;
@end

NS_ASSUME_NONNULL_END
