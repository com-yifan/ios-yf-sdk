//
//  YFAdapterDataModel.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2025/1/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdapterDataModel : NSObject
/**
 * 标题 text
 */
@property (copy, nonatomic) NSString *title;
/**
 * 描述 text
 */
@property (copy, nonatomic) NSString *text;
/**
 * 小图 url
 */
@property (copy, nonatomic) NSString *iconImageURLString;
/**
 * 大图 url
 */
@property (copy, nonatomic) NSString *mainImageURLString;

/**
 * 广告标识图标 url
 */
@property (copy, nonatomic) NSString *adLogoURLString;

/**
 * 联盟logo图标 url
 */
@property (copy, nonatomic) NSString *unionLogoURLString;

/**
 * 多图信息流的image url array
 */
@property (strong, nonatomic) NSArray *imageAry;
/**
 * 视频url
 */
@property (copy, nonatomic) NSString *videoURLString;
/**
 * 视频时长，单位为s
 */
@property (strong, nonatomic) NSNumber *videoDuration;

/**
 * 视频封面
 */
@property (copy, nonatomic) NSString *videoCover;

/**
 * 自动播放
 */
@property (strong, nonatomic) NSNumber *autoPlay;
/**
 * 品牌名称，若广告返回中无品牌名称则为空
 */
@property (copy, nonatomic) NSString *brandName;
///**
//* 开发者配置可接受视频后，对返回的广告单元，需先判断BaiduMobMaterialType再决定使用何种渲染组件
// */
@property (copy, nonatomic) NSString *materialType;

/**
 * 返回广告单元的点击类型
 */
@property (copy, nonatomic) NSString *actType;

/**
 * 大图图片宽
 */
@property (copy, nonatomic) NSString *w;
/**
 * 大图图片高
 */
@property (copy, nonatomic) NSString *h;
/**
 价格标签
 */
@property (copy, nonatomic) NSString *ECPMLevel;

///**
// 用户点击行为
// */
//@property (copy, nonatomic) NSString *actButtonString;

//// 发送视频广告相关日志
//@property (nonatomic, strong, readonly) BaiduMobAdNativeReporter *videoReport;

#pragma mark - 智能优选
///**
// 信息流广告样式类型
// */
//@property (nonatomic, assign) BaiduMobAdSmartFeedStyleType style_type;
///**
// 标记信息流广告容器宽高是px还是比例 0：无、1：像素、2：比例
// */
//@property (nonatomic, assign) BaiduMobAdSmartFeedSizeType size_type;
/**
 信息流广告容器宽
 */
@property (nonatomic, assign) int container_width;
/**
 信息流广告容器高
 */
@property (nonatomic, assign) int container_height;



/**
 * csj
 */
@property (copy, nonatomic) NSString *buttonText;
@property (nonatomic, assign) NSInteger videoHeight;
@property (nonatomic, assign) NSInteger videoWidth;

@property (nonatomic, strong) NSDictionary *ext;


#pragma mark =============== 聚合 ===============
/**
 * 聚合联盟中的ADN名
 */
@property (copy, nonatomic) NSString *subAdnName;
@end

NS_ASSUME_NONNULL_END
