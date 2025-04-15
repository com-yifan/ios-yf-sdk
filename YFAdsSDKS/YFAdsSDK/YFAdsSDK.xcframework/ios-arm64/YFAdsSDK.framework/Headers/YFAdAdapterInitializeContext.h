//
//  YFAdAdapterInitializeContext.h
//  YFAdsSDK
//
//  Created by Erik on 2025/3/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//#ifndef YFAdAdapterInitializeContext
//#define YFAdAdapterInitializeContext YFAdAdapterInitializeContext

@interface YFAdAdapterInitializeContext : NSObject

@property (nonatomic, copy) NSString *appid;

@property (nonatomic, copy) NSString *appkey;

@property (nonatomic, copy) NSString *platform;

@property (nonatomic, copy) NSString *wxAppId;

@property (nonatomic, copy) NSString *universalLink;

@end

//#endif

NS_ASSUME_NONNULL_END
