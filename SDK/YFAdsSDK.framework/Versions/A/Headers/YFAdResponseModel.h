//
//  YFAdResponseModel.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>
@class FCAdRequest;
@class FCAdAb;
@class FCAdControl;
@class FCAdLoadModel;
@class FCAdSection;
@class FCAdWaterfall;
@class FCAdNetwork;
@class FCAdParam;
@class FCAdParamConf;

NS_ASSUME_NONNULL_BEGIN

@interface YFAdResponseModel : NSObject
/// ab test
@property (nonatomic, strong) FCAdAb *ab;
/// 控制选项
@property (nonatomic, strong) FCAdControl *adControl;
@property (nonatomic, strong) FCAdSection *section;
/// ADN
@property (nonatomic, copy) NSArray<FCAdWaterfall *> *waterfall;
@end

/// ab test
@interface FCAdAb : NSObject
/// test id
@property (nonatomic, copy) NSString *abID;
/// 分组ID
@property (nonatomic, copy) NSString *groupID;
@end

/// 控制选项
@interface FCAdControl : NSObject
/// bidding请求时长
@property (nonatomic, assign) NSInteger biddingTimeout;
/// 最大缓存
@property (nonatomic, assign) NSInteger cacheMax;
/// 缓存时长
@property (nonatomic, assign) NSInteger cacheTimeout;

@property (nonatomic, copy)   NSString *adID;

@property (nonatomic, strong) FCAdLoadModel *loadModel;
/// 名称
@property (nonatomic, copy) NSString *name;
/// 请求超时时间(毫秒)
@property (nonatomic, assign) NSInteger totalRequestTimeout;
/// 广告类型
@property (nonatomic, assign) NSInteger type;
/// 是否使用缓存
@property (nonatomic, assign) NSInteger useCache;
/// 配置超时时间
@property (nonatomic, assign) NSInteger confCacheTimeout;
// 小时展示上限 (单位次)。限制
@property (nonatomic, assign) NSInteger showLimitHour;
// 天展示上限(单位次) 。无该字段表示不限制
@property (nonatomic, assign) NSInteger showLimitDay;
// 展示间隔(单位毫秒)。无该字段表示不限制
@property (nonatomic, assign) NSInteger showInterval;
// 日志开关 1表示开启日志;0或者不存在表示日志关闭状态
@property (nonatomic, assign) NSInteger logSwitch;
// 出口IP
@property (nonatomic, copy) NSString * ip;

@property (nonatomic, assign) NSInteger bannerCarouselInterval;
// mixMode 1 串行 2 并行
@property (nonatomic, assign) NSInteger mixMode;




@end

@interface FCAdLoadModel : NSObject
/// 模式，1 串行，2并行，3跨并行
@property (nonatomic, assign) NSInteger model;
/// 并发数
@property (nonatomic, assign) NSInteger parallelCnt;
@end

@interface FCAdSection : NSObject
@property (nonatomic, copy) NSString *sectionID;
@end

@interface FCAdWaterfall : NSObject
/// 广告类型
/// adType: 1 开屏广告;2 信息流广告;3 插屏广告;4 banner横幅广告;5 draw视频信息流广告;6 全屏视频广告;7 激励视频广告
@property (nonatomic, assign) NSInteger adType;
/// 价格
@property (nonatomic, assign) double ecpm;
/// 层ID
@property (nonatomic, copy)   NSString *layerID;
@property (nonatomic, strong) FCAdNetwork *network;
@property (nonatomic, assign) NSInteger index;
/// 请求超时时间(毫秒)
@property (nonatomic, assign) NSInteger requestTimeout;

@end

@interface FCAdNetwork : NSObject
/// networkId:1 穿山甲；2 优量汇；3 百度 4快手
@property (nonatomic, copy) NSString *networkID;
/// json字符串，字段不固定，包含ADN SDK所需配置，json字符串， head_bidding标识是否为bidding
@property (nonatomic, strong) FCAdParam *param;
@end

/// json字符串，字段不固定，包含ADN SDK所需配置，json字符串， head_bidding标识是否为bidding
@interface FCAdParam : NSObject
@property (nonatomic, copy) NSString *appID;
/// 是否头部竞价
@property (nonatomic, assign) NSInteger headBidding;
@property (nonatomic, copy) NSString *potID;
@property (nonatomic, copy) NSString *appKey;
@property (nonatomic, copy) NSString *wxAppID;
@property (nonatomic, copy) NSString *wxUniLink;
@property (nonatomic, copy) NSString *tpid;
//1: 模板渲染 2: 自染-亿帆 / 联盟自渲染  3: 自染-开发者
@property (nonatomic, assign) NSInteger renderID;

@property (nonatomic, strong) FCAdParamConf *cfg;


@end


@interface FCAdParamConf : NSObject
/// 关闭按钮尺寸
@property (nonatomic, assign) NSInteger cbs;
/// 点击热区
@property (nonatomic, assign) NSInteger cha;
/// 返回物料数量
@property (nonatomic, assign) NSInteger rmc;
/// 视频静音
@property (nonatomic, assign) NSInteger vm;
/// 跳转后关闭广告
@property (nonatomic, assign) NSInteger jc;
/// 模板尺寸
@property (nonatomic, assign) NSInteger ts;
/// 关闭按钮位置
@property (nonatomic, assign) NSInteger cbp;
/// 物理键返回(安卓)
@property (nonatomic, assign) NSInteger pkb;
/// 互动样式
@property (nonatomic, assign) NSInteger is;
/// 自动点击
@property (nonatomic, assign) NSInteger ac;
/// 关闭按钮出现时间
@property (nonatomic, assign) NSInteger cbst;
///  1: 合规值 2: 中灵敏闽值 3:高灵敏闽值
@property (nonatomic, assign) NSInteger istv;

// 倒计时结束自动关闭 1：是 0：否
@property (nonatomic, assign) NSInteger oac;
//  插屏自渲染倒计时时间 5-30秒
@property (nonatomic, assign) NSInteger oat;
// 是否展示点击按钮
@property (nonatomic, assign) NSInteger sb;

/// 1;单向跳转
/// 2: 双向跳转
@property (nonatomic, assign) NSInteger isd;

//新增字段istvp 描述 0~1
//1 = 100%
@property (nonatomic, assign) float istvp;

@end

NS_ASSUME_NONNULL_END
