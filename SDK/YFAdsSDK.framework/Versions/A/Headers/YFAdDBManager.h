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

/// 清除缓存
- (void)clearCache;

/// 创建表
- (void)createTable:(NSString *)tableName;
/// 添加上报信息
- (void)addReportWithName:(NSString *)tableName
                     adID:(NSString *)adID
              adnAdID:(NSString *)adnAdID
             adnAppID:(NSString *)adnAppID
                adnID:(NSInteger)adnID
                aType:(NSInteger)aType
                 ecpm:(NSInteger)ecpm
                  eID:(NSString *)eID
                eType:(NSString *)eType
                  gID:(NSString *)gID
                isBid:(NSString *)isBid
                  lID:(NSString *)lID
                  sID:(NSString *)sID
                    t:(NSString *)t
                    tCost:(NSString *)tCost;


/// 添加上报信息
- (void)addReportWithModel:(YFAdEventModel *)model;

- (NSMutableArray *)searchAllResultWithName:(NSString *)tableName;

- (void)deleteAllWithName:(NSString *)tableName;

- (void)deleteWithName:(NSString *)tableName eid:(NSString *)eid;

@end

NS_ASSUME_NONNULL_END
