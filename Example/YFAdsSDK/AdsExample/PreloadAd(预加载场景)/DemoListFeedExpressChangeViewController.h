//
//  DemoListFeedExpressViewController.h
//  Example
//
//  Created by CherryKing on 2019/11/21.
//  Copyright © 2019 CherryKing. All rights reserved.
//

#import "DemoBaseViewController.h"
#import <YFAdsSDK/YFAdNativeExpress.h>

NS_ASSUME_NONNULL_BEGIN

@interface DemoListFeedExpressChangeViewController : DemoBaseViewController
@property (nonatomic, strong) NSMutableArray *arrViewsM;
@property (nonatomic, strong) NSMutableArray <YFAdNativeExpress *>*adRequestArray;

@end

NS_ASSUME_NONNULL_END
