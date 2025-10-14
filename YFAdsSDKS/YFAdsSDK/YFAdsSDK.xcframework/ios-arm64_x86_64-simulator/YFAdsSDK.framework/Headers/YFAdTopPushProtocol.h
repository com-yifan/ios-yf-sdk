//
//  YFAdTopPushProtocol.h
//  YFAdsSDK
//
//  Created by Erik on 2025/9/18.
//

@protocol YFAdTopPushProtocol <NSObject>
@required
/// 最上层控制器展示广告
- (void)showAdFromWindow;
@end
