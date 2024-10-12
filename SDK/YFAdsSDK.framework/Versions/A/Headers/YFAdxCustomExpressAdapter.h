//
//  YFAdxCustomExpressAdapter.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/8/31.
//


#import <Foundation/Foundation.h>
#import "ADXNativeAd.h"
#import "YFAdNativeExpressDelegate.h"
#import <YFAdsSDK/YFAdBaseAdPosition.h>

NS_ASSUME_NONNULL_BEGIN

@class ADXNativeAd;

@interface YFAdxCustomExpressAdapter : YFAdBaseAdPosition
@property(nonatomic, weak) id <YFAdNativeExpressDelegate> delegate;


@end

NS_ASSUME_NONNULL_END
