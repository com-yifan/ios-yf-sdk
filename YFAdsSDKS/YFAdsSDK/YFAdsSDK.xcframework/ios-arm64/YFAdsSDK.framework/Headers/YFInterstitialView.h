//
//  YFInterstitialView.h
//  YFAdsSDK
//
//  Created by FC-0823 on 2023/11/1.
//

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YFAdInterstitialViewProtocol.h>
#import <YFAdsSDK/YFMaterialMeta.h>
#import <YFAdsSDK/YFAdReportWorker.h>

NS_ASSUME_NONNULL_BEGIN
@class YFAdInterstitialViewProtocol,YFMaterialMeta_new;

@interface YFInterstitialView : UIView

@property(nonatomic, weak) id<YFAdInterstitialViewProtocol> delegate;

@property (nonatomic, assign) BOOL autoClick;

@property (nonatomic, strong) YFAdReportWorker *reportWorker;

@property (nonatomic, strong) YFMaterialMeta_new *nativeAd;

@property (nonatomic, weak) UIViewController *viewController;

@property (nonatomic) BOOL hasExposed;

- (void)show;

@end

NS_ASSUME_NONNULL_END
