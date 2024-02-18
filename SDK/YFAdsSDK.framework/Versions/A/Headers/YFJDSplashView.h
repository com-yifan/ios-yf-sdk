//
//  YFJDSplashView.h
//  YFAdsSDK
//
//  Created by feng on 2023/11/8.
//


#import <UIKit/UIKit.h>
#if __has_include(<JADYun/JADYun.h>)
#import <JADYun/JADYun.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFJDSplashView : UIView

@property(nonatomic, weak) UIViewController *rootViewController;
@property(nonatomic, assign) NSUInteger ecpm;
@property(nonatomic, strong) UIView *area;
-(instancetype)initWithSplashMode:(id)model;

- (void)showInView:(UIView *)view;

-(void)loadAdData:(JADNativeAd *)dataObject;

-(void)toSetJumpTitle:(int )countDown;

-(void)toCloseNativeAdView;


@end

NS_ASSUME_NONNULL_END
#endif
