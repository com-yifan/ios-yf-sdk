//
//  YFAdsCountButton.h
//  YFAdsSDK
//
//  Created by aiken on 2024/6/11.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdReportModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdsCountButton : UIButton

@property (nonatomic, strong) UIView * cover;

// 设置倒计时时长
@property (nonatomic, assign) NSInteger countdownDuration;

// 倒计时结束回调
@property (nonatomic, copy) void (^countdownCompletion)(BOOL isAuto);
// 点击事件
@property (nonatomic, copy) void (^tapClick)(void);

// 开始倒计时
- (void)startCountdown:(YFAdEventModel *)event;
- (void)close;
- (void)cancel;
@end

NS_ASSUME_NONNULL_END
