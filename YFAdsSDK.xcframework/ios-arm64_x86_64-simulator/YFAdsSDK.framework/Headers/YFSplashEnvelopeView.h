//
//  YFSplashEnvelopeView.h
//  YFAdsSDK-YFAdsSDK
//
//  Created by 麻明康 on 2024/9/16.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdView.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFSplashEnvelopeView : UIImageView
@property (nonatomic, strong) UIImageView *yf_sp_envelope_inner;
@property (nonatomic, strong) UIImageView *yf_sp_envelope_cover;
@property (nonatomic, strong) UIImageView *yf_sp_envelope_letter;
@property(nonatomic, strong) YFAdImageView *brandLogoView;
@property (nonatomic, strong) UILabel *brandDescLab;
@property (nonatomic, weak) UILabel *adDescLab;
-(void)letterAddSubView:(UIView *)View;
@end

NS_ASSUME_NONNULL_END
