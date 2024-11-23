//
//  UIImage+YF_GIF.h
//  LBGIFImage
//
//  Created by Laurin Brandner on 06.01.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (YF_GIF)

+ (UIImage *)yf_animatedGIFNamed:(NSString *)name;

+ (UIImage *)yf_animatedGIFWithData:(NSData *)data;

//- (UIImage *)yf_animatedImageByScalingAndCroppingToSize:(CGSize)size;

@end
