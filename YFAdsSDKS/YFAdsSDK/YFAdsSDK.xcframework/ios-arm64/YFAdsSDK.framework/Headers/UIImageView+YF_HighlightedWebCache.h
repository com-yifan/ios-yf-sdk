/*
 * This file is part of the YF_SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <UIKit/UIKit.h>
#import <YFAdsSDK/YF_SDWebImageCompat.h>
#import <YFAdsSDK/YF_SDWebImageManager.h>

/**
 * Integrates YF_SDWebImage async downloading and caching of remote images with UIImageView for highlighted state.
 */
@interface UIImageView (YF_HighlightedWebCache)

/**
 * Set the imageView `highlightedImage` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 */
- (void)yf_setHighlightedImageWithURL:(NSURL *)url;

/**
 * Set the imageView `highlightedImage` with an `url` and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url     The url for the image.
 * @param options The options to use when downloading the image. @see YF_SDWebImageOptions for the possible values.
 */
- (void)yf_setHighlightedImageWithURL:(NSURL *)url options:(YF_SDWebImageOptions)options;

/**
 * Set the imageView `highlightedImage` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)yf_setHighlightedImageWithURL:(NSURL *)url completed:(YF_SDWebImageCompletionBlock)completedBlock;

/**
 * Set the imageView `highlightedImage` with an `url` and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param options        The options to use when downloading the image. @see YF_SDWebImageOptions for the possible values.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)yf_setHighlightedImageWithURL:(NSURL *)url options:(YF_SDWebImageOptions)options completed:(YF_SDWebImageCompletionBlock)completedBlock;

/**
 * Set the imageView `highlightedImage` with an `url` and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param options        The options to use when downloading the image. @see YF_SDWebImageOptions for the possible values.
 * @param progressBlock  A block called while image is downloading
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)yf_setHighlightedImageWithURL:(NSURL *)url options:(YF_SDWebImageOptions)options progress:(YF_SDWebImageDownloaderProgressBlock)progressBlock completed:(YF_SDWebImageCompletionBlock)completedBlock;

/**
 * Cancel the current download
 */
- (void)yf_cancelCurrentHighlightedImageLoad;

@end


//@interface UIImageView (HighlightedWebCacheDeprecated)
//
//- (void)setHighlightedImageWithURL:(NSURL *)url __deprecated_msg("Method deprecated. Use `yf_setHighlightedImageWithURL:`");
//- (void)setHighlightedImageWithURL:(NSURL *)url options:(YF_SDWebImageOptions)options __deprecated_msg("Method deprecated. Use `yf_setHighlightedImageWithURL:options:`");
//- (void)setHighlightedImageWithURL:(NSURL *)url completed:(YF_SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `yf_setHighlightedImageWithURL:completed:`");
//- (void)setHighlightedImageWithURL:(NSURL *)url options:(YF_SDWebImageOptions)options completed:(YF_SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `yf_setHighlightedImageWithURL:options:completed:`");
//- (void)setHighlightedImageWithURL:(NSURL *)url options:(YF_SDWebImageOptions)options progress:(YF_SDWebImageDownloaderProgressBlock)progressBlock completed:(YF_SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `yf_setHighlightedImageWithURL:options:progress:completed:`");
//
//- (void)cancelCurrentHighlightedImageLoad __deprecated_msg("Use `yf_cancelCurrentHighlightedImageLoad`");
//
//@end
