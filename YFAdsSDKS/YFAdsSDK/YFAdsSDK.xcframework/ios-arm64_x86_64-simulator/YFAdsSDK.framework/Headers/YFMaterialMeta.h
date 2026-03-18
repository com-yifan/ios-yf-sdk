//
//  YFResponseModel.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/19.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdModel.h>

NS_ASSUME_NONNULL_BEGIN

//@interface YFMaterialMeta_new : NSObject
//
//@property(nonatomic, copy) NSString *msg;
//@property(nonatomic, copy) NSString *rid;
//@property(nonatomic, copy) NSString *ua;
//@property(nonatomic, assign) NSInteger code;
//
//@property(nonatomic, copy) NSString *eKey;
//
//// 广告应答唯一标识(可以用于数据差异排查)
//@property(nonatomic, copy) NSString *req_id;
//// ssp 平台广告位 ID
//@property(nonatomic, copy) NSString *pid;
//// ssp 平台创意 ID（保留字段）
//@property(nonatomic, copy) NSString *cid;
//// ssp 平台广告主 ID（保留字段）
//@property(nonatomic, copy) NSString *ader_id;
//
//// 广告位高
//@property(nonatomic, assign) NSUInteger height;
//// 广告位宽
//@property(nonatomic, assign) NSUInteger width;
//
//// 创意类型（1:图片、2:视频、3:音频、4:纯文字、11:图标广告）当 值 为 4 时 ，srcUrls 可能 会不存在或为空
//@property(nonatomic, assign) NSUInteger creative_type;
//
//// 广告交互类型(0:网页跳转、1:下载、2:小程序) 默认值:0
//@property(nonatomic, assign) NSUInteger target_type;
//
//// 激励视频广告可点击范围：1：按钮可点击2：全屏可点击
//@property(nonatomic, assign) NSUInteger clickable_range;
//
//// 点击落地页
//@property(nonatomic, copy) NSArray *dUrl;
//
///* deep_link 落地页地址（媒体支持 deeplink 落地页,应优先处理deep_link,当无法处理 deep_link 时
//(如用户未安装相应 app)再转而处理 dUrl, 如 果deep_link 可以落地 则 无 须 处 理dUrl,如果媒体不
//支 持 deeplink 可以直接处理 dUrl）
// */
//@property(nonatomic, copy) NSString *deep_link;
//
//// 微信小程序原始 id，(支持微信小程序唤起时此字段才有效，该字段有值时需跳转至小程序，跳失败时调用 durl)。
//@property(nonatomic, copy) NSString *wx_username;
//
///*
// 拉起小程序页面的可带参路径，不填默认拉起小程序首页，对于小游戏，可以只传入 query 部分，来 实 现 传 参 效 果 ， 如 ： 传 入
// "?foo=bar
// */
//@property(nonatomic, copy) NSString *wx_path;
//
//// 物料 URL
//@property(nonatomic, copy) NSArray *srcUrls;
//
//// 视频大小(byte)
//@property(nonatomic, assign) NSUInteger video_size;
//
//// 音视频时长(单位/秒)
//@property(nonatomic, assign) NSUInteger video_duration;
//
//// 音视频封面图地址
//@property(nonatomic, copy) NSString *video_cover;
//
//// 视频播放完成后，需要展示的封面图
//@property(nonatomic, copy) NSString *video_endcover;
//
//// 强制观看时长(单位/秒)，此字段不存在或等于 0 表示观看全部视频
//@property(nonatomic, assign) NSUInteger video_keep_time;
//// 视频预加载后的有效时间（在该时间间隔内播放为有效，单位/秒）, 此字段不存在或等于 0 表示不允许预加载
//@property(nonatomic, assign) NSUInteger video_preload_time;
//// 视 频 播 放 完 成 后 ， 需 要 用webview 渲染的 HTML
//@property(nonatomic, copy) NSString *video_endpage_html;
//// 标题
//@property(nonatomic, copy) NSString *title;
//// 摘要、描述
//@property(nonatomic, copy) NSString *content;
//// 引导行动语：查看详情、立即下载…
//@property(nonatomic, copy) NSString *action_text;
//// 角标(品牌 Logo、广告主头像等)
//@property(nonatomic, copy) NSString *icon;
////角标标题（品牌名、广告主名）
//@property(nonatomic, copy) NSString *icon_title;
//// 广告来源 logo icon(一般放于广告位右下角)
//@property(nonatomic, copy) NSString *from_logo;
//// 预算源("INMIO"-麟镜,“OPPO”，“JT”,"TAP","HW","BID")
//@property(nonatomic, copy) NSString *from;
//// 广告主
//@property(nonatomic, copy) NSString *merchant;
//
////        map[string]Object{
////        value string; //sld取值
////        default string;//取值无法获取时，填写的默认值；例如”-999“.当无此字段或者空值的时候，不需要使用默认值进行替换。
////        }
//// sld取值。key只取范围：click（常规点击）,rolling(扭一扭), shake（摇一摇）,move（滑动点击），erasure(擦除)。举例：{”click“: {"value":"0", "default":"-999"}, "move":{"value":"1",default:"-999"}, "shake":{"value":"2"}, "rolling": {"value": "5"},"erasure"： {"value":"6"}}
//@property(nonatomic, copy) NSDictionary *sld;
//// 应用名称
//@property(nonatomic, copy) NSString *app_name;
//// 应用介绍
//@property(nonatomic, copy) NSString *app_intro;
//// 应用介绍链接(注:链接)
//@property(nonatomic, copy) NSString *app_intro_url;
//// 应用版本
//@property(nonatomic, copy) NSString *app_ver;
//// 包体大小（单位：KB）
//@property(nonatomic, copy) NSString *app_size;
//// 隐私权限,参考 4.1.1  List<Permission OBJ>
//@property(nonatomic, copy) NSArray *app_permission;
//// 隐私权限链接(注:链接)
//@property(nonatomic, copy) NSString *app_permission_url;
//// 隐私协议，外网可访问链接(注: 链接)
//@property(nonatomic, copy) NSString *privacy_agreement;
//// 开发者
//@property(nonatomic, copy) NSString *developer;
//// 应用包名
//@property(nonatomic, copy) NSString *package_name;
//// 苹果应用市场的应用 ID
//@property(nonatomic, copy) NSString *appstore_id;
//// 下载量(大于 0)
//@property(nonatomic, assign) NSUInteger down_num;
//// 应用评分(大于 0)
//@property(nonatomic, assign) float score;
//// 应用评论数(大于 0)
//@property(nonatomic, assign) NSUInteger comments;
//// 广告曝光时必须触发上报
//@property(nonatomic, copy) NSArray *monitorUrl;
//// 广告被点击时必须触发上报
//@property(nonatomic, copy) NSArray *clickUrl;
//// 竞价失败时，调用的通知 URL
//@property(nonatomic, copy) NSString *lurl;
//// 广告价格
//@property(nonatomic, assign) NSUInteger ecpm;
//// 下载类广告（下载开始时上报）
//@property(nonatomic, copy) NSArray *dn_start;
//// 下载类广告（下载成功时上报）
//@property(nonatomic, copy) NSArray *dn_succ;
//// 下载类广告（安装开始时上报）
//@property(nonatomic, copy) NSArray *dn_inst_start;
//// 下载类广告（安装成功时上报）
//@property(nonatomic, copy) NSArray *dn_inst_succ;
//// 下载类广告（安装完成并打开应用时上报）
//@property(nonatomic, copy) NSArray *dn_active;
//// deep link 检测已安装
//@property (nonatomic, copy) NSArray *dp_installed;
//// deep link 未安装列表
//@property (nonatomic, copy) NSArray *dp_uninstalled;
//// deep_link 字段非空时，直接唤起类（尝试唤起时上报）
//@property(nonatomic, copy) NSArray *dp_start;
//// deep_link 字段非空时，直接唤起类（唤起成功时上报）
//@property(nonatomic, copy) NSArray *dp_succ;
//// deep_link 字段非空时，直接唤起类（唤起失败时上报）
//@property(nonatomic, copy) NSArray *dp_fail;
//// 音/视频广告（播放开始时上报）
//@property(nonatomic, copy) NSArray *video_start;
//// 音/视频广告（播放了 25%时上报）
//@property(nonatomic, copy) NSArray *video_one_quarter;
//// 音/视频广告（播放了 50%时上报）
//@property(nonatomic, copy) NSArray *video_one_half;
//// 音/视频广告（播放了 75%时上报）
//@property(nonatomic, copy) NSArray *video_three_quarter;
//// 音/视频广告（播放完成时上报）
//@property(nonatomic, copy) NSArray *video_complete;
//// 音/视频广告（用户点击暂停按钮时上报）
//@property(nonatomic, copy) NSArray *video_pause;
//// 音/视频广告（被暂停或被停止之后，主动继续播放时上报）
//@property(nonatomic, copy) NSArray *video_resume;
//// 音/视频广告（用户点击跳过按钮时上报）
//@property(nonatomic, copy) NSArray *video_skip;
//// 音/视频广告（用户主动关闭声音时上报）
//@property(nonatomic, copy) NSArray *video_mute;
//// 音/视频广告（用户主动开启声音时上报）
//@property(nonatomic, copy) NSArray *video_unmute;
//
//// 音/视频广告（重播时上报）
//@property(nonatomic, copy) NSArray *video_replay;
//// 音/视频广告（关闭时上报）
//@property(nonatomic, copy) NSArray *video_close;
//// 视频广告（全屏时上报）
//@property(nonatomic, copy) NSArray *video_full;
//// 视频广告（退出全屏时上报）
//@property(nonatomic, copy) NSArray *video_exit_full;
///// 竞胜通知
//@property(nonatomic, copy) NSArray *wurl;
//
//@end




typedef NS_ENUM(NSUInteger, YFMaterialMetaAdAction) {
    /// webview
    YFMaterialMetaAdActionWebview = 1,
    /// 下载
    YFMaterialMetaAdActionDownload = 2,
    /// 小程序
    YFMaterialMetaAdActionWXMinProgram = 3,
    /// 唤起
    YFMaterialMetaAdActionOpenApp = 4,
};

/// 广告素材类型
typedef NS_ENUM(NSUInteger, YFMaterialMetaAssetType) {
    /// 图片
    YFMaterialMetaAssetTypeImage = 1,
    /// 视频
    YFMaterialMetaAssetTypeVideo = 2
};

@class YFMaterialMetaAd;
@class YFMaterialMetaMonitor;
@class YFMaterialMetaAsset;
@class YFMaterialMetaDownload;
//@class YFMaterialMetaSId;

@interface YFMaterialMeta_new: NSObject<YFAdModel>
@property(nonatomic, assign) NSInteger code;
@property(nonatomic, copy) NSString *msg;
@property(nonatomic, copy) NSString *rId;
@property(nonatomic, copy) NSString *ua;
@property (nonatomic, strong) YFMaterialMetaAd *ad;


@end


@interface YFMaterialMetaAd: NSObject<YFAdModel>
/// 应用ID
@property (nonatomic, copy) NSString *appId;
/// 广告位id
@property (nonatomic, copy) NSString *adId;
/// 出价单位：分
@property (nonatomic,assign) NSInteger price;
/// 广告交互 :webview;2:下载;3:小程 4唤起
@property (nonatomic, assign) YFMaterialMetaAdAction action;
/// 落地页
@property (nonatomic, copy) NSString *landingUrl;
/// deeplink
@property (nonatomic, copy) NSString *dplUrl;
@property (nonatomic, copy) NSString *wxProgramId;
@property (nonatomic, copy) NSString *wxProgramPath;
@property (nonatomic, copy) NSString *UniversalUrl;
/// 监测信息
@property (nonatomic, strong) YFMaterialMetaMonitor *monitor;
/// 素材信息
@property (nonatomic, strong) YFMaterialMetaAsset *asset;
/// 下载信息
@property (nonatomic, strong) YFMaterialMetaDownload *download;
/// 广告主
@property (nonatomic, copy) NSString *merchant;
/// 广告交互类型，用于宏替换
@property (nonatomic, strong) NSDictionary *sld;

@end

@interface YFMaterialMetaMonitor: NSObject<YFAdModel>
/// deepLink成功唤醒监测数组
@property (nonatomic, copy) NSArray *dplsurls;
/// deeplink检测应用已安装
@property (nonatomic, copy) NSArray *dplInstalledUrls;
/// deeplink检测应用未安装
@property (nonatomic, copy) NSArray *dplUnInstalledUrls;
/// deepLink开始唤醒监测数组
@property (nonatomic, copy) NSArray *dplturls;
/// deeplink 唤醒失败
@property (nonatomic, copy) NSArray *dplFailedUrls;
/// 曝光监测地址数组（支持宏替换
@property (nonatomic, copy) NSArray *exposureUrls;
/// 点击监测地址数组（支持宏替换
@property (nonatomic, copy) NSArray *clickUrls;
/// 音/视频广告（播放开始时上报）
@property (nonatomic, copy) NSArray *playStartUrls;
/// 音/视频广告（播放四分之一时上报
@property (nonatomic, copy) NSArray *playOneQuarterUrls;
/// 音/视频广告（播放一半时上报
@property (nonatomic, copy) NSArray *playOneHalfUrls;
/// 音/视频广告（播放75%时上报
@property (nonatomic, copy) NSArray *playThreeQuarterUrls;
/// 音/视频广告（用户点击暂停按钮时上报
@property (nonatomic, copy) NSArray *playPauseUrls;
/// 音/视频广告（被暂停或被停止之后，主动继续播放时上报）
@property (nonatomic, copy) NSArray *playResumeUrls;
/// 播放结束事件
@property (nonatomic, copy) NSArray *playEndUrls;
/// 音/视频广告（用户点击跳过按钮时上报）
@property (nonatomic, copy) NSArray *playSkipUrls;
/// 音/视频广告（用户主动关闭声音时上报）
@property (nonatomic, copy) NSArray *playMuteUrls;
/// 音/视频广告（用户主动打开声音时上报
@property (nonatomic, copy) NSArray *playUnmuteUrls;
/// 音/视频广告（关闭时上报
@property (nonatomic, copy) NSArray *playCloseUrls;
/// 视频广告（全屏播放时上报
@property (nonatomic, copy) NSArray *playFullScreenUrls;
/// 视频广告（退出全屏时上报
@property (nonatomic, copy) NSArray *playExitFullScreenUrls;
/// 下载类广告（下载开始时上报）
@property (nonatomic, copy) NSArray *downloadStartUrls;
/// 下载类广告（下载成功时上报
@property (nonatomic, copy) NSArray *downloadSuccessUrls;
/// 下载类广告（安装完成并打开应用时上报
@property (nonatomic, copy) NSArray *installWithAppOpenUrls;
/// 下载类广告（安装开始时上报
@property (nonatomic, copy) NSArray *installStartUrls;
/// 下载类广告（安装成功时上报
@property (nonatomic, copy) NSArray *installSuccessUrls;
/// 用户主动关闭上报
@property (nonatomic, copy) NSArray *userCloseUrls;
/// 竞胜通知
@property (nonatomic, copy) NSArray *winUrls;

@end

@interface YFMaterialMetaAssetImage: NSObject<YFAdModel>
/// 地址
@property (nonatomic, copy) NSArray *urls;
/// 格式
@property (nonatomic, copy) NSString *mine;
/// 图片高
@property (nonatomic, assign) NSInteger h;
/// 图片宽
@property (nonatomic, assign) NSInteger w;
/// 图片标题
@property (nonatomic, copy) NSString *title;
/// 图片广告语
@property (nonatomic, copy) NSString *text;
/// 图片素材名称
@property (nonatomic, copy) NSString *name;

@end

@interface YFMaterialMetaAssetVideo: NSObject<YFAdModel>
/// 地址
@property (nonatomic, copy) NSString *url;
/// 格式
@property (nonatomic, copy) NSString *mine;
/// 图片高
@property (nonatomic, assign) NSInteger h;
/// 图片宽
@property (nonatomic, assign) NSInteger w;
/// 图片标题
@property (nonatomic, copy) NSString *title;
/// 时长
@property (nonatomic, assign) NSInteger duration;
/// 图片广告语
@property (nonatomic, copy) NSString *text;
/// 图片素材名称
@property (nonatomic, copy) NSString *name;
/// 视频封面图片
@property (nonatomic, copy) NSString *imgUrl;
/// 视频大小
@property (nonatomic, assign) long size;
/// 视频文件的sha256
@property (nonatomic, copy) NSString *sha256;
/// 视频宽高比
@property (nonatomic, assign) float ratio;
/// 激励视频观看时长
@property (nonatomic, assign) NSInteger videoKeepTime;
/// endcard跟图片
@property (nonatomic, copy) NSString *endImgUrl;

@end

@interface YFMaterialMetaAsset: NSObject<YFAdModel>
///
@property (nonatomic, assign) YFMaterialMetaAssetType type;

@property (nonatomic, assign) BOOL isVideoAd;

/// 标题
@property (nonatomic, copy) NSString *title;
/// 广告语
@property (nonatomic, copy) NSString *text;
/// 图片素材名称
@property (nonatomic, copy) NSString *name;

/// 图片素材信息
@property (nonatomic, strong) YFMaterialMetaAssetImage *image;
/// 视频素材信息
@property (nonatomic, strong) YFMaterialMetaAssetVideo *video;

@end

@interface YFMaterialMetaDownload : NSObject<YFAdModel>
/// 下载地址
@property (nonatomic, copy) NSString *Url;
/// 下载地址
@property (nonatomic, copy) NSString *packageName;
/// 商店id
@property (nonatomic, copy) NSString *storeId;
/// 商店地址
@property (nonatomic, copy) NSString *marketUrl;
/// 隐私政策
@property (nonatomic, copy) NSString *privacyUrl;
/// 权限政策
@property (nonatomic, copy) NSString *permissionUrl;
/// APP信息
@property (nonatomic, copy) NSString *appInfoUrl;
/// 开发者名称
@property (nonatomic, copy) NSString *developerName;
/// 应用名称
@property (nonatomic, copy) NSString *appName;
/// 应用版本
@property (nonatomic, copy) NSString *appVer;
/// 文件大小
@property (nonatomic, assign) NSInteger fileSize;
/// 文件hash
@property (nonatomic, copy) NSString *sha256;
/// apk第二下载地址
@property (nonatomic, copy) NSString *secondUrl;
/// app 描述
@property (nonatomic, copy) NSString *appDesc;
/// App图标地址地址
@property (nonatomic, copy) NSString *appIconUrl;
/// 角标标题
@property (nonatomic, copy) NSString *iconTitle;
/// 广告来源logo地址
@property (nonatomic, copy) NSString *logoUrl;
/// 按钮文案
@property (nonatomic, copy) NSString *actionText;

@end


//@interface YFMaterialMetaSId : NSObject<YFAdModel>
///// 值
//@property (nonatomic, copy) NSString *value;
///// 默认值
//@property (nonatomic, copy) NSString *defaultValue;
//
//@end


NS_ASSUME_NONNULL_END
