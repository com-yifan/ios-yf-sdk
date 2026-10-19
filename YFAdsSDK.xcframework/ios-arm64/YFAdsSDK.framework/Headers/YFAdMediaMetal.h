//
//  YFAdParameterModel.h
//  YFAdsSDK
//
//  Created by aiken on 2023/5/9.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdInteractionType.h>
#import <YFAdsSDK/YFAdImage.h>
NS_ASSUME_NONNULL_BEGIN

@interface YFAdMediaMetal : NSObject
/// ⼴告⽀持的交互类型
@property (nonatomic, assign) YFAdInteractionType interactionType;
/// material pictures.
@property (nonatomic, strong) NSArray<YFAdImage *> *imageArray;
/// ad source.
@property (nonatomic, copy) NSString *adSource;

@property (nonatomic, copy) NSString *adLogo;

@property (nonatomic, copy) NSString *appIconImage;
/// 0-5
@property (nonatomic, assign) CGFloat appScore;
/// ad title.
@property (nonatomic, copy) NSString *adTitle;
/// ad description.
@property (nonatomic, copy) NSString *adDescription;
/// text displayed on the creative button.
@property (nonatomic, copy) NSString *actionDescription;
// video duration
@property (nonatomic, assign) NSInteger videoDuration;

@property (nonatomic, copy) NSString *videoCoverImage;

@property (nonatomic, copy) NSString *videoUrl;
// app name
@property (nonatomic, copy) NSString *appName;
// product name (for h5)
@property (nonatomic, copy) NSString *productName;

@property (nonatomic, copy) NSString *imageUrl;

@property (nonatomic, copy) NSString *ecpm;

-(instancetype)initWithObect:(id)object;

@end

NS_ASSUME_NONNULL_END
