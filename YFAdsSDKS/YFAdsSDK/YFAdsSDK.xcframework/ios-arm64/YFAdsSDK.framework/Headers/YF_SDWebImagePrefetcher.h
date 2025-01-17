/*
 * This file is part of the YF_SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import <YFAdsSDK/YF_SDWebImageManager.h>

@class YF_SDWebImagePrefetcher;

@protocol YF_SDWebImagePrefetcherDelegate <NSObject>

@optional

/**
 * Called when an image was prefetched.
 *
 * @param imagePrefetcher The current image prefetcher
 * @param imageURL        The image url that was prefetched
 * @param finishedCount   The total number of images that were prefetched (successful or not)
 * @param totalCount      The total number of images that were to be prefetched
 */
- (void)imagePrefetcher:(YF_SDWebImagePrefetcher *)imagePrefetcher didPrefetchURL:(NSURL *)imageURL finishedCount:(NSUInteger)finishedCount totalCount:(NSUInteger)totalCount;

/**
 * Called when all images are prefetched.
 * @param imagePrefetcher The current image prefetcher
 * @param totalCount      The total number of images that were prefetched (whether successful or not)
 * @param skippedCount    The total number of images that were skipped
 */
- (void)imagePrefetcher:(YF_SDWebImagePrefetcher *)imagePrefetcher didFinishWithTotalCount:(NSUInteger)totalCount skippedCount:(NSUInteger)skippedCount;

@end

typedef void(^YF_SDWebImagePrefetcherProgressBlock)(NSUInteger noOfFinishedUrls, NSUInteger noOfTotalUrls);
typedef void(^YF_SDWebImagePrefetcherCompletionBlock)(NSUInteger noOfFinishedUrls, NSUInteger noOfSkippedUrls);

/**
 * Prefetch some URLs in the cache for future use. Images are downloaded in low priority.
 */
@interface YF_SDWebImagePrefetcher : NSObject

/**
 *  The web image manager
 */
@property (strong, nonatomic, readonly) YF_SDWebImageManager *manager;

/**
 * Maximum number of URLs to prefetch at the same time. Defaults to 3.
 */
@property (nonatomic, assign) NSUInteger maxConcurrentDownloads;

/**
 * YF_SDWebImageOptions for prefetcher. Defaults to YF_SDWebImageLowPriority.
 */
@property (nonatomic, assign) YF_SDWebImageOptions options;

/**
 * Queue options for Prefetcher. Defaults to Main Queue.
 */
@property (nonatomic, assign) dispatch_queue_t prefetcherQueue;

@property (weak, nonatomic) id <YF_SDWebImagePrefetcherDelegate> delegate;

/**
 * Return the global image prefetcher instance.
 */
+ (YF_SDWebImagePrefetcher *)sharedImagePrefetcher;

/**
 * Allows you to instantiate a prefetcher with any arbitrary image manager.
 */
- (id)initWithImageManager:(YF_SDWebImageManager *)manager;

/**
 * Assign list of URLs to let YF_SDWebImagePrefetcher to queue the prefetching,
 * currently one image is downloaded at a time,
 * and skips images for failed downloads and proceed to the next image in the list
 *
 * @param urls list of URLs to prefetch
 */
- (void)prefetchURLs:(NSArray *)urls;

/**
 * Assign list of URLs to let YF_SDWebImagePrefetcher to queue the prefetching,
 * currently one image is downloaded at a time,
 * and skips images for failed downloads and proceed to the next image in the list
 *
 * @param urls            list of URLs to prefetch
 * @param progressBlock   block to be called when progress updates; 
 *                        first parameter is the number of completed (successful or not) requests, 
 *                        second parameter is the total number of images originally requested to be prefetched
 * @param completionBlock block to be called when prefetching is completed
 *                        first param is the number of completed (successful or not) requests,
 *                        second parameter is the number of skipped requests
 */
- (void)prefetchURLs:(NSArray *)urls progress:(YF_SDWebImagePrefetcherProgressBlock)progressBlock completed:(YF_SDWebImagePrefetcherCompletionBlock)completionBlock;

/**
 * Remove and cancel queued list
 */
- (void)cancelPrefetching;


@end
