//
//  DemoListFeedExpressViewController.m
//  Example
//
//  Created by CherryKing on 2019/11/21.
//  Copyright © 2019 CherryKing. All rights reserved.
//

#import "DemoListFeedExpressChangeViewController.h"
#import "CellBuilder.h"
#import "BYExamCellModel.h"
#import "YFEnvironmentManager.h"
#import <YFAdsSDK/YFKit.h>
#import <YFAdsSDK/YFAdNativeExpress.h>
#import <YFAdsSDK/YFAdNativeExpressView.h>
#import "AdDataJsonManager.h"
#import "DemoPresentViewController.h"

@interface DemoListFeedExpressChangeViewController () <UITableViewDelegate, UITableViewDataSource, YFAdNativeExpressDelegate>
{
    BOOL _isLoadAndShow;
    BOOL _isShowLogView;
    CGFloat _navAndStateBarHeight;
    
}
@property (strong, nonatomic) UITableView *tableView;

@property (strong,nonatomic) YFAdNativeExpress *advanceFeed;
@property (nonatomic, strong) NSMutableArray *dataArrM;
@property (nonatomic, assign) BOOL isLoadAndShow;
@property (nonatomic, assign) BOOL isShowLogView;

@end

@implementation DemoListFeedExpressChangeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title = @"信息流切换控制器展示";
    self.btnLoad.hidden = YES;
    self.btnShow.hidden = NO;
    self.btnLoadAndShow.hidden = YES;
    self.btnChange.hidden = YES;

    
    CGFloat statusHeight = [[UIApplication sharedApplication] statusBarFrame].size.height;
    CGFloat navHeight = self.navigationController.navigationBar.frame.size.height;
    
    _navAndStateBarHeight = navHeight + statusHeight;
    
    self.textV.frame = CGRectMake(0,0 - 300, self.view.frame.size.width, 300);
    self.dic = [[AdDataJsonManager shared] loadAdDataWithType:JsonDataType_nativeExpress];

    UIBarButtonItem *rightBar = [[UIBarButtonItem alloc] initWithTitle:@"显示日志" style:UIBarButtonItemStylePlain target:self action:@selector(showLogView)];
    self.navigationItem.rightBarButtonItem = rightBar;
    
    _tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
    [self.view addSubview:_tableView];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.bottom.equalTo(self.view);
        make.height.equalTo(@(self.view.frame.size.height - 330));
    }];
    
    [_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"splitnativeexpresscell"];
    [_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"nativeexpresscell"];
    [_tableView registerClass:[ExamTableViewCell class] forCellReuseIdentifier:@"ExamTableViewCell"];
    _tableView.delegate = self;
    _tableView.dataSource = self;
    _tableView.tableFooterView = [UIView new];
    [self.tableView reloadData];

    _dataArrM = [[NSMutableArray alloc] initWithCapacity:0];
}

- (void)dismissVC{
    [self dismissViewControllerAnimated:YES completion:nil];
}


-(void)viewDidDisappear:(BOOL)animated{
    [super viewDidDisappear:animated];
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    [self showAd];
}

- (void)showAd {
    if (self.arrViewsM.count == 0 ) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    
    for (YFAdNativeExpress *adapter in self.adRequestArray) {
        [adapter setNewDelegate:self];
        [adapter setRootController:self];
    }
    [self showNativeAd];
}





- (void)deallocAd {

    [self.dataArrM removeAllObjects];
    [self.arrViewsM removeAllObjects];
    [self.tableView reloadData];
    [self loadAdWithState:AdState_Normal];

}

// 信息流广告比较特殊, 渲染逻辑需要自行处理
- (void)showNativeAd {
    for (NSInteger i = 0; i < self.arrViewsM.count; i++) {
        YFAdNativeExpressView *view = self.arrViewsM[i];
        [self showProcessWithText:[NSString stringWithFormat:@"%zd -- %@",i ,[view isValid] ? @"有效":@"无效"]];
        [view setRootController:self];
        [view render];
        [_dataArrM insertObject:self.arrViewsM[i] atIndex:0];
    }
    [self.tableView reloadData];

}

- (void)showLogView {
    [UIView animateWithDuration:0.2 animations:^{
        self.textV.frame = CGRectMake(0,((self->_isShowLogView = !self->_isShowLogView) ? kAppTopH : -300 ), self.view.frame.size.width, 300);
        self.navigationItem.rightBarButtonItem.title = self->_isShowLogView ? @"隐藏日志":@"显示日志";
    }];
}

// MARK: ======================= YFAdNativeExpressDelegate =======================



/// 广告曝光
- (void)fcAdNativeExpressOnAdShow:(YFAdNativeExpressView *)adView {
    AlertIfNotMainThread
    
    NSLog(@"广告曝光 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

/// 广告点击
- (void)fcAdNativeExpressOnAdClicked:(YFAdNativeExpressView *)adView {
    AlertIfNotMainThread
    NSLog(@"广告点击 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击", __func__]];
}

/// 广告渲染成功
/// 注意和广告数据拉取成功的区别  广告数据拉取成功, 但是渲染可能会失败
/// 广告加载失败 是广点通 穿山甲 mercury 在拉取广告的时候就全部失败了
/// 该回调的含义是: 比如: 广点通拉取广告成功了并返回了一组view  但是其中某个view的渲染失败了
/// 该回调会触发多次
- (void)fcAdNativeExpressOnAdRenderSuccess:(YFAdNativeExpressView *)adView {
    AlertIfNotMainThread
    /// 过滤穿山上甲渲染成功之后返回高度
//    if (([adView.expressView isKindOfClass:NSClassFromString(@"BUNativeExpressFeedVideoAdView")] ||
//         [adView.expressView isKindOfClass:NSClassFromString(@"BUNativeExpressAdView")] ||
//         [adView.expressView isKindOfClass:NSClassFromString(@"CSINativeExpressFeedVideoAdView")] ||
//         [adView.expressView isKindOfClass:NSClassFromString(@"CSJNativeExpressAdView")])) {
//        [adView setRootController:[UIViewController new]];
//        [_dataArrM insertObject:adView atIndex:0];
//        [self.tableView reloadData];
//
//    }
    
    
    NSLog(@"广告渲染成功 %s %@", __func__, adView);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染成功", __func__]];
    [self.tableView reloadData];
}

/// 广告渲染失败
/// 注意和广告加载失败的区别  广告数据拉取成功, 但是渲染可能会失败
/// 广告加载失败 是广点通 穿山甲 mercury 在拉取广告的时候就全部失败了
/// 该回调的含义是: 比如: 广点通拉取广告成功了并返回了一组view  但是其中某个view的渲染失败了
/// 该回调会触发多次
- (void)fcAdNativeExpressOnAdRenderFail:(YFAdNativeExpressView *)adView {
    AlertIfNotMainThread
    NSLog(@"广告渲染失败 %s %@", __func__, adView);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染失败", __func__]];
    [_dataArrM removeObject:adView];
    [self.tableView reloadData];
}

/// 广告加载失败
/// 该回调只会触发一次
- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description{
    AlertIfNotMainThread
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常:%@ \r\n", __func__,error.userInfo.description]];
    [self showErrorWithDescription:description];
    [self loadAdWithState:AdState_LoadFailed];
    [self deallocAd];

}

- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter description:(NSDictionary *)description {
    AlertIfNotMainThread
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);

    dispatch_async(dispatch_get_main_queue(), ^{
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error.userInfo.description]];
        [self showErrorWithDescription:description];
    });
}


/// 广告被关闭
- (void)fcAdNativeExpressOnAdClosed:(YFAdNativeExpressView *)adView {
    AlertIfNotMainThread
    //需要从tableview中删除
    NSLog(@"广告关闭 %s", __func__);
    [_dataArrM removeObject: adView];
    [self.tableView reloadData];
}



// MARK: ======================= UITableViewDelegate, UITableViewDataSource =======================

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
//    return _expressAdViews.count*2;
//    return 2;
    return _dataArrM.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    if ([_dataArrM[indexPath.row] isKindOfClass:[BYExamCellModelElement class]]) {
        return ((BYExamCellModelElement *)_dataArrM[indexPath.row]).cellh;
    } else {
        CGFloat height = ([_dataArrM[indexPath.row] expressView]).frame.size.height;
//        NSLog(@"=======> %f", height);
        return height;
    }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell;
    if ([_dataArrM[indexPath.row] isKindOfClass:[BYExamCellModelElement class]]) {
        cell = [tableView dequeueReusableCellWithIdentifier:@"ExamTableViewCell"];
        ((ExamTableViewCell *)cell).item = _dataArrM[indexPath.row];
        return cell;
    } else {
        cell = [self.tableView dequeueReusableCellWithIdentifier:@"nativeexpresscell" forIndexPath:indexPath];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;

        UIView *subView = (UIView *)[cell.contentView viewWithTag:1000];
        if ([subView superview]) {
            [subView removeFromSuperview];
        }
        UIView *view = [_dataArrM[indexPath.row] expressView];

        view.tag = 1000;
        [cell.contentView addSubview:view];
        cell.accessibilityIdentifier = @"nativeTemp_ad";
//        [view mas_remakeConstraints:^(MASConstraintMaker *make) {
//            make.edges.equalTo(@0);
//        }];

        return cell;
    }
}

-(void)dealloc {
    NSLog(@"信息流释放 %s", __func__);
}

@end


