//
//  BaseViewController.h
//  Example
//
//  Created by CherryKing on 2019/12/20.
//  Copyright © 2019 CherryKing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JDStatusBarNotification.h"
#import <YFAdsSDK/YFAdBaseAdPosition.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    AdState_Normal,// 未加载
    AdState_Loading,// 加载中
    AdState_LoadSucceed,// 加载成功
    AdState_LoadFailed,// 加载失败
} AdState;

@interface DemoBaseViewController : UIViewController
@property (nonatomic, strong) NSDictionary *dic;
@property (nonatomic, assign) BOOL isOnlyLoad;
@property (nonatomic, assign) BOOL isLoaded;
@property (nonatomic, strong) UITextView *textV;
@property (nonatomic, strong) UIButton *btnLoad;
@property (nonatomic, strong) UIButton *btnShow;
@property (nonatomic, strong) UIButton *btnLoadAndShow;
@property (nonatomic, strong) UILabel *labNotify;

- (void)loadAd;

- (void)showAd;

- (void)loadAndShowAd;

-(void)changeVC;

- (void)deallocAd;

- (void)loadAdWithState:(AdState)state;

- (void)showProcessWithText:(NSString *)text;

- (void)clearText;

- (void)showErrorWithDescription:(NSDictionary *)description;

- (NSString *)getSianKeyWithDic:(NSDictionary *)dic;

- (void)generateEarlyReturn;

@end

NS_ASSUME_NONNULL_END
