//
//  YFGdtFusionBannerAdapter.h
//  YFAdsSDK
//
//  Created by Erik on 2024/10/24.
//

#import <YFAdsSDK/YFAdBaseAdPosition.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdFusionBannerDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFGdtFusionBannerAdapter : YFAdBaseAdPosition

@property (nonatomic, weak) id<YFAdFusionBannerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
