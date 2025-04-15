//
//  DemoAdConfigVC.m
//  YFAdsDemo_Example
//
//  Created by 麻明康 on 2025/3/25.
//  Copyright © 2025 Nanjing Fengchuan Yunju Infomation Technology Co., LTD. All rights reserved.
//

#import "DemoAdConfigVC.h"
#import "DemoAdConfig.h"
#import "DemoEarlyRetrunCell.h"
#import "DemoCommonSwitchCell.h"
@interface DemoAdConfigVC ()<UITableViewDelegate,UITableViewDataSource>
@property (nonatomic, strong) UITableView *table;
@property (nonatomic, strong) NSArray *configArr;
@property (nonatomic, copy) NSArray *titleArray;
@end

@implementation DemoAdConfigVC

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
        
    if (@available(iOS 15.0, *)) {
        UINavigationBarAppearance *appearance = [[UINavigationBarAppearance alloc] init];
        appearance.backgroundEffect = [UIBlurEffect effectWithStyle:UIBlurEffectStyleRegular];
        self.navigationController.navigationBar.scrollEdgeAppearance = appearance;
        self.navigationController.navigationBar.standardAppearance = appearance;
    }

    
    _configArr = @[@"DemoEarlyRetrunCell",@"DemoCommonSwitchCell"];
    _titleArray = @[@"开屏强制提前返回广告时间",@"冷启开屏切换Window展示"];
    self.title = @"Demo广告配置";
    // Do any additional setup after loading the view.
    [self.view addSubview:self.table];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/
#pragma mark =============== createTable ===============
- (UITableView *)table{
    if (!_table) {
        _table = [[UITableView alloc]initWithFrame:CGRectMake(0, self.navigationController.navigationBar.frame.size.height + [UIApplication sharedApplication].statusBarFrame.size.height, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height) style:UITableViewStylePlain];
        _table.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
        _table.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
        _table.estimatedRowHeight = 0;
        _table.estimatedSectionHeaderHeight = 0;
        _table.estimatedSectionFooterHeight = 0;
        _table.backgroundColor = [UIColor whiteColor];
        _table.delegate = self;
        _table.dataSource = self;
    }
    for (NSString *clsName in _configArr) {
        if ([clsName isEqualToString:@"DemoCommonSwitchCell"]) {
            [_table registerClass:NSClassFromString(clsName) forCellReuseIdentifier:clsName];
        } else {
            UINib *nib = [UINib nibWithNibName:clsName bundle:[NSBundle mainBundle]];
            if (nib) {
                [_table registerNib:nib forCellReuseIdentifier:clsName];
            }
        }
    }
    return _table;
}

#pragma mark =============== UITableViewDataSource ===============
-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return _configArr.count;
}
-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *clsName = _configArr[indexPath.row];
    Class class = NSClassFromString(clsName);
    UINib *nib = [UINib nibWithNibName:clsName bundle:[NSBundle mainBundle]];

    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:clsName];
    
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:clsName];
    }
    // 开启切换window加载开屏
    if (indexPath.row == 1) {
        DemoCommonSwitchCell *switchCell = (DemoCommonSwitchCell *)cell;
        [switchCell updateTitle:_titleArray[indexPath.row]];
        [switchCell updateSwitchState:[[DemoAdConfig sharedInstance] useSplashWindow]];
        switchCell.switchStateChanged = ^(BOOL state) {
            [DemoAdConfig sharedInstance].useSplashWindow = state;
        };
    }
    
    return cell;
}

#pragma mark =============== UITableViewDelegate ===============
-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 44;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
}

@end
