//
//  YFAdsCountButton.h
//  YFAdsSDK
//
//  Created by aiken on 2024/6/11.
//

#import <UIKit/UIKit.h>
#import "YFAdReportModel.h"
#import "YFAnimationView.h"


NS_ASSUME_NONNULL_BEGIN

@interface YFAdsDetailButton : UIButton

@property(nonatomic, strong) YFAnimationView *lotAnimation;
@property(nonatomic, copy) NSString * text;

- (instancetype)initWithModel:(YFAdEventModel *)event;


@end

NS_ASSUME_NONNULL_END
