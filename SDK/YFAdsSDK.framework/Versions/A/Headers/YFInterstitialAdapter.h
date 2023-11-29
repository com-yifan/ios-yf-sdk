//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YFAdInterstitialDelegate.h"
#import "YFAdBaseAdPosition.h"

NS_ASSUME_NONNULL_BEGIN

@class YFAdInterstitial;

@interface YFInterstitialAdapter : YFAdBaseAdPosition
@property(nonatomic, weak) id <YFAdInterstitialDelegate> delegate;


@end

NS_ASSUME_NONNULL_END
