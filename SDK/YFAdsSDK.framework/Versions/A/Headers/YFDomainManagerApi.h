//
//  YFDomainManagerApi.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/10/30.
//

#import "YFDomainManager.h"

#define FC_CONF_URL [NSString stringWithFormat:@"http://%@/api/v2/ads/adsc",[[YFDomainManagerApi sharedInstance] currentDomain]]
#define YF_DATA_URL [NSString stringWithFormat:@"http://%@/api/v1/ads/app",[[YFDomainManagerApi sharedInstance] currentDomain]]


NS_ASSUME_NONNULL_BEGIN

@interface YFDomainManagerApi : YFDomainManager

@end
NS_ASSUME_NONNULL_END
