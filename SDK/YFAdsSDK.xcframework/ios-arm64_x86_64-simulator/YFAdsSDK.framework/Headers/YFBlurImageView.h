//
//  YFBlurImageView.h
//  YFAdsSDK
//
//  Created by FC-0823 on 2023/11/18.
//

#import "YFAdView.h"

NS_ASSUME_NONNULL_BEGIN
@class YFAdImageView;

@interface YFBlurImageView : YFAdImageView


- (void)configUrl:(NSString *)imageUrl completion:(void (^)(UIImage * _Nullable image,NSError * _Nullable error))completion;

- (void)configImage:(UIImage *)image;

- (void)hideContent:(BOOL)isHidden;

@end

NS_ASSUME_NONNULL_END
