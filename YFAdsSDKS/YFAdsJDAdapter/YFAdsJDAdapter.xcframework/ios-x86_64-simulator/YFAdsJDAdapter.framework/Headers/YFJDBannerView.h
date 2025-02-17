//
//  YFJDBannerView.h
//  YFAdsSDK
//
//  Created by feng on 2023/11/10.
//


#import <YFAdsSDK/YFAdBaseCustomView.h>
#import <YFAdsSDK/YFAdReportModel.h>
#import <YFAdsSDK/YFAdView.h>
#import <YFAdsSDK/YFAdsCloseButton.h>
#import <YFAdsSDK/YFVideoView.h>

#if __has_include(<JADYun/JADYun.h>)
#import <JADYun/JADYun.h>
@interface YFJDBannerView : YFAdBaseCustomView

@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong) YFVideoView *videoView;
@property(nonatomic,strong) JADNativeAd *nativeAd;
@property (nonatomic, strong) YFAdEventModel *eventModel;

///是否播放完成
@property (nonatomic, assign) BOOL playFinished;

-(void)startMonitor;

-(void)toLoadPlayVideo;

- (void)closeAd;

- (void)playVideo;

-(instancetype)initWithFrame:(CGRect)frame model:(id)model viewController:(UIViewController *)viewController;

-(void)loadAdData:(JADNativeAd *)dataObject close: (void(^)(id))close;

@end
#endif


