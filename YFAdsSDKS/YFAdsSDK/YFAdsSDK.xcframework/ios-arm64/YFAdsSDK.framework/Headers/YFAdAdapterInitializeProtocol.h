//
//  YFAdAdapterProtocol.h
//  YFAdsSDK
//
//  Created by Erik on 2025/3/7.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdAdapterInitializeContext.h>

//#ifndef YFAdAdapterInitializeProtocol
//#define YFAdAdapterInitializeProtocol YFAdAdapterInitializeProtocol

@protocol YFAdAdapterInitializeProtocol <NSObject>

@required
/// 联盟版本号
+ (NSString * _Nonnull)platformSDKVersion;
/// 联盟平台
+ (NSString * _Nonnull)platform;
/// 初始化SDK
+ (void)initializeSDKWithContext:(YFAdAdapterInitializeContext * _Nonnull)context completion:(void (^_Nullable)(BOOL success, NSError * _Nullable error))completion;

@end


//#endif 
