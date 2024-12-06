//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <YFAdsSDK/YFAdBaseAdPosition.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdInterstitialDelegate.h>


@class EasyAdInterstitial;

NS_ASSUME_NONNULL_BEGIN

@interface YFBdInterstitialAdapter : YFAdBaseAdPosition
@property (nonatomic, weak) id<YFAdInterstitialDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
