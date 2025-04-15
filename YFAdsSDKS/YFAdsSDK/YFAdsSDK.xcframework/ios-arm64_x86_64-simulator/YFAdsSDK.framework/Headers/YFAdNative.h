//
//  YFAdNative.h

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM (NSInteger, YFAdNativeInteractionType) {
    YFAdNativeInteractionTypeUnknown        = 0,
    YFAdNativeInteractionTypeNone           = 1,  // pure ad display
    YFAdNativeInteractionTypeURL            = 2,  // open the webpage using a browser
    YFAdNativeInteractionTypePage           = 3,  // open the webpage within the app
    YFAdNativeInteractionTypeDownload       = 4,  // download the app
    YFAdNativeInteractionTypePhone          = 5,  // make a call
    YFAdNativeInteractionTypeMessage        = 6,  // send messages
    YFAdNativeInteractionTypeEmail          = 7,  // send email
    YFAdNativeInteractionTypeVideoAdDetail  = 8,  // video ad details page
    YFAdNativeInteractionTypeWechat         = 9,  // open wechat
    YFAdNativeInteractionTypeOthers         = 100 // types returned by other ad sdk
};

typedef NS_ENUM(NSInteger, YFAdSourceType) {
    YFAdSourceTypeBD  = 1,
    YFAdSourceTypeCSJ = 2,
    YFAdSourceTypeGDT = 3,
    YFAdSourceTypeJD  = 4,
    YFAdSourceTypeKS  = 5,
    YFAdSourceTypeYF  = 6,
    YFAdSourceTypeTX  = 7

};


@interface YFAdNative : NSObject

/// Advertiser, advertiser's name or link
@property(nonatomic, readonly) NSString * advertiser;

/// appName
@property(nonatomic, readonly) NSString *appName;

/// ad title
@property(nonatomic, readonly) NSString *title;

/// Ad details
@property(nonatomic, readonly) NSString *mainText;

/// CTA Button text such as 'download/install'
@property(nonatomic, readonly) NSString *ctaText;

/// app  icon
@property(nonatomic, readonly) UIImage *icon;

/// main image
@property(nonatomic, readonly) UIImage *mainImage;

/// ad logo
@property(nonatomic, readonly) UIImage *logo;

/// video url
@property(nonatomic, readonly) NSString *videoUrl;

/// ad logo url
@property(nonatomic, readonly) NSString *logoUrl;

/// app icon url
@property(nonatomic, readonly) NSString *iconUrl;

/// main image url
@property(nonatomic, readonly) NSString *imageUrl;

/// main image width
@property(nonatomic, readonly) CGFloat mainImageWidth;

/// main image height
@property(nonatomic, readonly) CGFloat mainImageHeight;

/// mediaView
@property(nonatomic, readonly, nullable) UIView *mediaView;

/// image url list
@property(nonatomic, readonly) NSArray<NSString *> *imageList;

/// video duration, in second, if there is no value, return 0
@property(nonatomic, readonly) NSInteger videoDuration;

/// video aspect ratio (width/height), if no value or exception returns 0
@property (nonatomic, assign, readonly) CGFloat videoAspectRatio;

/// Only for template AdView
@property(nonatomic, readonly) CGFloat nativeExpressAdViewWidth;

@property(nonatomic, readonly) CGFloat nativeExpressAdViewHeight;

/// Ad-supported jump types
@property(nonatomic, assign, readonly) YFAdNativeInteractionType interactionType;

/// adSourceType
@property(nonatomic, assign, readonly) YFAdSourceType adSourceType;


@property(nonatomic, readonly) NSString *ecpm;

/// media extension data
@property(nonatomic, copy, readonly) NSDictionary *mediaExt;

/// app source, marketplace, such as 'App Store'
@property(nonatomic, copy, readonly) NSString *source;

/// app rating
@property(nonatomic, readonly) NSNumber *rating;

/// the number of comments, or -1 if there is no value
@property(nonatomic, assign, readonly) NSInteger commentNum;

/// the size of the ad installation package, in KB, if there is no value, return -1
@property(nonatomic, assign, readonly) NSInteger appSize;

/// app purchase price, such as 'free', nil if none
@property(nonatomic, strong, readonly) NSString *appPrice;

/// The domain. only for adx native
@property(nonatomic, strong, readonly) NSString *domain;

/// The warning. only for adx native
@property(nonatomic, strong, readonly) NSString *warning;

/// is it template ad
@property(nonatomic, assign, readonly) BOOL isExpressAd;

/**
 * For some ads, this property does not always determines whether the ad is a video ad or not; however, to do this, you can always use the corresponding ad view's isVideoContents method instead.
 */
@property(nonatomic, readonly, getter=isVideoContents) BOOL videoContents;

@property(nonatomic, assign ,readonly) BOOL isVideoAd;



- (instancetype)initWithAssets:(NSDictionary*)assets;

@end

NS_ASSUME_NONNULL_END
