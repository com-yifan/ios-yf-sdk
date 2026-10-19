//
//  YFAdSplashAdExtraDataModel.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdSplashAdExtraDataModel : NSObject
/// 是否屏蔽摇一摇，false或者不赋值，不屏蔽，true屏蔽
@property (nonatomic, assign) BOOL disableShake;
/// 是否屏蔽扭一扭，false或者不赋值，不屏蔽，true屏蔽
@property (nonatomic, assign) BOOL disableRotate;
/// 是否屏蔽手势滑动转化，false或者不赋值，不屏蔽，true屏蔽
@property (nonatomic, assign) BOOL disableSlide;
@end

NS_ASSUME_NONNULL_END
