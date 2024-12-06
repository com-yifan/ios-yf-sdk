//
//  YFDomainManagerApiTest.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/10/30.
//

#import <YFAdsSDK/YFDomainManager.h>
#define FC_CONF_URL_TEST [NSString stringWithFormat:@"http://%@/api/v2/ads/adsc",[[YFDomainManagerApiTest sharedInstance] currentDomain]]
#define YF_DATA_URL_TEST [NSString stringWithFormat:@"http://%@/api/v1/ads/app",[[YFDomainManagerApiTest sharedInstance] currentDomain]]


NS_ASSUME_NONNULL_BEGIN

@interface YFDomainManagerApiTest : YFDomainManager

@end
NS_ASSUME_NONNULL_END
