//
//  YFGlobalMotionModel.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/10/23.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFGlobalMotionActionHandler.h>
#import <YFAdsSDK/YFAdReportModel.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFGlobalMotionModel : NSObject
+(instancetype)modelWithView:(UIView <YFGlobalMotionActionHandler>*)motionView model:(YFAdEventModel *)eventModel;

@property (nonatomic, weak) UIView <YFGlobalMotionActionHandler>*view;
@property (nonatomic, weak) UIScrollView *scrollView;
@property (nonatomic, strong) NSMutableArray *observedArray;
@property (nonatomic, weak) YFAdEventModel *eventModel;
@property (nonatomic) BOOL triggered;
@property (nonatomic) BOOL superViewBeObserved;
@end

NS_ASSUME_NONNULL_END
