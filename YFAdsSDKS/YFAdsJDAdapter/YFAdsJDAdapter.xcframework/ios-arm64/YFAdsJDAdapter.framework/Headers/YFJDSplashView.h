//
//  YFJDSplashView.h
//  YFAdsSDK
//
//  Created by feng on 2023/11/8.
//


#import <YFAdsSDK/YFAdBaseCustomView.h>
#if __has_include(<JADYun/JADYun.h>)
#import <JADYun/JADYun.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFJDSplashView : YFAdBaseCustomView

@property(nonatomic, weak) UIViewController *rootViewController;
@property(nonatomic, assign) NSUInteger ecpm;
@property(nonatomic, strong) UIView *area;
@property(nonatomic, strong) UIButton *jumpBtn;
@property(nonatomic, assign) BOOL isvalid;

-(instancetype)initWithSplashMode:(id)model;

- (void)showInView:(UIView *)view;

-(void)loadAdData:(JADNativeAd *)dataObject;

-(void)toSetJumpTitle:(int )countDown;

-(void)toCloseNativeAdView;


@end

NS_ASSUME_NONNULL_END
#endif
