//
//  YFInterstitialView.h
//  YFAdsSDK
//
//  Created by FC-0823 on 2023/11/1.
//

#import <UIKit/UIKit.h>
#import "YFAdInterstitialViewProtocol.h"
#import "YFMaterialMeta.h"

NS_ASSUME_NONNULL_BEGIN
@class YFAdInterstitialViewProtocol,YFMaterialMeta;

@interface YFInterstitialView : UIView

@property(nonatomic, weak) id<YFAdInterstitialViewProtocol> delegate;

@property (nonatomic, assign) BOOL autoClick;

@property (nonatomic, strong) YFMaterialMeta *nativeAd;

@property (nonatomic, weak) UIViewController *viewController;

-(instancetype)initWithFrame:(CGRect)frame model:(id)model;

- (void)show;

@end

NS_ASSUME_NONNULL_END
