//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#define FC_SCREEN_WIDTH    [UIScreen mainScreen].bounds.size.width
#define FC_SCREEN_HEIGHT    [UIScreen mainScreen].bounds.size.height

///  弱对象
#define yf_weakify( x ) autoreleasepool{} __weak typeof(x) weak##x = x;

#define yf_strongify( x ) autoreleasepool{} __strong typeof(x) x = weak##x;

/// iPhoneX  iPhoneXS  iPhoneXS Max  iPhoneXR 机型判断
#define YF_IsiPhoneX \
({BOOL isPhoneX = NO;\
if (@available(iOS 11.0, *)) {\
isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
}\
(isPhoneX);})

///顶部安全距离
#define YF_SAFEAREA_TOP \
({CGFloat height = 20;\
if (@available(iOS 11.0, *)) {\
if (YF_IsiPhoneX) {\
height = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.top;\
}\
}\
(height);})

///底部安全距离
#define YF_SAFEAREA_BOTTOM \
({CGFloat height = 0;\
if (@available(iOS 11.0, *)) {\
height = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom;\
}\
(height);})
