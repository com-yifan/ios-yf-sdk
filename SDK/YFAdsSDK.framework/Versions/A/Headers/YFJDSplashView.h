//
//  YFJDSplashView.h
//  YFAdsSDK
//
//  Created by feng on 2023/11/8.
//


#import <UIKit/UIKit.h>
#if __has_include(<JADYun/JADYun.h>)
#import <JADYun/JADYun.h>
#import "YFAdInteractionType.h"
NS_ASSUME_NONNULL_BEGIN

@interface YFJDSplashView : UIView

@property(nonatomic, weak) UIViewController *rootViewController;
/// ad interaction type, avaliable after ksad_splashAdContentDidLoad:
@property(nonatomic, assign, readonly) YFAdInteractionType interactionType;
/// ad material type, avaliable after ksad_splashAdContentDidLoad:
@property(nonatomic, assign, readonly) YFAdMaterialType materialType;
@property(nonatomic, assign) NSUInteger ecpm;
@property(nonatomic,strong)JADNativeAd *natived;
@property(nonatomic,strong) JADNativeAdData *nativeAdData;
@property(nonatomic, strong) UIView *area;
/**
 * @brief 开屏样式
 * @discussion 开屏广告样式，具体样式类型可查看JADYunConstant.h中声明。
 * 注意：如果您开启了动态化渲染，该属性配置则不生效
 */
@property (nonatomic, assign) JADSplashStyle splashStyle;

/**
 * @brief 手势类型
 * @discussion 触发点击事件的手势类型
 */
@property (nonatomic, assign) JADClickEventTriggerType triggerType DEPRECATED_ATTRIBUTE;

-(instancetype)initWithSplashMode:(id)model;

- (void)showInView:(UIView *)view;

-(void)loadAdData:(JADNativeAd *)dataObject close: (void(^)(id))close;


-(void)toSetJumpTitle:(int )countDown;

-(void)toCloseNativeAdView;


@end

NS_ASSUME_NONNULL_END
#endif
