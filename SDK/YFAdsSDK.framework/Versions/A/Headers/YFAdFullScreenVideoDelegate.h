//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//


#ifndef FCAdFullScreenVideoDelegate_h
#define FCAdFullScreenVideoDelegate_h
#import "YFAdBaseDelegate.h"
@protocol YFAdFullScreenVideoDelegate <YFAdBaseDelegate>
@optional
/// 视频播放完成
- (void)fcAdFullScreenVideoOnAdPlayFinish;

@end

#endif
