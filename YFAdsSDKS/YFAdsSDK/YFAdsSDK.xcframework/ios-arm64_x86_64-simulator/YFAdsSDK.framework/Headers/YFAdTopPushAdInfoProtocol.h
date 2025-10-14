//
//  YFAdTopPushProtocol.h
//  YFAdsSDK
//
//  Created by Erik on 2025/9/18.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdReportModel.h>
// 顶推广告数据协议
@protocol YFAdTopPushAdInfoProtocol <NSObject>
- (NSString * _Nullable)iconUrl;
- (NSString * _Nullable)title;
- (NSString * _Nullable)desc;
- (NSString * _Nullable)imageUrl;
- (NSString * _Nullable)videoUrl;
- (YFAdEventModel * _Nonnull)eventModel;
- (BOOL)isVideoAd;
@end
