//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "YFAdSplashDelegate.h"
#import "YFAdBaseAdPosition.h"

@class YFAdSplash;

NS_ASSUME_NONNULL_BEGIN

@interface YFBdSplashAdapter : YFAdBaseAdPosition

@property (nonatomic, weak) id<YFAdSplashDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
