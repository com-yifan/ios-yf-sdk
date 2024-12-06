//
//  YFDomainManagerTracker.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/10/30.
//

#import <YFAdsSDK/YFDomainManager.h>

#define FC_UPLOAD_URL [NSString stringWithFormat:@"http://%@/api/v2/ads/batchUpload",[[YFDomainManagerTracker sharedInstance] currentDomain]]

NS_ASSUME_NONNULL_BEGIN

@interface YFDomainManagerTracker : YFDomainManager

@end
NS_ASSUME_NONNULL_END
