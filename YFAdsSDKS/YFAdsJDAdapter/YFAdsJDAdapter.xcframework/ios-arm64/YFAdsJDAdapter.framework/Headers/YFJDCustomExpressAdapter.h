//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#if __has_include(<JADYun/JADYun.h>)
#import <JADYun/JADYun.h>
#import <YFAdsSDK/YFAdBaseAdPosition.h>
#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdNativeExpressDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFJDCustomExpressAdapter : YFAdBaseAdPosition
@property (nonatomic, weak) id<YFAdNativeExpressDelegate> delegate;
@property (nonatomic, assign) float left;

@end

NS_ASSUME_NONNULL_END
#endif
