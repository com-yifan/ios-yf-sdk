//
//  YFAdAdapterInitializeClassLoader.h
//  YFAdsSDK
//
//  Created by Erik on 2025/3/7.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdAdapterInitializeProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdAdapterInitializeClassLoader : NSObject

+ (NSArray<NSString *> *)allPlatforms;

+ (void)registPlatformClass:(Class<YFAdAdapterInitializeProtocol>)klass forSdkName:(NSString *)sdkName;

+ (Class<YFAdAdapterInitializeProtocol>)platformClassForSdkName:(NSString *)sdkName;

@end

NS_ASSUME_NONNULL_END
