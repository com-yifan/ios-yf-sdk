//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import "YFAdBaseAdapter.h"

#import <UIKit/UIKit.h>

#import "YFAdSDKSetting.h"
#import "YFAdInterstitialDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFAdInterstitial : YFAdBaseAdapter <NSCopying>
/// 广告方法回调代理
@property (nonatomic, weak) id<YFAdInterstitialDelegate> delegate;

- (instancetype)initWithAdUnitID:(NSString *)pID viewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
