

#import "YFAdView.h"
#import "YFAdImageManager.h"

@interface YFAdImageView (Cache)

/**
 设置url图片

 @param url 图片url
 */
- (void)xh_setImageWithURL:(nonnull NSURL *)url;

/**
 设置url图片

 @param url 图片url
 @param placeholder 占位图
 */
- (void)xh_setImageWithURL:(nonnull NSURL *)url placeholderImage:(nullable UIImage *)placeholder;

/**
 设置url图片

 @param url 图片url
 @param placeholder 占位图
 @param options YFLaunchAdImageOptions
 */
- (void)xh_setImageWithURL:(nonnull NSURL *)url placeholderImage:(nullable UIImage *)placeholder options:(YFLaunchAdImageOptions)options;

/**
 设置url图片

 @param url 图片url
 @param placeholder 占位图
 @param completedBlock YFExternalCompletionBlock
 */
- (void)xh_setImageWithURL:(nonnull NSURL *)url placeholderImage:(nullable UIImage *)placeholder completed:(nullable YFExternalCompletionBlock)completedBlock;

/**
 设置url图片

 @param url 图片url
 @param completedBlock YFExternalCompletionBlock
 */
- (void)xh_setImageWithURL:(nonnull NSURL *)url completed:(nullable YFExternalCompletionBlock)completedBlock;


/**
 设置url图片

 @param url 图片url
 @param placeholder 占位图
 @param options YFLaunchAdImageOptions
 @param completedBlock YFExternalCompletionBlock
 */
- (void)xh_setImageWithURL:(nonnull NSURL *)url placeholderImage:(nullable UIImage *)placeholder options:(YFLaunchAdImageOptions)options completed:(nullable YFExternalCompletionBlock)completedBlock;

/**
 设置url图片

 @param url 图片url
 @param placeholder 占位图
 @param GIFImageCycleOnce gif是否只循环播放一次
 @param options YFLaunchAdImageOptions
 @param cycleOnceFinishBlock gif播放完回调(GIFImageCycleOnce = YES 有效)
 @param completedBlock YFExternalCompletionBlock
 */
- (void)xh_setImageWithURL:(nonnull NSURL *)url placeholderImage:(nullable UIImage *)placeholder GIFImageCycleOnce:(BOOL)GIFImageCycleOnce options:(YFLaunchAdImageOptions)options GIFImageCycleOnceFinish:(void(^_Nullable)(void))cycleOnceFinishBlock completed:(nullable YFExternalCompletionBlock)completedBlock ;

@end
