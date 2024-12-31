//
//  DemoListSceneSimulateVC.m
//  YFAdsSDK_Example
//
//  Created by 麻明康 on 2024/8/21.
//  Copyright © 2024 Cheng455153666. All rights reserved.
//

#import "DemoListSceneSimulateVC.h"
#import "UIButton+FunctionExpansion.h"
#import "YFEnvironmentManager.h"
#import "DemoUtils.h"
#import <KSAdSDK/KSAdSDK.h>

#define KS_TEST_APP_ID @"90010"

@interface DemoListSceneSimulateVC ()<UITextFieldDelegate>
@property (nonatomic, strong) UISwitch *switch_secene1;
@property (nonatomic, strong) UISwitch *switch_secene2;
@property (nonatomic, strong) UISwitch *switch_clean;
@property (nonatomic, strong) UISwitch *switch_ks;

@property (nonatomic, strong) UITextField *hot_interval_textField;
@property (nonatomic, strong) UITextField *times_number_textField;

@end

@implementation DemoListSceneSimulateVC


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.btnLoad.hidden = YES;
    self.btnShow.hidden = YES;
    self.btnLoadAndShow.hidden = YES;
    self.labNotify.hidden = YES;
    NSInteger sceneSimulateType = 0;
    NSNumber *scene = [[NSUserDefaults standardUserDefaults] valueForKey:@"yf_scene_simulate"];
    if (scene) {
        sceneSimulateType = scene.integerValue;
    }
    
    UITapGestureRecognizer *tap1 = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(viewTapped)];
    tap1.cancelsTouchesInView = NO;
    [self.view addGestureRecognizer:tap1];
    
    UILabel *hot_interval_lab = [[UILabel alloc]initWithFrame:CGRectMake(20, 100, 250, 50)];
    hot_interval_lab.text = @"设置热启时间间隔(默认0s):";
    [self.view addSubview:hot_interval_lab];
    
    self.hot_interval_textField = [[UITextField alloc]initWithFrame:CGRectMake(270, 100, kScreenW-290, 50)];
    self.hot_interval_textField.placeholder = @"默认0s";
    NSString *hot_interval = [[NSUserDefaults standardUserDefaults] valueForKey:@"yf_scene_hot_interval"];
    if ( hot_interval
        && ![hot_interval isEqualToString:@"0"]) {
        self.hot_interval_textField.text = [[NSUserDefaults standardUserDefaults] valueForKey:@"yf_scene_hot_interval"];
    }
    self.hot_interval_textField.keyboardType = UIKeyboardTypeNumbersAndPunctuation;
    self.hot_interval_textField.returnKeyType = UIReturnKeyDone;
    self.hot_interval_textField.delegate = self;
    self.hot_interval_textField.layer.cornerRadius = 10.;
    self.hot_interval_textField.layer.borderWidth = 2.0;
    self.hot_interval_textField.layer.borderColor = [UIColor systemGrayColor].CGColor;
    self.hot_interval_textField.layer.masksToBounds = YES;
    self.hot_interval_textField.textAlignment = NSTextAlignmentCenter;
    [self.view addSubview:self.hot_interval_textField];

    UILabel *times_number_lab = [[UILabel alloc]initWithFrame:CGRectMake(20, 170, 250, 50)];
    times_number_lab.text = @"设置热启频次次数(默认10次):";
    [self.view addSubview:times_number_lab];
    
    self.times_number_textField = [[UITextField alloc]initWithFrame:CGRectMake(270, 170, kScreenW-290, 50)];
    self.times_number_textField.placeholder = @"默认10次";
    NSString *times_number = [[NSUserDefaults standardUserDefaults] valueForKey:@"yf_scene_times_number"];
    if ( times_number
        && ![times_number isEqualToString:@"10"]) {
        self.times_number_textField.text = [[NSUserDefaults standardUserDefaults] valueForKey:@"yf_scene_times_number"];
    }
    self.times_number_textField.keyboardType = UIKeyboardTypeNumbersAndPunctuation;
    self.times_number_textField.returnKeyType = UIReturnKeyDone;
    self.times_number_textField.delegate = self;
    self.times_number_textField.layer.cornerRadius = 10.;
    self.times_number_textField.layer.borderWidth = 2.0;
    self.times_number_textField.layer.borderColor = [UIColor systemGrayColor].CGColor;
    self.times_number_textField.layer.masksToBounds = YES;
    self.times_number_textField.textAlignment = NSTextAlignmentCenter;
    [self.view addSubview:self.times_number_textField];

    UILabel *tips = [[UILabel alloc]initWithFrame:CGRectMake(0, 220, kScreenW, 50)];
    tips.textColor = [UIColor grayColor];
    tips.text = @"tips:热启一般是指App退到后台再返回前台的场景";
    tips.font = [UIFont systemFontOfSize:12];
    tips.textAlignment = NSTextAlignmentCenter;
    [self.view addSubview:tips];

//    场景1：冷启开屏+冷启插屏+热启开屏
    CGFloat btn_h = 60;
    CGFloat btn_w = 250;
    UIColor *btn_color = [UIColor clearColor];
    UIColor *text_color = [UIColor systemBlueColor];
    UIFont *btn_font = [UIFont systemFontOfSize:14];
    
    
    UIButton *openAppBtn1 = [UIButton buttonWithFrame:CGRectMake(kScreenW/2-btn_w/2+25, 300, btn_w, btn_h) title:@"冷启开屏+冷启插屏+热启开屏" titleColor:text_color backgroundColor:btn_color font:btn_font normalImage:nil highlightedImage:nil backgroundImage:nil target:self selector:@selector(setScene1)];
    openAppBtn1.layer.cornerRadius = 10.;
    openAppBtn1.layer.borderWidth = 2.0;
    openAppBtn1.layer.borderColor = [UIColor systemBlueColor].CGColor;
    openAppBtn1.layer.masksToBounds = YES;
    [self.view addSubview:openAppBtn1];
    self.switch_secene1 = [UISwitch new];
    self.switch_secene1.on = (sceneSimulateType==1);
    [self.switch_secene1 setCenter:CGPointMake(openAppBtn1.frame.origin.x-50, openAppBtn1.center.y)];
    [self.switch_secene1 addTarget:self action:@selector(setScene1) forControlEvents: UIControlEventTouchUpInside];
    [self.view addSubview:self.switch_secene1];

//    场景2：冷启开屏+冷启插屏+热启插屏
    UIButton *openAppBtn2 = [UIButton buttonWithFrame:CGRectMake(kScreenW/2-btn_w/2+25, 400, btn_w, btn_h) title:@"冷启开屏+冷启插屏+热启插屏" titleColor:text_color backgroundColor:btn_color font:btn_font normalImage:nil highlightedImage:nil backgroundImage:nil target:self selector:@selector(setScene2)];
    openAppBtn2.layer.cornerRadius = 10.;
    openAppBtn2.layer.borderWidth = 2.0;
    openAppBtn2.layer.borderColor = [UIColor systemBlueColor].CGColor;
    openAppBtn2.layer.masksToBounds = YES;
    [self.view addSubview:openAppBtn2];
    self.switch_secene2 = [UISwitch new];
    self.switch_secene2.on = (sceneSimulateType==2);
    [self.switch_secene2 setCenter:CGPointMake(openAppBtn2.frame.origin.x-50, openAppBtn2.center.y)];
    [self.switch_secene2 addTarget:self action:@selector(setScene2) forControlEvents: UIControlEventTouchUpInside];
    [self.view addSubview:self.switch_secene2];
    
    UIButton *cleanBtn = [UIButton buttonWithFrame:CGRectMake(kScreenW/2-btn_w/2+25, 500, btn_w, btn_h) title:@"清空测试场景" titleColor:text_color backgroundColor:btn_color font:btn_font normalImage:nil highlightedImage:nil backgroundImage:nil target:self selector:@selector(cleanScene)];
    cleanBtn.layer.cornerRadius = 10.;
    cleanBtn.layer.borderWidth = 2.0;
    cleanBtn.layer.borderColor = [UIColor systemBlueColor].CGColor;
    cleanBtn.layer.masksToBounds = YES;
    [self.view addSubview:cleanBtn];
    self.switch_clean = [UISwitch new];
    self.switch_clean.on = (sceneSimulateType==0);
    [self.switch_clean setCenter:CGPointMake(cleanBtn.frame.origin.x-50, cleanBtn.center.y)];
    [self.switch_clean addTarget:self action:@selector(cleanScene) forControlEvents: UIControlEventTouchUpInside];
    [self.view addSubview:self.switch_clean];
    
    
    UIButton *ksBtn = [UIButton buttonWithFrame:CGRectMake(kScreenW/2-btn_w/2+25, 600, btn_w, btn_h) title:@"快手重复初始化测试" titleColor:text_color backgroundColor:btn_color font:btn_font normalImage:nil highlightedImage:nil backgroundImage:nil target:self selector:@selector(regiestKS)];
    ksBtn.layer.cornerRadius = 10.;
    ksBtn.layer.borderWidth = 2.0;
    ksBtn.layer.borderColor = [UIColor systemBlueColor].CGColor;
    ksBtn.layer.masksToBounds = YES;
    [self.view addSubview:ksBtn];
    
    self.switch_ks = [UISwitch new];
    self.switch_ks.on = ([[KSAdSDKConfiguration configuration].appId isEqualToString:KS_TEST_APP_ID]);
    [self.switch_ks setCenter:CGPointMake(ksBtn.frame.origin.x-50, ksBtn.center.y)];
    [self.switch_ks addTarget:self action:@selector(regiestKS) forControlEvents: UIControlEventTouchUpInside];
    [self.view addSubview:self.switch_ks];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillHide:)
                                                     name:UIKeyboardWillHideNotification object:nil];
}

- (void)regiestKS{
    KSAdSDKConfiguration *configuration = [KSAdSDKConfiguration configuration];
    configuration.appId = KS_TEST_APP_ID;
    [configuration setLoglevel:KSAdSDKLogLevelOff];
    // 启动SDK:SDK启动成功后，才可以继续进行后续的广告请求操作
    // 没回调之前加载广告会回调错误
    __weak typeof(self) weakSelf = self;
    [KSAdSDKManager startWithCompletionHandler:^(BOOL success, NSError *error) {
        if (success) {
            //do...
            weakSelf.switch_ks.on = success;
        }
    }];
}

-(void)viewTapped{
    [self.hot_interval_textField resignFirstResponder];
    [self.times_number_textField resignFirstResponder];
}

-(void)saveConfig{
    if (self.hot_interval_textField.text.length) {
        [[NSUserDefaults standardUserDefaults] setObject:self.hot_interval_textField.text forKey:@"yf_scene_hot_interval"];
    }else{
        [[NSUserDefaults standardUserDefaults] setObject:@"0" forKey:@"yf_scene_hot_interval"];
    }
    if (self.times_number_textField.text.length) {
        [[NSUserDefaults standardUserDefaults] setObject:self.times_number_textField.text forKey:@"yf_scene_times_number"];
    }else{
        [[NSUserDefaults standardUserDefaults] setObject:@"10" forKey:@"yf_scene_times_number"];
    }
    [[NSUserDefaults standardUserDefaults] synchronize];
    [JDStatusBarNotification showWithStatus:@"配置已保存" dismissAfter:1.5];
}

-(void)setScene1{
    [[NSUserDefaults standardUserDefaults] setObject:@1 forKey:@"yf_scene_simulate"];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    self.switch_secene1.on = YES;
    self.switch_secene2.on = NO;
    self.switch_clean.on = NO;
    
    [JDStatusBarNotification showWithStatus:@"已设置模拟场景1，请重启APP查看效果" dismissAfter:1.5];
    [DemoUtils showToast:@"已设置模拟场景1，请重启APP查看效果"];
}

-(void)setScene2{
    [[NSUserDefaults standardUserDefaults] setObject:@2 forKey:@"yf_scene_simulate"];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    [JDStatusBarNotification showWithStatus:@"已设置模拟场景2，请重启APP查看效果" dismissAfter:1.5];
    [DemoUtils showToast:@"已设置模拟场景2，请重启APP查看效果"];
    
    self.switch_secene1.on = NO;
    self.switch_secene2.on = YES;
    self.switch_clean.on = NO;
}

-(void)cleanScene{
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:@"yf_scene_simulate"];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    [JDStatusBarNotification showWithStatus:@"模拟场景已清空" dismissAfter:1.5];
    [DemoUtils showToast:@"模拟场景已清空"];
    
    self.switch_secene1.on = NO;
    self.switch_secene2.on = NO;
    self.switch_clean.on = YES;
}

#pragma mark =============== UITextFieldDelegate ===============
- (BOOL)textFieldShouldReturn:(UITextField *)textField{
    [self viewTapped];
    return YES;
}

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string {

    if ([self validateNumber:string]) {
        return YES;
    }
    [JDStatusBarNotification showWithStatus:@"请输入数字" dismissAfter:1.5];
    return NO;
}

- (BOOL)validateNumber:(NSString*)number {
    BOOL res = YES;
    NSCharacterSet* tmpSet = [NSCharacterSet characterSetWithCharactersInString:@"0123456789"];
    int i = 0;
    while (i < number.length) {
        NSString * string = [number substringWithRange:NSMakeRange(i, 1)];
        NSRange range = [string rangeOfCharacterFromSet:tmpSet];
        if (range.length == 0) {
            res = NO;
            break;
        }
        i++;
    }
    return res;
}
#pragma mark =============== keyBroad ===============
-(void)keyboardWillHide:(NSNotification*)notification{
    [self saveConfig];
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
