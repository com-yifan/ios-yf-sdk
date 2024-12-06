//
//  ViewController.m

////  Created by CherryKing on 2020/4/9.
//  Copyright © 2020 bayescom. All rights reserved.
//

#import "YFViewController.h"
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>
#import "JDStatusBarNotification.h"
#import <YFAdsSDK/YFAdUtils.h>
#import <YFAdsSDK/YFAdSDKSetting.h>

#import "YFEnvironmentManager.h"

@interface YFViewController () <UITableViewDataSource, UITableViewDelegate>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray<NSDictionary<NSString *, NSString *> *> *dataArr;
@property (nonatomic, strong) UIImageView *logoImgV;
@property (nonatomic, strong) UILabel *idfaLab;
@property (nonatomic, strong) UILabel *deviceLab;


@end

@implementation YFViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setTitle:@"亿帆"];
    [self initSubviews];

    
    
    _dataArr = @[
//        @{@"title":@"自定义管理SDK", @"targetVCName": @"CustomListViewController"},
        @{@"title":@"开屏", @"targetVCName": @"DemoSplashViewController"},
        @{@"title":@"横幅(不支持百度)", @"targetVCName": @"DemoBannerViewController"},
        @{@"title":@"融合横幅(不支持)", @"targetVCName": @"DemoFusionBannerViewController"},
        @{@"title":@"插屏", @"targetVCName": @"DemoInterstitialViewController"},
        @{@"title":@"激励视频", @"targetVCName": @"DemoRewardVideoViewController"},
        @{@"title":@"信息流", @"targetVCName": @"DemoListFeedExpressViewController"},
        @{@"title":@"全屏视频", @"targetVCName": @"DemoFullScreenVideoController"},
        @{@"title":@"Draw流", @"targetVCName": @"DemoDrawViewController"},
        @{@"title":@"贴片", @"targetVCName": @"DemoPatchViewController"},
        @{@"title":@"媒体自渲染", @"targetVCName": @"DemoMediaRenderViewController"},
        @{@"title":@"IDFA", @"targetVCName": @""},
        @{@"title":@"设备ID", @"targetVCName": @""},
        @{@"title":@"当前环境", @"targetVCName": @""},
        @{@"title":@"穿山甲测试工具", @"targetVCName": @""},

    ];
    
    [_tableView reloadData];
}

-(void)viewWillAppear:(BOOL)animated{
    
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            __block NSString *idfa = @"";
            ASIdentifierManager *manager = [ASIdentifierManager sharedManager];
            if (@available(iOS 14, *)) {
                [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
                    if (status == ATTrackingManagerAuthorizationStatusAuthorized) {
                        idfa = [[manager advertisingIdentifier] UUIDString];
                    }
                    [YFAdSDKSetting shareInstance].customIDFA = idfa;
                }];
            }else{
            if ([manager isAdvertisingTrackingEnabled]) {
                idfa = [[manager advertisingIdentifier] UUIDString];
            }
        }
        
        [YFAdSDKSetting shareInstance].customIDFA = idfa;
        
    });
    
   
    
}


- (void)initSubviews {
    
//    UIBarButtonItem *settingItem = [[UIBarButtonItem alloc] initWithTitle:@"SDK设置" style:UIBarButtonItemStylePlain target:self action:@selector(toSettingsViewController)];
//    self.navigationItem.rightBarButtonItem = settingItem;
    
    _tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStylePlain];
    _tableView.dataSource = self;
    _tableView.delegate = self;
    _tableView.tableFooterView = [UIView new];
    [self.view addSubview:_tableView];
    
    self.idfaLab = [[UILabel alloc] init];
    self.idfaLab.text = @"IDFA:";
    self.idfaLab.backgroundColor = UIColor.redColor;
    [self.view addSubview:self.idfaLab];
    self.deviceLab = [[UILabel alloc] init];
    self.deviceLab.text = @"设备号:";
    [self.view addSubview:self.deviceLab];

    if (@available(iOS 15.0, *)) {
        self.tableView.sectionHeaderTopPadding = 0;
    }
    [_tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.top.right.mas_equalTo(0);
        make.bottom.mas_equalTo(300);
    }];
    
    [_idfaLab mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.mas_equalTo(0);
        make.bottom.mas_equalTo(_tableView.mas_bottom);
        make.height.mas_equalTo(30);
    }];
    
    [_deviceLab mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.mas_equalTo(0);
        make.top.mas_equalTo(_idfaLab.mas_bottom);
        make.height.mas_equalTo(30);
    }];
}

- (void)toSettingsViewController {
    [self.navigationController pushViewController:[[NSClassFromString(@"SettingsViewController") alloc] init] animated:YES];
}

// MARK: UITableViewDataSource, UITableViewDelegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return _dataArr.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cellid"];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"cellid"];
    }
    NSString *title = _dataArr[indexPath.row][@"title"];
    cell.textLabel.text = title;
    if ([title isEqualToString:@"IDFA"]) {
        [self addIdfaLabeWithView:cell.contentView];
    }else if ([title isEqualToString:@"设备ID"]){
        [self deviceLabeWithView:cell.contentView];
    }else if ([title isEqualToString:@"当前环境"]){
        [self enviLabeWithView:cell.contentView];
    }


    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    UIViewController *vc = [[NSClassFromString(_dataArr[indexPath.row][@"targetVCName"]) alloc] init];

    if(vc){
        vc.title = _dataArr[indexPath.row][@"title"];
        [self.navigationController pushViewController:vc animated:YES];
//        vc.modalPresentationStyle = 0;
//        [self presentViewController:vc animated:YES completion:nil];
    }
    
    NSString *title = _dataArr[indexPath.row][@"title"];
    
    if ([title isEqualToString:@"IDFA"]) {
        
        __block NSString *idfa = @"";
        ASIdentifierManager *manager = [ASIdentifierManager sharedManager];
        if (@available(iOS 14, *)) {
            [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
                if (status == ATTrackingManagerAuthorizationStatusAuthorized) {
                    idfa = [[manager advertisingIdentifier] UUIDString];
                }
            }];
        }else{
            if ([manager isAdvertisingTrackingEnabled]) {
                idfa = [[manager advertisingIdentifier] UUIDString];
            }
        }
        
        
        UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
        pasteboard.string = idfa;
        [JDStatusBarNotification showWithStatus:@"IDFA已复制" dismissAfter:1.5];
    }else if ([title isEqualToString:@"设备ID"]){
        
        UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
        pasteboard.string = [YFAdUtils getDeviceID];
        [JDStatusBarNotification showWithStatus:@"设备ID已复制" dismissAfter:1.5];
    }else if ([title isEqualToString:@"当前环境"]){
        [[YFEnvironmentManager shareManager] showPopWithVC:self complete:^(NSString *title) {
            [self.tableView reloadRowsAtIndexPaths:@[[NSIndexPath indexPathForRow:indexPath.row inSection:0]] withRowAnimation:UITableViewRowAnimationNone];
        }];
        
    }else if ([title isEqualToString:@"穿山甲测试工具"]){
        [BUAdTestMeasurementManager showTestMeasurementWithController:self];
    }

}


- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 60;
}

- (NSString *)getIDFA{
    
    return [YFAdUtils getIDFA];
}

- (void)addIdfaLabeWithView:(UIView *)view {
    for (UIView *subv in view.subviews) {
        [subv removeFromSuperview];
    }
    
    UILabel * idfaLab = [UILabel new];
    idfaLab.numberOfLines = 0;
    [view addSubview:idfaLab];
    [idfaLab mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.top.bottom.right.equalTo(view);
        make.left.equalTo(view).offset(100);
    }];
    
    idfaLab.text = [[self getIDFA] isEqualToString:@""] ? @"请设置-隐私-允许App请求跟踪" : [self getIDFA];
}

- (void)enviLabeWithView:(UIView *)view  {
    for (UIView *subv in view.subviews) {
        [subv removeFromSuperview];
    }
    UILabel * idfaLab = [UILabel new];
    idfaLab.numberOfLines = 0;
    [view addSubview:idfaLab];
    [idfaLab mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.bottom.right.equalTo(view);
        make.left.equalTo(view).offset(100);
    }];
    
    idfaLab.text = [YFEnvironmentManager getENV_NAME];
}



- (void)deviceLabeWithView:(UIView *)view  {
    UILabel * idfaLab = [UILabel new];
    idfaLab.numberOfLines = 0;
    [view addSubview:idfaLab];
    [idfaLab mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.bottom.right.equalTo(view);
        make.left.equalTo(view).offset(100);
    }];
    
    idfaLab.text = [YFAdUtils getDeviceID];
}

- (UILabel *)idfaLab {
    if (!_idfaLab) {
        _idfaLab = [UILabel new];
        _idfaLab.numberOfLines = 0;
    }
    return _idfaLab;
}



@end
