//
//  YFAdDetailViewController.h
//  YFAdsSDK
//
//  Created by aiken on 2023/10/23.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdBaseViewController.h>
#import <YFAdsSDK/YFRouter.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdDetailViewController : YFAdBaseViewController

@property(nonatomic,copy)NSString *url;
@property(nonatomic,copy) void (^complete)(YFRouterResult success);
@property(nonatomic,assign) BOOL present;
@property (nonatomic, assign) BOOL callOpen;

@end

NS_ASSUME_NONNULL_END
