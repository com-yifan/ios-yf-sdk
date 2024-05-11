//
//  YFTouchReportView.h
//  YFAdsSDK
//
//  Created by FC-0823 on 2023/10/31.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class YFTouchLocModel;
@class YFMaterialMeta;
@class YFAdEventModel;


@interface YFTouchLocModel : NSObject

///广告总宽度
@property(nonatomic, assign) NSInteger ad_width;

///广告总高度
@property(nonatomic, assign) NSInteger ad_height;

///手指按下x坐标
@property(nonatomic, assign) NSInteger down_x;

///手指按下y坐标
@property(nonatomic, assign) NSInteger down_y;

///手指离开x坐标
@property(nonatomic, assign) NSInteger up_x;

///手指离开y坐标
@property(nonatomic, assign) NSInteger up_y;

///触发时间戳：秒
@property(nonatomic, assign) NSTimeInterval timestamp;

///触发时间戳：毫秒
@property(nonatomic, assign) NSTimeInterval mtimestamp;

@property(nonatomic, assign) NSUInteger ecpm;

@property(nonatomic, copy) NSString * pID ;

@property(nonatomic, copy) NSString * req_id;

@property(nonatomic, copy) NSString * eKey;

-(instancetype)initWithModel:(YFMaterialMeta *)model;

@end

@interface YFTouchReportView : UIView

- (instancetype)initWithFrame:(CGRect)frame jumpType:(NSInteger)type;

///可点击控件数组(子控件)，只有点击在这些控件上才会上报
@property(nonatomic, strong) NSMutableArray<UIView *> *_Nonnull clickableViews;

///点击事件上报回调
@property(nonatomic, copy) void (^reportClickEvent)(YFTouchLocModel *model);


@end

NS_ASSUME_NONNULL_END
