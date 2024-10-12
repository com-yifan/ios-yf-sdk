//
//  YFWeakProxy.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/9/27.
//

#import <Foundation/Foundation.h>

@interface YFWeakProxy : NSProxy

@property (nonatomic, weak, readonly, nullable) id target;

- (nonnull instancetype)initWithTarget:(nonnull id)target;
+ (nonnull instancetype)proxyWithTarget:(nonnull id)target;

@end
