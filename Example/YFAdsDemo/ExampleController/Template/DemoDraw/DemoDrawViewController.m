//
//  DemoDrawViewController.m
//  Example
//
//  Created by CherryKing on 2019/11/21.
//  Copyright © 2019 CherryKing. All rights reserved.
//

#import "DemoDrawViewController.h"
#import "BYExamCellModel.h"
#import "YFEnvironmentManager.h"
#import <YFAdsSDK/YFKit.h>
#import <YFAdsSDK/YFAdDraw.h>
#import <YFAdsSDK/YFAdDrawView.h>
#import "AdDataJsonManager.h"
#import "DemoDrawChangeViewController.h"
#import "DemoDrawNormalCell.h"
#import "DemoDrawAdCell.h"


@interface DemoDrawViewController () <UITableViewDelegate, UITableViewDataSource, YFAdDrawDelegate>
{
    BOOL _isLoadAndShow;
    BOOL _isShowLogView;
    CGFloat _navAndStateBarHeight;
    
}
@property (strong, nonatomic) UITableView *tableView;

@property (nonatomic, strong) NSMutableArray *dataArr;
@property (nonatomic, strong) NSMutableArray *adViews;
@property (nonatomic, assign) BOOL isLoadAndShow;
@property (nonatomic, assign) BOOL isShowLogView;
@property (nonatomic, strong) UIButton *closeBtn;
@property (nonatomic, strong) YFAdDraw *advanceDraw;

@end

@implementation DemoDrawViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"Draw流";
    
    CGFloat statusHeight = [[UIApplication sharedApplication] statusBarFrame].size.height;
    CGFloat navHeight = self.navigationController.navigationBar.frame.size.height;
//    self.navigationController.navigationBar.hidden = YES;
    
    _navAndStateBarHeight = navHeight + statusHeight;
    
    self.textV.frame = CGRectMake(0,0 - 300, self.view.frame.size.width, 300);
    self.dic = [[AdDataJsonManager shared] loadAdDataWithType:JsonDataType_nativeExpress];
    
    UIBarButtonItem *rightBar = [[UIBarButtonItem alloc] initWithTitle:@"显示日志" style:UIBarButtonItemStylePlain target:self action:@selector(showLogView)];
    self.navigationItem.rightBarButtonItem = rightBar;
    
    self.edgesForExtendedLayout = UIRectEdgeTop;
    if (@available(iOS 11.0, *)) {
        self.tableView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
    }

//    UIBarButtonItem *rightBar = [[UIBar
    
    [self.view addSubview:self.tableView];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.left.right.bottom.equalTo(@0);
    }];
    
    
    UIButton *closeBtn = [[UIButton alloc]initWithFrame:CGRectMake(22, _navAndStateBarHeight + 20, 120, 22)];
    self.closeBtn = closeBtn;
    [closeBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [closeBtn addTarget:self action:@selector(closeTable) forControlEvents:UIControlEventTouchUpInside];
    [closeBtn setTitle:@"关闭Draw流" forState:UIControlStateNormal];
    closeBtn.titleLabel.font = [UIFont systemFontOfSize:20];
    closeBtn.hidden = YES;
    [self.view addSubview:closeBtn];
    
}

- (void)closeTable{
    [self deallocAd];
}

-(void)viewDidDisappear:(BOOL)animated{
    [super viewDidDisappear:animated];
    
}

- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    
    _isLoadAndShow = NO;
    
    for (NSInteger i =0 ; i <= 5; i++) {
        [self.dataArr addObject:@"App NormalCell"];
    }
        
    self.advanceDraw = [[YFAdDraw alloc] initWithAdUnitID:[YFEnvironmentManager getDRAW_ID] viewController:self adSize:CGSizeMake(self.view.bounds.size.width, self.view.bounds.size.width * 400.0 /600.0)];
    self.advanceDraw.count = 1;
    self.advanceDraw.delegate = self;
    [self.advanceDraw loadAndShowAd];
    [self loadAdWithState:AdState_Loading];

}

- (void)showAd {
    if ( self.dataArr.count == 0 || self.adViews.count == 0) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    [self showNativeAd];
}

-(void)changeVC {
    
    if (self.adViews.count == 0) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    
    DemoDrawChangeViewController * pvc = [[DemoDrawChangeViewController alloc] init];
    pvc.adapter = self.advanceDraw;
    pvc.adViews = [self.adViews copy];
    [self.navigationController pushViewController:pvc animated:YES];
    
}

- (void)loadAndShowAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    
    _isLoadAndShow = YES;

    for (NSInteger i =0 ; i <= 5; i++) {
        [self.dataArr addObject:@"App NormalCell"];
    }
    
    self.advanceDraw = [[YFAdDraw alloc] initWithAdUnitID:[YFEnvironmentManager getDRAW_ID] viewController:self adSize:CGSizeMake([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)];
    self.advanceDraw.delegate = self;
    self.advanceDraw.count = 1;
    [self.advanceDraw loadAndShowAd];
    [self loadAdWithState:AdState_Loading];
  
}

- (void)deallocAd {
    if (self.tableView.hidden) {
        return;
    }
//    [self.dataArr removeAllObjects];
////    [self.adViews removeAllObjects];
//    self.advanceDraw.delegate = nil;
//    self.advanceDraw = nil;
//    [self.tableView reloadData];
//    [self loadAdWithState:AdState_Normal];
    self.tableView.hidden = YES;
    self.closeBtn.hidden = YES;
}

// Draw流广告比较特殊, 渲染逻辑需要自行处理
- (void)showNativeAd {
    
    [self.adViews enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        YFAdDrawView *expressView = (YFAdDrawView *)obj;
        NSUInteger index = arc4random() % (self.dataArr.count-3)+2;
        [self.dataArr insertObject:expressView atIndex:index];
    }];
    self.tableView.hidden = NO;
    self.closeBtn.hidden = NO;
    [self.tableView reloadData];
}


- (void)showLogView {
    [UIView animateWithDuration:0.2 animations:^{
        self.textV.frame = CGRectMake(0,((self->_isShowLogView = !self->_isShowLogView) ? self->_navAndStateBarHeight : -300 ), self.view.frame.size.width, 300);
        self.navigationItem.rightBarButtonItem.title = self->_isShowLogView ? @"隐藏日志":@"显示日志";
    }];
}

// MARK: ======================= YFAdDrawDelegate =======================

- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    AlertIfNotMainThread
    ///===================

}


- (void)fcAdDrawOnAdLoadSuccess:(NSArray *)views {
    AlertIfNotMainThread
    NSLog(@"广告拉取成功 %s", __func__);
    self.adViews = [views mutableCopy];
    self.isLoaded = YES;
    if (_isLoadAndShow) {
        [self showNativeAd];
    }
//    
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告拉取成功", __func__]];
    [self loadAdWithState:AdState_LoadSucceed];

}


/// 广告曝光
- (void)fcAdDrawOnAdShow:(YFAdDrawView *)adView {
    AlertIfNotMainThread
    NSLog(@"广告曝光 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

/// 广告点击
- (void)fcAdDrawOnAdClicked:(YFAdDrawView *)adView {
    AlertIfNotMainThread
    NSLog(@"广告点击 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击", __func__]];
}

/// 广告渲染成功
/// 注意和广告数据拉取成功的区别  广告数据拉取成功, 但是渲染可能会失败
/// 广告加载失败 是广点通 穿山甲 mercury 在拉取广告的时候就全部失败了
/// 该回调的含义是: 比如: 广点通拉取广告成功了并返回了一组view  但是其中某个view的渲染失败了
/// 该回调会触发多次
- (void)fcAdDrawOnAdRenderSuccess:(YFAdDrawView *)adView {
    AlertIfNotMainThread
    NSLog(@"广告渲染成功 %s %@", __func__, adView);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染成功", __func__]];
}

/// 广告渲染失败
/// 注意和广告加载失败的区别  广告数据拉取成功, 但是渲染可能会失败
/// 广告加载失败 是广点通 穿山甲 mercury 在拉取广告的时候就全部失败了
/// 该回调的含义是: 比如: 广点通拉取广告成功了并返回了一组view  但是其中某个view的渲染失败了
/// 该回调会触发多次
- (void)fcAdDrawOnAdRenderFail:(YFAdDrawView *)adView {
    AlertIfNotMainThread
    NSLog(@"广告渲染失败 %s %@", __func__, adView);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染失败", __func__]];
    [_dataArr removeObject: adView];
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
- (void)fcAdDrawOnAdClosed:(YFAdDrawView *)adView {
    AlertIfNotMainThread
    //需要从tableview中删除
    NSLog(@"广告关闭 %s", __func__);
    [_dataArr removeObject: adView];
    [self.tableView reloadData];
}


// MARK: ======================= UITableViewDelegate, UITableViewDataSource =======================

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
//    return _expressAdViews.count*2;
//    return 2;
    return self.dataArr.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return [DemoDrawNormalCell cellHeight];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSUInteger index = indexPath.row;
    id model = self.dataArr[index];
    if (![model isKindOfClass:[YFAdDrawView class]]) {
        DemoDrawNormalCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass(DemoDrawNormalCell.class)];
        if (!cell) {
            cell = [[DemoDrawNormalCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:NSStringFromClass(DemoDrawNormalCell.class)];
        }

        [cell refreshUIAtIndex:index];
        
        return cell;
    } else {
        DemoDrawAdCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass(DemoDrawAdCell.class)];
        if (!cell) {
            cell = [[DemoDrawAdCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:NSStringFromClass(DemoDrawAdCell.class)];
        }
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        YFAdDrawView *drawAd = _dataArr[index];
        [cell refreshWithDrawAd:drawAd];

        return cell;
    }
}

-(void)dealloc {
    NSLog(@"Draw流释放 %s", __func__);
}


-(NSMutableArray *)dataArr{
    if (!_dataArr) {
        _dataArr = [NSMutableArray array];
    }
    return _dataArr;
}

-(NSMutableArray *)adViews{
    if (!_adViews) {
        _adViews = [NSMutableArray array];
    }
    return _adViews;
}

- (UITableView *)tableView {
    if (_tableView == nil) {
        _tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.pagingEnabled = YES;
        _tableView.showsVerticalScrollIndicator = NO;
        _tableView.allowsSelection = NO;
        _tableView.hidden = YES;
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        if (@available(iOS 15, *)) {
            _tableView.prefetchingEnabled = NO;
        }
    }
    return _tableView;
}

@end


