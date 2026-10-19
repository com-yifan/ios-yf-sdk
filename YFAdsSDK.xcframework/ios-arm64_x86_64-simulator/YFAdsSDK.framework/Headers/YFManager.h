//
//  YFNativeAdsManager.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFManager : NSObject

+(nonnull instancetype )sharedManager;
@property(nonatomic,copy)NSString * app_id;
+(void)setAppID:(NSString *)appID;
@end

NS_ASSUME_NONNULL_END
