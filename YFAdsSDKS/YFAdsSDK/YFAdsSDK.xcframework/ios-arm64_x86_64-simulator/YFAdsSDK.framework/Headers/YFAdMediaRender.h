//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <YFAdsSDK/YFAdBaseAdapter.h>

#import <UIKit/UIKit.h>

#import <YFAdsSDK/YFAdSDKSetting.h>
#import <YFAdsSDK/YFAdMediaDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdMediaRender : YFAdBaseAdapter
/// 广告方法回调代理
@property (nonatomic, weak) id<YFAdMediaDelegate> delegate;

- (instancetype)initWithAdUnitID:(NSString *)pID viewController:(UIViewController *)viewController;
- (instancetype)initWithAdUnitID:(NSString *)pID viewController:(UIViewController *)viewController videoViewFrame:(CGRect)videoFrame;

@end

NS_ASSUME_NONNULL_END
