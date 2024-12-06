//
//  DemoListFeedExpressViewController.m
//  Example
//
//  Created by CherryKing on 2019/11/21.
//  Copyright © 2019 CherryKing. All rights reserved.
//

#import "DemoListFeedExpressViewController.h"
#import "CellBuilder.h"
#import "BYExamCellModel.h"
#import "YFEnvironmentManager.h"
#import <YFAdsSDK/YFKit.h>
#import <YFAdsSDK/YFAdNativeExpress.h>
#import <YFAdsSDK/YFAdNativeExpressView.h>
#import "AdDataJsonManager.h"
#import "DemoPresentViewController.h"
#import "DemoListFeedExpressChangeViewController.h"
#import <MJRefresh/MJRefresh.h>

@interface DemoListFeedExpressViewController () <UITableViewDelegate, UITableViewDataSource, YFAdNativeExpressDelegate>
{
    BOOL _isLoadAndShow;
    BOOL _isShowLogView;
    CGFloat _navAndStateBarHeight;
    
}
@property (strong, nonatomic) UITableView *tableView;

@property (nonatomic, strong) NSMutableArray <YFAdNativeExpress *>*adRequestArray;
@property (nonatomic, strong) NSMutableArray *dataArrM;
@property (nonatomic, strong) NSMutableArray *adsViewsArrM;
@property (nonatomic, assign) BOOL isLoadAndShow;
@property (nonatomic, assign) BOOL isShowLogView;

@end

@implementation DemoListFeedExpressViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"信息流";
    self.adRequestArray = [NSMutableArray array];

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
    //下拉刷新
    self.tableView.mj_header = [MJRefreshNormalHeader headerWithRefreshingTarget:self refreshingAction:@selector(refreshAction)];
    MJRefreshAutoFooter* foot = [MJRefreshAutoNormalFooter footerWithRefreshingTarget:self refreshingAction:@selector(loadMore)];
//    foot.triggerAutomaticallyRefreshPercent = -10.;
    self.tableView.mj_footer = foot;
//    self.tableView.mj_footer.ignoredScrollViewContentInsetBottom = 20;
//    if (self.navigationController) {
//        UIBarButtonItem *rightBar = [[UIBarButtonItem alloc] initWithTitle:@"Push" style:UIBarButtonItemStylePlain target:self action:@selector(pushVC)];
//        self.navigationItem.rightBarButtonItem = rightBar;
//    }else{
//        UIButton *closeBtn = [[UIButton alloc]initWithFrame:CGRectMake(20,40, 50, 50)];
//        [closeBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
//        [closeBtn addTarget:self action:@selector(dismissVC) forControlEvents:UIControlEventTouchUpInside];
//        [closeBtn setTitle:@"关闭" forState:UIControlStateNormal];
//        [self.view addSubview:closeBtn];
//
//        UIButton *pushBtn = [[UIButton alloc]initWithFrame:CGRectMake(self.view.frame.size.width - 50 - 20,40, 50, 50)];
//        [pushBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
//        [pushBtn addTarget:self action:@selector(pushVC) forControlEvents:UIControlEventTouchUpInside];
//        [pushBtn setTitle:@"Push" forState:UIControlStateNormal];
//        [self.view addSubview:pushBtn];
//    }
    
}

- (void)dismissVC {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)pushVC {
    DemoPresentViewController *newVC = [[DemoPresentViewController alloc]init];
//    [self.navigationController pushViewController:newVC animated:YES];
    newVC.modalPresentationStyle = 0;
    [self presentViewController:newVC animated:YES completion:nil];
}

-(void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    
}

#pragma mark =============== 上拉加载下拉刷新 ===============
-(void)refreshAction{
    [self.adRequestArray removeAllObjects];
    [self loadAndShowAd];
    self.view.userInteractionEnabled = NO;
}

-(void)loadMore{
    [self loadAndShowAd];
}
#pragma mark =============== 广告加载 ===============
- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    
    _isLoadAndShow = NO;
    
    self.dataArrM = [NSMutableArray arrayWithArray:[CellBuilder dataFromJsonFile:@"cell01"]];
    YFAdNativeExpress *advanceFeed = [[YFAdNativeExpress alloc] initWithAdUnitID:[YFEnvironmentManager getNATIVE_ID] adContainer:nil viewController:self adSize:CGSizeMake(self.view.bounds.size.width, (self.view.bounds.size.width) * 400.0 /600.0)];
    advanceFeed.count = 3;
    advanceFeed.delegate = self;
    [advanceFeed loadAndShowAd];
    [self.adRequestArray addObject:advanceFeed];

    [self loadAdWithState:AdState_Loading];

}

- (void)showAd {
    if (self.adRequestArray.count == 0 || !self.isLoaded || self.dataArrM.count == 0 || self.adsViewsArrM.count == 0) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    [self showNativeAd];

}


- (void)loadAndShowAd {
    [super loadAd];
    [self loadAdWithState:AdState_Normal];
    
    _isLoadAndShow = YES;


    YFAdNativeExpress *advanceFeed = [[YFAdNativeExpress alloc] initWithAdUnitID:[YFEnvironmentManager getNATIVE_ID] adContainer:nil viewController:self adSize:CGSizeMake(self.view.bounds.size.width, (self.view.bounds.size.width) * 400.0 /600.0)];
    advanceFeed.count = 3;
    advanceFeed.delegate = self;
    [advanceFeed loadAndShowAd];
    [self.adRequestArray addObject:advanceFeed];
    [self loadAdWithState:AdState_Loading];
  
}

- (void)deallocAd {
    [self.adRequestArray removeAllObjects];

    self.isLoaded = NO;
    [self.dataArrM removeAllObjects];
    [self.adsViewsArrM removeAllObjects];
    [self.tableView reloadData];
    [self loadAdWithState:AdState_Normal];

}

// 信息流广告比较特殊, 渲染逻辑需要自行处理
- (void)showNativeAd {
    YFAdNativeExpressView *firstView = self.adsViewsArrM.firstObject;
    // 穿山甲需要在渲染成功之后的回调里
    if (([firstView.expressView isKindOfClass:NSClassFromString(@"BUNativeExpressFeedVideoAdView")] ||
         [firstView.expressView isKindOfClass:NSClassFromString(@"BUNativeExpressAdView")] ||
        [firstView.expressView isKindOfClass:NSClassFromString(@"CSINativeExpressFeedVideoAdView")] ||
        [firstView.expressView isKindOfClass:NSClassFromString(@"CSJNativeExpressAdView")])) {
        [firstView render];
    }else {
        [self insertAdToDataSource];
    }
}


-(void)insertAdToDataSource{

    if (self.tableView.mj_footer.state == MJRefreshStateRefreshing) {
        NSInteger startCount = self.dataArrM.count;
        [self.dataArrM addObjectsFromArray:[NSMutableArray arrayWithArray:[CellBuilder dataFromJsonFile:@"cell01"]]];

        for (NSInteger i = 0; i < self.adsViewsArrM.count; i++) {
            YFAdNativeExpressView *view = self.adsViewsArrM[i];
            [view render];
            //广告视图有效性校验请放到render之后，部分联盟未render不生效
            NSLog(@"广告视图%p有效性：%@",view,view.isValid?@"有效":@"失效");
            // 随机位置
            NSUInteger randomIndex = startCount + arc4random_uniform((uint32_t)(_dataArrM.count + 1 - startCount));
            // 将视图插入到随机位置
            [_dataArrM insertObject:view atIndex:randomIndex];
        }
        [self.tableView.mj_footer endRefreshing];
    }else{
        self.dataArrM = [NSMutableArray arrayWithArray:[CellBuilder dataFromJsonFile:@"cell01"]];

        for (NSInteger i = 0; i < self.adsViewsArrM.count; i++) {
            YFAdNativeExpressView *view = self.adsViewsArrM[i];
            [view render];
            //广告视图有效性校验请放到render之后，部分联盟未render不生效
            NSLog(@"广告视图%p有效性：%@",view,view.isValid?@"有效":@"失效");
            // 随机位置
            NSUInteger randomIndex = arc4random_uniform((uint32_t)(_dataArrM.count + 1));
            // 将视图插入到随机位置
            [_dataArrM insertObject:view atIndex:randomIndex];
        }
        [self.tableView.mj_header endRefreshing];
    }
    self.view.userInteractionEnabled = YES;
    [self.tableView reloadData];
}

-(void)changeVC {
    
    if (self.adsViewsArrM == nil && self.adsViewsArrM.count <= 0) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    
    DemoListFeedExpressChangeViewController * pvc = [[DemoListFeedExpressChangeViewController alloc] init];
    pvc.adRequestArray = [self.adRequestArray copy];
    pvc.arrViewsM = [self.adsViewsArrM copy];
    [self.navigationController pushViewController:pvc animated:YES];
    
}


- (void)showLogView {
    [UIView animateWithDuration:0.2 animations:^{
        self.textV.frame = CGRectMake(0,((self->_isShowLogView = !self->_isShowLogView) ? kAppTopH : -300 ), self.view.frame.size.width, 300);
        self.navigationItem.rightBarButtonItem.title = self->_isShowLogView ? @"隐藏日志":@"显示日志";
    }];
}

// MARK: ======================= YFAdNativeExpressDelegate =======================


- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    AlertIfNotMainThread
    ///===================

}


/// 广告数据拉取成功
- (void)fcAdNativeExpressOnAdLoadSuccess:(NSArray<YFAdNativeExpressView *> *)views {
    AlertIfNotMainThread
    if (!views||views.count == 0) {
        self.view.userInteractionEnabled = YES;
        [self.tableView.mj_header endRefreshing];
        [self.tableView.mj_footer endRefreshing];
        return;
    }
    NSLog(@"广告拉取成功 %s", __func__);
    self.adsViewsArrM = [views mutableCopy];
    NSLog(@"=========%@",views[0].isValid?@"有效":@"无效");
    if (_isLoadAndShow) {
        [self showNativeAd];
    }
    
    self.isLoaded = YES;
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告拉取成功", __func__]];
    [self loadAdWithState:AdState_LoadSucceed];

}


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
    /// 穿山上甲渲染成功之后返回高度
    if (([adView.expressView isKindOfClass:NSClassFromString(@"BUNativeExpressFeedVideoAdView")] ||
         [adView.expressView isKindOfClass:NSClassFromString(@"BUNativeExpressAdView")] ||
         [adView.expressView isKindOfClass:NSClassFromString(@"CSINativeExpressFeedVideoAdView")] ||
         [adView.expressView isKindOfClass:NSClassFromString(@"CSJNativeExpressAdView")])) {
        [adView setRootController:[UIViewController new]];
        [self insertAdToDataSource];
    }
    
    
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
    [_dataArrM removeObject: adView];
    self.view.userInteractionEnabled = YES;
    [self.tableView.mj_header endRefreshing];
    [self.tableView.mj_footer endRefreshing];
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
}

- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter description:(NSDictionary *)description {
    AlertIfNotMainThread
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);

    dispatch_async(dispatch_get_main_queue(), ^{
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error.userInfo.description]];
        [self showErrorWithDescription:description];
        self.view.userInteractionEnabled = YES;
        [self.tableView.mj_header endRefreshing];
        [self.tableView.mj_footer endRefreshing];
    });
}


/// 广告被关闭
- (void)fcAdNativeExpressOnAdClosed:(YFAdNativeExpressView *)adView {
    AlertIfNotMainThread
    //需要从tableview中删除
    NSLog(@"广告关闭 %s", __func__);
    NSInteger index = [_dataArrM indexOfObject:adView];
    [_dataArrM removeObject: adView];
    [self.tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:[NSIndexPath indexPathForRow:index inSection:0]] withRowAnimation:UITableViewRowAnimationFade];
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

- (NSMutableArray *)dataArrM{
    if (!_dataArrM) {
        _dataArrM = [NSMutableArray array];
    }
    return _dataArrM;
}
-(void)dealloc {
//    NSLog(@"======对象释放 %@", NSStringFromClass([self class]));
}

@end


