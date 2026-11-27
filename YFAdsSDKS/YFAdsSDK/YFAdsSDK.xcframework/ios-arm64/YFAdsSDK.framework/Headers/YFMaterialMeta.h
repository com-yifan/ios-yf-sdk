//
//  YFResponseModel.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/19.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdModel.h>

NS_ASSUME_NONNULL_BEGIN


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
@class YFAdCouponModel;
@class YFAdxMaterialGroup;
//@class YFMaterialMetaSId;

@interface YFMaterialMeta_new: NSObject<YFAdModel>
@property(nonatomic, assign) NSInteger code;
@property(nonatomic, copy) NSString *msg;
@property(nonatomic, copy) NSString *rId;
@property(nonatomic, copy) NSString *ua;
/// 当前素材快照
@property (atomic, copy) NSArray<YFMaterialMetaAd *> *ads;
@property (nonatomic, strong, readonly, nullable) YFMaterialMetaAd *ad;
@property (nonatomic, strong, nullable) YFAdxMaterialGroup *materialGroup;

@end


@interface YFMaterialMetaAd: NSObject<YFAdModel>
/// 关联组反向保留素材。
@property (nonatomic, weak, nullable) YFAdxMaterialGroup *materialGroup;
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
/// 优惠券信息
@property (nonatomic, strong, nullable) YFAdCouponModel *coupon;
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
