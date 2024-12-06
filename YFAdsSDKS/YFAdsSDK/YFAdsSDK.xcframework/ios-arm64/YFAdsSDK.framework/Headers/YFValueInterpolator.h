//
//  YFValueInterpolator.h
//  Pods
//
//  Created by brandon_withrow on 7/10/17.
//
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFKeyframe.h>
#import <YFAdsSDK/YFValueDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFValueInterpolator : NSObject

- (instancetype)initWithKeyframes:(NSArray <YFKeyframe *> *)keyframes;

@property (nonatomic, weak, nullable) YFKeyframe *leadingKeyframe;
@property (nonatomic, weak, nullable) YFKeyframe *trailingKeyframe;
@property (nonatomic, readonly) BOOL hasDelegateOverride;

- (void)setValueDelegate:(id<YFValueDelegate> _Nonnull)delegate;

- (BOOL)hasUpdateForFrame:(NSNumber *)frame;
- (CGFloat)progressForFrame:(NSNumber *)frame;

@end

NS_ASSUME_NONNULL_END
