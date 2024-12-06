//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//



#import <YFAdsSDK/YFAdBaseDelegate.h>
@class YFAdMedia;

@protocol YFAdMediaDelegate <YFAdBaseDelegate>
@optional
/**
 This method is called when native ad  render  success
 */
- (void)mediaAdRenderSuccess:(YFAdMedia *)mediaAd;
/**
 This method is called when native ad  render  fail
 */
- (void)mediaAdRenderFail:(YFAdMedia *)mediaAd;
/**
 This method is called when native ad is clicked.
 */
- (void)mediaAdDidClick:(YFAdMedia *)mediaAd;
/**
 This method is called when native ad play finished.
 */
- (void)mediaAdVideoPlayFinished:(YFAdMedia *)mediaAd;


@end


