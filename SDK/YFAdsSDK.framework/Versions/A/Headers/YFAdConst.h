//  Created by ldm on 2023/05/04.
//  Copyright © 2023 FC. All rights reserved.
//

#define FC_SCREEN_WIDTH    [UIScreen mainScreen].bounds.size.width
#define FC_SCREEN_HEIGHT    [UIScreen mainScreen].bounds.size.height

///  弱对象
#define weakify( x ) autoreleasepool{} __weak typeof(x) weak##x = x;

