//
//  YFAdDetailViewController.h
//  YFAdsSDK
//
//  Created by aiken on 2023/10/23.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdDetailViewController : UIViewController

@property(nonatomic,copy)NSString *url;
@property(nonatomic,copy) void (^complete)(BOOL success);
@property(nonatomic,assign) BOOL present;

@end

NS_ASSUME_NONNULL_END
