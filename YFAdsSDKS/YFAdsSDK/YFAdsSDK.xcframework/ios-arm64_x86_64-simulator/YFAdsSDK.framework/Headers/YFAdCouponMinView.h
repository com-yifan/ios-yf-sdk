//
//  YFAdCouponMinView.h
//  YFAdsSDK
//

#import <UIKit/UIKit.h>

@class YFAdCouponModel;

NS_ASSUME_NONNULL_BEGIN

/// ADX 优惠券精简样式。内部按 100x92pt 基准尺寸整体等比缩放。
@interface YFAdCouponMinView : UIView

@property (nonatomic, strong, readonly) YFAdCouponModel *coupon;

+ (CGSize)preferredSize;
- (instancetype)initWithCoupon:(YFAdCouponModel *)coupon;
- (instancetype)initWithFrame:(CGRect)frame coupon:(YFAdCouponModel *)coupon NS_DESIGNATED_INITIALIZER;
- (void)updateWithCoupon:(YFAdCouponModel *)coupon;
/// 重播渐显放大后缩小至原尺寸的入场动画
- (void)playAppearAnimation;

@end

NS_ASSUME_NONNULL_END
