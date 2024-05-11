

#import <UIKit/UIKit.h>


#define XHWeakSelf __weak typeof(self) weakSelf = self;

//#define XH_IPHONEX  ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
//#define XH_IPHONEXR    ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) : NO)
//#define XH_IPHONEXSMAX    ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) : NO)
//#define XH_FULLSCREEN ((XH_IPHONEX || XH_IPHONEXR || XH_IPHONEXSMAX) ? YES : NO)
//

//#define XHISURLString(string)  ([string hasPrefix:@"https://"] || [string hasPrefix:@"http://"]) ? YES:NO
//#define XHStringContainsSubString(string,subString)  ([string rangeOfString:subString].location == NSNotFound) ? NO:YES

#ifdef DEBUG
#define JQLaunchAdLog(FORMAT, ...) fprintf(stderr,"%s:%d\t%s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define JQLaunchAdLog(...)
#endif

#define XHISGIFTypeWithData(data)\
({\
BOOL result = NO;\
if(!data) result = NO;\
uint8_t c;\
[data getBytes:&c length:1];\
if(c == 0x47) result = YES;\
(result);\
})

#define XHISVideoTypeWithPath(path)\
({\
BOOL result = NO;\
if([path hasSuffix:@".mp4"])  result =  YES;\
(result);\
})

//#define DISPATCH_SOURCE_CANCEL_SAFE(time) if(time)\
//{\
//dispatch_source_cancel(time);\
//time = nil;\
//}
//
//#define REMOVE_FROM_SUPERVIEW_SAFE(view) if(view)\
//{\
//[view removeFromSuperview];\
//view = nil;\
//}
UIKIT_EXTERN NSString *const XHCacheImageUrlStringKey;
UIKIT_EXTERN NSString *const XHCacheVideoUrlStringKey;
/** 视频播放失败通知 */
UIKIT_EXTERN NSString *const JQLaunchAdVideoPlayFailedNotification;



