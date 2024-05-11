

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YFAdDownloader.h"

typedef NS_OPTIONS(NSUInteger, YFLaunchAdImageOptions) {
    /** 有缓存,读取缓存,不重新下载,没缓存先下载,并缓存 */
    YFLaunchAdImageDefault = 1 << 0,
    /** 只下载,不缓存 */
    YFLaunchAdImageOnlyLoad = 1 << 1,
    /** 先读缓存,再下载刷新图片和缓存 */
    YFLaunchAdImageRefreshCached = 1 << 2 ,
    /** 后台缓存本次不显示,缓存OK后下次再显示(建议使用这种方式)*/
    YFLaunchAdImageCacheInBackground = 1 << 3
};

typedef void(^YFExternalCompletionBlock)(UIImage * _Nullable image,NSData * _Nullable imageData, NSError * _Nullable error, NSURL * _Nullable imageURL);

@interface YFAdImageManager : NSObject

+(nonnull instancetype )sharedManager;
- (void)loadImageWithURL:(nullable NSURL *)url options:(YFLaunchAdImageOptions)options progress:(nullable YFLaunchAdDownloadProgressBlock)progressBlock completed:(nullable YFExternalCompletionBlock)completedBlock;

@end
