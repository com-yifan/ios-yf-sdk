//
//  YFTouchReportView.h
//  YFAdsSDK
//
//  Created by FC-0823 on 2023/10/31.
//
#import <CoreMotion/CoreMotion.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@class YFTouchLocModel;
@class YFMaterialMeta;
@class YFAdEventModel;

typedef NS_ENUM(NSInteger, YFInteractionType){
    ///        0-未知
    YFInteractionTypeUnknow = 0,
    ///        1-正常点击
    YFInteractionTypeClick = 1,
    ///        2-摇一摇
    YFInteractionTypeShake = 2,
    ///        3-扭一扭
    YFInteractionTypeRolling = 3,
    ///        4-滑动
    YFInteractionTypeMove = 4,
//    ///        5-擦除
//    YFInteractionTypeErasure = 5,
//    ///        7：横竖屏
//    YFInteractionTypeRotation = 7,
//    ///        11-自定义手势
//    YFInteractionTypeCustomGesture = 11,
    ///跳过
    YFInteractionTypeSkip = 9,

    ///        曝光
    YFInteractionTypeExposure = 21,
    ///    视频进度
    YFInteractionTypeVideoProcess = 22,
};
@interface YFTouchLocModel : NSObject

/// sld取值。key只取范围：click（常规点击）,rolling(扭一扭), shake（摇一摇）,move（滑动点击），erasure(擦除)。举例：{”click“: {"value":"0", "default":"-999"}, "move":{"value":"1",default:"-999"}, "shake":{"value":"2"}, "rolling": {"value": "5"},"erasure"： {"value":"6"}}
///        map[string]Object{
///            value string; //sld取值
///            default string;//取值无法获取时，填写的默认值；例如”-999“.当无此字段或者空值的时候，不需要使用默认值进行替换。
///        }
/**
{
    "click": {
        "value": "0",
        "default": "-999"
    },
    "move": {
        "value": "1",
        "default": "-999"
    },
    "shake": {
        "value": "2"
    },
    "rolling": {
        "value": "5"
    },
    "erasure": {
        "value": "6"
    }
}
*/
@property (nonatomic, copy) NSDictionary *sld;


/// 交互方式
@property (nonatomic, assign) YFInteractionType interactionType;

/// 触发摇一摇的数据
@property (nonatomic, copy) CMAccelerometerData * _Nullable accelerometerData;

/// 触发扭一扭的数据
@property (nonatomic, copy) CMDeviceMotion * _Nullable motion;

///广告x坐标
@property(nonatomic, assign) NSInteger ad_x;

///广告y坐标
@property(nonatomic, assign) NSInteger ad_y;

///广告总宽度
@property(nonatomic, assign) NSInteger ad_width;

///广告总高度
@property(nonatomic, assign) NSInteger ad_height;

///广告视图宽度
@property(nonatomic, assign) NSInteger ad_w;

///广告视图高度
@property(nonatomic, assign) NSInteger ad_h;

///手指按下x坐标
@property(nonatomic, assign) NSInteger down_x;

///手指按下y坐标
@property(nonatomic, assign) NSInteger down_y;

///手指离开x坐标
@property(nonatomic, assign) NSInteger up_x;

///手指离开y坐标
@property(nonatomic, assign) NSInteger up_y;

///广告x坐标  相对屏幕
@property(nonatomic, assign) NSInteger ad_window_x;

///广告y坐标 相对屏幕
@property(nonatomic, assign) NSInteger ad_window_y;

///手指按下x坐标(相对屏幕)
@property(nonatomic, assign) NSInteger down_window_x;

///手指按下y坐标(相对屏幕)
@property(nonatomic, assign) NSInteger down_window_y;

///手指离开x坐标(相对屏幕)
@property(nonatomic, assign) NSInteger up_window_x;

///手指离开y坐标(相对屏幕)
@property(nonatomic, assign) NSInteger up_window_y;

///曝光时间戳
@property (nonatomic, assign) NSTimeInterval exposure_timestamp;

///手指按下的时间戳
@property (nonatomic, assign) NSTimeInterval down_timestamp;

///手指抬起的时间戳
@property (nonatomic, assign) NSTimeInterval up_timestamp;

///触发时间戳：秒
@property(nonatomic, assign) NSTimeInterval timestamp;

///触发时间戳：毫秒
@property(nonatomic, assign) NSTimeInterval mtimestamp;

@property(nonatomic, assign) NSUInteger ecpm;

@property(nonatomic, copy) NSString * deep_link;

@property(nonatomic, copy) NSArray *dUrl;

@property(nonatomic, copy) NSString * pID ;

@property(nonatomic, copy) NSString * req_id;

@property(nonatomic, copy) NSString *ua;

@property(nonatomic, copy) NSString * eKey;

-(instancetype)initWithModel:(YFMaterialMeta *)model;

@end

@interface YFTouchReportView : UIView

- (instancetype)initWithFrame:(CGRect)frame jumpType:(NSInteger)type model:(nullable YFMaterialMeta *)model;

///可点击控件数组(子控件)，只有点击在这些控件上才会上报
@property(nonatomic, strong) NSMutableArray<UIView *> *_Nonnull clickableViews;

///点击事件上报回调
@property(nonatomic, copy) void (^reportClickEvent)(YFTouchLocModel *model);

/// 上报点击
- (void)reportEventWithPoint:(CGPoint)location pointInWindow:(CGPoint)locationInWindow;

@end

NS_ASSUME_NONNULL_END
