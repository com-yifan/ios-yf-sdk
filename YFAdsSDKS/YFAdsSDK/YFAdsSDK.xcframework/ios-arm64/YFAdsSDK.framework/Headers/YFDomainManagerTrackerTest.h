//
//  YFDomainManagerTrackerTest.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/10/30.
//

#import <YFAdsSDK/YFDomainManager.h>
#define FC_UPLOAD_URL_TEST [NSString stringWithFormat:@"http://%@/api/v2/ads/batchUpload",[[YFDomainManagerTrackerTest sharedInstance] currentDomain]]

NS_ASSUME_NONNULL_BEGIN

@interface YFDomainManagerTrackerTest : YFDomainManager

@end
NS_ASSUME_NONNULL_END
