//
//  YFBdAdBaseBannerView.h
//  YFAdsBDAdapter
//
//  Created by Erik on 2025/1/2.
//

#import <YFAdsSDK/YFAdsSDK.h>

NS_ASSUME_NONNULL_BEGIN
/// 百度自渲染信息流广告基类
@interface YFBdAdBaseBannerView : YFAdBaseCustomView
- (instancetype)initWithFrame:(CGRect)frame model:(id)model;
- (void)loadAdData:(id)object close:(void(^)(id))close;
- (void)show;
- (void)pauseVideo;
- (void)playVideo;
- (void)toAddShakeView;
- (void)trackImpression;
@end

NS_ASSUME_NONNULL_END
