/*
 * This file is part of the YF_SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <YFAdsSubstrate/YF_SDWebImageCompat.h>
#import <YFAdsSubstrate/YF_SDWebImageManager.h>

/**
 * Integrates SDWebImage async downloading and caching of remote images with UIButtonView.
 */
@interface UIButton (YF_WebCache)

/**
 * Get the current image URL.
 */
- (NSURL *)yf_currentImageURL;

/**
 * Get the image URL for a control state.
 * 
 * @param state Which state you want to know the URL for. The values are described in UIControlState.
 */
- (NSURL *)yf_imageURLForState:(UIControlState)state;

/**
 * Set the imageView `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url   The url for the image.
 * @param state The state that uses the specified title. The values are described in UIControlState.
 */
- (void)yf_setImageWithURL:(NSURL *)url forState:(UIControlState)state;

/**
 * Set the imageView `image` with an `url` and a placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param state       The state that uses the specified title. The values are described in UIControlState.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @see yf_setImageWithURL:placeholderImage:options:
 */
- (void)yf_setImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param state       The state that uses the specified title. The values are described in UIControlState.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options     The options to use when downloading the image. @see YF_SDWebImageOptions for the possible values.
 */
- (void)yf_setImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options;

/**
 * Set the imageView `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param state          The state that uses the specified title. The values are described in UIControlState.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)yf_setImageWithURL:(NSURL *)url forState:(UIControlState)state completed:(YF_SDWebImageCompletionBlock)completedBlock;

/**
 * Set the imageView `image` with an `url`, placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param state          The state that uses the specified title. The values are described in UIControlState.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)yf_setImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder completed:(YF_SDWebImageCompletionBlock)completedBlock;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param state          The state that uses the specified title. The values are described in UIControlState.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see YF_SDWebImageOptions for the possible values.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)yf_setImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options completed:(YF_SDWebImageCompletionBlock)completedBlock;

/**
 * Set the backgroundImageView `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url   The url for the image.
 * @param state The state that uses the specified title. The values are described in UIControlState.
 */
- (void)yf_setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state;

/**
 * Set the backgroundImageView `image` with an `url` and a placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param state       The state that uses the specified title. The values are described in UIControlState.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @see yf_setImageWithURL:placeholderImage:options:
 */
- (void)yf_setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder;

/**
 * Set the backgroundImageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param state       The state that uses the specified title. The values are described in UIControlState.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options     The options to use when downloading the image. @see YF_SDWebImageOptions for the possible values.
 */
- (void)yf_setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options;

/**
 * Set the backgroundImageView `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param state          The state that uses the specified title. The values are described in UIControlState.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)yf_setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state completed:(YF_SDWebImageCompletionBlock)completedBlock;

/**
 * Set the backgroundImageView `image` with an `url`, placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param state          The state that uses the specified title. The values are described in UIControlState.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)yf_setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder completed:(YF_SDWebImageCompletionBlock)completedBlock;

/**
 * Set the backgroundImageView `image` with an `url`, placeholder and custom options.
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
- (void)yf_setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options completed:(YF_SDWebImageCompletionBlock)completedBlock;

/**
 * Cancel the current image download
 */
- (void)yf_cancelImageLoadForState:(UIControlState)state;

/**
 * Cancel the current backgroundImage download
 */
- (void)yf_cancelBackgroundImageLoadForState:(UIControlState)state;

@end


//@interface UIButton (WebCacheDeprecated)
//
//- (NSURL *)currentImageURL __deprecated_msg("Use `yf_currentImageURL`");
//- (NSURL *)imageURLForState:(UIControlState)state __deprecated_msg("Use `yf_imageURLForState:`");
//
//- (void)setImageWithURL:(NSURL *)url forState:(UIControlState)state __deprecated_msg("Method deprecated. Use `yf_setImageWithURL:forState:`");
//- (void)setImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder __deprecated_msg("Method deprecated. Use `yf_setImageWithURL:forState:placeholderImage:`");
//- (void)setImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options __deprecated_msg("Method deprecated. Use `yf_setImageWithURL:forState:placeholderImage:options:`");
//
//- (void)setImageWithURL:(NSURL *)url forState:(UIControlState)state completed:(YF_SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `yf_setImageWithURL:forState:completed:`");
//- (void)setImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder completed:(YF_SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `yf_setImageWithURL:forState:placeholderImage:completed:`");
//- (void)setImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options completed:(YF_SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `yf_setImageWithURL:forState:placeholderImage:options:completed:`");
//
//- (void)setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state __deprecated_msg("Method deprecated. Use `yf_setBackgroundImageWithURL:forState:`");
//- (void)setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder __deprecated_msg("Method deprecated. Use `yf_setBackgroundImageWithURL:forState:placeholderImage:`");
//- (void)setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options __deprecated_msg("Method deprecated. Use `yf_setBackgroundImageWithURL:forState:placeholderImage:options:`");
//
//- (void)setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state completed:(YF_SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `yf_setBackgroundImageWithURL:forState:completed:`");
//- (void)setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder completed:(YF_SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `yf_setBackgroundImageWithURL:forState:placeholderImage:completed:`");
//- (void)setBackgroundImageWithURL:(NSURL *)url forState:(UIControlState)state placeholderImage:(UIImage *)placeholder options:(YF_SDWebImageOptions)options completed:(YF_SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `yf_setBackgroundImageWithURL:forState:placeholderImage:options:completed:`");
//
//- (void)cancelCurrentImageLoad __deprecated_msg("Use `yf_cancelImageLoadForState:`");
//- (void)cancelBackgroundImageLoadForState:(UIControlState)state __deprecated_msg("Use `yf_cancelBackgroundImageLoadForState:`");
//
//@end
