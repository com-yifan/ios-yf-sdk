//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <YFAdsSDK/YFAdBaseAdPosition.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdSplashDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFGroSplashAdapter : YFAdBaseAdPosition
@property (nonatomic, weak) id<YFAdSplashDelegate> delegate;

@end

NS_ASSUME_NONNULL_END