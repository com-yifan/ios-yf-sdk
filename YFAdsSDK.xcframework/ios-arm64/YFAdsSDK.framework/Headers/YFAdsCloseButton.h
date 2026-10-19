//
//  YFAdsCountButton.h
//  YFAdsSDK
//
//  Created by aiken on 2024/6/11.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdReportModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdsCloseButton : UIButton

@property (nonatomic, strong) UIView *cover;
// 关闭回调
@property (nonatomic, copy) void (^closeCompletion)(BOOL isAuto);

- (instancetype)initWithModel:(YFAdEventModel *)event;

- (void)reset;

/// 模板广告加载时调用：取消初始化计时，保留遮罩直到首次曝光。
- (void)yf_prepareCloseCoverForExposure;
/// 首次曝光开始按 cbde（毫秒）计时；重复调用不会重置计时。
- (void)yf_startCloseCoverCountdown;

@end

NS_ASSUME_NONNULL_END
