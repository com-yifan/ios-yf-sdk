//
//  YFAdUtils.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>
@class YFMaterialMeta;
@class YFAdEventModel;
NS_ASSUME_NONNULL_BEGIN

@interface YFRouter : NSObject
typedef NS_ENUM(NSInteger, YFRouterResult){
    
    YFRouterResultFail = 0,
    
    YFRouterResultTypeDeepLink = 1,
    
    YFRouterResultTypeAppstore = 2,

    YFRouterResultTypeDurl = 3,
    // 详情
    YFRouterResultTypeDetail = 4,
    // 微信小程序
    YFRouterResultTypeWXMiniParam = 5
};
///  是否是 手动点击 manual YES 手动点击事件  NO 自动点击事件
+ (instancetype)shareInstance;
//  是否是 手动点击 manual YES 手动点击事件  NO 自动点击事件
-(void)addRouterWith:(YFMaterialMeta *)model event:(YFAdEventModel *)event manual:(BOOL)manual complete:(void (^)(YFRouterResult))success;

-(void)addRouterWith:(YFMaterialMeta *)model complete:(void (^)(YFRouterResult))success;

@end

NS_ASSUME_NONNULL_END
