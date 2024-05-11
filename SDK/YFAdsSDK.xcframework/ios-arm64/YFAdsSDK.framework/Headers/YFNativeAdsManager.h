//
//  YFNativeAdsManager.h
//  YFAdsSDK
//
//  Created by feng on 2023/10/20.
//

#import <Foundation/Foundation.h>
#import "YFNativeAd.h"
#import "YFAdNativeAdExtraDataModel.h"


NS_ASSUME_NONNULL_BEGIN
@protocol YFNativeAdsManagerDelegate;

@interface YFNativeAdsManager : NSObject
@property(nonatomic, strong, nullable) NSArray<YFNativeAd *> *data;
/// The delegate for receiving state change messages such as requests succeeding/failing.
@property(nonatomic, weak, nullable) id <YFNativeAdsManagerDelegate> delegate;

- (id)initWithPosId:(NSString *)posId;

/**
 The number of ads requested,The maximum is 5
 */
- (void)loadAdDataWithCount:(NSInteger)count;
/**
 server bidding load ad data plan 2
 */
//- (void)loadAdDataWithResponseV2:(NSDictionary *)response;

- (void)setExtraData:(YFAdNativeAdExtraDataModel *)extraDataModel;
@end

@protocol YFNativeAdsManagerDelegate <NSObject>

@optional

- (void)nativeAdsManagerSuccessToLoad:(YFNativeAdsManager *)adsManager nativeAds:(NSArray<YFNativeAd *> *_Nullable)nativeAdDataArray;

- (void)nativeAdsManager:(YFNativeAdsManager *)adsManager didFailWithError:(NSError *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
