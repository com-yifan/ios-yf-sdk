//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <YFAdsSDK/YFAdBaseAdPosition.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdRewardVideoDelegate.h>



NS_ASSUME_NONNULL_BEGIN

@interface YFGroRewardVideoAdapter : YFAdBaseAdPosition
@property (nonatomic, weak) id<YFAdRewardVideoDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
