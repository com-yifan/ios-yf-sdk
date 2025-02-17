//
//  YFKsInterstitialViewController.h
//  YFAdsSDK
//
//  Created by Erik on 2024/11/9.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFKsInterstitialViewController : UIViewController

@property (nonatomic, copy) void (^presentController)(void);

@end

NS_ASSUME_NONNULL_END
