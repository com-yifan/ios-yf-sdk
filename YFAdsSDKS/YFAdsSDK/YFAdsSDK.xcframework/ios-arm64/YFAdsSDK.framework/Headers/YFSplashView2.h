//
//  YFSplashView2.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/18.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdBaseView.h>
#import <YFAdsSDK/YFAdView.h>
#import <YFAdsSDK/YFAdMarkImageView.h>
#import <YFAdsSubstrate/YFAnimationView.h>
#import <YFAdsSDK/YFAdInteractionType.h>
#import <YFAdsSDK/YFSplashEnum.h>
#import <YFAdsSDK/YFAdInteractionType.h>
#import <YFAdsSDK/YFAdInteractionType.h>
#import <YFAdsSDK/YFAdSplashAdExtraDataModel.h>
#import <YFAdsSDK/YFMotionManager.h>
#import <YFAdsSDK/YFMaterialMeta.h>
#import <YFAdsSDK/YFAdReportModel.h>
#import <YFAdsSDK/YFTapBarAnimationView.h>
#import <YFAdsSDK/YFAdError.h>
///delegate先用1里的
#import <YFAdsSDK/YFSplashView.h>



NS_ASSUME_NONNULL_BEGIN


@class YFSplashView2;


@interface YFSplashView2 : YFAdBaseView


@property(nonatomic, weak) id <YFSplashAdViewDelegate> delegate;
@property(nonatomic, weak) UIViewController *rootViewController;
/// max timeout interval, default is 5
@property(nonatomic, assign) NSTimeInterval timeoutInterval;
@property(nonatomic, assign,readonly) BOOL autoClick;
/// ad interaction type, avaliable after ksad_splashAdContentDidLoad:
@property(nonatomic, assign, readonly) YFAdInteractionType interactionType;
/// ad material type, avaliable after ksad_splashAdContentDidLoad:
@property(nonatomic, assign, readonly) YFAdMaterialType materialType;
@property(nonatomic, readonly) BOOL isValid;
@property(nonatomic, assign) NSUInteger ecpm;

- (id)initWithPosId:(NSString *)posId model:(id)model;

//-(void)toSetYFAdEventModel:(YFAdEventModel *)eventModel;
//屏蔽摇一摇/是否屏蔽扭一扭/是否屏蔽手势滑动转化
- (void)setExtraData:(YFAdSplashAdExtraDataModel *)extraDataModel;

// load ad data
- (void)loadAdData;

//-(void)show ;
- (void)showInView:(UIView *)view;

-(void)closeAction;


@end

NS_ASSUME_NONNULL_END

