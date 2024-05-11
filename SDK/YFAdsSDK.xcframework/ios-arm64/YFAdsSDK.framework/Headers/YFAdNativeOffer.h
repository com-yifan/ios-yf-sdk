//
//  YFAdNativeOffer.h
//  AnyThinkNative
//
//  Created by Topon on 10/27/21.
//  Copyright © 2021 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YFAdNative.h"
#import "YFAdNativePrepareInfo.h"


NS_ASSUME_NONNULL_BEGIN

@class YFAdNativeView;
@class YFAdNativeConfiguration;

@interface YFAdNativeOffer : NSObject
/**
 * The native ad that is being shown.
 */
@property(nonatomic, readonly) YFAdNative *nativeAd;
/**
 * The networkFirm id of native ad.
 */
@property(nonatomic, readonly) NSInteger networkFirmID;
/**
 * The adOffer info of native ad.
 */
@property(nonatomic, readonly) NSDictionary *adOfferInfo;


- (void)rendererWithConfiguration:(YFAdNativeConfiguration*)configuration selfRenderView:(UIView *)selfRenderView nativeADView:(YFAdNativeView *)nativeADView;


@end

NS_ASSUME_NONNULL_END
