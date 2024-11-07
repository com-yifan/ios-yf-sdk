//
//  YFAdFusionBannerView.h
//  YFAdsSDK
//
//  Created by Erik on 2024/10/23.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
/// 融合banner返回广告所属平台
typedef enum : NSUInteger {
    // 穿山甲
    YFAdFusionBannerPlatform_CSJ,
    // 优量汇
    YFAdFusionBannerPlatform_YLH,
    // 百度
    YFAdFusionBannerPlatform_BD,
    // 快手
    YFAdFusionBannerPlatform_KS,
    // 京东
    YFAdFusionBannerPlatform_JD,
    // 亿帆
    YFAdFusionBannerPlatform_YF,
    // Tanx
    YFAdFusionBannerPlatform_Tanx
} YFAdFusionBannerPlatform;

/// 融合Banner返回的广告类型
typedef enum : NSUInteger {
    // 横幅
    YFAdFusionBannerAdType_Banner,
    // 自渲染信息流
    YFAdFusionBannerAdType_CustomNative,
    // 模板信息流
    YFAdFusionBannerAdType_Express
} YFAdFusionBannerAdType;

@interface YFAdFusionBannerView : UIView
/// 所属联盟平台
@property (nonatomic, assign) YFAdFusionBannerPlatform platform;
/// 融合banner返回的广告类型
@property (nonatomic, assign) YFAdFusionBannerAdType adType;
/// 广告视图
@property (nonatomic, strong) UIView *adView;
/// 是否渲染成功（素材加载完成，图片可以显示或视频可以播放）
@property (nonatomic, assign) BOOL isReady;
/// 渲染广告；调用该方法后开始渲染广告，成功回调 fcAdFusionBannerOnAdRenderSuccess: 渲染失败回调 fcAdFusionBannerOnAdRenderFail
- (void)render;

@end

NS_ASSUME_NONNULL_END
