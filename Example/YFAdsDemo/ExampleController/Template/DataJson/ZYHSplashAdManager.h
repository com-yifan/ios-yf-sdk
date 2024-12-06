//
//  ZSplashAdManager.h
//  Volunteer
//
//  Created by liwei sun on 2024/3/7.
//  Copyright © 2024 Hangzhou Yicun Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZYHSplashAdManager : NSObject

+ (instancetype)sharedManager;

@property(nonatomic, assign)BOOL show;
/// 使用App的keyWindow
@property(nonatomic, strong)UIWindow * window;

-(void)initAdSDK;

@end

NS_ASSUME_NONNULL_END
