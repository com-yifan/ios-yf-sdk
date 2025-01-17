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
#import "YFDataJsonManager.h"
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
@property (nonatomic, strong) UIScrollView *contentV;
@property (nonatomic, strong) UIView *container;

@property (nonatomic, strong) NSMutableArray <YFAdNativeExpress *>*adRequestArray;
@property (nonatomic, strong) NSMutableArray *dataArrM;
@property (nonatomic, strong) NSMutableArray *adsViewsArrM;
@property (nonatomic, assign) BOOL isLoadAndShow;
@property (nonatomic, assign) BOOL isShowLogView;
/// 是否是列表场景,默认固定视图
@property (nonatomic, assign) BOOL isListMode;
@property (nonatomic, strong) UIButton *listBtn;
@property (nonatomic, strong) UIButton *viewBtn;

@end

@implementation DemoListFeedExpressViewController

#pragma mark - property

- (UIButton *)listBtn {
    if (!_listBtn) {
        _listBtn = [UIButton buttonWithType:UIButtonTypeSystem];
        _listBtn.backgroundColor = UIColor.clearColor;
        _listBtn.layer.cornerRadius = 5.f;
        _listBtn.layer.masksToBounds = YES;
        _listBtn.layer.borderWidth = 2.f;
        _listBtn.layer.borderColor = UIColor.systemBlueColor.CGColor;
        [_listBtn setTitle:@"列表场景" forState:UIControlStateNormal];
        [_listBtn setTitleColor:[UIColor systemBlueColor] forState:UIControlStateNormal];
        [_listBtn addTarget:self action:@selector(changeListMode) forControlEvents:UIControlEventTouchUpInside];
    }
    return _listBtn;
}

- (UIButton *)viewBtn {
    if (!_viewBtn) {
        _viewBtn = [UIButton buttonWithType:UIButtonTypeSystem];
        _viewBtn.backgroundColor = UIColor.clearColor;
        _viewBtn.layer.cornerRadius = 5.f;
        _viewBtn.layer.masksToBounds = YES;
        _viewBtn.layer.borderWidth = 2.f;
        _viewBtn.layer.borderColor = UIColor.systemBlueColor.CGColor;
        [_viewBtn setTitle:@"固定场景" forState:UIControlStateNormal];
        [_viewBtn setTitleColor:[UIColor systemBlueColor] forState:UIControlStateNormal];
        [_viewBtn addTarget:self action:@selector(changeViewMode) forControlEvents:UIControlEventTouchUpInside];
    }
    return _viewBtn;
}

- (UIScrollView *)contentV {
    if (!_contentV) {
        float width = self.view.bounds.size.width;
        _contentV = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 10,width, 400)];
        _contentV.backgroundColor = UIColor.whiteColor;
    }
    return _contentV;
}

- (UIView *)container {
    if (!_container) {
        _container = [[UIView alloc] init];
        _container.backgroundColor = UIColor.whiteColor;
    }
    return _container;
}

- (UITableView *)tableView {
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
        [_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"splitnativeexpresscell"];
        [_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"nativeexpresscell"];
        [_tableView registerClass:[ExamTableViewCell class] forCellReuseIdentifier:@"ExamTableViewCell"];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.tableFooterView = [UIView new];
        //下拉刷新
        _tableView.mj_header = [MJRefreshNormalHeader headerWithRefreshingTarget:self refreshingAction:@selector(refreshAction)];
        MJRefreshAutoFooter* foot = [MJRefreshAutoNormalFooter footerWithRefreshingTarget:self refreshingAction:@selector(loadMore)];
        _tableView.mj_footer = foot;
    }
    return _tableView;
}

- (NSMutableArray *)dataArrM{
    if (!_dataArrM) {
        _dataArrM = [NSMutableArray array];
    }
    return _dataArrM;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"信息流";
    // 加载器强引用
    self.adRequestArray = [NSMutableArray array];

    CGFloat statusHeight = [[UIApplication sharedApplication] statusBarFrame].size.height;
    CGFloat navHeight = self.navigationController.navigationBar.frame.size.height;
    _navAndStateBarHeight = navHeight + statusHeight;
    
    self.dic = [[YFDataJsonManager shared] loadAdDataWithType:JsonDataType_nativeExpress];
    UIBarButtonItem *rightBar = [[UIBarButtonItem alloc] initWithTitle:@"显示日志" style:UIBarButtonItemStylePlain target:self action:@selector(showLogView)];
    self.navigationItem.rightBarButtonItem = rightBar;
    double width = (UIScreen.mainScreen.bounds.size.width - 2 * 50);
    self.listBtn.frame = CGRectMake(50, 280, width, 40);
    self.viewBtn.frame = CGRectMake(50, 340, width, 40);
    [self.view addSubview:self.listBtn];
    [self.view addSubview:self.viewBtn];
    [self.view bringSubviewToFront:self.textV];
    self.textV.frame = CGRectMake(0,-600, self.view.frame.size.width, 300);
    [self.labNotify setHidden:YES];
    // 默认固定场景演示
    [self changeViewMode];
}

- (void)dismissVC {
    [self dismissViewControllerAnimated:YES completion:nil];
}

-(void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    
}

#pragma mark =============== 上拉加载下拉刷新 ===============

- (void)refreshAction{
    [self.adRequestArray removeAllObjects];
    [self loadAndShowAd];
    self.view.userInteractionEnabled = NO;
}

- (void)loadMore{
    [self loadAndShowAd];
}

#pragma mark =============== 广告加载 ===============

- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    _isLoadAndShow = NO;
    self.dataArrM = [NSMutableArray arrayWithArray:[CellBuilder dataFromJsonFile:@"cell01"]];
    // 初始化广告加载器 viewController需传入最上层可见控制器，否则无法模态推出广告落地页影响转化
    // 尺寸建议传入期望尺寸大小 部分联盟不支持0
    YFAdNativeExpress *advanceFeed = [[YFAdNativeExpress alloc] initWithAdUnitID:[YFEnvironmentManager getNATIVE_ID] adContainer:nil viewController:self adSize:CGSizeMake(self.view.bounds.size.width, _isListMode ? (self.view.bounds.size.width) * 400.0 /600.0 : 0)];
    advanceFeed.count = 1;
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
    if (!_isListMode) [self deallocAd];
    _isLoadAndShow = YES;
    // 初始化广告加载器 viewController需传入最上层可见控制器，否则无法模态推出广告落地页影响转化
    // 尺寸建议传入期望尺寸大小 部分联盟不支持0
    YFAdNativeExpress *advanceFeed = [[YFAdNativeExpress alloc] initWithAdUnitID:[YFEnvironmentManager getNATIVE_ID] adContainer:nil viewController:self adSize:CGSizeMake(self.view.bounds.size.width, _isListMode ? (self.view.bounds.size.width) * 400.0 /600.0 : 0)];
    advanceFeed.count = 1;
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
    [self.tableView removeFromSuperview];
    [self.container removeFromSuperview];
    self.tableView = nil;
    self.container = nil;
    self.contentV = nil;

}

// 信息流广告比较特殊, 渲染逻辑需要自行处理
- (void)showNativeAd {
    if (!self.isLoaded) return;
    if (_isListMode) {
        // 列表场景
        [self.view addSubview:self.tableView];
        [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.right.bottom.equalTo(self.view);
            make.height.equalTo(@(self.view.frame.size.height - 400));
        }];
        [self.tableView reloadData];
    } else {
        // 固定场景
        [self.view addSubview:self.container];
        [self.container setHidden:NO];
        [self.container mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.right.bottom.equalTo(self.view);
            make.height.equalTo(@(self.view.frame.size.height - 400));
        }];
    }
}


- (void)insertAdToDataSource{
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

- (void)showLogView {
    [UIView animateWithDuration:0.2 animations:^{
        self.textV.frame = CGRectMake(0,((self->_isShowLogView = !self->_isShowLogView) ? kAppTopH : -300 ), self.view.frame.size.width, 300);
        self.navigationItem.rightBarButtonItem.title = self->_isShowLogView ? @"隐藏日志":@"显示日志";
    }];
}

/// 切换为列表场景
- (void)changeListMode {
    [self deallocAd];
    [self.contentV removeFromSuperview];
    self.contentV = nil;
    [self.container removeFromSuperview];
    self.container = nil;
    [self.view addSubview:self.tableView];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.bottom.equalTo(self.view);
        make.height.equalTo(@(self.view.frame.size.height - 400));
    }];
    _isListMode = YES;
    [JDStatusBarNotification showWithStatus:@"已切换为列表场景" dismissAfter:1.5];
}

/// 切换为固定视图场景
- (void)changeViewMode {
    [self deallocAd];
    [self.tableView removeFromSuperview];
    [self.container addSubview:self.contentV];
    [self.view addSubview:self.container];
    _isListMode = NO;
    [JDStatusBarNotification showWithStatus:@"已切换为固定视图场景" dismissAfter:1.5];
    [self.container mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.bottom.equalTo(self.view);
        make.height.equalTo(@(self.view.frame.size.height - 400));
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
    self.isLoaded = YES;
    NSLog(@"广告拉取成功 %s", __func__);
    self.adsViewsArrM = [views mutableCopy];
    NSLog(@"=========%@",views[0].isValid?@"有效":@"无效");
    [self insertAdToDataSource];
    if (!_isListMode && _isLoadAndShow) {
        [self.contentV addSubview:views.firstObject.expressView];
        self.contentV.frame = CGRectMake(self.view.bounds.size.width/2 - views.firstObject.expressView.bounds.size.width/2, 0,views.firstObject.expressView.bounds.size.width, 400);
        self.contentV.contentSize = CGSizeMake(views.firstObject.expressView.bounds.size.width, views.firstObject.expressView.bounds.size.height);
        [self.container addSubview:self.contentV];
    }
    if (_isLoadAndShow) {
        [self showNativeAd];
    }
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
    if (_isListMode) {
        NSInteger index = [_dataArrM indexOfObject:adView];
        [_dataArrM removeObject: adView];
        [self.tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:[NSIndexPath indexPathForRow:index inSection:0]] withRowAnimation:UITableViewRowAnimationFade];
    } else {
        /// 广告关闭移除广告视图
        [adView.expressView removeFromSuperview];
        [self.container removeFromSuperview];
    }
}



// MARK: ======================= UITableViewDelegate, UITableViewDataSource =======================

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return _dataArrM.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    if ([_dataArrM[indexPath.row] isKindOfClass:[BYExamCellModelElement class]]) {
        return ((BYExamCellModelElement *)_dataArrM[indexPath.row]).cellh;
    } else {
        CGFloat height = ([_dataArrM[indexPath.row] expressView]).frame.size.height;
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

        return cell;
    }
}

- (void)dealloc {

}
@end


