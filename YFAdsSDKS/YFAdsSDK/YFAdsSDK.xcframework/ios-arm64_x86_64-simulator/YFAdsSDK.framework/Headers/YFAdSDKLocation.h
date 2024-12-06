//
//  YFAdDataCenterManager.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdSDKSetting.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdSDKLocation : NSObject

+ (instancetype)shareInstance;

- (void)startLocationUpdatesWithCompletion:(void (^)(CLLocation *location, NSError *error))completion;

@end

NS_ASSUME_NONNULL_END
