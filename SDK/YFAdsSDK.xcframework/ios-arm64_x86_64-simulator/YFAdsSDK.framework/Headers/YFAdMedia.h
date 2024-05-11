//
//  YFAdParameterModel.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>
#import "YFAdInteractionType.h"
#import "YFAdImage.h"
#import "YFAdBaseAdapter.h"
#import "YFAdNative.h"

@class YFAdMediaMetal;

NS_ASSUME_NONNULL_BEGIN

@protocol YFAdMediaDelegate;

@interface YFAdMedia : NSObject

@property (nonatomic, strong, readonly) YFAdNative *data;

@property (nonatomic, strong) UIView *mediaView;

/**
 The delegate for receiving state change messages.
 The delegate is not limited to viewcontroller.
 The delegate can be set to any object which conforming to <YFAdMediaDelegate>.
 */
@property (nonatomic, weak, readwrite, nullable) id<YFAdMediaDelegate> delegate;

/**
 required.
 Root view controller for handling ad actions.
 Action method includes 'pushViewController' and 'presentViewController'.
 */
@property (nonatomic, weak, readwrite) UIViewController *rootViewController;

/**
 Register clickable views in native ads view.
 Interaction types can be configured on TikTok Audience Network.
 Interaction types include view video ad details page, make a call, send email, download the app, open the webpage using a browser,open the webpage within the app, etc.
 @param containerView : required.
 container view of the native ad.
 @param clickableViews : optional.
 Array of views that are clickable.
 */
- (void)registerContainer:(UIView *)containerView withClickableViews:(NSArray<UIView *> *_Nullable)clickableViews;

/**
 Unregister ad view from the native ad.
 */
- (void)unregisterView;

/// set mute  YES no sound
- (void)muteEnable:(BOOL)enable;

- (id)initWithObject:(id)object adNative:(id)adNative adapter:(YFAdBaseAdapter *)adapter;

- (id)initWithObject:(id)object adNative:(id)adNative ksView:(UIView *)view adapter:(YFAdBaseAdapter *)adapter;

@end



@protocol YFAdMediaDelegate <NSObject>

@optional



@end

NS_ASSUME_NONNULL_END
