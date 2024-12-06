//
//  YFAdDrawView.h
//  YFAdsSDK
//
//  Created by jiangchao on 2024/1/11.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdDrawView : NSObject
- (instancetype)initWithViewController:(UIViewController *)controller;
@property (nonatomic, strong) id adData;
- (void)registerContainer:(UIView *)containerView;
- (void)unregisterView;
- (void)setRootViewController:(UIViewController *)rootVC;

@end

NS_ASSUME_NONNULL_END
