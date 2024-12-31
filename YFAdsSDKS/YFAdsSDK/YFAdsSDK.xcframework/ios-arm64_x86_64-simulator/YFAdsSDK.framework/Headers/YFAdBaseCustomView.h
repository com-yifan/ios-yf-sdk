//
//  YFAdBaseCustomView.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/10/7.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdBaseCustomView : UIView
@property(nonatomic,copy) void (^exposureBlk)(void);
@property (nonatomic, copy) void(^renderCompletion)(BOOL, NSError * _Nullable);
/// 销毁定时器
- (void)destroyTrackTimer;
/// 设置边距后元素相应缩放
- (float)scaleWith600_150;
- (float)scaleWith600_400;
/// 广告视图高度
- (float)getViewHeight;
@end

NS_ASSUME_NONNULL_END
