//
//  YFAdBaseCustomView.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/10/7.
//

#import <UIKit/UIKit.h>
//#import <YFAdsSDK/YFAdInterstitial+TopPush.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdBaseCustomView : UIView // <YFAssociationTopPushDelegate>
//@property (nonatomic, weak) YFAdInterstitial *adSpot;
@property(nonatomic,copy) void (^exposureBlk)(void);
@property (nonatomic, copy) void(^renderCompletion)(BOOL, NSError * _Nullable);
//- (void)showAssciatonTopPush;
/// 销毁定时器
- (void)destroyTrackTimer;
/// 本地可见性监测首次命中曝光时调用，先于 exposureBlk；子类可扩展。
- (void)yf_didTrackExposure;
/// 广告视图高度
- (float)getViewHeight;
/// 设置边距后元素相应缩放
- (float)scaleWith600_150;
- (float)scaleWith600_400;
- (float)scaleWith600_260;
- (float)scaleWith640_100;
@end

NS_ASSUME_NONNULL_END
