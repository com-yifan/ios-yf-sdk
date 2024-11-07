
#import <UIKit/UIKit.h>
#import "YFTouchReportView.h"
#import "YFAdError.h"
#import "YFMaterialMeta.h"
#import "YFAdReportModel.h"
#import "YFPlayerAdControlView.h"
#import "YFAVPlayerManager.h"
#import "YFPlayerAdControlView.h"
#import "YFPlayerController.h"

typedef NS_ENUM(NSInteger, YFBannerViewType) {
    YFBannerViewTypeNormal,///普通banner
    YFBannerViewTypeFeed ///信息流
};

@class YFBannerView;

@protocol YFBannerViewDelegate <NSObject>
@optional
/**
 *  请求广告条数据成功后调用
 *  当接收服务器返回的广告数据成功后调用该函数
 */
- (void)yfBannerViewDidLoad:(YFBannerView *)bannerView;

/**
 *  请求广告条数据失败后调用
 *  当接收服务器返回的广告数据失败后调用该函数
 */
- (void)yfBannerViewFailedToLoad:(YFBannerView *)bannerView error:(NSError *)error;


/**
 *
 * 广告渲染成功
 */
- (void)yfBannerNativeExpressOnAdRenderSuccess:(YFBannerView *)bannerView;

/**
 *  
 * 广告渲染失败
 */
- (void)yfBannerNativeExpressOnAdRenderFail:(YFBannerView *)bannerView error:(NSError *)error;
/**
 *  曝光回调
 */
- (void)yfBannerViewWillExpose:(YFBannerView *)bannerView;

/**
 *  点击回调
 */
- (void)yfBannerViewClicked:(YFBannerView *)bannerView;


/**
 *  被用户关闭时调用
 *  会立即关闭当前banner广告，若启用轮播，（刷新间隔 - 当前广告已展示时间）后会展示新的广告
 *  若未启用轮播或不需要再展示，需在回调中将unifiedBannerView从父view移除置nil
 */
- (void)yfBannerViewWillClose:(YFBannerView *)bannerView;

@end

@interface YFBannerView : UIView


@property(nonatomic, weak) id <YFBannerViewDelegate> delegate;

@property(nonatomic, readonly) YFMaterialMeta *materialMetaModel;
@property(nonatomic, copy,readonly) NSString *posId;
@property(nonatomic, copy,readonly) YFAdEventModel *eventModel;
@property(nonatomic, assign,readonly) NSUInteger ecpm;
@property(nonatomic, copy,readonly) NSArray *clickUrls;
@property(nonatomic, strong) YFTouchLocModel *touchModel;
@property(nonatomic, assign) YFBannerViewType type;
@property(nonatomic, strong) YFAVPlayerManager *playerManager;
@property(nonatomic, strong) YFPlayerController *player;
@property(nonatomic, assign) YFPlayerPlaybackState cuurentPlayState;
@property(nonatomic, strong) YFPlayerAdControlView *controlView;
///是否播放完成
@property (nonatomic, assign) BOOL playFinished;
/**
 *  广告是否有效，以下情况会返回NO，建议在展示广告之前判断，否则会影响计费或展示失败
 *  a.广告未拉取成功
 *  b.广告过期
 */
@property(nonatomic, readonly) BOOL isValid;
/// 广告素材是否加载完成；视频是否准备好播放/图片加载完成
@property (nonatomic, assign) BOOL isReady;
@property(nonatomic, copy) void(^closeAd)(void);

/**
 *  构造方法
 *  详解：frame - banner 展示的位置和大小
 *       placementId - 广告位 ID
 *       viewController - 视图控制器
 */
- (instancetype)initWithFrame:(CGRect)frame
                        posId:(NSString *)posId
                        model:(id)model
               viewController:(UIViewController *)viewController;

/**
 *  拉取广告
 */
- (void)loadAdData;

/**
 *  获取高度
 */
- (float)getViewHeight;
-(void)toPlayVideo;
-(void)turnClickBtn;

@end


