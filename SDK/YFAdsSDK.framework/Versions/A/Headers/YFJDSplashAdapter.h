//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import "YFAdBaseAdPosition.h"
#if __has_include(<JADYun/JADYun.h>)
#import <JADYun/JADYun.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YFAdSplashDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFJDSplashAdapter : YFAdBaseAdPosition
@property (nonatomic, weak) id<YFAdSplashDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
#endif
