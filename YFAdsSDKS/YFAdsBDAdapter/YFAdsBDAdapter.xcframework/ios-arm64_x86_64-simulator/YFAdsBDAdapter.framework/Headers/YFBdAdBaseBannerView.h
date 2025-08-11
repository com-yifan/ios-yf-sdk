//
//  YFBdAdBaseBannerView.h
//  YFAdsBDAdapter
//
//  Created by Erik on 2025/1/2.
//

#import <YFAdsSDK/YFAdsSDK.h>
#if __has_include(<BaiduMobAdSDK/BaiduMobAdNativeAdView.h>)
#import <BaiduMobAdSDK/BaiduMobAdNativeAdObject.h>
#import <BaiduMobAdSDK/BaiduMobAdNativeShakeView.h>
NS_ASSUME_NONNULL_BEGIN
/// 百度自渲染信息流广告基类
@interface YFBdAdBaseBannerView : YFAdBaseCustomView

// 百度返回摇一摇组件
@property (nonatomic, strong, nullable) BaiduMobAdNativeShakeView *shakeView;

- (instancetype)initWithFrame:(CGRect)frame model:(id)model;
- (void)loadAdData:(id)object close:(void(^)(id))close;
- (void)show;
- (void)pauseVideo;
- (void)playVideo;
- (void)toAddShakeView;
- (void)trackImpression;

@end

NS_ASSUME_NONNULL_END
#endif
