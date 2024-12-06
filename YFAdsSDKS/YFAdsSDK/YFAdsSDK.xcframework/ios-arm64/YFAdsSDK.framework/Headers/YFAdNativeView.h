//
//  YFAdNativeView.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 18/04/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdNative.h>
#import <YFAdsSDK/YFAdNativeRendering.h>
#import <YFAdsSDK/YFAdNativePrepareInfo.h>
#import <YFAdsSDK/YFAdNativeOffer.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, YFAdNativeRenderType) {
    YFAdNativeRenderSelfRender = 1,
    YFAdNativeRenderExpress = 2
};

typedef NS_ENUM(NSInteger, YFAdNativeType) {
    YFAdNativeTypeFeed = 1, //In-feed Ads (Native Ads)
    YFAdNativeTypePaster = 2 //Patch Ads
};

typedef NS_ENUM(NSInteger, YFPlayerStatus) {
    YFPlayerStatusStartPlay,
    YFPlayerStatusPause,
    YFPlayerStatusFinish,
    YFPlayerStatusResume,
    YFPlayerStatusAbort
};

/**
 * Subclasses are expected to call super when overriding willMoveToSuperview: because it it within this method the base class kick off the rendering process.
 */
@protocol YFAdNativeDelegate;
@protocol YFAdNativeRenderer;
@class YFAdNativeConfiguration;

#define YFMediaViewTag 2023122516
#define YFSimpleMediaViewTag 2023122515

@interface YFAdNativeView : UIView <YFAdNativeRendering>
/**
 * Subclass implementation has to call [super initSubviews] for the ad view to work properly. By the time this method's called, the ad view is not yet full fledged.
 */
-(void)initSubviews;

/**
 * Create constraints for subviews in this method if you are using autolayout.
 */
-(void)makeConstraintsForSubviews;

/**
 * Whether the ad being shown is a video ad.
 */
-(BOOL)isVideoContents;

/*
 * ALWAYS call this method to retrieve the REAL rendered adview.
 */
-(YFAdNativeView*)embededAdView;

/**
 * Returns an array containing views that are used to track clicks.
 */
-(NSArray<UIView*>*)clickableViews;

@property(nonatomic, weak) id<YFAdNativeDelegate> delegate;
/**
 * The view that is used to play video or other media; it is set by the sdk; might be nil.
 */
//@property(nonatomic, nullable) UIView *mediaView;
/**
 * The native ad that is being shown.
 */
@property(nonatomic, readonly) YFAdNative *nativeAd;
/**
 * The networkFirm id of native ad.
 */
@property(nonatomic, readonly) NSInteger networkFirmID;

/**
 * The duration of the video ad playing, unit ms
 */
- (CGFloat)videoPlayTime;
/**
 * Video ad duration, unit ms
 */
- (CGFloat)videoDuration;
/**
 Play mute switch
 @param flag whether to mute
 */
- (void)muteEnable:(BOOL)flag;
/**
 * The video ad play
 */
- (void)videoPlay;
/**
 * The video ad pause
 */
- (void)videoPause;

/// The destroy  network native ad
- (void)destroyNative;
/**
 * The native ad type
 */
- (YFAdNativeType)getNativeAdType;
/**
 * The native ad render type
 */
- (YFAdNativeRenderType)getCurrentNativeAdRenderType;

/**
 * Set the background color for the self-rendered AD AdChoicesView.
 * only Meta
 */
- (void)setAdChoicesViewColor:(UIColor *)color;

@property(nonatomic, strong) UIView *selfRenderView;

- (void)recordCustomPlayerStatus:(YFPlayerStatus)status currentTime:(NSTimeInterval)time;

- (void)prepareWithNativePrepareInfo:(YFAdNativePrepareInfo *)nativePrepareInfo;

- (UIView *)getMediaView;
// only support BaiDu native Ad
- (UIView *)getNetworkShakeViewWithFrame:(CGRect)frame;

/// 初始化滑一滑组件，仅支持百度
/// - Parameters:
///   - frame: 组件frame
///   - repeat: 动画播放次数，-1为无限循环
///   - animationWidth: 动画区域的宽度,不包括文本，不得超过frame尺寸
///   - animationHeight: 动画区域的高度,不包括文本，不得超过frame尺寸
- (UIView *)getNetworkSlideViewWithFrame:(CGRect)frame
                                  repeat:(int)repeat
                          animationWidth:(CGFloat)animationWidth
                         animationHeight:(CGFloat)animationHeight;



- (instancetype)initWithConfiguration:(YFAdNativeConfiguration*)configuration currentOffer:(YFAdNativeOffer *)currentOffer placementID:(NSString*)placementID;

- (void)updateAdViewConfiguration:(YFAdNativeConfiguration*)configuration currentOffer:(YFAdNativeOffer *)currentOffer placementID:(NSString*)placementID;

- (void)registerClickableViewArray:(NSArray *)registerClickViewArray;



@end

//Defined for TT native
extern NSString const* kATExtraNativeImageSize228_150;
extern NSString const* kATExtraNativeImageSize690_388;
extern NSString const* kATExtraNativeImageSizeKey;
extern NSString const* kATExtraNativeImageSize1280_720;
extern NSString const* kATExtraNativeImageSize1200_628;
extern NSString const* kATExtraNativeImageSize640_640;
extern NSString const* kATExtraStartAPPNativeMainImageSizeKey;
extern NSString const* kATExtraNativeIconImageSizeKey;

@interface YFAdNativeView(DrawVideo)
/*
 * Override this method to layout draw video assets.
 */
-(void) makeConstraintsDrawVideoAssets;
@property (nonatomic, strong, readonly, nullable) UIButton *dislikeDrawButton;
@property (nonatomic, strong, readonly, nullable) UILabel *adLabel;
@property (nonatomic, strong, readonly, nullable) UIImageView *logoDrawImageView;
@property (nonatomic, strong, readonly, nullable) UIImageView *logoADImageView;
@property (nonatomic, strong, readonly, nullable) UIView *videoAdView;
@end

NS_ASSUME_NONNULL_END
