//
//  YFPlayerAdControlView.h
//  YFAdsSDK
//
//  Created by FC-0823 on 2023/11/6.
//


#import <UIKit/UIKit.h>
#import "YFPortraitControlView.h"
#import "YFLandScapeControlView.h"
#import "YFSpeedLoadingView.h"
#import "YFMaterialMeta.h"
#import "YFSmallFloatControlView.h"
#import "YFPlayerMediaControl.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFPlayerAdControlView : UIView <YFPlayerMediaControl>
/// 底部播放进度
@property (nonatomic, strong) YFSliderView *bottomPgrogress;
/// 底部播放进度
@property (nonatomic, strong) UIButton *playBtn;
/// 封面图
@property (nonatomic, strong) UIImageView *coverImageView;
/// 高斯模糊的背景图
@property (nonatomic, strong) UIImageView *bgImgView;
/// prepare时候是否显示loading,默认 NO.
@property (nonatomic, assign) BOOL prepareShowLoading;

@property (nonatomic, strong) YFMaterialMeta *nativeAd;

@property(nonatomic,copy)void (^toPlayClick)(void);

@property(nonatomic,copy)void (^toPlayControEvent)(void);
@end

NS_ASSUME_NONNULL_END
