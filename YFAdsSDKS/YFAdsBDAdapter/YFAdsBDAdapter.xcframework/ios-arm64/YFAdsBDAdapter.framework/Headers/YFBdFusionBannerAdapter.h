//
//  YFBdFusionBannerAdapter.h
//  YFAdsSDK
//
//  Created by Erik on 2024/10/25.
//

#import <YFAdsSDK/YFAdBaseAdPosition.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdFusionBannerDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFBdFusionBannerAdapter : YFAdBaseAdPosition

@property (nonatomic, weak) id<YFAdFusionBannerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
