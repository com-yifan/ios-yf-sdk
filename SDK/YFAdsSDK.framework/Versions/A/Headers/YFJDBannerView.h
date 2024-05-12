//
//  YFJDBannerView.h
//  YFAdsSDK
//
//  Created by feng on 2023/11/10.
//


#import <UIKit/UIKit.h>
#import "YFPlayerAdControlView.h"
#import "YFAVPlayerManager.h"
#import "YFPlayerAdControlView.h"
#import "YFAdReportModel.h"
#import "YFAdView.h"

#if __has_include(<JADYun/JADYun.h>)
#import <JADYun/JADYun.h>
@interface YFJDBannerView : UIView

@property (nonatomic, strong) YFAdImageView *contentView;
@property(nonatomic, strong) YFAVPlayerManager *playerManager;
@property(nonatomic, strong) YFPlayerController *player;
@property(nonatomic,strong) YFPlayerAdControlView *controlView;
@property(nonatomic,strong) JADNativeAd *nativeAd;
@property (nonatomic, strong) YFAdEventModel *eventModel;

///是否播放完成
@property (nonatomic, assign) BOOL playFinished;

-(void)startMonitor;

-(void)toLoadPlayVideo;

- (void)closeAd;

-(instancetype)initWithFrame:(CGRect)frame model:(id)model viewController:(UIViewController *)viewController;

-(void)loadAdData:(JADNativeAd *)dataObject;

@end
#endif


