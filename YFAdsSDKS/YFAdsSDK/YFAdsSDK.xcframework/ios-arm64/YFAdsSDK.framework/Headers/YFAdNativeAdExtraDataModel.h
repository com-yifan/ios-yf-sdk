//
//  YFAdNativeAdExtraDataModel.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdNativeAdExtraDataModel : NSObject
/// 是否开启摇一摇，false或者不赋值，不开启，true开启
@property (nonatomic, assign) BOOL enableShake;
@end

NS_ASSUME_NONNULL_END
