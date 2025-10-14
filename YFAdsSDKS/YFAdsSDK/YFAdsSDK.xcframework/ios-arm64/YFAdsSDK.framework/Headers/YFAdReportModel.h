//
//  YFAdParameterModel.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>

#import <YFAdsSDK/NSObject+YFAdModel.h>
@class YFAdReportModel;
@class YFAdEventModel;
//1-应用打开；2-请求(聚合向广告网络发送请求)；3-填充(聚合向广告网络发送请求)；4-展示(聚合向广告网络发送请求)；5-点击(聚合统计的广告)；6-流量请求(应用向聚合发送请求)；7-流量填充(应用向聚合发送请求)|
//2. 初始化SDK（app初始化SDK时候上报该事件）
//3. 请求（聚合SDK向ADN发送请求时上报该事件）
//4. 填充（发送请求有填充时上报该事件）
//5. 展示（展示广告时上报该事件）
//6. 点击（当用户点击广告时，上报该事件）
//7. 流量请求（APP向聚合SDK发送请求时，上报该事件）
//8. 流量填充（当聚合SDK有填充时，完成比价后上报该事件。注意：需要填写选取填充的耗时，在比价之后show之前上报该事件）

typedef NS_ENUM(NSUInteger, YFAdSDKReportEventType) {
    
    YFAdSDKReportEventTypeNone = 0,
    /// 应用打开
    YFAdSDKReportEventTypeOpen = 1,
    /// 聚合向广告网络发送请求
    YFAdSDKReportEventTypeRequest = 2,
    /// 填充
    YFAdSDKReportEventTypeFill = 3,
    /// 联盟曝光展示
    YFAdSDKReportEventTypeShow = 4,
    /// 点击
    YFAdSDKReportEventTypeClicked = 5,
    /// 流量请求
    YFAdSDKReportEventTypeFlowRequest = 6,
    /// 流量填充
    YFAdSDKReportEventTypeFlowFill = 7,
    /// 资源就位
    YFAdSDKReportEventTypeReady = 8,
    /// 失败
    YFAdSDKReportEventTypeFail = 9,
    /// 自动点击
    YFAdSDKReportEventTypeAuto = 10,
    /// 发放激励
    YFAdSDKReportEventTypeReward = 11,
    /// ECPM过滤成功
    YFAdSDKReportEventTypeECPMFilterSuccess = 12,
    /// ECPM过滤失败
    YFAdSDKReportEventTypeECPMFilterFail = 13,
    /// crash
    YFAdSDKReportEventTypeCrashUpload = 14,
    
    /// 模版关闭按钮广告
    YFAdSDKReportEventTypeCloseBTNAd = 15,
    /// 关闭广告
    YFAdSDKReportEventTypeCloseAd = 16,
    /// 媒体调用展示当前已填充广告的最优层接口，无需等待亿帆SDK执行完成整体逻辑
    YFAdSDKReportEventTypeForceReturn = 17,
    /// 媒体调用展示当前已填充广告的最优层接口，请求失败
    YFAdSDKReportEventTypeForceReturnFail = 19,
    /// 插屏轮播
    YFAdSDKReportEventTypeInterstitalCarousel = 20,
    /// 有填充但是ECPM过低被过滤
    YFAdSDKReportEventTypeLowECPMFill = 33,
    /// 填充失败
    YFAdSDKReportEventTypeFillFail = 109,
    /// 自渲染SDK展示 亿帆统计
    YFAdSDKReportEventTypeCustomSDKShow = 100,
    /// 亿帆监测的展示，以自渲染广告在手机屏幕中展示50%面积为准，同一个广告重复展示的情况只上报第一次展示
    YFAdSDKReportEventTypeExposure = 101,
    /// 实时初始化
    YFAdSDKReportEventTypeRealTimeInit = 112,
    /// 实时流量请求
    YFAdSDKReportEventTypeRealTimeAdRequest = 116,
    /// 实时流量填充
    YFAdSDKReportEventTypeRealTimeAdFill = 117,
    /// 实时展示
    YFAdSDKReportEventTypeRealTimeAdShow = 114,
    /// 实时点击
    YFAdSDKReportEventTypeRealTimeAdClick = 115,
    /// 实时填充上报
    YFAdSDKReportEventTypeRealTimeAdFillFail = 119,
    /// app 配置同步
    YFAdSDKReportEventTypeAppRquestStart = 10001,
    YFAdSDKReportEventTypeAppRquestSuccess = 10002,
    YFAdSDKReportEventTypeAppRquestFail = 10003,
    
    /// adn sdk  初始化
    YFAdSDKReportEventTypeAdnInitStart = 10101,
    YFAdSDKReportEventTypeAdnInitSuccess = 10102,
    YFAdSDKReportEventTypeAdnInitFail = 10103,
    
    /// 媒体调用load接口
    YFAdSDKReportEventTypeAdsLoadStart = 10601,
    
    /// ads  配置同步
    YFAdSDKReportEventTypeAdsRquestStart = 10201,
    YFAdSDKReportEventTypeAdsRquestSuccess = 10202,
    YFAdSDKReportEventTypeAdsRquestFail = 10203,
    /// 使用配置缓存
    YFAdSDKReportEventTypeAdsUseConfCache = 10204,
    
    
    /// 开始获取广告缓存
    YFAdSDKReportEventTypeAdsReadConfCache = 10301,
    /// 获取广告缓存成功
    YFAdSDKReportEventTypeAdsReadConfCacheSuccess = 10302,
    /// 广告缓存为空
    YFAdSDKReportEventTypeAdsReadConfCacheFail = 10303,
    /// 广告缓存未启用
    YFAdSDKReportEventTypeAdsNoUseConfCache = 10304,
    
    /// 开始缓存ecpm截断
    YFAdSDKReportEventTypeCacheCutOffStart = 10401,
    /// 获取广告缓存成功
    YFAdSDKReportEventTypeCacheCutOffEnd = 10402,
    
    
    /// adn sdk  初始化
    YFAdSDKReportEventTypeAdnRevealInitStart = 10501,
    YFAdSDKReportEventTypeAdnRevealInitSuccess = 10502,
    YFAdSDKReportEventTypeAdnRevealInitFail = 10503,

    /// 缓存
    YFAdSDKReportEventTypeCacheStart = 10801,
    YFAdSDKReportEventTypeCacheSuccess = 10802,
    YFAdSDKReportEventTypeCacheFail = 10803,


};

/// 广告商枚举ID 1 穿山甲；2 优量汇；3 百度; 4快手;  5 亿帆;  9 京东; 11 gromore 12 adx;  14 Tanx; 15 AY
typedef NS_ENUM(NSUInteger, YFAdnType) {
    YFAdnTypeUnknow,
    YFAdnTypeCSJ       = 1,
    YFAdnTypeGDT       = 2,
    YFAdnTypeBD        = 3,
    YFAdnTypeKS        = 4,
//    YFAdnTypeYF        = 5,
    YFAdnTypeJD        = 9,
    YFAdnTypeGM        = 11,
    YFAdnTypeADX       = 12,
    YFAdnTypeTX        = 14,
    YFAdnTypeAY        = 15,
};
NS_ASSUME_NONNULL_BEGIN

@interface YFAdReportModel : NSObject
/// 应用ID
@property (nonatomic, copy) NSString *appID;
/// 应用版本
@property (nonatomic, copy) NSString *appVer;
/// 激活时间
@property (nonatomic, assign) NSInteger at;
/// 应用buldle名称
@property (nonatomic, copy) NSString *buldle;
/// 设备ID
@property (nonatomic, copy) NSString *devID;
/// 设备类型，0表示安卓，1表示IPhone
@property (nonatomic, assign) NSInteger devType;
/// 事件
@property (nonatomic, copy) NSArray<YFAdEventModel *> *events;
/// idfa状态  是 1  否 0
@property (nonatomic, assign) NSInteger idfa;
/// sdk版本
@property (nonatomic, copy) NSString *sdkVer;
/// idfa
@property (nonatomic, copy) NSString * ia;
/// 品牌
@property (nonatomic, copy) NSString * db;
/// 设备型号
@property (nonatomic, assign) NSString * dm;
/// 拓展字段
@property (nonatomic, retain) NSDictionary *ex;
/// 拓展字段2
@property (nonatomic, retain) NSDictionary *ud;
@end

@interface YFAdEventModel : NSObject<NSCopying>

/// 广告位ID
@property (nonatomic, copy) NSString *adID;
/// 广告商广告位ID
@property (nonatomic, copy) NSString *adnAdID;
/// 广告商appID
@property (nonatomic, copy) NSString *adnAppID;
/// 广告商appID
@property (nonatomic, copy) NSString *adnAppKey;
/// 广告商枚举ID 1 穿山甲；2 优量汇；3 百度; 4快手;  5 亿帆;  9 京东; 11 gromore 12 adx;  14 Tanx;
@property (nonatomic, assign) YFAdnType adnID;
/// 广告商名称
@property (nonatomic, copy) NSString *adnName;
/// 广告类型
/// 1 开屏广告;2 信息流广告;3 插屏广告;4 banner横幅广告;5 draw视频信息流广告;6 全屏视频广告;7 激励视频广告
@property (nonatomic, assign) NSInteger aType;
/// 广告位类型
/// 1 开屏广告;2 信息流广告;3 插屏广告;4 banner横幅广告;5 draw视频信息流广告;6 全屏视频广告;7 激励视频广告 10顶推广告
@property (nonatomic, assign) NSInteger pt;
/// 底价
@property (nonatomic, assign) NSInteger ecpm;
/// 事件ID
@property (nonatomic, copy) NSString *eID;
//1-应用打开；2-请求(聚合向广告网络发送请求)；3-填充(聚合向广告网络发送请求)；4-展示(聚合向广告网络发送请求)；5-点击(聚合统计的广告)；6-流量请求(应用向聚合发送请求)；7-流量填充(应用向聚合发送请求)|
/// 事件类型
@property (nonatomic, assign)YFAdSDKReportEventType eType;
///
@property (nonatomic, copy) NSString * abID;
/// group ID
@property (nonatomic, copy) NSString *gID;
/// 是否bidding
@property (nonatomic, assign) NSInteger isBid;
/// layer ID
@property (nonatomic, copy) NSString *lID;
/// section ID
@property (nonatomic, copy) NSString *sID;
/// 事件触发时间
@property (nonatomic, assign) NSInteger t;
/// 总瀑布流耗时
@property (nonatomic, assign) double tCost;
/// 流量请求时间
@property (nonatomic, assign) double frt;
/// 流量填充时间
@property (nonatomic, assign) double fft;
/// 单层请求时间
@property (nonatomic, assign) double st;
/// 单层填充时间
@property (nonatomic, assign) double et;
/// 激活时间
@property (nonatomic, assign) double at;

/// 进入后台开始时间
@property (nonatomic, assign) double bst;
/// 进入后台结束时间
@property (nonatomic, assign) double bet;

/// 超时时间
@property (nonatomic, assign) NSInteger timeout;
/// 标识
@property (nonatomic, assign) NSInteger index;
/// 展示模版 自渲染可用
@property (nonatomic, copy) NSString * tpid;
/// 请求ID
@property (nonatomic, copy) NSString * rID;
/// 模版ID  2自渲染banner、3信息流
@property (nonatomic, assign) NSInteger renderID;

@property (nonatomic, copy) NSString *sdkVer;


/// skipBtnStyle 跳过按钮样式
/*
1：联盟默认按钮
2：亿帆胶囊按钮
 */
@property (nonatomic, assign) NSInteger sbs;

/// 关闭按钮尺寸
/*
 1、最小
 2、小
 3、标准
 4、大
 5、最大
 */
@property (nonatomic, assign) NSInteger cbs;
/// 点击热区   1: 全屏可点   2: 仅按钮 3: 文案区域可点 4: 75%可点   5: 50%可点   6: 25%可点
@property (nonatomic, assign) NSInteger cha;
/// 返回物料数量
@property (nonatomic, assign) NSInteger rmc;
/// 视频静音  1静音 0否
@property (nonatomic, assign) NSInteger vm;
/// 跳转后关闭广告 1关闭广告  0是不关闭
@property (nonatomic, assign) NSInteger jc;
/// 模板尺寸
@property (nonatomic, assign) NSInteger ts;
/// 关闭按钮位置。根据布局需求实现其中几种，剩余的默认即可
//1: 左上角
//2: 右上角
//3: 底部
//4: 素材左上角
//5: 素材右上角
//6: 左下角
//7: 右下角
//8：中上
//9：中下
@property (nonatomic, assign) NSInteger cbp;

/// 按钮样式  1：常规样式  2：通底大面积样式
@property (nonatomic, assign) NSInteger bs;
/// 关闭按钮出现时间
@property (nonatomic, assign) NSInteger cbst;
/// 物理键返回(安卓)
@property (nonatomic, assign) NSInteger pkb;
// 互动样式
/*
 0: 无互动按钮
 1: 点击跳转(手指)
 2: 摇一摇
 3: 点击+摇一摇
 4: 扭一扭
 5: 点击+扭一扭
 6: 滑动跳转
 7: 点击跳转(无手指)
 8：点击+滑动
 9：点击(有手指)
 */
@property (nonatomic, assign) NSInteger is;

/// 仅摇一次 0： 否 ，1： 是
@property (nonatomic, assign) NSInteger tc;

///  重设交互为点击
@property (nonatomic) BOOL resetIsToClick;
/// 是否 自动跳转 0关闭 1是开启
@property (nonatomic, assign) NSInteger ac;
/// 平台错误码。上报一次事件后，会被置空，下次需要重新设置
@property (nonatomic, copy) NSString *cd;

/// 1;单向跳转
/// 2: 双向跳转
@property (nonatomic, assign) NSInteger isd;

//新增字段istvp 描述 0~100
//1 = 100%
@property (nonatomic, assign) float istvp;

/// 设备型号
@property (nonatomic, assign) NSString * dm;

/// 设备类型
@property (nonatomic, assign) NSInteger dt;

/// 额外信息。上报一次事件后，会被置空，下次需要重新设置
@property (nonatomic, nullable ,copy) NSString *msg;

/// 融合Banner广告源比例尺寸，值：宽*高
@property (nonatomic, copy) NSString *ss;
/// 1 hidden
@property (nonatomic, assign) BOOL haal;
/// 快手滑动跳转
@property (nonatomic, assign) BOOL sj;
// 落地页兜底唤起
@property (nonatomic, assign) BOOL lpaa;
/// 文案替换开关
@property (nonatomic, assign) BOOL rcs;
@property (nonatomic, copy) NSString *rt;
@property (nonatomic, copy) NSString *rc;

@property (nonatomic, assign) NSInteger bannerCarouselInterval;
// 倒计时结束自动关闭 1：是 0：否
@property (nonatomic, assign) NSInteger oac;
// 倒计时时间 插屏自渲染 5-30秒，开屏 3-5秒
@property (nonatomic, assign) NSInteger oat;

// 展示点击按钮 1：展示 0：不展示
@property (nonatomic, assign) NSInteger sb;

// open sdk appid
@property (nonatomic, copy) NSString *wxAppID;

@property (nonatomic, copy) NSString *universalLink;

@property (nonatomic, assign) BOOL isValid;
// 展示开始时间
@property (nonatomic, assign) double cst;
// 展示结束时间
@property (nonatomic, assign) double cet;
// 动画效果:[ae](0:无动画; 1:上下浮动*3;)
@property (nonatomic, assign) NSInteger ae;
// 启用倒计时关闭  0:否 1:是
@property (nonatomic, assign) NSInteger ecbc;
// 关闭按钮延迟生效 ms
@property (nonatomic, assign) NSInteger cbde;
// 亿帆关闭按钮[新增]:cbm(0不使用，1倒计时关闭，2手动关闭)
@property (nonatomic, assign) NSInteger cbm;
// 缓存
@property (nonatomic, assign) NSInteger cacheTimeout;
/// 激励视频点击5s样式是否开启 0关闭 1开启
@property (nonatomic, assign) NSInteger cte;
///
@property (nonatomic, strong) NSArray<NSString *> *wURL;
/// 同一次请求使用相同ua
@property(nonatomic, copy) NSString *ua;
///是否已经记录过本地请求限制，主要用于过滤信息流等存在多次曝光的广告
@property (nonatomic) BOOL reqLimitRecorded;
@end
NS_ASSUME_NONNULL_END
