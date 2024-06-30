//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YFAdResponseModel.h"
#import "YFAdReportModel.h"
#import "YFAdSupplierManager.h"
NS_ASSUME_NONNULL_BEGIN

@interface YFAdBaseAdapter : NSObject

/// 各渠道错误的详细原因
@property (nonatomic, strong) NSMutableDictionary * errorDescriptions;
/// 是否填充
@property(nonatomic, assign) BOOL fill;

@property(nonatomic, assign) NSUInteger ecpm;
/// 激励视频是否下载完成
@property (nonatomic, assign) BOOL isReady;



@property (nonatomic, strong) YFAdSupplierManager *mgr;
/// 控制器(在一次广告周期中 不可更改, 不然会引起未知错误)
@property(nonatomic, weak) UIViewController *viewController;
/// 初始化广告位ID
- (instancetype)initWithAdUnitID:(NSString *)pID;
/// 加载广告
- (void)loadAd;
/// 展示广告
- (void)showAd;
/// 加载并展现
- (void)loadAndShowAd;
/// 移除广告 (banner ，信息流可用)
- (void)removeAd;
/// 上报
- (void)reportWithType:(YFAdSDKReportEventType)repoType supplier:(id)supplier error:(nullable NSError *)error;
///  搜集错误
- (void)collectErrorWithSupplier:(YFAdEventModel *)supplier error:(NSError *)error;
/// 取消当前策略请求
- (void)deallocAdapter;
/// 设置根控制器
- (void)setRootController:(UIViewController *)rootController;


@end

NS_ASSUME_NONNULL_END
