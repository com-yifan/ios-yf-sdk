//
//  YFAdBaseSplashView.h
//  YFAdsSDK
//
//  Created by Erik on 2025/6/11.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdBaseCustomView.h>
#import <YFAdsSDK/YFSplashButton.h>
#import <YFAdsSDK/YFAdView.h>
#import <YFAdsSDK/YFTouchReportView.h>
#import <YFAdsSDK/YFSplashAnimationView2.h>
#import <YFAdsSDK/YFAdMarkImageView.h>

NS_ASSUME_NONNULL_BEGIN
/// 自渲染开屏2.0基类
@interface YFAdBaseSplashView : YFAdBaseCustomView

@property(nonatomic, weak) UIViewController *rootViewController;
@property(nonatomic, assign) NSUInteger ecpm;
@property(nonatomic, strong) YFTouchReportView *reportView;
@property(nonatomic, strong) YFSplashButton *jumpBtn;
@property(nonatomic, strong) YFAdEventModel *eventModel;
@property(nonatomic, strong) YFAdImageView *contentView;
@property(nonatomic, strong) YFAdImageView *contentImageView;
@property(nonatomic, strong) YFSplashAnimationView2 *tapBarAnimationView;
@property(nonatomic, strong) YFAdMarkImageView *logoView;
@property (nonatomic, strong) UIView *btnLine;
@property (nonatomic, strong) UIView *bottomView;
@property(nonatomic, assign) BOOL isvalid;
@property(nonatomic,copy) void (^closeClick)(id);
@property(nonatomic,copy) void (^skipClick)(id);

- (instancetype)initWithSplashMode:(id)model;

- (void)showInView:(UIView *)view;
// 添加独有广告视图
- (void)addOtherViews;
// 注册可点击元素
- (void)registerClickableItems:(NSArray *)items;
// 长按溯源
- (void)feedback;
// 描述
- (NSString *)adDesc;
// 广告标题
- (NSString *)adTitle;
// icon
- (NSString *)iconUrl;
// 关闭广告
-(void)toCloseNativeAdView;
// 暂停倒计时
- (void)pause;
// 恢复倒计时
- (void)resume;
// 横竖屏变化
- (void)orientationChanged;
// 竖屏UI
- (void)updatePortraitUI;
// 横屏UI
- (void)updateLandscapeUI;
- (void)toCutJumpBtn:(YFSplashButton *)btn splashState:(YFSplashState)splashtype;
- (CGSize)getJumpSizeByType:(YFSplashState)type;
- (CGSize)getJumpStr:(NSString *)jumpStr areaWidth:(CGFloat)areaWith sizeByType:(YFSplashState)type;
- (void)toLoadLandscapeJumpBtnView;
- (void)toLoadPortraiJumpBtnView;
@end

NS_ASSUME_NONNULL_END
