//
//  YFIntertitialAdViewController.h
//  YFAdsSDK
//
//  Created by Erik on 2024/11/26.
//

#import <YFAdsSDK/YFAdBaseViewController.h>
#import <YFAdsSDK/UIView+YFAutoLayout.h>
#import <YFAdsSDK/UIApplication+YFAds.h>
#import <YFAdsSDK/YFAdUtils.h>
#import <YFAdsSDK/YFAdConst.h>
#import <YFAdsSDK/UIImageView+YF_WebCache.h>
#import <YFAdsSDK/YFAdMarkImageView.h>
#import <YFAdsSDK/UIImage+YFImageEffects.h>
#import <YFAdsSDK/YFtie.h>
#import <YFAdsSDK/YFAdReportModel.h>
#import <YFAdsSDK/YFAdsAnimationView.h>
#import <YFAdsSDK/YFPrivateKit.h>
#import <YFAdsSDK/YFAdsCountButton.h>
#import <YFAdsSDK/YFAdsCloseButton.h>
#import <YFAdsSDK/YFAdBaseCustomView.h>

NS_ASSUME_NONNULL_BEGIN
/// 插屏承载控制器
@interface YFEnvelopeIntertitialAdViewController : YFAdBaseViewController
/// 广告底图
@property (nonatomic, strong) YFAdBaseCustomView *backgroundView;
/// 广告内容视图
@property (nonatomic, strong) UIView *contentView;
/// 广告主图
@property (nonatomic, strong) YFAdImageView * imgView;
/// 标题
@property (nonatomic, strong) UILabel *titleLabel;
/// 子标题
@property (nonatomic, strong) UILabel * subTitleLabel;
/// 广告icon
@property (nonatomic, strong) YFAdImageView * adIcon;
/// logo视图
@property (nonatomic, strong) UIImageView *logoView;
/// 联盟logo
@property (nonatomic, strong) YFAdMarkImageView *adLogo;
/// 倒计时关闭
@property (nonatomic, strong) YFAdsCountButton *countButton;
/// 关闭按钮
@property (nonatomic, strong) YFAdsCloseButton *closeBtn;
/// 信封图片
@property (nonatomic, strong) YFAdImageView *envelopeView;
/// 信封视图
@property (nonatomic, strong) UIView *envelopeContentView;
/// 模糊视图
@property (nonatomic, strong) YFAdImageView * frostedGlass;
@property (nonatomic, strong) UIView * lotAnimationView;
/// 点击按钮
@property(nonatomic,strong) YFAdsAnimationView *tapBarAnimationView;
/// 展示时长
@property (nonatomic, assign) NSTimeInterval showInterval;
/// 广告位信息
@property (nonatomic, strong) YFAdEventModel *eventModel;
/// 点击视频 部分联盟点击视频额外回调
@property(nonatomic, copy) void (^clickVideoBlk)(void);
/// 点击关闭
@property(nonatomic, copy) void (^closeClick)(id);
/// 渲染成功（视频/图片加载完成）
@property (nonatomic, copy) void(^renderCompletion)(BOOL, NSError * _Nullable);
/// 曝光
@property(nonatomic,copy) void (^exposureBlk)(void);
/// 初始化
- (instancetype)initWithFrame:(CGRect)frame model:(id)model;
/// 添加进入后台监听
- (void)addNotification;
/// 构建视图
- (void)setupViews;
/// 布局视图
- (void)layoutViews;
/// 创建视图抖动效果
- (void)addShakeAnimation;
/// 展示
- (void)show;
/// 关闭
- (void)close;
/// 移除布局
- (void)removeLayout;
/// 配置事件
- (void)configureActions;
/// 触发事件
- (void)tapBarAnimatioShakeOrTwist:(YFMotionJump)motionJump withSensitivity:(YFMotionSensitivity)motionSensitivity withMotionStyle:(YFMotionStyle)motionStyle withAccelerometerData:(CMAccelerometerData * _Nullable)accelerometerData withMotion:(CMDeviceMotion * _Nullable) motion;
/// 竖屏布局
- (void)portraitLayout;
/// 横屏布局
- (void)landandscapeLayout;
@end

NS_ASSUME_NONNULL_END
