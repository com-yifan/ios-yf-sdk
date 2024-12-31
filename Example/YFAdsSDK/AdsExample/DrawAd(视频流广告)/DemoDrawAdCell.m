//
//  DemoDrawAdCell.m
//  YFAdsSDK_Example
//
//  Created by jiangchao on 2024/1/13.
//  Copyright © 2024 Cheng455153666. All rights reserved.
//

#import "DemoDrawAdCell.h"
#import <YFAdsSDK/YFAdDrawView.h>

@interface DemoDrawAdCell ()

@property (nonatomic, weak) YFAdDrawView *drawAd;

@end

@implementation DemoDrawAdCell


- (void)refreshWithDrawAd:(YFAdDrawView *)drawAd {
    self.drawAd = drawAd;
//    NSLog(@"$$$$$registerView");
    [drawAd registerContainer:self.contentView];
}

- (void)prepareForReuse {
    [super prepareForReuse];
//    NSLog(@"$$$$$unregisterView");
    [self.drawAd unregisterView];
}

@end
