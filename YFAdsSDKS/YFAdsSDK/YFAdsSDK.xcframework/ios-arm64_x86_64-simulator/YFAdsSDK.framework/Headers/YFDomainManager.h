//
//  YFDomainManager.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/10/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface YFDomainManager : NSObject
/// 请在子类中重写单例初始化
+ (instancetype)sharedInstance;


/// 初始化配置
-(void)initConfig;

/// 开始自检
-(void)startSelfCheck;

/// 开始轮询
//-(void)startPoll;

/// 停止自检以及轮询，外部请求成功的情况下调用
-(void)stopExecutingTask;


/// 子类需实现方法
-(NSArray *)subDomainArray;

///// 获取当前域名
//-(NSString *)currentDomain;
//
//-(void)setCurrentDomain;

-(NSString *)localDomainKey;
@property (nonatomic, strong) NSString *currentDomain;
@end

NS_ASSUME_NONNULL_END
