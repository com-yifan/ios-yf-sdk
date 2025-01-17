/*
 * This file is part of the YF_SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <YFAdsSDK/YF_SDWebImageCompat.h>
#import <YFAdsSDK/YF_SDWebImageManager.h>

/**
 * Integrates YF_SDWebImage async downloading and caching of remote images with UIImageView.
 *
 * Usage with a UITableViewCell sub-class:
 *
 * @code

#import <YF_SDWebImage/UIImageView+YF_WebCache.h>

...

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *MyIdentifier = @"MyIdentifier";
 
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:MyIdentifier];
 
    if (cell == nil) {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:MyIdentifier]
                 autorelease];
    }
 
    // Here we use the provided xh_setImageWithURL: method to load the web image
    // Ensure you use a placeholder image otherwise cells will be initialized with no image
    [cell.imageView xh_setImageWithURL:[NSURL URLWithString:@"http://example.com/image.jpg"]
                      placeholderImage:[UIImage imageNamed:@"placeholder"]];
 
    cell.textLabel.text = @"My Text";
    return cell;
}

 * @endcode
 */
@interface UIImageView (YF_WebCache)

/**
 * Get the current image URL.
 *
 * Note that because of the limitations of categories this property can get out of sync
 * if you use yf_setImage: directly.
 */
- (NSURL *)yf_imageURL;

/**
 * Set the imageView `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 */
- (void)xh_setImageWithURL:(NSURL *)url;

/**
 * Set the imageView `image` with an `url` and a placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @see xh_setImageWithURL:placeholderImage:options:
 */
- (void)xh_setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options     The options to use when downloading the image. @see YF_SDWebImageOptions for the possible values.
 */
- (void)xh_setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options;

/**
 * Set the imageView `image` with an `url`.
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
- (void)xh_setImageWithURL:(NSURL *)url completed:(YF_SDWebImageCompletionBlock)completedBlock;

/**
 * Set the imageView `image` with an `url`, placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)xh_setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder completed:(YF_SDWebImageCompletionBlock)completedBlock;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see YF_SDWebImageOptions for the possible values.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)xh_setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options completed:(YF_SDWebImageCompletionBlock)completedBlock;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see YF_SDWebImageOptions for the possible values.
 * @param progressBlock  A block called while image is downloading
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)xh_setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options progress:(YF_SDWebImageDownloaderProgressBlock)progressBlock completed:(YF_SDWebImageCompletionBlock)completedBlock;

/**
 * Set the imageView `image` with an `url` and optionally a placeholder image.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see YF_SDWebImageOptions for the possible values.
 * @param progressBlock  A block called while image is downloading
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)yf_setImageWithPreviousCachedImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options progress:(YF_SDWebImageDownloaderProgressBlock)progressBlock completed:(YF_SDWebImageCompletionBlock)completedBlock;

/**
 * Download an array of images and starts them in an animation loop
 *
 * @param arrayOfURLs An array of NSURL
 */
- (void)yf_setAnimationImagesWithURLs:(NSArray *)arrayOfURLs;

/**
 * Cancel the current download
 */
- (void)yf_cancelCurrentImageLoad;

- (void)yf_cancelCurrentAnimationImagesLoad;

/**
 *  Show activity UIActivityIndicatorView
 */
- (void)setShowActivityIndicatorView:(BOOL)show;

/**
 *  set desired UIActivityIndicatorViewStyle
 *
 *  @param style The style of the UIActivityIndicatorView
 */
- (void)setIndicatorStyle:(UIActivityIndicatorViewStyle)style;

@end

//
//@interface UIImageView (WebCacheDeprecated)
//
//- (NSURL *)imageURL __deprecated_msg("Use `yf_imageURL`");
//
//- (void)setImageWithURL:(NSURL *)url __deprecated_msg("Method deprecated. Use `xh_setImageWithURL:`");
//- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder __deprecated_msg("Method deprecated. Use `xh_setImageWithURL:placeholderImage:`");
//- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options __deprecated_msg("Method deprecated. Use `xh_setImageWithURL:placeholderImage:options`");
//
//- (void)setImageWithURL:(NSURL *)url completed:(YF_SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `xh_setImageWithURL:completed:`");
//- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder completed:(YF_SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `xh_setImageWithURL:placeholderImage:completed:`");
//- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options completed:(YF_SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `xh_setImageWithURL:placeholderImage:options:completed:`");
//- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options progress:(YF_SDWebImageDownloaderProgressBlock)progressBlock completed:(YF_SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `xh_setImageWithURL:placeholderImage:options:progress:completed:`");
//
//- (void)yf_setImageWithPreviousCachedImageWithURL:(NSURL *)url andPlaceholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options progress:(YF_SDWebImageDownloaderProgressBlock)progressBlock completed:(YF_SDWebImageCompletionBlock)completedBlock __deprecated_msg("Method deprecated. Use `yf_setImageWithPreviousCachedImageWithURL:placeholderImage:options:progress:completed:`");
//
//- (void)setAnimationImagesWithURLs:(NSArray *)arrayOfURLs __deprecated_msg("Use `yf_setAnimationImagesWithURLs:`");
//
//- (void)cancelCurrentArrayLoad __deprecated_msg("Use `yf_cancelCurrentAnimationImagesLoad`");
//
//- (void)cancelCurrentImageLoad __deprecated_msg("Use `yf_cancelCurrentImageLoad`");
//
//@end
