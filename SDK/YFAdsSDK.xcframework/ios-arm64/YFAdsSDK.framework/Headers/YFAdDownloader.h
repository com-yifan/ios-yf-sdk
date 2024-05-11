

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^YFLaunchAdDownloadProgressBlock)(unsigned long long total, unsigned long long current);

typedef void(^YFLaunchAdDownloadImageCompletedBlock)(UIImage *_Nullable image, NSData * _Nullable data, NSError * _Nullable error);

typedef void(^YFLaunchAdDownloadVideoCompletedBlock)(NSURL * _Nullable location, NSError * _Nullable error);

typedef void(^YFLaunchAdBatchDownLoadAndCacheCompletedBlock) (NSArray * _Nonnull completedArray);

@protocol YFLaunchAdDownloadDelegate <NSObject>

- (void)downloadFinishWithURL:(nonnull NSURL *)url;

@end

@interface YFLaunchAdDownload : NSObject
@property (assign, nonatomic ,nonnull)id<YFLaunchAdDownloadDelegate> delegate;
@end

@interface YFLaunchAdImageDownload : YFLaunchAdDownload

@end

@interface YFLaunchAdVideoDownload : YFLaunchAdDownload

@end

@interface YFAdDownloader : NSObject

+(nonnull instancetype )sharedDownloader;

- (void)downloadImageWithURL:(nonnull NSURL *)url progress:(nullable YFLaunchAdDownloadProgressBlock)progressBlock completed:(nullable YFLaunchAdDownloadImageCompletedBlock)completedBlock;

- (void)downLoadImageAndCacheWithURLArray:(nonnull NSArray <NSURL *> * )urlArray;
- (void)downLoadImageAndCacheWithURLArray:(nonnull NSArray <NSURL *> * )urlArray completed:(nullable YFLaunchAdBatchDownLoadAndCacheCompletedBlock)completedBlock;

- (void)downloadVideoWithURL:(nonnull NSURL *)url progress:(nullable YFLaunchAdDownloadProgressBlock)progressBlock completed:(nullable YFLaunchAdDownloadVideoCompletedBlock)completedBlock;

- (void)downLoadVideoAndCacheWithURLArray:(nonnull NSArray <NSURL *> * )urlArray;
- (void)downLoadVideoAndCacheWithURLArray:(nonnull NSArray <NSURL *> * )urlArray completed:(nullable YFLaunchAdBatchDownLoadAndCacheCompletedBlock)completedBlock;

@end

