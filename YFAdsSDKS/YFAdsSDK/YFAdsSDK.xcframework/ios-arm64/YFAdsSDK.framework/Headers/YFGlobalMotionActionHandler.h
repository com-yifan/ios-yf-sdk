//
//  YFGlobalMotionActionHandler.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/10/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, YFGlobalMotionViewStatus){
    
    YFGlobalMotionViewStatusNotAdded = 0,
    
    YFGlobalMotionViewStatusAdded,
};
@protocol YFGlobalMotionActionHandler <NSObject>

/// 处理摇一摇事件响应
-(void)yf_globalMotionActionHandler;

-(YFGlobalMotionViewStatus)getViewStatus;
@end

NS_ASSUME_NONNULL_END
