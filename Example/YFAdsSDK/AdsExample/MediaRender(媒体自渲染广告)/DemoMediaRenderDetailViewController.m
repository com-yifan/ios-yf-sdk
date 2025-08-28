//
//  ATNativeShowViewController.m
//  AnyThingSDKDemo
//
//  Created by mac on 2021/12/7.
//

#import "DemoMediaRenderDetailViewController.h"
#import "DemoNativeSelfRenderView.h"


#define kScreenH ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortrait || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortraitUpsideDown ? UIScreen.mainScreen.bounds.size.height : UIScreen.mainScreen.bounds.size.width)

#define kScreenW ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortrait || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortraitUpsideDown ? UIScreen.mainScreen.bounds.size.width : UIScreen.mainScreen.bounds.size.height)

#define kScaleW(x) (([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortrait || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortraitUpsideDown) ? (UIScreen.mainScreen.bounds.size.width / 750 * x) : (UIScreen.mainScreen.bounds.size.height / 750 * x))

#define kRGB(r, g, b) [UIColor colorWithRed:((r) / 255.0) green:((g) / 255.0) blue:((b) / 255.0) alpha:1.0]

@interface DemoMediaRenderDetailViewController ()

@property (nonatomic, strong) DemoNativeSelfRenderView *adView;

@property (nonatomic, strong) UIButton *voiceChange;

@property (nonatomic, strong) UIButton *voicePause;

@property (nonatomic, strong) UIButton *voicePlay;

@property(nonatomic, assign) BOOL mute;

@property(nonatomic, assign) BOOL isPlaying;

@property(nonatomic, strong) YFAdMedia *adOffer;

@end

@implementation DemoMediaRenderDetailViewController

- (instancetype)initWithAdView:(DemoNativeSelfRenderView *)adView offer:(YFAdMedia *)offer {
    if(self = [super init]) {
        _adOffer = offer;
        _adView = adView;
        //  进入默认播放状态
        _isPlaying = YES;
    }
    return self;
    
}

- (void)dealloc
{
    NSLog(@"%s", __func__);
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    [self setupUI];
}

- (void)setupUI
{
    [self.view addSubview:self.voiceChange];
    [self.view addSubview:self.voicePause];
    [self.view addSubview:self.voicePlay];
    [self.view addSubview:self.adView];
    
//    [self.voicePlay mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.width.mas_equalTo((kScreenW - kScaleW(26) * 4) / 3);
//        make.height.mas_equalTo((kScreenW - kScaleW(26) * 4) / 6);
//        make.left.equalTo(self.view.mas_left).offset(kScaleW(26));
//        make.bottom.equalTo(self.view.mas_bottom).offset(-kScaleW(26));
//    }];
    
    [self.voiceChange mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.mas_equalTo((kScreenW - kScaleW(26) * 4) / 3);
        make.height.mas_equalTo((kScreenW - kScaleW(26) * 4) / 6);
        make.left.equalTo(self.view.mas_left).offset(kScaleW(26));
        make.bottom.equalTo(self.view.mas_bottom).offset(-kScaleW(52));
    }];
    
    [self.voicePause mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.mas_equalTo((kScreenW - kScaleW(26) * 4) / 3);
        make.height.mas_equalTo((kScreenW - kScaleW(26) * 4) / 6);
        make.left.equalTo(self.voiceChange.mas_right).offset(kScaleW(26));
        make.bottom.equalTo(self.voiceChange.mas_bottom);
    }];
    
    [self.voicePlay mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.mas_equalTo((kScreenW - kScaleW(26) * 4) / 3);
        make.height.mas_equalTo((kScreenW - kScaleW(26) * 4) / 6);
        make.left.equalTo(self.voicePause.mas_right).offset(kScaleW(26));
        make.bottom.equalTo(self.voiceChange.mas_bottom);
    }];
    
    [self.adView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.height.mas_equalTo(@400);
        make.left.equalTo(self.view);
        make.right.equalTo(self.view);
        make.top.equalTo(@100);
    }];
}


#pragma mark - Action
- (void)clickChange
{
    [self.adOffer muteEnable:self.mute];
     self.mute = !self.mute;
}

- (void)clickProgress
{
//    NSLog(@"ATNativeViewController:videoDuration:%f,videoPlayTime:%f",[self.adView videoDuration],[self.adView videoPlayTime]);
}

- (void)clickPause
{
    if (self.isPlaying) {
        [self.adOffer pauseVideo];
        self.isPlaying = NO;
    }
}

- (void)clickPlay
{
    if (!self.isPlaying) {
        [self.adOffer resumeVideo];
        self.isPlaying = YES;
    }
}

#pragma mark - lazy
- (UIButton *)voiceChange
{
    if (!_voiceChange) {
        _voiceChange = [[UIButton alloc] init];
        _voiceChange.layer.borderColor = kRGB(73, 109, 255).CGColor;
        _voiceChange.layer.borderWidth = kScaleW(3);
        [_voiceChange setTitleColor:[UIColor whiteColor] forState:UIControlStateHighlighted];
        [_voiceChange setTitleColor:kRGB(73, 109, 255) forState:UIControlStateNormal];
        [_voiceChange setBackgroundImage:[self imageWithColor:kRGB(73, 109, 255)] forState:UIControlStateHighlighted];
        [_voiceChange setBackgroundImage:[self imageWithColor:[UIColor whiteColor]] forState:UIControlStateNormal];
        _voiceChange.layer.masksToBounds = YES;
        _voiceChange.layer.cornerRadius = 5;
        [_voiceChange setTitle:@"视频静音" forState:UIControlStateNormal];
        _voiceChange.titleLabel.font = [UIFont systemFontOfSize:14];
        [_voiceChange addTarget:self action:@selector(clickChange) forControlEvents:UIControlEventTouchUpInside];
    }
    return _voiceChange;
}

- (UIButton *)voicePause
{
    if (!_voicePause) {
        _voicePause = [[UIButton alloc] init];
        _voicePause.layer.borderColor = kRGB(73, 109, 255).CGColor;
        _voicePause.layer.borderWidth = kScaleW(3);
        [_voicePause setTitleColor:[UIColor whiteColor] forState:UIControlStateHighlighted];
        [_voicePause setTitleColor:kRGB(73, 109, 255) forState:UIControlStateNormal];
        [_voicePause setBackgroundImage:[self imageWithColor:kRGB(73, 109, 255)] forState:UIControlStateHighlighted];
        [_voicePause setBackgroundImage:[self imageWithColor:[UIColor whiteColor]] forState:UIControlStateNormal];
        _voicePause.layer.masksToBounds = YES;
        _voicePause.layer.cornerRadius = 5;
        [_voicePause setTitle:@"视频暂停" forState:UIControlStateNormal];
        _voicePause.titleLabel.font = [UIFont systemFontOfSize:14];
        [_voicePause addTarget:self action:@selector(clickPause) forControlEvents:UIControlEventTouchUpInside];
    }
    return _voicePause;
}

- (UIButton *)voicePlay
{
    if (!_voicePlay) {
        _voicePlay = [[UIButton alloc] init];
        _voicePlay.layer.borderColor = kRGB(73, 109, 255).CGColor;
        _voicePlay.layer.borderWidth = kScaleW(3);
        [_voicePlay setTitleColor:[UIColor whiteColor] forState:UIControlStateHighlighted];
        [_voicePlay setTitleColor:kRGB(73, 109, 255) forState:UIControlStateNormal];
        [_voicePlay setBackgroundImage:[self imageWithColor:kRGB(73, 109, 255)] forState:UIControlStateHighlighted];
        [_voicePlay setBackgroundImage:[self imageWithColor:[UIColor whiteColor]] forState:UIControlStateNormal];
        _voicePlay.layer.masksToBounds = YES;
        _voicePlay.layer.cornerRadius = 5;
        [_voicePlay setTitle:@"视频播放" forState:UIControlStateNormal];
        _voicePlay.titleLabel.font = [UIFont systemFontOfSize:14];
        [_voicePlay addTarget:self action:@selector(clickPlay) forControlEvents:UIControlEventTouchUpInside];
    }
    return _voicePlay;
}

- (UIImage *)imageWithColor:(UIColor *)color {
    CGRect rect = CGRectMake(0.0f, 0.0f, 1.0f, 1.0f);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();

    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextFillRect(context, rect);

    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();

    return image;
}
@end
