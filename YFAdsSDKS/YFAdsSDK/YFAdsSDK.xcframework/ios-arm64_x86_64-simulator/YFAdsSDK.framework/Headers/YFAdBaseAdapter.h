//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdResponseModel.h>
#import <YFAdsSDK/YFAdReportModel.h>
#import <YFAdsSDK/YFAdSupplierManager.h>
NS_ASSUME_NONNULL_BEGIN

/// 适配器基类
@interface YFAdBaseAdapter : NSObject

/// 各渠道错误的详细原因
@property (nonatomic, strong) NSMutableDictionary * errorDescriptions;
/// 是否填充
@property(nonatomic, assign) BOOL fill;

@property(nonatomic, assign) NSUInteger ecpm;
///  广告是否有效
@property (nonatomic, assign) BOOL isValid;
/// 激励视频是否下载完成
@property (nonatomic, assign) BOOL isReady;
/// 自定义唯一标识
@property (nonatomic, assign) NSInteger tag;
///  联盟 ID
@property (nonatomic, assign) NSInteger adnID;

@property (nonatomic, strong) YFAdSupplierManager *mgr;
/// 控制器(在一次广告周期中 不可更改, 不然会引起未知错误)
@property(nonatomic, weak) UIViewController *viewController;
/// 初始化广告位ID
- (instancetype)initWithAdUnitID:(NSString *)pID;
/// 加载广告
- (void)loadAd;
/// 展示广告
- (void)showAd;

-(void)recordLimitCount;
/// 加载并展现
- (void)loadAndShowAd;
/// 移除广告 (banner ，信息流可用)
- (void)removeAd;

/// 移除广告 (自渲染插屏)
- (void)removeCustomRenderAd;
/// 上报
- (void)reportWithType:(YFAdSDKReportEventType)repoType supplier:(id)supplier error:(nullable NSError *)error;
///  搜集错误
- (void)collectErrorWithSupplier:(YFAdEventModel *)supplier error:(NSError *)error;
/// 取消当前策略请求
- (void)deallocAdapter;
/// 设置根控制器
- (void)setRootController:(UIViewController *)rootController;
/// 重新设置delegate
- (void)setNewDelegate:(id)delegate;


@end

NS_ASSUME_NONNULL_END
