//
//  YFAdAuthModel.h
//  YFAdsSDK
//
//  Created by Erik on 2026/6/17.
//

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YFAdReportModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFAdAuthModel : NSObject<NSCopying>

@property (nonatomic, assign) NSInteger cuaid;
@property (nonatomic, assign) NSInteger cul;
@property (nonatomic, assign) NSInteger cuo;
@property (nonatomic, assign) NSInteger cuw;
@property (nonatomic, assign) NSInteger lp;
@property (nonatomic, assign) NSInteger aipa;
@property (nonatomic, assign) NSInteger adi;
@property (nonatomic, assign) NSInteger aas;

+ (instancetype)initWithAdnType:(YFAdnType)adnType;
- (void)reportEvent;

@end

NS_ASSUME_NONNULL_END
