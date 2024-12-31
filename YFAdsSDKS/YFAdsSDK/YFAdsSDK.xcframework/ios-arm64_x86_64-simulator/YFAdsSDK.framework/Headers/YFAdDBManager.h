//
//  YFAdDataCenterManager.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class YFAdEventModel;
// 数据中心 增删改查
@interface YFAdDBManager : NSObject

+ (instancetype)shareInstance;
/// 开屏缓存
@property(nonatomic,retain)NSMutableArray * launchs;
/// banner缓存
@property(nonatomic,retain)NSMutableArray * banners;
/// 插屏缓存
@property(nonatomic,retain)NSMutableArray * interstitials;
/// 激励视频缓存
@property(nonatomic,retain)NSMutableArray * rewardvideo;
/// 信息流缓存
@property(nonatomic,retain)NSMutableArray * express;
/// 全屏视频缓存
@property(nonatomic,retain)NSMutableArray * fullvideo;
/// drawvideo
@property(nonatomic,retain)NSMutableArray * drawvideo;



/// 清除缓存
- (void)clearCache;
/// 创建表
- (void)createTable:(NSString *)tableName;
/// 添加上报信息
- (void)addReportWithModel:(YFAdEventModel *)orgModel;

- (NSMutableArray *)searchAllResultWithName:(NSString *)tableName;

- (NSMutableArray *)searchResultWithName:(NSString *)tableName limit:(NSInteger)limit;

- (void)deleteAllWithName:(NSString *)tableName;

- (void)deleteWithName:(NSString *)tableName eid:(NSString *)eid complate:(void(^)(BOOL))complate;

@end

NS_ASSUME_NONNULL_END
