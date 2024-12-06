//
//  DemoInterstitialViewController.h
//  advancelib
//
//  Created by allen on 2019/12/31.
//  Copyright © 2019 Bayescom. All rights reserved.
//

#import "BaseViewController.h"

#import <UIKit/UIKit.h>
#import "DemoNativeSelfRenderView.h"

NS_ASSUME_NONNULL_BEGIN

@interface DemoMediaRenderDetailViewController : UIViewController

- (instancetype)initWithAdView:(DemoNativeSelfRenderView *)adView offer:(YFAdMedia *)offer;

@end

NS_ASSUME_NONNULL_END
