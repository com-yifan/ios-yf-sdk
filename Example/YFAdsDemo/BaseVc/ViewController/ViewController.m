//
//  ViewController.m

#import "ViewController.h"
#import "YFHomeTableViewCell.h"
#import "YFHomeFootView.h"
#import <AppTrackingTransparency/ATTrackingManager.h>

#import <YFAdsSDK/YFAdInterstitial.h>
#import <YFAdsSDK/YFAdSplash.h>
#import <YFAdsSDK/YFAdSDKLocation.h>
#import <SDWebImage/SDWebImage.h>

#import "AdDataJsonManager.h"
#import "YFEnvironmentManager.h"
#import "JDStatusBarNotification.h"
#import "Demoutils.h"
#import <KSUAdDebugTool/KSAdDebugHomeViewController.h>
typedef NS_ENUM(NSInteger, SceneSimulateType) {
    SceneSimulateTypeNone,
    //    场景1：冷启开屏+冷启插屏+热启开屏
    SceneSimulateType_CS_CI_HS,
    //    场景2：冷启开屏+冷启插屏+热启插屏
    SceneSimulateType_CS_CI_HI,
};
// 加载提示视图宽高
#define ProgressViewWidth 60.0
#define ProgressViewHeight 60.0

@interface ViewController ()<UITableViewDelegate, UITableViewDataSource, YFAdInterstitialDelegate,YFAdSplashDelegate>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray *dataSource;
@property (nonatomic) BOOL autoLoadEnable;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *autoEnableBtn;
@property (nonatomic, strong) YFAdInterstitial *interstitial;
@property (nonatomic, strong) YFAdSplash *hot_splash;

@property (nonatomic) bool isAdLoaded;
@property (nonatomic, assign) SceneSimulateType sceneSimulateType;

@property (nonatomic, assign) NSInteger current_scene_times_number;
@property (nonatomic, assign) NSInteger yf_scene_times_number;
@property (nonatomic, assign) NSInteger yf_scene_hot_interval;
@property (nonatomic, strong) NSString *nextHotAdTimestamp;
@property (nonatomic) BOOL cold_splash_loaded;
@property (nonatomic, strong) UIActivityIndicatorView *hotSplashProgressView;
// 开屏广告背景视图
@property(strong,nonatomic)  UIImageView  *bgImageView;
@end

@implementation ViewController

#pragma mark - property

- (UITableView *)tableView {
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        [_tableView registerClass:[YFHomeTableViewCell class] forCellReuseIdentifier:[YFHomeTableViewCell idString]];
    }
    return _tableView;
}

- (UIActivityIndicatorView *)hotSplashProgressView {
    if (!_hotSplashProgressView) {
        if (@available(iOS 13.0, *)) {
            _hotSplashProgressView = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyleMedium)];
        } else {
            // Fallback on earlier versions
            _hotSplashProgressView = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyleGray)];
        }
        _hotSplashProgressView.hidesWhenStopped = YES;
        _hotSplashProgressView.frame = CGRectMake(kScreenW/2 - ProgressViewWidth/2, kScreenH/2 - ProgressViewHeight/2, ProgressViewWidth, ProgressViewHeight);
    }
    return _hotSplashProgressView;
}

#pragma mark - life crycle

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    [self getSceneSimulateInfo];
    [self setupData];
    [self setupUI];
    [self checkTrackingPermission];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(mainThread:) name:@"YFSplashNotificationCenter" object:nil];
    
    @yf_weakify(self)
    [[NSNotificationCenter defaultCenter] addObserverForName:UIApplicationDidBecomeActiveNotification object:nil queue:nil usingBlock:^(NSNotification * _Nonnull note) {
        NSLog(@"热启动");
        if (!self.cold_splash_loaded) return;
        if (self.current_scene_times_number>=self.yf_scene_times_number) return;
        if ([DemoUtils compareTimeA:self.nextHotAdTimestamp withTimeB:[DemoUtils getTimestampSince1970]]==NSOrderedDescending) {
            return;
        }
        if ([DemoUtils getCurrentVC] != self) {
            return;
        }
        @yf_strongify(self);
        if (self.sceneSimulateType == SceneSimulateType_CS_CI_HI) {
            //插屏已经关闭置空才在热启动加载插屏
            if (self.interstitial) return;
            self.current_scene_times_number ++;
            [self loadAndShowInterstitial:[YFEnvironmentManager getINSERT_ID]];
        }
        if (self.sceneSimulateType == SceneSimulateType_CS_CI_HS) {
            //冷启插屏已经关闭置空，且热启开屏也已经关闭置空，才在热启动加载开屏
            if (self.interstitial||self.hot_splash) return;
            self.current_scene_times_number ++;
            [self loadAndShowSplash:[YFEnvironmentManager getColdSPLASH_ID]];
        }
    }];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    self.navigationController.navigationBar.barTintColor = [UIColor whiteColor];


}

- (void)dealloc {
    NSLog(@"插屏释放 %s",__func__);
}

- (void)deallocAd {
    self.interstitial.delegate = nil;
    self.interstitial = nil;
    self.hot_splash.delegate = nil;
    self.hot_splash = nil;
    self.hotSplashProgressView = nil;
    self.bgImageView = nil;
    self.isAdLoaded = NO;
    self.nextHotAdTimestamp = [DemoUtils getCurrentTimeSecondsOffset:self.yf_scene_hot_interval];
}

- (void)mainThread:(id)object {
    [JDStatusBarNotification showWithStatus:@"冷启广告结束" dismissAfter:1.5];
    NSLog(@"========冷启广告流程结束");
//    [[YFAdSDKLocation shareInstance] startLocationUpdatesWithCompletion:^(CLLocation * _Nonnull location, NSError * _Nonnull error) {
//        if(location){
//            // 获取纬度和经度
//            CLLocationDegrees latitude = location.coordinate.latitude;
//            CLLocationDegrees longitude = location.coordinate.longitude;
//            NSLog(@"Latitude: %f, Longitude: %f", latitude, longitude);
//        }
//    }];
    self.cold_splash_loaded = YES;
    
    if (self.sceneSimulateType==SceneSimulateTypeNone) return;
    
    [self loadAndShowInterstitial:[YFEnvironmentManager getINSERT_ID]];
}

- (void)getSceneSimulateInfo {
    NSNumber *scene = [[NSUserDefaults standardUserDefaults] valueForKey:@"yf_scene_simulate"];
    if (scene) {
        self.sceneSimulateType = scene.integerValue;
    }else{
        self.sceneSimulateType = SceneSimulateTypeNone;
    }
    
    if([[NSUserDefaults standardUserDefaults] valueForKey:@"yf_scene_hot_interval"]) {
        self.yf_scene_hot_interval = [[[NSUserDefaults standardUserDefaults] valueForKey:@"yf_scene_hot_interval"] integerValue];
    } else {
        self.yf_scene_hot_interval = 0;
    }
    
    if([[NSUserDefaults standardUserDefaults] valueForKey:@"yf_scene_times_number"]) {
        self.yf_scene_times_number = [[[NSUserDefaults standardUserDefaults] valueForKey:@"yf_scene_times_number"] integerValue];
    } else {
        self.yf_scene_times_number = 10;
    }
    self.current_scene_times_number = 0;
    self.nextHotAdTimestamp = [DemoUtils getCurrentTimeSecondsOffset:self.yf_scene_hot_interval];
}

/// 获取IDFA
- (void)checkTrackingPermission {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if (@available(iOS 14, *)) {
            //iOS 14
            [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
                
            }];
        } else {
            // Fallback on earlier versions
        }
    });
}

- (void)setupData {
    self.dataSource = @[
        @{
            @"image":@"home_list_icon",
            @"title":@"Reward Video(激励视频)",
            @"class":@"DemoRewardVideoViewController",
            @"des":@"Users can engage with a video ad in exchange for in-app rewards.",
          
        },
        @{
            @"image":@"home_list_icon",
            @"title":@"Interstitial(插屏)",
            @"class":@"DemoInterstitialViewController",
            @"des":@"Include Interstitial and FullScreen.Appears at natural breaks or transition points.",
        
        },
        @{
            @"image":@"home_list_icon",
            @"title":@"Splash(开屏)",
            @"class":@"DemoSplashViewController",
            @"des":@"Displayed immediately after the application is launched.",
        },
        @{
            @"image":@"home_list_icon",
            @"title":@"Banner(横幅)",
            @"class":@"DemoBannerViewController",
            @"des":@"Flexible formats which could appear at the top, middle or bottom of your app.",
        },
        @{
            @"image":@"home_list_icon",
            @"title":@"Fusion Banner(融合横幅)",
            @"class":@"DemoFusionBannerViewController",
            @"des":@"Flexible formats which could appear at the top, middle or bottom of your app.",
        },
        @{
            @"image":@"home_list_icon",
            @"title":@"MediaRender(媒体自渲染)",
            @"class":@"DemoMediaRenderViewController",
            @"des":@"Include Native,Vertical Draw Video and Pre-roll Ads.Most compatible with your native app code for video ads and graphic ads.",
        },
        @{
            @"image":@"home_list_icon",
            @"title":@"FullScreen(全屏视频)",
            @"class":@"DemoFullScreenVideoController",
            @"des":@"full screen video",
        },
        @{
            @"image":@"home_list_icon",
            @"title":@"Darw(视频流)",
            @"class":@"DemoDrawViewController",
            @"des":@"Vertical Draw Video and Pre-roll Ads",
        },
        @{
            @"image":@"home_list_icon",
            @"title":@"Patch(贴片)",
            @"class":@"DemoPatchViewController",
            @"des":@"pre-movie adverts ",
        },
        @{
            @"image":@"home_list_icon",
            @"title":@"Feed(信息流)",
            @"class":@"DemoListFeedExpressViewController",
            @"des":@"stream advertising",
        },
        
        @{
            @"image":@"home_list_icon",
            @"title":@"场景测试",
            @"class":@"DemoListSceneSimulateVC",
            @"des":@"scene simulate",
        },
        @{
            @"image":@"home_list_icon",
            @"title":@"快手测试工具",
            @"class":@"KSAdDebugHomeViewController",
            @"des":@"scene simulate"
        },
        @{
            @"image":@"home_list_icon",
            @"title":@"测试crash",
        }
        
    ];
}

- (void)setupUI {
    [self setupNav];
    [self.view addSubview:self.tableView];
    self.tableView.tableFooterView = [[YFHomeFootView alloc] initWithFrame:CGRectMake(0, 0, kScreenW, kScaleW(300))];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(self.view);
    }];
}

-(void)setupNav {
    UIView * navView = [[UIView alloc]initWithFrame:CGRectMake(0, 0,200,40)];
    UIImageView * logoIV = [[ UIImageView alloc]initWithImage:[UIImage imageNamed:@"AppIcon"]];
    logoIV.frame = CGRectMake(0, 0, 40, 40);
    [navView addSubview:logoIV];

    UILabel * title = [[UILabel alloc]initWithFrame:CGRectZero];
    title.frame = CGRectMake(44+5, 0, 150, 40);
    title.font = [UIFont boldSystemFontOfSize:17];
    title.text = @"亿帆 SDK Demo";
    [navView addSubview:title];
  
    self.navigationItem.titleView = navView;
    UIBarButtonItem *leftBar = [[UIBarButtonItem alloc] initWithTitle:[YFEnvironmentManager getENV_NAME] style:UIBarButtonItemStylePlain target:self action:@selector(setupEnv:)];
    self.navigationItem.leftBarButtonItem = leftBar;
    
}

- (void)setupEnv:(id)sender {
    [[YFEnvironmentManager shareManager] showPopWithVC:self complete:^(NSString *title) {
        UIBarButtonItem *leftBar = [[UIBarButtonItem alloc] initWithTitle:title style:UIBarButtonItemStylePlain target:self action:@selector(setupEnv:)];
        self.navigationItem.leftBarButtonItem = leftBar;
    }];
}

- (IBAction)autoLoadEnable:(id)sender {
    self.autoLoadEnable = !self.autoLoadEnable;
    NSLog(@"auto load %@",self.autoLoadEnable ? @"enable" : @"disable");

    UIBarButtonItem *btnItem = self.navigationItem.rightBarButtonItem;
    UIButton *clearBtn = btnItem.customView;
    [clearBtn setTitleColor:self.autoLoadEnable ? [UIColor blackColor] : [UIColor lightGrayColor] forState:UIControlStateNormal];
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataSource.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return kScaleW(100);
}

#pragma mark - UITableViewDelegate

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    YFHomeTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:[YFHomeTableViewCell idString]];
    cell.backgroundColor = kRGB(245, 245, 245);
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    NSDictionary *dic = self.dataSource[indexPath.row];
    cell.titleLabel.text = [NSString stringWithFormat:@"%@", dic[@"title"]];
    cell.subTitleLabel.text = [NSString stringWithFormat:@"%@", dic[@"des"]];
    cell.logoImage.image = [UIImage imageNamed:[NSString stringWithFormat:@"%@", dic[@"image"]]];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSDictionary *dic = self.dataSource[indexPath.row];
    NSString *classString = [NSString stringWithFormat:@"%@", dic[@"class"]];

    if(classString){
        Class class = NSClassFromString(classString);
        UIViewController *con = [class new];
        [self.navigationController pushViewController:con animated:YES];
        
    }
    
    if(indexPath.row == self.dataSource.count - 1){
        NSArray * array = @[@"1"];
        [array objectAtIndex:3];
    }
}

/// 加载展示插屏广告
- (void)loadAndShowInterstitial:(NSString *)unitID {
    [JDStatusBarNotification showWithStatus:@"广告加载" dismissAfter:1.5];

    self.interstitial = [[YFAdInterstitial alloc] initWithAdUnitID:unitID viewController:self];
    self.interstitial.delegate = self;
    _isAdLoaded = false;
    [self.interstitial loadAndShowAd];
}


/// 加载展示开屏广告
- (void)loadAndShowSplash:(NSString *)adID {
    [JDStatusBarNotification showWithStatus:@"广告加载" dismissAfter:1.5];
    self.hot_splash = [[YFAdSplash alloc] initWithAdUnitID:adID viewController:self];
    self.hot_splash.delegate = self;
    // 开屏广告底图
    UIImageView *imageView = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, kScreenW, 80)];
    imageView.image = [UIImage imageNamed:@"app_logo"];
    UILabel *bottomLabel = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, 200, 80)];
    bottomLabel.text = @"这是开屏底部视图，不要超过屏幕高度的20%";
    bottomLabel.textAlignment = NSTextAlignmentCenter;
    [imageView addSubview:bottomLabel];
    self.hot_splash.bottomView = imageView;
    _bgImageView = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, kScreenW, kScreenH)];
    _bgImageView.image = [UIImage imageNamed:@"splashBg"];
        
    self.hot_splash.backgroundView = _bgImageView;
    // 添加加载视图
    [_bgImageView addSubview:self.hotSplashProgressView];
    self.hot_splash.timeout = 5;
    self.hot_splash.showLogoRequire = NO;
    // 加载广告提示
    [self.hotSplashProgressView startAnimating];
    [self.hot_splash loadAndShowAd];
}


#pragma mark  - YFAdInterstitialDelegate & YFAdSplashDelegate

/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    self.isAdLoaded = YES;
}

/// 广告曝光
- (void)fcAdExposured:(id)adapter  {
    NSLog(@"广告曝光回调 %s", __func__);
    [self.hotSplashProgressView stopAnimating];
}

/// 广告点击
- (void)fcAdClicked:(id)adapter  {
    NSLog(@"广告点击 %s", __func__);
}

- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter description:(NSDictionary *)description{
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
    [JDStatusBarNotification showWithStatus:@"加载失败" dismissAfter:1.5];
    //通知主线程刷新
    [self deallocAd];
}

/// 广告关闭了
- (void)fcAdDidClose:(id)adapter  {
    NSLog(@"广告关闭了 %s", __func__);
    [self deallocAd];
}

/// 广告点击跳过
- (void)fcAdSplashOnAdSkipClicked{
    NSLog(@"广告点击了跳过 %s", __func__);
    [self deallocAd];
}

/// 广告倒计时结束回调 百度广告不支持该回调
- (void)fcAdSplashOnAdCountdownToZero{
    NSLog(@"广告倒计时结束 %s", __func__);
    [self deallocAd];
}

@end
