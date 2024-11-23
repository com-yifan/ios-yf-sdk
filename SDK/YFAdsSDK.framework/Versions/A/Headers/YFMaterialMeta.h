//
//  YFResponseModel.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFMaterialMeta : NSObject

@property(nonatomic, copy) NSString *msg;
@property(nonatomic, copy) NSString *rid;
@property(nonatomic, assign) NSInteger code;

@property(nonatomic, copy) NSString *eKey;

// 广告应答唯一标识(可以用于数据差异排查)
@property(nonatomic, copy) NSString *req_id;
// ssp 平台广告位 ID
@property(nonatomic, copy) NSString *pid;
// ssp 平台创意 ID（保留字段）
@property(nonatomic, copy) NSString *cid;
// ssp 平台广告主 ID（保留字段）
@property(nonatomic, copy) NSString *ader_id;

// 广告位高
@property(nonatomic, assign) NSUInteger height;
// 广告位宽
@property(nonatomic, assign) NSUInteger width;

// 创意类型（1:图片、2:视频、3:音频、4:纯文字、11:图标广告）当 值 为 4 时 ，srcUrls 可能 会不存在或为空
@property(nonatomic, assign) NSUInteger creative_type;

// 广告交互类型(0:网页跳转、1:下载) 默认值:0
@property(nonatomic, assign) NSUInteger target_type;

// 激励视频广告可点击范围：1：按钮可点击2：全屏可点击
@property(nonatomic, assign) NSUInteger clickable_range;

// 点击落地页
@property(nonatomic, copy) NSArray *dUrl;

/* deep_link 落地页地址（媒体支持 deeplink 落地页,应优先处理deep_link,当无法处理 deep_link 时
(如用户未安装相应 app)再转而处理 dUrl, 如 果deep_link 可以落地 则 无 须 处 理dUrl,如果媒体不
支 持 deeplink 可以直接处理 dUrl）
 */
@property(nonatomic, copy) NSString *deep_link;

// 微信小程序原始 id，(支持微信小程序唤起时此字段才有效，该字段有值时需跳转至小程序，跳失败时调用 durl)。
@property(nonatomic, copy) NSString *wx_username;

/*
 拉起小程序页面的可带参路径，不填默认拉起小程序首页，对于小游戏，可以只传入 query 部分，来 实 现 传 参 效 果 ， 如 ： 传 入
 "?foo=bar
 */
@property(nonatomic, copy) NSString *wx_path;

// 物料 URL
@property(nonatomic, copy) NSArray *srcUrls;

// 视频大小(byte)
@property(nonatomic, assign) NSUInteger video_size;

// 音视频时长(单位/秒)
@property(nonatomic, assign) NSUInteger video_duration;

// 音视频封面图地址
@property(nonatomic, copy) NSString *video_cover;

// 视频播放完成后，需要展示的封面图
@property(nonatomic, copy) NSString *video_endcover;

// 强制观看时长(单位/秒)，此字段不存在或等于 0 表示观看全部视频
@property(nonatomic, assign) NSUInteger video_keep_time;
// 视频预加载后的有效时间（在该时间间隔内播放为有效，单位/秒）, 此字段不存在或等于 0 表示不允许预加载
@property(nonatomic, assign) NSUInteger video_preload_time;
// 视 频 播 放 完 成 后 ， 需 要 用webview 渲染的 HTML
@property(nonatomic, copy) NSString *video_endpage_html;
// 标题
@property(nonatomic, copy) NSString *title;
// 摘要、描述
@property(nonatomic, copy) NSString *content;
// 引导行动语：查看详情、立即下载…
@property(nonatomic, copy) NSString *action_text;
// 角标(品牌 Logo、广告主头像等)
@property(nonatomic, copy) NSString *icon;
//角标标题（品牌名、广告主名）
@property(nonatomic, copy) NSString *icon_title;
// 广告来源 logo icon(一般放于广告位右下角)
@property(nonatomic, copy) NSString *from_logo;
// 广告来源
@property(nonatomic, copy) NSString *from;
// 应用名称
@property(nonatomic, copy) NSString *app_name;
// 应用介绍
@property(nonatomic, copy) NSString *app_intro;
// 应用介绍链接(注:链接)
@property(nonatomic, copy) NSString *app_intro_url;
// 应用版本
@property(nonatomic, copy) NSString *app_ver;
// 包体大小（单位：KB）
@property(nonatomic, copy) NSString *app_size;
// 隐私权限,参考 4.1.1  List<Permission OBJ>
@property(nonatomic, copy) NSArray *app_permission;
// 隐私权限链接(注:链接)
@property(nonatomic, copy) NSString *app_permission_url;
// 隐私协议，外网可访问链接(注: 链接)
@property(nonatomic, copy) NSString *privacy_agreement;
// 开发者
@property(nonatomic, copy) NSString *developer;
// 应用包名
@property(nonatomic, copy) NSString *package_name;
// 苹果应用市场的应用 ID
@property(nonatomic, copy) NSString *appstore_id;
// 下载量(大于 0)
@property(nonatomic, assign) NSUInteger down_num;
// 应用评分(大于 0)
@property(nonatomic, assign) float score;
// 应用评论数(大于 0)
@property(nonatomic, assign) NSUInteger comments;
// 广告曝光时必须触发上报
@property(nonatomic, copy) NSArray *monitorUrl;
// 广告被点击时必须触发上报
@property(nonatomic, copy) NSArray *clickUrl;
// 竞价失败时，调用的通知 URL
@property(nonatomic, copy) NSString *lurl;
// 广告价格
@property(nonatomic, assign) NSUInteger ecpm;
// 下载类广告（下载开始时上报）
@property(nonatomic, copy) NSArray *dn_start;
// 下载类广告（下载成功时上报）
@property(nonatomic, copy) NSArray *dn_succ;
// 下载类广告（安装开始时上报）
@property(nonatomic, copy) NSArray *dn_inst_start;
// 下载类广告（安装成功时上报）
@property(nonatomic, copy) NSArray *dn_inst_succ;
// 下载类广告（安装完成并打开应用时上报）
@property(nonatomic, copy) NSArray *dn_active;
// deep link 检测已安装
@property (nonatomic, copy) NSArray *dp_installed;
// deep link 未安装列表
@property (nonatomic, copy) NSArray *dp_uninstalled;
// deep_link 字段非空时，直接唤起类（尝试唤起时上报）
@property(nonatomic, copy) NSArray *dp_start;
// deep_link 字段非空时，直接唤起类（唤起成功时上报）
@property(nonatomic, copy) NSArray *dp_succ;
// deep_link 字段非空时，直接唤起类（唤起失败时上报）
@property(nonatomic, copy) NSArray *dp_fail;
// 音/视频广告（播放开始时上报）
@property(nonatomic, copy) NSArray *video_start;
// 音/视频广告（播放了 25%时上报）
@property(nonatomic, copy) NSArray *video_one_quarter;
// 音/视频广告（播放了 50%时上报）
@property(nonatomic, copy) NSArray *video_one_half;
// 音/视频广告（播放了 75%时上报）
@property(nonatomic, copy) NSArray *video_three_quarter;
// 音/视频广告（播放完成时上报）
@property(nonatomic, copy) NSArray *video_complete;
// 音/视频广告（用户点击暂停按钮时上报）
@property(nonatomic, copy) NSArray *video_pause;
// 音/视频广告（被暂停或被停止之后，主动继续播放时上报）
@property(nonatomic, copy) NSArray *video_resume;
// 音/视频广告（用户点击跳过按钮时上报）
@property(nonatomic, copy) NSArray *video_skip;
// 音/视频广告（用户主动关闭声音时上报）
@property(nonatomic, copy) NSArray *video_mute;
// 音/视频广告（用户主动开启声音时上报）
@property(nonatomic, copy) NSArray *video_unmute;

// 音/视频广告（重播时上报）
@property(nonatomic, copy) NSArray *video_replay;
// 音/视频广告（关闭时上报）
@property(nonatomic, copy) NSArray *video_close;
// 视频广告（全屏时上报）
@property(nonatomic, copy) NSArray *video_full;
// 视频广告（退出全屏时上报）
@property(nonatomic, copy) NSArray *video_exit_full;
/// 竞胜通知
@property(nonatomic, copy) NSArray *wurl;

@end

NS_ASSUME_NONNULL_END
