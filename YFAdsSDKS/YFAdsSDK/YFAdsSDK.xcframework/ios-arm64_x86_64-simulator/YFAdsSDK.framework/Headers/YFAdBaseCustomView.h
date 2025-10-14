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
/// 广告视图高度
- (float)getViewHeight;
/// 设置边距后元素相应缩放
- (float)scaleWith600_150;
- (float)scaleWith600_400;
- (float)scaleWith600_260;
- (float)scaleWith640_100;
@end

NS_ASSUME_NONNULL_END
