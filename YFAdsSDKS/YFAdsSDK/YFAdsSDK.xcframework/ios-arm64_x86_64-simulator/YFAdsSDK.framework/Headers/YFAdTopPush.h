//
//  YFAdTopPush.h
//  YFAdsSDK
//
//  Created by Erik on 2025/9/17.
//

#import <YFAdsSDK/YFAdBaseAdapter.h>
#import <YFAdsSDK/YFAdTopPushDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdTopPush : YFAdBaseAdapter

/// 广告方法回调代理
@property (nonatomic, weak) id<YFAdTopPushDelegate> delegate;

/// 展示的顶推广告联盟，加载成功后获取
@property (nonatomic, assign, readonly) YFAdnType adn;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithAdUnitID:(NSString *)pID NS_UNAVAILABLE;

/// 初始化顶推广告
/// - Parameters:
///   - pID: 广告位ID
///   - viewController: 打开落地页的控制器
- (instancetype)initWithAdUnitID:(NSString *)pID withViewController:(UIViewController *)viewController;

/// 主动关闭顶推广告
- (void)close;

/// 不适用，请直接使用- (void)close;
- (void)closeTopPushAd NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
