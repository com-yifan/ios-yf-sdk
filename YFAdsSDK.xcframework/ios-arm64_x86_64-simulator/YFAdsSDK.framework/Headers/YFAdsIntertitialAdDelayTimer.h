//
//  YFAdsIntertitialAdDelayTimer.h
//  YFAdsSDK
//
//  Created by Erik on 2024/12/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdReportModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol YFAdsIntertitialAdDelayTimerDelegate <NSObject>

@required
/// 达到需要延迟时长
- (void)intertitialAdDelayTimeOver;

@end

@interface YFAdsIntertitialAdDelayTimer : NSObject
// 代理对象
@property (nonatomic, weak) id<YFAdsIntertitialAdDelayTimerDelegate> delegate;
// 延迟关闭结束
@property (nonatomic, assign, readonly) BOOL isDelayOver;
- (instancetype)initWithEventModel:(YFAdEventModel *)eventModel controller:(nullable UIViewController *)intertitialAdController view:(nullable UIView *)intertitialAdView;
// 暂停
- (void)pause;
// 恢复
- (void)resume;
// 取消
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
