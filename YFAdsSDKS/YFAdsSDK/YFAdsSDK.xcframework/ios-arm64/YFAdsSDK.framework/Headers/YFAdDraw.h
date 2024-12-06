//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <YFAdsSDK/YFAdBaseAdapter.h>
#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdSDKSetting.h>
#import <YFAdsSDK/YFAdDrawDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdDraw : YFAdBaseAdapter
/// 广告方法回调代理
@property (nonatomic, weak) id<YFAdDrawDelegate> delegate;
/// 广告尺寸
@property (nonatomic, assign) CGSize adSize;
/// 广告条数
@property (nonatomic, assign) NSInteger count;

/// @param pID 广告位
/// @param viewController  viewController
/// @param size 尺寸
- (instancetype)initWithAdUnitID:(NSString *)pID viewController:(UIViewController *)viewController adSize:(CGSize)size;




@end

NS_ASSUME_NONNULL_END
