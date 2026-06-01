//
//  YFAdTextLink.h
//  YFAdsSDK
//
//  Created by Codex on 2026/4/9.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdBaseAdapter.h>
#import <YFAdsSDK/YFAdTextLinkDelegate.h>
#import <YFAdsSDK/YFAdTextLinkView.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdTextLink : YFAdBaseAdapter

/// 广告方法回调代理
@property (nonatomic, weak) id<YFAdTextLinkDelegate> delegate;

/// 展示的文字链广告联盟，加载成功后获取
@property (nonatomic, assign, readonly) YFAdnType adn;
/// 加载成功后返回的广告视图，由开发者自行添加到界面上展示
@property (nonatomic, strong, readonly, nullable) YFAdTextLinkView *adView;
/// 广告尺寸，默认使用 SDK 预设大小 `(0, 0, 屏宽-32, 27)`
@property (nonatomic, assign) CGSize adSize;
/// 文字字号，默认 15
@property (nonatomic, assign) CGFloat fontSize;
/// 文字颜色，默认黑色
@property (nonatomic, strong, nullable) UIColor *fontColor;
/// 广告区域背景色，默认浅灰
@property (nonatomic, strong, nullable) UIColor *adBackgroundColor;
/// 文字边距。有图片时表示文字与图片的间距；无图片时表示文字距视图左侧的间距。支持传 0，未设置时默认 10
@property (nonatomic, assign) CGFloat textPadding;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithAdUnitID:(NSString *)pID NS_UNAVAILABLE;
- (void)loadAndShowAd NS_UNAVAILABLE;
- (void)showAd NS_UNAVAILABLE;

/// 初始化文字链广告
/// - Parameters:
///   - pID: 广告位ID
///   - viewController: 打开落地页的控制器
- (instancetype)initWithAdUnitID:(NSString *)pID withViewController:(UIViewController *)viewController;

/// 加载广告
- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
