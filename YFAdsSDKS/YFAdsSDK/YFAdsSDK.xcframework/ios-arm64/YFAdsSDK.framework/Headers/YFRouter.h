//
//  YFAdUtils.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdReportWorker.h>
@class YFMaterialMeta_new;
@class YFAdEventModel;
@class UIViewController;
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
-(void)addRouterWith:(YFMaterialMeta_new *)model reportWorker:(YFAdReportWorker *)reportWorker event:(YFAdEventModel *)event manual:(BOOL)manual complete:(void (^)(YFRouterResult))success;
//  优先使用调用方传入的控制器打开落地页/Store页，避免多window场景下取错presenter
-(void)addRouterWith:(YFMaterialMeta_new *)model reportWorker:(YFAdReportWorker *)reportWorker event:(YFAdEventModel *)event manual:(BOOL)manual viewController:(nullable UIViewController *)viewController complete:(void (^)(YFRouterResult))success;

-(void)addRouterWith:(YFMaterialMeta_new *)model reportWorker:(YFAdReportWorker *)reportWorker complete:(void (^)(YFRouterResult))success;

@end

NS_ASSUME_NONNULL_END
