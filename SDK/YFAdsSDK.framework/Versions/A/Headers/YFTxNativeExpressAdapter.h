//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <YFAdsSDK/YFAdBaseAdPosition.h>
#import <Foundation/Foundation.h>
#import "YFAdNativeExpressDelegate.h"

NS_ASSUME_NONNULL_BEGIN


@interface YFTxNativeExpressAdapter : YFAdBaseAdPosition
@property (nonatomic, weak) id<YFAdNativeExpressDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
