//
//  YFAdsCountButton.h
//  YFAdsSDK
//
//  Created by aiken on 2024/6/11.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdReportModel.h>
#import <YFAdsSDK/UIImageView+YF_WebCache.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdsCloseButton : UIButton

@property (nonatomic, strong) UIView *cover;
// 关闭回调
@property (nonatomic, copy) void (^closeCompletion)(BOOL isAuto);

- (instancetype)initWithModel:(YFAdEventModel *)event;
@end

NS_ASSUME_NONNULL_END
