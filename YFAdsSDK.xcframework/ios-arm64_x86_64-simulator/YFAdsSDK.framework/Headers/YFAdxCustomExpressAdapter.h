//
//  YFAdxCustomExpressAdapter.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/8/31.
//


#import <Foundation/Foundation.h>
#import <YFAdsSDK/ADXNativeAd.h>
#import <YFAdsSDK/YFAdNativeExpressDelegate.h>
#import <YFAdsSDK/YFAdBaseAdPosition.h>

NS_ASSUME_NONNULL_BEGIN

@class ADXNativeAd;

@interface YFAdxCustomExpressAdapter : YFAdBaseAdPosition
@property(nonatomic, weak) id <YFAdNativeExpressDelegate> delegate;


@end

NS_ASSUME_NONNULL_END
