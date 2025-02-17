//
//  YFAdsCountButton.h
//  YFAdsSDK
//
//  Created by aiken on 2024/6/11.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdReportModel.h>
#import <YFAdsSubstrate/YFAnimationView.h>


NS_ASSUME_NONNULL_BEGIN

@interface YFAdsDetailButton : UIView

@property(nonatomic, strong) YFAnimationView *lotAnimation;
@property(nonatomic, copy) NSString * text;

@property (nonatomic, strong) UILabel *titleLabel;
- (instancetype)initWithModel:(YFAdEventModel *)event;


@end

NS_ASSUME_NONNULL_END
