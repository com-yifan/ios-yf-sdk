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

@interface YFJDBannerView : UIView

@property(nonatomic, strong) YFAVPlayerManager *playerManager;
@property(nonatomic, strong) YFPlayerController *player;
@property(nonatomic,strong) YFPlayerAdControlView *controlView;
@property(nonatomic,strong) JADNativeAd *nativeAd;
///是否播放完成
@property (nonatomic, assign) BOOL playFinished;

-(void)startMonitor;

- (void)closeAd;

-(instancetype)initWithFrame:(CGRect)frame model:(id)model viewController:(UIViewController *)viewController;

-(void)loadAdData:(JADNativeAd *)dataObject;

@end

