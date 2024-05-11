//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import "YFAdBaseAdapter.h"
#import <UIKit/UIKit.h>
#import "YFAdSDKSetting.h"
#import <YFAdsSDK/YFAdRewardVideoDelegate.h>

typedef NS_ENUM(NSInteger, YFAdsShowDirection) {
    YFAdsShowDirectionVertical    = 0,     //竖屏
    YFAdsShowDirectionHorizontal  = 1,     //横屏
};

NS_ASSUME_NONNULL_BEGIN

@interface YFAdRewardVideo : YFAdBaseAdapter
/// 广告方法回调代理
@property (nonatomic, weak) id<YFAdRewardVideoDelegate> delegate;
/// 用户ID
@property (nonatomic, copy) NSString *userId;
/// 拓展字段 json字符串
@property (nonatomic, copy) NSString *extra;
/// 仅支持快手（百度，优量汇，自适应屏幕方向。穿山甲联系运营配置）
@property (nonatomic, assign) YFAdsShowDirection  adsShowDirection;

- (instancetype)initWithAdUnitID:(NSString *)pID viewController:(UIViewController *)viewController;        
@end

NS_ASSUME_NONNULL_END
