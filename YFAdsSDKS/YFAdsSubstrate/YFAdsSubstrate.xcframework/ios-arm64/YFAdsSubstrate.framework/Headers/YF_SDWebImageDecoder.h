/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * Created by james <https://github.com/mystcolor> on 9/28/11.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import <YFAdsSubstrate/YF_SDWebImageCompat.h>

@interface UIImage (YFForceDecode)

+ (UIImage *)yf_decodedImageWithImage:(UIImage *)image;

@end
