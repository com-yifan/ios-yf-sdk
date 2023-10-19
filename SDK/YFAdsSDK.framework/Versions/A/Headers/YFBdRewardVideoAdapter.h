//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YFAdRewardVideoDelegate.h"
#import "YFAdBaseAdPosition.h"


@class YFAdRewardVideo;

NS_ASSUME_NONNULL_BEGIN

@interface YFBdRewardVideoAdapter : YFAdBaseAdPosition
@property (nonatomic, weak) id<YFAdRewardVideoDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
