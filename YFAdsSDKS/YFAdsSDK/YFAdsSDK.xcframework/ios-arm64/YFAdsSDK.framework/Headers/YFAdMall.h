//
//  YFAdMall.h
//  YFAdsSDK
//
//  Created by Erik on 2025/11/1.
//

#import <YFAdsSDK/YFAdBaseAdapter.h>
#import <YFAdsSDK/YFAdMallDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdMall : YFAdBaseAdapter

/// 广告方法回调代理
@property (nonatomic, weak) id<YFAdMallDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithAdUnitID:(NSString *)pID withViewController:(UIViewController *)viewController NS_UNAVAILABLE;
/// 初始化商城广告
/// - Parameters:
///   - pID: 广告位ID
///   - viewController: 打开落地页的控制器
- (instancetype)initWithAdUnitID:(NSString *)pID;

/// 加载广告
- (void)loadAd;
/// 展示广告
- (void)showAd;
/// 加载并展示广告
- (void)loadAndShowAd;

/// 暂时隐藏和显示浮窗icon
- (void)hideFloatIcon;
- (void)showFloatIcon;

- (void)showAdFromViewController:( UIViewController * _Nullable)viewController NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
