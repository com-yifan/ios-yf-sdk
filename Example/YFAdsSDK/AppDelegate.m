//
//  AppDelegate.m
//  YFAdsSDK
//
//  Created by Cheng455153666 on 02/27/2020.
//  Copyright (c) 2020 Cheng455153666. All rights reserved.
//

#import "AppDelegate.h"
#import "YFEnvironmentManager.h"
#import <YFAdsSDK/YFAdsSDK.h>
#import <AppTrackingTransparency/ATTrackingManager.h>
#import "DemoHomeViewController.h"
#include <mach/task.h>
#include <mach/mach.h>
//#import <YFAdsSDK/YFAdAESEncrypt.h>
#import <FLAnimatedImage/FLAnimatedImageView.h>
#import "JDStatusBarNotification.h"
#import "DemoAdConfig.h"
#import "WXApi.h"
// 同意隐私协议key
#define PrivacyKey @"IsAgreePrivacy"

@interface AppDelegate ()<YFAdSplashDelegate>

/// 开屏广告
@property(nonatomic, strong) YFAdSplash *coldSplashAd;
/// 广告是否结束
@property(nonatomic, assign) BOOL isEnd;
/// 开屏广告背景图【可选，建议使用自定义背景图】
@property (nonatomic, strong) UIImageView *splashBackgroundView;
// 开屏承载window
@property (nonatomic, strong) UIWindow *splashWindow;
@property (nonatomic, strong) UIWindow *keyWindow;

@property (nonatomic, assign) BOOL isSplashLoaded;


@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // 初始化App keyWindow
    _window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    _window.backgroundColor = [UIColor whiteColor];
    _window.rootViewController = [[UINavigationController alloc] initWithRootViewController:[DemoHomeViewController new]];
    [_window makeKeyAndVisible];
    // demo状态栏提示工具
    [JDStatusBarNotification setDefaultStyle:^JDStatusBarStyle * _Nullable(JDStatusBarStyle * _Nonnull style) {
        style.barColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:0.5];
        style.progressBarPosition = JDStatusBarProgressBarPositionBottom;
        style.font = [UIFont systemFontOfSize:18];
        style.textColor = [UIColor whiteColor];
        return style;
    }];
    // 隐私协议弹窗在用户同意协议后初始化SDK
    [self showPrivacyAlert];
    // 加载开屏广告
    [self loadColdSplash];

    return YES;
}

/// 通用链接回调方法
- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler {
    // 通用链
    if ([userActivity.activityType isEqualToString:NSUserActivityTypeBrowsingWeb]) {
        NSURL *url = userActivity.webpageURL;
        NSLog(@"通用链接 ：%@", url);
    }
    return [WXApi handleOpenUniversalLink:userActivity delegate:self];
}

/// 初始化广告SDK
- (void)initAdSDK {
///  自定义拓展参数【可选】特殊需求使用详情咨询技术同学
    NSMutableDictionary * customDefine = [[NSMutableDictionary alloc] initWithCapacity:0];
//    [customDefine setValue:@"c1" forKey:@"c1"];
//    [customDefine setValue:@"c2" forKey:@"c2"];
//    [customDefine setValue:@"c3" forKey:@"c3"];
//    [customDefine setValue:@"c4" forKey:@"c4"];
//    [customDefine setValue:@"5" forKey:@"c5"];
//    [customDefine setValue:@"6" forKey:@"c6"];
    [YFAdSDKSetting shareInstance].customDefine = customDefine;
        
///  自定义用户标签【可选】
    NSMutableDictionary * userDefine = [[NSMutableDictionary alloc] initWithCapacity:0];
//    这里需要替换成真实的用户ID
//    [userDefine setValue:@"<#yf_demo_user_id#>" forKey:@"UserID"];
    [YFAdSDKSetting shareInstance].userDefine = userDefine;
    // 自定义用户id，非特殊需求建议传入真实用户ID
    [YFAdSDKSetting shareInstance].userId = @"test";
//    // 是否允许SDK进行声道控制，默认允许
//    [YFAdSDKSetting shareInstance].allowAudioSetting = YES;
    
    // Demo环境配置参数媒体开发者无需使用
    [YFAdSDKSetting shareInstance].fc_conf_url = [YFEnvironmentManager getFC_CONF_URL];
    [YFAdSDKSetting shareInstance].fc_upload_url = [YFEnvironmentManager getFC_UPLOAD_URL];
    [YFAdSDKSetting shareInstance].yf_conf_url = [YFEnvironmentManager getYF_CONF_URL];
    [YFAdSDKSetting shareInstance].fc_data_url = [YFEnvironmentManager getYF_DATA_URL];
    [YFAdSDKSetting shareInstance].useLocation = YES;
    //SDK注册【必须】 AppID可从运营同学提供的广告配置表中获取
    [YFAdSDKManager setupSDKWithAppId:[YFEnvironmentManager getAPP_ID]];
}

/// 请求IDFA
- (void)requestIDFA {
    // 请在info.plist 文件中配置key：NSUserTrackingUsageDescription value:该ID将用于向您推送个性化广告
    // 项目需要适配http，如不支持http请咨询技术同学添加域名白名单
    /*
     <key>NSAppTransportSecurity</key>
     <dict>
     <key>NSAllowsArbitraryLoads</key>
     <true/>
     </dict>
     */
    // 调试阶段尽量用真机, 以便获取idfa, 如果获取不到idfa, 则打开idfa开关
    // 打开idfa开关的过程:设置 -> 隐私 -> 跟踪 -> 允许App请求跟踪
    // 添加系统库 AdSupport.framework #import <AppTrackingTransparency/ATTrackingManager.h>
    // SDK初始化成功后可通过过滤YFAds:idfa查看设备IDFA
    if (@available(iOS 14, *)) {
        //iOS 14
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
            
        }];
    } else {
        // Fallback on earlier versions
    }
}

/// 隐私协议弹窗
- (void)showPrivacyAlert {
    if ([[NSUserDefaults standardUserDefaults] boolForKey:PrivacyKey]) {
        // 用户同意隐私协议，直接初始化广告SDK，获取IDFA
        [self requestIDFA];
        [self initAdSDK];
        [JDStatusBarNotification showWithStatus:@"亿帆SDK初始化" dismissAfter:1.5];
        return;
    }
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"隐私协议" message:@"这是一个隐私协议示例内容，目的在于模拟亿帆广告SDK初始化时机" preferredStyle:(UIAlertControllerStyleAlert)];
    UIAlertAction *cancleAction = [UIAlertAction actionWithTitle:@"拒绝并退出" style:(UIAlertActionStyleCancel) handler:^(UIAlertAction * _Nonnull action) {
        
    }];
    UIAlertAction *sureAction = [UIAlertAction actionWithTitle:@"同意" style:(UIAlertActionStyleDefault) handler:^(UIAlertAction * _Nonnull action) {
        [[NSUserDefaults standardUserDefaults] setBool:YES forKey:PrivacyKey];
        [[NSUserDefaults standardUserDefaults] synchronize];
        // 用户同意隐私协议初始化SDK和获取IDFA
        [self requestIDFA];
        [self initAdSDK];
        [JDStatusBarNotification showWithStatus:@"亿帆SDK初始化" dismissAfter:1.5];
    }];
    [alertController addAction:cancleAction];
    [alertController addAction:sureAction];
    [self.window.rootViewController presentViewController:alertController animated:YES completion:nil];
}

/// 加载冷启开屏广告
- (void)loadColdSplash {
    // 用户未同意协议不进行广告请求
    if (![[NSUserDefaults standardUserDefaults] boolForKey:PrivacyKey]) return;
    /// 获取当前最上层控制器
    UIViewController *rootVC = self.window.rootViewController;
    // 使用新建window承载
    if ([DemoAdConfig sharedInstance].useSplashWindow) {
        self.splashWindow = [self getSplashWindow];
        rootVC = self.splashWindow.rootViewController;
        // 暂存原始keywindow
        self.keyWindow = _window;
    }
    /// 初始化自定义的广告背景图
    if (!_splashBackgroundView)
        _splashBackgroundView = [UIImageView new];
    _splashBackgroundView.image = [UIImage imageNamed:@"splashBg"];
    // 自定义的背景图添加至主控制器 广告关闭或者失败时进行移除
    [rootVC.view addSubview:_splashBackgroundView];
    _splashBackgroundView.frame = UIScreen.mainScreen.bounds;
    /// 注意： 初始化传入当前可见最上层控制器，避免无法弹出落地页，广告位id见广告配置表
    self.coldSplashAd = [[YFAdSplash alloc] initWithAdUnitID:[YFEnvironmentManager getColdSPLASH_ID] viewController:rootVC];
    self.coldSplashAd.delegate = self;
    /// 设置开屏底部视图（可选）不要超过屏幕高度的20%
    UIImageView *imageView = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, kScreenW, 80)];
    imageView.image = [UIImage imageNamed:@"app_logo"];
    UILabel *bottomLabel = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, kScreenW, 80)];
//    bottomLabel.text = @"这是开屏底部视图，不要超过屏幕高度的20%";
    bottomLabel.textAlignment = NSTextAlignmentCenter;
    [imageView addSubview:bottomLabel];
    self.coldSplashAd.bottomView = imageView;
    /// 超时时间
    self.coldSplashAd.timeout = 5;
    /// 是否展示底部logo视图
    self.coldSplashAd.showLogoRequire = YES;
    /// 加载广告
    [self.coldSplashAd loadAd];
    /// 兜底倒计时
    [self countDown];
    // 加载时 切换keywindow
    if ([DemoAdConfig sharedInstance].useSplashWindow) {
        [self.splashWindow makeKeyAndVisible];
    }
}

/// 部分联盟不回调关闭，建议加一个倒计时兜底，防止进入不了首页
- (void)countDown {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(15 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if (self.isSplashLoaded) return;
        [self splashEnd];
    });
}

/// 广告结束
-(void)splashEnd {
    if(!self.isEnd) {
        self.isEnd = YES;
        self.coldSplashAd = nil;
        [self->_splashBackgroundView removeFromSuperview];
        if ([DemoAdConfig sharedInstance].useSplashWindow) {
            [self.keyWindow makeKeyAndVisible];
        }
    }
}

/// 新创建承载开屏的window
- (UIWindow *)getSplashWindow {
    UIWindow *window = [UIWindow new];
    window.frame = [UIScreen mainScreen].bounds;
    window.backgroundColor = [UIColor whiteColor];
    UIViewController *viewController = [UIViewController new];
    viewController.view.backgroundColor = [UIColor whiteColor];
    window.rootViewController = viewController;
    return window;
}

#pragma mark - YFAdSplashDelegate
/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    NSLog(@"开屏-亿帆-广告数据加载成功");
    self.isSplashLoaded = YES;
    if(!self.isEnd) {
        /// 展示广告时移除自定义背景图
        dispatch_async(dispatch_get_main_queue(), ^{
//            [self.splashBackgroundView removeFromSuperview];
        });
        [model showAd];
    }
}

/// 广告曝光成功
- (void)fcAdExposured:(YFAdBaseAdapter *)model {
    NSLog( @"开屏-亿帆-广告曝光成功");
}

///  获取数据失败
- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter description:(NSDictionary *)description {
    NSLog(@"开屏-亿帆-广告加载失败-%@", error);
    [self splashEnd];
}

/// 广告点击
- (void)fcAdClicked:(YFAdBaseAdapter *)model {
    NSLog(@"开屏-亿帆-广告点击");
    /// 部分联盟需要使用当前控制器的navigate，避免背景视图覆盖落地页，需要在点击的时候移除背景视图
    [self->_splashBackgroundView removeFromSuperview];
}

-(void)fcAdDidCloseOtherController:(id)adapter interactionType:(YFAdInteractionType)interactionType {
    NSLog(@"开屏-亿帆-广告关闭-fcAdDidCloseOtherController");
//    [self splashEnd];
}

/// 广告关闭
- (void)fcAdDidClose:(YFAdBaseAdapter *)model {
    NSLog(@"开屏-亿帆-广告关闭");
    [self splashEnd];
}

/// 广告倒计时结束
- (void)fcAdSplashOnAdCountdownToZero {
    NSLog(@"开屏-亿帆-广告倒计时结束");
//    [self splashEnd];
}

/// 点击了跳过
- (void)fcAdSplashOnAdSkipClicked {
    NSLog(@"开屏-亿帆-点击了跳过");
//    [self splashEnd];
}

#pragma mark =============== 微信SDK回调 ===============

/*! @brief 收到一个来自微信的请求，第三方应用程序处理完后调用sendResp向微信发送结果
 *
 * 收到一个来自微信的请求，异步处理完成后必须调用sendResp发送处理结果给微信。
 * 可能收到的请求有GetMessageFromWXReq、ShowMessageFromWXReq等。
 * @param req 具体请求内容，是自动释放的
 */
- (void)onReq:(BaseReq*)req{
    
}



/*! @brief 发送一个sendReq后，收到微信的回应
 *
 * 收到一个来自微信的处理结果。调用一次sendReq后会收到onResp。
 * 可能收到的处理结果有SendMessageToWXResp、SendAuthResp等。
 * @param resp具体的回应内容，是自动释放的
 */
- (void)onResp:(BaseResp*)resp{
    
}

/* ! @brief 用于在iOS16以及以上系统上，控制OpenSDK是否读取剪切板中微信传递的数据以及读取的时机
 * 在iOS16以及以上系统，在SDK需要读取剪切板中微信写入的数据时，会回调该方法。没有实现默认会直接读取微信通过剪切板传递过来的数据
 * 注意：
 *      1. 只在iOS16以及以上的系统版本上回调;
 *      2. 不实现时，OpenSDK会直接调用读取剪切板接口，读取微信传递过来的数据;
 *      3. 若实现该方法：开发者需要通过调用completion(), 支持异步，通知SDK允许读取剪切板中微信传递的数据,
 *                    不调用completion()则代表不授权OpenSDK读取剪切板，会导致收不到onReq:, onResp:回调，无法后续业务流程。请谨慎使用
 *      4. 不要长时间持有completion不释放，可能会导致内存泄漏。
 */
- (void)onNeedGrantReadPasteBoardPermissionWithURL:(nonnull NSURL *)openURL completion:(nonnull WXGrantReadPasteBoardPermissionCompletion)completion{
    
}
@end

