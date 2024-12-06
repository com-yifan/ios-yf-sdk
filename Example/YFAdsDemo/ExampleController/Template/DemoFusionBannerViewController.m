//
//  DemoFusionBannerViewController.m
//  YFAdsSDK_Example
//
//  Created by Erik on 2024/10/22.
//  Copyright © 2024 Cheng455153666. All rights reserved.
//

#import "DemoFusionBannerViewController.h"
#import <YFAdsSDK/YFAdFusionBanner.h>
#import "AdDataJsonManager.h"
#import "YFEnvironmentManager.h"
#import "DemoPresentViewController.h"
#import "CellBuilder.h"
#import "BYExamCellModel.h"
#import "AdDataJsonManager.h"
#import <MJRefresh/MJRefresh.h>

@interface DemoFusionBannerViewController ()<YFAdFusionBannerDelegate,UITableViewDataSource,UITableViewDelegate>

@property (nonatomic, strong) YFAdFusionBanner *adBanner;
@property (nonatomic, strong) UIScrollView *contentV;
@property (nonatomic, strong) UIView *container;
@property (nonatomic, strong) UITableView *tableView;
/// 数据源
@property (nonatomic, strong) NSMutableArray *dataArrays;
/// 广告加载器
@property (nonatomic, strong) NSMutableArray *fusionBannerArrays;

@property (nonatomic, strong) UISlider * slider;
@property (nonatomic, strong) UILabel * marginLabel;
@property (nonatomic, assign) BOOL isShowLogView;
/// 是否是列表场景,默认固定视图
@property (nonatomic, assign) BOOL isListMode;
@property (nonatomic, strong) UIButton *listBtn;
@property (nonatomic, strong) UIButton *viewBtn;

@end

@implementation DemoFusionBannerViewController

#pragma mark - lazy load
- (NSMutableArray *)fusionBannerArrays{
    if (!_fusionBannerArrays) {
        _fusionBannerArrays = [NSMutableArray array];
    }
    return _fusionBannerArrays;
}

- (NSMutableArray *)dataArrays{
    if (!_dataArrays) {
        _dataArrays = [NSMutableArray array];
    }
    return _dataArrays;
}
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
        float width = self.view.bounds.size.width - (self.slider.value * 60 * 2);
        _contentV = [[UIScrollView alloc] initWithFrame:CGRectMake(self.slider.value * 60, 10,width, 400)];
        _contentV.backgroundColor = UIColor.whiteColor;
    }
    return _contentV;
}

- (UIView *)container {
    if (!_container) {
        _container = [[UIView alloc] initWithFrame:CGRectMake(0, 460 ,self.view.frame.size.width,self.view.frame.size.height - 460.0)];
        _container.backgroundColor = UIColor.systemBlueColor;
    }
    return _container;
}

- (UITableView *)tableView {
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 460 ,self.view.frame.size.width,self.view.frame.size.height - 460.0) style:UITableViewStylePlain];
        [_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"splitnativeexpresscell"];
        [_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"nativeexpresscell"];
        [_tableView registerClass:[ExamTableViewCell class] forCellReuseIdentifier:@"ExamTableViewCell"];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.tableFooterView = [UIView new];
        //下拉刷新
        _tableView.mj_header = [MJRefreshNormalHeader headerWithRefreshingTarget:self refreshingAction:@selector(refreshAction)];
        _tableView.mj_footer = [MJRefreshBackNormalFooter footerWithRefreshingTarget:self refreshingAction:@selector(loadMore)];

    }
    return _tableView;
}

- (void)viewDidLoad {
    [super viewDidLoad];
   
    self.title = @"融合横幅";
    UIBarButtonItem *rightBar = [[UIBarButtonItem alloc] initWithTitle:@"显示日志" style:UIBarButtonItemStylePlain target:self action:@selector(showLogView)];
    self.navigationItem.rightBarButtonItem = rightBar;
    
    double width = (UIScreen.mainScreen.bounds.size.width - 2 * 50);
    [self.btnChange removeFromSuperview];
    self.listBtn.frame = CGRectMake(50, 280, width, 40);
    self.viewBtn.frame = CGRectMake(50, 340, width, 40);
    [self.view addSubview:self.listBtn];
    [self.view addSubview:self.viewBtn];
    [self.view bringSubviewToFront:self.textV];
    // 边距控制
    self.slider = [UISlider new];
    self.slider.frame = CGRectMake(30, 400,self.view.frame.size.width - 60, 20);
    [self.slider addTarget:self action:@selector(sliderEndChangeValue:) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:self.slider];
    // 边距提示
    self.marginLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 420,self.view.frame.size.width, 20)];
    self.marginLabel.textAlignment = NSTextAlignmentCenter;
    self.marginLabel.text = @"边距：0";
    [self.view addSubview:self.marginLabel];
    // 日志
    self.textV.frame = CGRectMake(0,_isShowLogView ? kAppTopH : -600, self.view.frame.size.width, 600);
    [self.labNotify setHidden:YES];
    // 默认固定场景演示
    [self changeViewMode];
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
   // [self loadAndShowAd];
    self.navigationController.navigationBar.hidden = NO;

}

- (void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated{
    [super viewDidDisappear:animated];
}

#pragma mark =============== 上拉加载下拉刷新 ===============
-(void)refreshAction{
    [self.fusionBannerArrays removeAllObjects];
    [self loadAndShowAd];
    self.view.userInteractionEnabled = NO;
}

-(void)loadMore{
    [self loadAndShowAd];
}

#pragma mark - 广告相关生命周期
- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    self.dataArrays = [NSMutableArray arrayWithArray:[CellBuilder dataFromJsonFile:@"cell01"]];
    // 列表场景
    if (_isListMode) {
        YFAdFusionBanner *adBanner = [[YFAdFusionBanner alloc] initWithAdUnitID:[YFEnvironmentManager getFusionBanner_ID] viewController:self];
        // 设置融合banner代理对象
        adBanner.delegate = self;
        // 设置融合banner返回广告尺寸宽度，高度按广告实际比例返回
        adBanner.adWidth = self.view.bounds.size.width - (self.slider.value * 60 * 2);
        // 加载广告
        [adBanner loadAndShowAd];
        // 设置强引用
        [self.fusionBannerArrays addObject:adBanner];
    } else {
        self.adBanner = [[YFAdFusionBanner alloc] initWithAdUnitID:[YFEnvironmentManager getFusionBanner_ID] viewController:self];
        // 设置融合banner代理对象
        self.adBanner.delegate = self;
        // 设置融合banner加载数量（建议1条，最多3条）
        self.adBanner.adCount = _isListMode ?  2 : 1;
        // 设置融合banner返回广告尺寸宽度，高度按广告实际比例返回
        self.adBanner.adWidth = self.view.bounds.size.width - (self.slider.value * 60 * 2);
        // 加载广告
        [self.adBanner loadAndShowAd];
    }
    [self loadAdWithState:AdState_Loading];
    self.isOnlyLoad = YES;
}

- (void)showAd {
    if (!self.isLoaded) return;
    if (_isListMode) {
        [self.view addSubview:self.tableView];
    } else {
        [self.view addSubview:self.container];
        [self.container setHidden:NO];
    }
}

- (void)loadAndShowAd{
    [super loadAndShowAd];
    [self loadAdWithState:AdState_Normal];
    if (_isListMode) {
        YFAdFusionBanner *adBanner = [[YFAdFusionBanner alloc] initWithAdUnitID:[YFEnvironmentManager getFusionBanner_ID] viewController:self];
        // 设置融合banner代理对象
        adBanner.delegate = self;
        // 设置融合banner返回广告尺寸宽度，高度按广告实际比例返回
        adBanner.adWidth = self.view.bounds.size.width - (self.slider.value * 60 * 2);
        // 加载广告
        [adBanner loadAndShowAd];
        // 设置强引用
        [self.fusionBannerArrays addObject:adBanner];
    } else {
        self.adBanner = [[YFAdFusionBanner alloc] initWithAdUnitID:[YFEnvironmentManager getFusionBanner_ID] viewController:self];
        // 设置融合banner代理对象
        self.adBanner.delegate = self;
        // 设置融合banner加载数量（建议1条，最多3条）
        self.adBanner.adCount = _isListMode ?  2 : 1;
        // 设置融合banner返回广告尺寸宽度，高度按广告实际比例返回
        self.adBanner.adWidth = self.view.bounds.size.width - (self.slider.value * 60 * 2);
        // 加载广告
        [self.adBanner loadAndShowAd];
    }
    [self loadAdWithState:AdState_Loading];
    [self.container setHidden:NO];
    [self.tableView setHidden:NO];
    if (_isListMode) {
        [self.view addSubview:self.tableView];
    } else {
        [self.view addSubview:self.container];
    }
}

- (void)dealloc {
    [self deallocAd];
}

/// 释放广告加载器
- (void)deallocAd {
    self.isLoaded = NO;
    self.dataArrays = [NSMutableArray arrayWithArray:[CellBuilder dataFromJsonFile:@"cell01"]];
    // 释放广告加载器
    self.fusionBannerArrays = [NSMutableArray new];
    self.adBanner = nil;
    [self.tableView reloadData];
    [self.tableView removeFromSuperview];
    [self.container removeFromSuperview];
    self.container = nil;
    self.contentV = nil;
}

#pragma mark  - UITableViewDataSource & UITableViewDelegate

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return _dataArrays.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    if ([_dataArrays[indexPath.row] isKindOfClass:[BYExamCellModelElement class]]) {
        return ((BYExamCellModelElement *)_dataArrays[indexPath.row]).cellh;
    } else {
        CGFloat height = ((YFAdFusionBannerView *)_dataArrays[indexPath.row]).bounds.size.height;
        return height;
    }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell;
    if ([_dataArrays[indexPath.row] isKindOfClass:[BYExamCellModelElement class]]) {
        cell = [tableView dequeueReusableCellWithIdentifier:@"ExamTableViewCell"];
        ((ExamTableViewCell *)cell).item = _dataArrays[indexPath.row];
        return cell;
    } else {
        cell = [self.tableView dequeueReusableCellWithIdentifier:@"nativeexpresscell" forIndexPath:indexPath];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;

        UIView *subView = (UIView *)[cell.contentView viewWithTag:1000];
        if ([subView superview]) {
            [subView removeFromSuperview];
        }
        UIView *view = _dataArrays[indexPath.row];

        view.tag = 1000;
        [cell.contentView addSubview:view];
        view.frame = CGRectMake(cell.contentView.bounds.size.width/2 - view.bounds.size.width/2, 0, view.bounds.size.width, view.bounds.size.height);
        cell.accessibilityIdentifier = @"nativeTemp_ad";
        return cell;
    }
}

#pragma mark - YFAdFusionBannerDelegate 广告相关回调

/// 广告数据拉取成功
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdLoadSuccess:(NSArray<YFAdFusionBannerView *> * _Nullable)views {
    AlertIfNotMainThread
    if (views.count > 0) {
        self.isLoaded = YES;
        if(self.isOnlyLoad) {}
        [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功", __func__]];
        /// 调用渲染方法，不调用无渲染相关回调
        for (YFAdFusionBannerView *bannerView in views) {
            [bannerView render];
        }
    } else {
        NSLog(@"广告展示失败 %s  返回广告为空", __func__);
        //通知主线程刷新
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n广告返回为空", __func__]];
            self.view.userInteractionEnabled = YES;
            [self.tableView.mj_header endRefreshing];
            [self.tableView.mj_footer endRefreshing];
        });
    }
    
}

/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter  description:(NSDictionary *)description{
    AlertIfNotMainThread
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
    //通知主线程刷新
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error.userInfo.description]];
        [self showErrorWithDescription:description];
        self.view.userInteractionEnabled = YES;
        [self.tableView.mj_header endRefreshing];
        [self.tableView.mj_footer endRefreshing];
    });
}

/// 广告曝光
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdShow:(YFAdFusionBannerView * _Nullable)adView {
    AlertIfNotMainThread
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

/// 广告点击
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdClicked:(YFAdFusionBannerView * _Nullable)adView {
    AlertIfNotMainThread
    NSLog(@"广告点击 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击", __func__]];
}

/// 广告渲染成功
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdRenderSuccess:(YFAdFusionBannerView * _Nullable)adView {
    AlertIfNotMainThread
    ///  渲染成功后 依据广告大小重设容器；其他需求可同理实现
    if (_isListMode) {
        [self insertAdToDataSource:adView];
    } else {
        [self.contentV addSubview:adView];
        self.contentV.frame = CGRectMake(self.slider.value * 60, 10,adView.bounds.size.width, self.container.bounds.size.height);
        self.contentV.contentSize = CGSizeMake(adView.bounds.size.width, adView.bounds.size.height);
        adView.frame = CGRectMake(0, 0, adView.bounds.size.width, adView.bounds.size.height);
        [self.container addSubview:self.contentV];
    }
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染成功", __func__]];
}

-(void)insertAdToDataSource:(YFAdFusionBannerView * _Nullable)adView{
    if (self.tableView.mj_footer.state == MJRefreshStateRefreshing) {
        NSInteger startCount = self.dataArrays.count;

        [self.dataArrays addObjectsFromArray:[NSMutableArray arrayWithArray:[CellBuilder dataFromJsonFile:@"cell01"]]];

        if (self.dataArrays.count > startCount+5) {
            if (![self.dataArrays[0] isKindOfClass:[YFAdFusionBannerView class]]) {
                [self.dataArrays insertObject:adView atIndex:startCount+0];
            } else if (![self.dataArrays[2] isKindOfClass:[YFAdFusionBannerView class]]) {
                [self.dataArrays insertObject:adView atIndex:startCount+2];
            } else if (![self.dataArrays[4] isKindOfClass:[YFAdFusionBannerView class]]) {
                [self.dataArrays insertObject:adView atIndex:startCount+4];
            } else {
                [self.dataArrays addObject:adView];
            }
        }
        [self.tableView.mj_footer endRefreshing];
    }else{
        self.dataArrays = [NSMutableArray arrayWithArray:[CellBuilder dataFromJsonFile:@"cell01"]];

        if (self.dataArrays.count > 5) {
            if (![self.dataArrays[0] isKindOfClass:[YFAdFusionBannerView class]]) {
                [self.dataArrays insertObject:adView atIndex:0];
            } else if (![self.dataArrays[2] isKindOfClass:[YFAdFusionBannerView class]]) {
                [self.dataArrays insertObject:adView atIndex:2];
            } else if (![self.dataArrays[4] isKindOfClass:[YFAdFusionBannerView class]]) {
                [self.dataArrays insertObject:adView atIndex:4];
            } else {
                [self.dataArrays addObject:adView];
            }
        }
        [self.tableView.mj_header endRefreshing];
    }
    self.view.userInteractionEnabled = YES;
    [self.tableView reloadData];
}

/// 广告渲染失败
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdRenderFail:(YFAdFusionBannerView * _Nullable)adView {
    AlertIfNotMainThread
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染失败", __func__]];
    self.view.userInteractionEnabled = YES;
    [self.tableView.mj_header endRefreshing];
    [self.tableView.mj_footer endRefreshing];
}

/// 广告被关闭
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdClosed:(YFAdFusionBannerView * _Nullable)adView {
    AlertIfNotMainThread
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭了", __func__]];
    if (_isListMode) {
        NSInteger index = [self.dataArrays indexOfObject:adView];
        [self.dataArrays removeObject: adView];
        [self.tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:[NSIndexPath indexPathForRow:index inSection:0]] withRowAnimation:UITableViewRowAnimationFade];
    } else {
        /// 广告关闭移除广告视图
        [adView removeFromSuperview];
        [self.container removeFromSuperview];
    }
    /// 可在此处理 fusionBanner 与其关联的广告视图，当全部广告关闭时，可释放fusionBanner加载器
    /// ...............
}

#pragma mark - private method

/// 边距变化
- (void)sliderEndChangeValue:(id)va {
    self.marginLabel.text = [NSString stringWithFormat:@"边距：%d", (int)[self calMargin]];
}

/// 当前边距
- (CGFloat)calMargin {
    return (self.slider.value * 60);
}

- (void)popVC {
    [self dismissViewControllerAnimated:YES completion:nil];
}

/// 展示日志
- (void)showLogView {
    [UIView animateWithDuration:0.2 animations:^{
        self.textV.frame = CGRectMake(0,((self->_isShowLogView = !self->_isShowLogView) ? kAppTopH : -600 ), self.view.frame.size.width, 600);
        self.navigationItem.rightBarButtonItem.title = self->_isShowLogView ? @"隐藏日志":@"显示日志";
    }];
}

/// 切换为列表场景
- (void)changeListMode {
    [self.container removeFromSuperview];
    self.container = nil;
    [self.view addSubview:self.tableView];
    _isListMode = YES;
    [JDStatusBarNotification showWithStatus:@"已切换为列表场景" dismissAfter:1.5];
}

/// 切换为固定视图场景
- (void)changeViewMode {
    [self.tableView removeFromSuperview];
    [self.container addSubview:self.contentV];
    [self.view addSubview:self.container];
    _isListMode = NO;
    [JDStatusBarNotification showWithStatus:@"已切换为固定视图场景" dismissAfter:1.5];
}


@end
