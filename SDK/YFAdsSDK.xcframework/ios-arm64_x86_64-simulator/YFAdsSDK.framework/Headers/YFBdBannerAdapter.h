//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <YFAdsSDK/YFAdBaseAdPosition.h>
#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdBannerDelegate.h>

@class YFAdBanner;

NS_ASSUME_NONNULL_BEGIN

@interface YFBdBannerAdapter : YFAdBaseAdPosition
@property (nonatomic, weak) id<YFAdBannerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
 
