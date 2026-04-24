//
//  YFAdTextLinkAdInfoProtocol.h
//  YFAdsSDK
//
//  Created by Codex on 2026/4/9.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdReportModel.h>

/// 文字链广告数据协议
@protocol YFAdTextLinkAdInfoProtocol <NSObject>

- (NSString * _Nullable)iconUrl;
- (NSString * _Nullable)text;
- (YFAdEventModel * _Nonnull)eventModel;
- (void)feedBackAd;


@end
