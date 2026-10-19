//
//  YFAdTextLinkProtocol.h
//  YFAdsSDK
//
//  Created by Codex on 2026/4/9.
//

@class YFAdTextLinkView;

@protocol YFAdTextLinkProtocol <NSObject>

@required
/// 返回当前可展示的文字链视图
- (nullable YFAdTextLinkView *)adView;

@end
