//
//  GDTUnifiedBannerView.h
//  GDTMobSDK
//
//  Created by nimomeng on 2019/3/1.
//  Copyright © 2019 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YFVideoAd.h"

NS_ASSUME_NONNULL_BEGIN

@class YFFullScreenVideoAd;

@protocol YFFullScreenVideoAdDelegate <NSObject>
@optional
/**
 This method is called when video ad material loaded successfully.
 */
- (void)yfFullScreenVideoAdDidLoad:(YFFullScreenVideoAd *)fullscreenVideoAd;
/**
 This method is called when video ad materia failed to load.
 @param error : the reason of error
 */
- (void)yfFullScreenVideoAd:(YFFullScreenVideoAd *)fullscreenVideoAd didFailWithError:(NSError *_Nullable)error;

/**
 This method is called when video render failed to load.
 @param error : the reason of error
 */
- (void)yfFullScreenVideoAd:(YFFullScreenVideoAd *)fullscreenVideoAd renderFailedWithError:(NSError *_Nullable)error;
/**
 This method is called when cached successfully.
 */
- (void)yfFullScreenVideoAdVideoDidCache:(YFFullScreenVideoAd *)fullscreenVideoAd;

/**
 This method is called when video ad slot has been shown.
 */
- (void)yfFullScreenVideoAdDidVisible:(YFFullScreenVideoAd *)fullscreenVideoAd;
/**
 This method is called when video ad is closed.
 */
- (void)yfFullScreenVideoAdDidClose:(YFFullScreenVideoAd *)fullscreenVideoAd;

/**
 This method is called when video ad is clicked.
 */
- (void)yfFullScreenVideoAdDidClick:(YFFullScreenVideoAd *)fullscreenVideoAd;
/**
 This method is called when video ad play completed or an error occurred.
 */
- (void)yfFullScreenVideoAdDidPlayFinish:(YFFullScreenVideoAd *)fullscreenVideoAd;
/**
 This method is called when the video begin to play.
 */
- (void)yfFullScreenVideoAdStartPlay:(YFFullScreenVideoAd *)fullscreenVideoAd;

@end


@interface YFFullScreenVideoAd:YFVideoAd

@property (nonatomic, weak, nullable) id<YFFullScreenVideoAdDelegate> delegate;

@property(nonatomic,assign)NSUInteger ecpm;

@property (nonatomic, assign) BOOL autoClick;

-(instancetype)initWithPosId:(NSString *)posId eventModel:(YFAdEventModel *)eventModel;
@end


NS_ASSUME_NONNULL_END
