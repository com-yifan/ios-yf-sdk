//
//  YFSerialQueue.h
//  YFAdsSDK
//
//  Created by 麻明康 on 2024/11/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFSerialQueue : NSObject
#define dispatch_yf_serial_async_safe(block)\
    if ([[YFSerialQueue sharedInstance] isCurrentQueueSerialQueue]) {\
        block();\
    } else {\
        dispatch_async([YFSerialQueue sharedInstance].serialQueue, block);\
    }
#define dispatch_yf_report_async_safe(block)\
    if ([[YFSerialQueue sharedInstance] isCurrentQueueReportQueue]) {\
        block();\
    } else {\
        dispatch_async([YFSerialQueue sharedInstance].reportQueue, block);\
    }
+ (instancetype)sharedInstance ;
@property (nonatomic, strong) dispatch_queue_t serialQueue;
@property (nonatomic, strong) dispatch_queue_t reportQueue;
- (BOOL)isCurrentQueueSerialQueue;
- (BOOL)isCurrentQueueReportQueue;

@end

NS_ASSUME_NONNULL_END
