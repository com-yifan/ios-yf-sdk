

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <MediaPlayer/MediaPlayer.h>
#import <AVKit/AVKit.h>

#if __has_include(<FLAnimatedImage/FLAnimatedImage.h>)
    #import <FLAnimatedImage/FLAnimatedImage.h>
#else
    #import "YFAnimatedImage.h"
#endif

#if __has_include(<FLAnimatedImage/FLAnimatedImageView.h>)
    #import <FLAnimatedImage/YFAnimatedImageView.h>
#else
    #import "YFAnimatedImageView.h"
#endif


#pragma mark - image
@interface YFAdImageView : YFAnimatedImageView

@property (nonatomic, copy) void(^click)(CGPoint point);

@end

#pragma mark - video
@interface FCAdVideoView : UIView

@property (nonatomic, copy) void(^click)(CGPoint point);
@property (nonatomic, strong) AVPlayerViewController *videoPlayer;
@property (nonatomic, assign) MPMovieScalingMode videoScalingMode;
@property (nonatomic, assign) AVLayerVideoGravity videoGravity;
@property (nonatomic, assign) BOOL videoCycleOnce;
@property (nonatomic, assign) BOOL muted;
@property (nonatomic, strong) NSURL *contentURL;

-(void)stopVideoPlayer;

@end

