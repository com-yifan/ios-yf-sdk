//
//  YFSplashButton.h
//  YFAdsSDK
//
//  Created by feng on 2023/11/11.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdReportModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFSplashButton : UIButton
@property(nonatomic,strong)UILabel *splashTitleL;
@property (nonatomic, strong) UIView *cover;
-(void)setDelayEffectByModel:(YFAdEventModel *)eventModel;
@end

NS_ASSUME_NONNULL_END
