//
//  YFAdCouponModel.h
//  YFAdsSDK
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, YFAdCouponType) {
    /// 无门槛固定金额减免券
    YFAdCouponTypeNoThreshold = 1,
    /// 满减固定金额减免券
    YFAdCouponTypeFullReduction = 2,
    /// 折扣券
    YFAdCouponTypeDiscount = 3,
};

@interface YFAdCouponModel : NSObject <YFAdModel>

/// 优惠券类型
@property (nonatomic, assign) YFAdCouponType coupon_type;
/// 使用门槛，单位：分。0 表示无门槛
@property (nonatomic, assign) NSInteger threshold;
/// 固定金额券单位为分；折扣券 value=80 表示 8 折
@property (nonatomic, assign) NSInteger value;
/// 绝对过期时间戳，单位：秒
@property (nonatomic, assign) NSInteger expire_absolute_sec;
/// 扩展信息
@property (nonatomic, copy, nullable) NSString *ext_info;

/// 优惠券类型文案
@property (nonatomic, copy, readonly) NSString *typeText;
/// “无门槛立减”或“满XX元可用”
@property (nonatomic, copy, readonly) NSString *usageText;
/// 减免金额或折扣数字，不包含“¥”和“折”
@property (nonatomic, copy, readonly) NSString *displayValueText;
/// 当前是否已过期。未提供过期时间时返回 NO
@property (nonatomic, assign, readonly, getter=isExpired) BOOL expired;

@end

NS_ASSUME_NONNULL_END
