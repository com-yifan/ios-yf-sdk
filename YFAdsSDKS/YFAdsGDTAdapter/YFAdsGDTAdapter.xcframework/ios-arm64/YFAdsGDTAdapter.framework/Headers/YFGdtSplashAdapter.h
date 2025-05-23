//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <YFAdsSDK/YFAdBaseAdPosition.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdSplashDelegate.h>


@class YFAdSplash;

NS_ASSUME_NONNULL_BEGIN

@interface YFGdtSplashAdapter : YFAdBaseAdPosition
@property (nonatomic, weak) id<YFAdSplashDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
