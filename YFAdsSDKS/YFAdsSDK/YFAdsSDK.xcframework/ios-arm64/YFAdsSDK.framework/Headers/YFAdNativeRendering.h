//
//  YFAdNativeRendering.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 09/04/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//


#import <UIKit/UIKit.h>
@protocol YFAdNativeRendering<NSObject>
@optional
/**
 * Return the UILabel that your view is using for the advertiser name.
 */
-(UILabel*)advertiserLabel;
/**
 * Return the UILabel that your view is using for the main text.
 *
 * @return a UILabel that is used for the main text.
 */
-(UILabel*)textLabel;

/**
 * Return the UILabel that your view is using for the title text.
 *
 * @return a UILabel that is used for the title text.
 */
-(UILabel*)titleLabel;

/**
 * Return a label for showing cta text.
 */
-(UILabel*)ctaLabel;

/**
 * Return a label for showing the rating text.
 */
-(UILabel*)ratingLabel;

/**
 * Return a label for showing the domain text.
 */
-(UILabel*)domainLabel;

/**
 * Return a label for showing the warning text.
 */
-(UILabel*)warningLabel;

/**
 * Return the UIImageView that your view is using for the icon image.
 *
 * @return a UIImageView that is used for the icon image.
 */
-(UIImageView*)iconImageView;

/**
 * Return the UIImageView that your view is using for the main image.
 *
 * @return a UIImageView that is used for the main image.
 */
-(UIImageView*)mainImageView;

/**
 *Return the UIImageView that your view is using for the logo image.
 */
-(UIImageView*)logoImageView;

/**
 * This is the view provided by third-pary network to render it's ad offer.
 *
 */
-(UIView*)mediaView;

/**
 * The button to close Ad for normal native ads.
 *
 */
- (UIButton *)dislikeButton;

/**
 * This is the view provided by third-pary network to render it's ad offer.
 *
 */
-(UIView*)mediaContainerView;

@end
