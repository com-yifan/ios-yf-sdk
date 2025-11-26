//
//  YFSplashWithMallManager.h
//  YFAdsSDK
//
//  Created by Erik on 2025/11/4.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdSplash.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFSplashWithMallManager : NSObject

+ (instancetype)sharedInstance;
- (void)startLoadMallAdWithAdId:(NSString *)adId;
- (void)showMallAd;

/// 隐藏开屏关联红包浮窗
- (void)hideFloatIcon;
/// 显示开屏关联红包浮窗
- (void)showFloatIcon;

@end

NS_ASSUME_NONNULL_END
