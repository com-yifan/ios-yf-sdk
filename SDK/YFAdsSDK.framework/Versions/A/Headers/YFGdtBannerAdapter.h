//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <YFAdsSDK/YFAdBaseAdPosition.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdBannerDelegate.h>


@class EasyAdBanner;

NS_ASSUME_NONNULL_BEGIN

@interface YFGdtBannerAdapter : YFAdBaseAdPosition

@property (nonatomic, weak) id<YFAdBannerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
