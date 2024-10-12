//
//  YFAdBaseCustomView.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/10/7.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdBaseCustomView : UIView
@property(nonatomic,copy) void (^exposureBlk)(void);
-(void)destroyTrackTimer;
@end

NS_ASSUME_NONNULL_END
