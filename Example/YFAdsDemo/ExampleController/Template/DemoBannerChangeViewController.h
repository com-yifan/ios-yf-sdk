//
//  DemoBannerViewController.h
//  Example
//
//  Created by CherryKing on 2019/11/8.
//  Copyright © 2019 CherryKing. All rights reserved.
//

#import "BaseViewController.h"
#import <YFAdsSDK/YFAdBaseAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@interface DemoBannerChangeViewController : BaseViewController

@property (nonatomic, strong) UIView *adView;
@property (nonatomic, strong) YFAdBaseAdapter *adapter;
@end

NS_ASSUME_NONNULL_END
