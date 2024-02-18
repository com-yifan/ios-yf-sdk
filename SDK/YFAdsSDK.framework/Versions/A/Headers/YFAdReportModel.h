//
//  YFAdParameterModel.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>

#import "NSObject+YFAdModel.h"
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
    
    YFAdSDKReportEventTypeNone,
    /// 应用打开
    YFAdSDKReportEventTypeOpen,
    /// 聚合向广告网络发送请求
    YFAdSDKReportEventTypeRequest,
    /// 填充
    YFAdSDKReportEventTypeFill,
    /// 展示
    YFAdSDKReportEventTypeShow,
    /// 点击
    YFAdSDKReportEventTypeClicked,
    /// 流量请求
    YFAdSDKReportEventTypeFlowRequest,
    /// 流量填充
    YFAdSDKReportEventTypeFlowFill,
    /// 资源就位
    YFAdSDKReportEventTypeReady,
    /// 失败
    YFAdSDKReportEventTypeFail,
    /// 自动点击
    YFAdSDKReportEventTypeAuto,
    /// 发放激励
    YFAdSDKReportEventTypeReward,
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


@end

@interface YFAdEventModel : NSObject<NSCopying>

/// 广告位ID
@property (nonatomic, copy) NSString *adID;
/// 广告商广告位ID
@property (nonatomic, copy) NSString *adnAdID;
/// 广告商appID
@property (nonatomic, copy) NSString *adnAppID;
/// 广告商枚举ID
@property (nonatomic, assign) NSInteger adnID;
/// 广告类型
/// 1 开屏广告;2 信息流广告;3 插屏广告;4 banner横幅广告;5 draw视频信息流广告;6 全屏视频广告;7 激励视频广告
@property (nonatomic, assign) NSInteger aType;
/// 广告位类型
/// 1 开屏广告;2 信息流广告;3 插屏广告;4 banner横幅广告;5 draw视频信息流广告;6 全屏视频广告;7 激励视频广告
@property (nonatomic, assign) NSInteger pt;
/// 底价
@property (nonatomic, assign) NSInteger ecpm;
/// 事件ID
@property (nonatomic, copy) NSString *eID;
//1-应用打开；2-请求(聚合向广告网络发送请求)；3-填充(聚合向广告网络发送请求)；4-展示(聚合向广告网络发送请求)；5-点击(聚合统计的广告)；6-流量请求(应用向聚合发送请求)；7-流量填充(应用向聚合发送请求)|
/// 事件类型
@property (nonatomic, assign)YFAdSDKReportEventType eType;

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
/// 超时时间
@property (nonatomic, assign) NSInteger timeout;
/// 标识
@property (nonatomic, assign) NSInteger index;
/// 展示模版 自渲染可用
@property (nonatomic, copy) NSString * tpid;
/// 请求ID
@property (nonatomic, copy) NSString * rID;
/// 模版ID
@property (nonatomic, assign) NSInteger renderID;
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
/// 关闭按钮位置 1左上角 2右上角
@property (nonatomic, assign) NSInteger cbp;
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
 7:点击跳转(无手指)
 8：点击+滑动
 */
@property (nonatomic, assign) NSInteger is;
/// 是否 自动跳转 0关闭 1是开启
@property (nonatomic, assign) NSInteger ac;
/// 1: 合规值 2: 中灵敏闽值 3:高灵敏闽值
@property (nonatomic, assign) NSInteger istv;
/// 平台错误码
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


@end
NS_ASSUME_NONNULL_END
