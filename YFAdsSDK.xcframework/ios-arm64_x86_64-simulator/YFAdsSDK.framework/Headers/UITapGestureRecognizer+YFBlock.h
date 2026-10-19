#import <UIKit/UIKit.h>
#import <objc/runtime.h>

static void *TapGestureBlockKey = &TapGestureBlockKey;

@interface UITapGestureRecognizer (YFBlock)

@property (nonatomic, copy) void (^tapAction)(void);

@end
