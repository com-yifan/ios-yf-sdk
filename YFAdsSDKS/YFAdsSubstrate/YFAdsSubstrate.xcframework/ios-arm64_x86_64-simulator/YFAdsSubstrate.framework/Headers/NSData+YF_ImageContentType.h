//
// Created by Fabrice Aneche on 06/01/14.
// Copyright (c) 2014 Dailymotion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (YF_ImageContentType)

/**
 *  Compute the content type for an image data
 *
 *  @param data the input data
 *
 *  @return the content type as string (i.e. image/jpeg, image/gif)
 */
+ (NSString *)yf_contentTypeForImageData:(NSData *)data;

@end


@interface NSData (ImageContentTypeDeprecated)

+ (NSString *)contentTypeForImageData:(NSData *)data __deprecated_msg("Use `yf_contentTypeForImageData:`");

@end
