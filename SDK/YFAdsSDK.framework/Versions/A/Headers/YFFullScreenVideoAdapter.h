//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import "YFAdBaseAdPosition.h"
#import <Foundation/Foundation.h>
#import "YFAdFullScreenVideoDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class YFAdFullScreenVideo;

@interface YFFullScreenVideoAdapter : YFAdBaseAdPosition
@property(nonatomic, weak) id <YFAdFullScreenVideoDelegate> delegate;


@end

NS_ASSUME_NONNULL_END
