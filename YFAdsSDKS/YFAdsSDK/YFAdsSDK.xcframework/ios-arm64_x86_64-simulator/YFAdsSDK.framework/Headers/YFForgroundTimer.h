//
//  YFForgroundTimer.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/12/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFForgroundTimer : NSObject

@property (nonatomic, strong) dispatch_source_t timer;
@property (nonatomic, assign) NSInteger timeCount;       // 当前的倒计时秒数
@property (nonatomic, weak) id target;
@property (nonatomic, assign) SEL selector;
/// 触发的时间间隔，默认1秒
@property (nonatomic, assign) NSTimeInterval timeInterval;

- (instancetype)initWithTarget:(id)target selector:(SEL)selector;
- (void)startTimer;
- (void)stopTimer;
- (void)pauseTimer;
@end

NS_ASSUME_NONNULL_END
