
# 亿帆SDK对接⽂档: V6.0.0.5


## 1.开发⽂档修改记录
|  版本号   |                                                                                 修改内容                                                                                 |                                         更新步骤                                          |   更新时间   |
| -------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------- | ---------- |
| 6.0.0.5 | <font color="red">1.穿山甲、优量汇、快手、百度、京东 618预算SDK更新</font> </br> 2.新增支持 GroMore 广告                                                                        | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.05.10 |
| 5.3.3.8  | 1.京东展示优化 </br> <font color="red">2.穿山甲、优量汇SDK更新</font> </br>                                                                                                 | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.04.15 |
| 5.3.3.6  | 1.修复穿山甲、优量汇展示问题</br> <font color="red">2.穿山甲、优量汇SDK更新</font>                                                                                             | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.03.29 |
| 5.3.2.80 | 1.修复百度展示问题</br>                                                                                                                                                   | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.03.15 |
| 5.3.2.27 | 1.修复穿山甲展示问题</br>                                                                                                                                                 | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.03.05 |
| 5.3.2.4  | 1.修复已知问题</br>                                                                                                                                                       | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.02.18 |
| 5.3.2.3  | 1.修复已知问题</br> <font color="red">2.开屏、激励视频 、横幅、插屏、信息流、全屏视频 、draw 、贴片 回调修改</br></font>                                                           | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.02.01 |
| 5.3.2.0  | 1. 更新百青藤⾄5.332</br>  2.更新京东摇一摇组件</br> 3.新增广告类型贴片、draw </br> <font color="red">4.开屏、激励视频 、横幅、插屏、信息流、全屏视频 、draw 、贴片 回调修改</br></font> | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.01.29 |
| 5.3.1.0  | 1. 新增媒体自渲染广告 </br> 2.更新穿⼭甲⾄5.8.1.2 </br>  3.更新优量汇⾄4.14.62</br>  4.更新百青藤⾄5.332</br>  5.更新快手⾄3.3.57 </br> 6.更新京东⾄2.5.4                           | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.01.06 |
| 5.3.0.21 | 1、开屏⼴告样式优化</br>2、插屏⼴告样式优化                                                                                                                                  | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2023.12.28 |
| 5.3.0.10 | 1、插屏⼴告样式优化 </br> 2、Banner⼴告样式优化； </br>3、填充率优化；</br>4、更新⼴点通⾄4.14.45 </br>5、更新穿⼭甲⾄5.6.0.7 </br>6、更新百度SDK⾄5.322 </br>7、更新京东版本⾄2.5.0     | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2023.11.30 |

## 2.支持的SDK平台及广告位

|   平台   | 开屏 | 激励视频 | 横幅 | 插屏 | 信息流 | 全屏视频 | draw | 贴片 |
| ------- | ---- | ------- | ---- | ---- | ----- | ------- | ---- | ---- |
| 穿山甲   | ✅  | ✅      | ✅  | ✅  | ✅    | ✅      | ✅   | ❌  |
| 优量汇   | ✅  | ✅      | ✅  | ✅  | ✅    | ✅      | ❌   | ✅  |
| 百青藤   | ✅  | ✅      | ✅  | ✅  | ✅    | ✅      | ❌   | ❌  |
| 快手     | ✅  | ✅      | ✅  | ✅  | ✅    | ✅      | ✅   | ❌  |
| 京东     | ✅  | ❌      | ✅  | ✅  | ✅    | ❌      | ❌   | ❌  |
| 亿帆     | ✅  | ✅      | ✅  | ✅  | ✅    | ✅      | ❌   | ❌  |
| gromore | ✅  | ✅      | ✅  | ✅  | ✅    | ✅      | ❌   | ❌  |

**注意:** 
1.该版本是基于上述SDK平台版本进行开发的
2.SDK⽀持的架构有：armv7 x86_64 arm64
3.⽀持iOS版本为11.0及以上

## 3. 快速接入

### 3.1 开发环境准备
- 开发工具：推荐使用Xcode 12及以上版本
- 部署目标：iOS 11.0及以上版本
- 开发管理工具：[CocoaPods](https://cocoapods.org/)
### 3.2 引入SDK

#### 方法一：
右键点击⼯程，选择Add File to…，选择解压SDK包后得到的YFAdsSDK.framework，点击Add。或者
将⽂件拖⼊XCode⼯程⽬录结构中，在弹出的界⾯中勾选“Copy items into destination group's
folder(if needed)”，并确保Add To Targets勾选相应的target。同时将YFAdsSDK.framework ⽬录⾥⾯的YFAdsSDK.bundle⽂件导⼊Xcode。


#### <font color="red">方法二（推荐）：</font>
通过Cocoapods导⼊三⽅⼴告SDK，以及第三⽅依赖（如遇到拉不下来，可能是github访问问题，可以
使⽤VPN


```
 pod 'YFAdsSDK', '6.0.0.5'
#优量汇⼴告
 pod 'GDTMobSDK', '4.14.76'
#穿⼭甲⼴告
 pod 'Ads-Fusion-CN-Beta','6.1.1.0', :subspecs => ['BUAdSDK', 'CSJMediation']
#快⼿⼴告SDK
 pod 'KSAdSDK', '3.3.64.4', :inhibit_warnings => false
#百度⼴告SDK
 pod 'BaiduMobAdSDK', '5.351'
#京东⼴告SDK
 pod 'JADYun', '2.5.12' 
#京东摇一摇组件(可选)
 pod 'JADYunMotion', '2.5.12' 


```

#### <font color="red">注意事项：</font>
**1.HTTP权限设置：** 

设置HTTP权限请求，需要在info.plist⾥⾯增加⼀条App Transport Security Settings，添加Allow Arbitrary Loads(NSAllowsArbitraryLoads)，值为YES

**2.删除Scene：** 

1.先直接删除SceneDelegate.h .m⽂件
2.在AppDelegate.h添加@property (strong, nonatomic) UIWindow * window;属性
3.移除AppDelegate⾥⾯的UIScene代理
4.最后在info.plist⽂件中移除Application Scene Manifest

**3.头⽂件冲突：** 

如果遇到头⽂件冲突的问题，可能是，other linker flags的设置问题。删除TARGETS->Linking->Other Linker Flags⾥⾯的-all_load

**4.Bitcode：** 

由于第三⽅库的原因，我们需要在Xcode中关闭Bitcode。设置TARGETS->Build Settings->Enable Bitcode为NO

**5.位置权限：** 

如果应⽤开启了位置权限，SDK可以获取应⽤位置信息⽤以精准推送⼴告，需要在应⽤的 info.plist 添加相应权限提示信息，避免AppStore 审核被拒：
```
Privacy - Location When In Use Usage Description
Privacy - Location Always and When In Use Usage Description
Privacy - Location Always Usage Description
Privacy - Location Usage Description
```

**<font color="red">6.iOS14适配（重要）：</font>** 

由于iOS14.5系统策略更新，我们需要在App中添加SKAdNetwork标识和ATT权限，以避免⼴告收益降
低。

1.升级穿⼭甲 iOS SDK 3.4.2.3 及以上版本，升级⼴点通4.12.3及以上版本，提供了iOS14与
SKAdNetwork⽀持
2.将SKAdNetwork ID 添加到 info.plist 中，以保证 SKAdNetwork 的正确运⾏，以下内容复制到您的info.plist中，

```
穿⼭甲：238da6jt44.skadnetwork，22mmun2rn5.skadnetwork，x2jnk7ly8j.skadnetwork
⼴点通：f7s53z58qe.skadnetwork
```

```
<key>SKAdNetworkItems</key>
  <array>
    <dict>
      <key>SKAdNetworkIdentifier</key>
      <string>238da6jt44.skadnetwork</string>
    </dict>
    <dict>
      <key>SKAdNetworkIdentifier</key>
      <string>22mmun2rn5.skadnetwork</string>
    </dict>
    <dict>
      <key>SKAdNetworkIdentifier</key>
      <string>f7s53z58qe.skadnetwork</string>
    </dict>
     <dict>
      <key>SKAdNetworkIdentifier</key>
      <string>r3y5dwb26t.skadnetwork</string>
    </dict>
  </array>
```

3.获取App Tracking Transparency 权限，请更新您的 Info.plist，添加
NSUserTrackingUsageDescription 字段和⾃定义⽂案描述

```
<key>NSUserTrackingUsageDescription</key>
<string>该标识符将⽤于向您投放个性化⼴告</string>
```

4.从 iOS 14 开始，在应⽤程序调⽤ App Tracking Transparency 向⽤户提跟踪授权请求之前，IDFA将不可⽤。 如果应⽤未提出此请求，应⽤获取到的 IDFA 将⾃动清零，可能会导致您的⼴告收⼊的降低

```
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>
- (void)requestIDFA {
 [ATTrackingManager
requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthoriza
tionStatus status) {
 }];
 // 
 [self loadAd];
}

```
**<font color="red">5. 微信小程序⼴告⽀持：</font>** 

集成微信OpenSDK，可有效提升流量的填充和CPM值
集成步骤：
在微信开发平台注册APPID和Universal Links
集成微信open sdk
提供APPID和Universal Links给运营进⾏绑定

**<font color="red">6.LSApplicationQueriesSchemes⽩名单设置：</font>** 



为了提升⼴告价值，需要在info.plist⾥⾯配置url⽩名单，确保配置在前50个以内。

```
taobao
tbopen
openjd
openjx
taobaolite
meituan0000
pddopen
snssdk1128
snssdk2329
kwai
ksnebula
```


### 3.3 跳转须知

⼴告接⼝中的所有ViewController均为必传项，⽤来处理⼴告跳转。
SDK⾥所有的跳转均采⽤present的⽅式，请确保传⼊的rootViewController不能为空且没有present其他的控制器，否则会出现presentedViewController已经存在⽽导致present失败。

### 3.4 请求失败可能的原因

1. 应⽤包名，appID, posID 必须匹配。（不能直接⽤demo中的posID在你的⼯程中请求⼴告）。
2. 确保⽹络连接正常。（可⽤Wi-Fi和手机⽹络分别请求⼴告验证）。
3. 同⼀天，同⼀设备，⼴告展示有次数限制。（可更换不同设备请求⼴告）。
4. 测试设备不要限制⼴告跟踪（⼴告请求需要获取idfa）。
5. ⼴告请求不能保证每次都有⼴告返回。（⼴告不能频繁请求）。

### 3.5 初始化SDK及全局配置

```
    [YFAdSDKManager setupSDKWithAppId:[YFEnvironmentManager getAPP_ID] config:^YFAdSDKSetting * (YFAdSDKSetting * c) {
        c.customIDFA = idfa;
        return c;
    }];
```

### 3.6 扩展字段参数

⽬前⽀持多维度的扩展字段，可以设置⾃定义数据，后台可以根据维度做云控和数据统计

```
    [YFAdSDKSetting shareInstance].customIDFA = idfa;
    [YFAdSDKSetting shareInstance].userId = @"test";

```



## 4. ⼴告渲染 

### 4.1 开屏⼴告

 
1.请求代码
 ```

    YFAdSplash *splash = [[YFAdSplash alloc] initWithAdUnitID:@"0bbcfd82-779d-4ff8-9a38-781b31c5ab61"viewController:self];
    splash.delegate = self;
    splash.showLogoRequire = YES;
    splash.logoImage = [UIImage imageNamed:@"app_logo"];
    splash.backgroundImage = [UIImage imageNamed:@"LaunchImage_img"];
    splash.timeout = 5;
    [splash loadAndShowAd];

 ```
 
2.回调方法
 ```
/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {

}

/// 广告曝光成功
- (void)fcAdExposured:(YFAdBaseAdapter *)model {
   
}

/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description{


}


/// 广告点击
- (void)fcAdClicked:(YFAdBaseAdapter *)model {

}

/// 广告关闭
- (void)fcAdDidClose:(YFAdBaseAdapter *)model {
    
}

/// 广告倒计时结束
- (void)fcAdSplashOnAdCountdownToZero {

}

/// 点击了跳过
- (void)fcAdSplashOnAdSkipClicked {
   
}

 ```
 
开屏⼴告闪屏问题
 1、⾸⻚闪现之后在弹出⼴告。这种现象对⽤户体验不友好。我们的⽅案是backgroundImage需要保持
和App启动⻚⼀致，这样在加载开屏⼴告的时候，会覆盖在⾸⻚上⾯，⽤户感觉不到是在加载App还是
加载⼴告过程。

### 4.2 横幅⼴告

1.请求代码
 ```
 - (void)loadAdAndShow {
  
UIView *contentV = [[UIView alloc] initWithFrame:CGRectMake(0, 100, self.view.bounds.size.width, self.view.bounds.size.width * 400.0 /600.0)];
 [self.view addSubview:contentV];
 
FCAdBanner * fcAdBanner = [[FCAdBanner alloc] initWithAdUnitID:pID adContainer:contentV viewController:self];
fcAdBanner.delegate = self;
[fcAdBanner loadAndShowAd];
}
 ```
 
2.回调方法
 ```
/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {

}

/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description{

}


/// 广告曝光
- (void)fcAdExposured:(YFAdBaseAdapter *)model {
 
}

/// 广告点击
- (void)fcAdClicked:(YFAdBaseAdapter *)model {

}

/// 广告关闭回调
- (void)fcAdDidClose:(YFAdBaseAdapter *)model {
   
}




 ```
 
 ### 4.3 插屏⼴告

1.请求代码
 ```
 - (void)loadAdAndShow {
  
    YFAdInterstitial * fcAdInterstitial = [[YFAdInterstitial alloc] initWithAdUnitID:PID viewController:self];
    fcAdInterstitial.delegate = self;
    [fcAdInterstitial loadAndShowAd];
}
 ```
 
2.回调方法
 ```
/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {

}

/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description{

}



/// 广告曝光
- (void)fcAdExposured:(YFAdBaseAdapter *)model {
 
}

/// 广告点击
- (void)fcAdClicked:(YFAdBaseAdapter *)model {

}

/// 广告关闭回调
- (void)fcAdDidClose:(YFAdBaseAdapter *)model {
   
}




 ```
 
 ### 4.4 全屏视频⼴告

1.请求代码
 ```
 - (void)loadAdAndShow {
  
     YFAdFullScreenVideo * fcAdFullScreenVideo  = [[YFAdFullScreenVideo alloc] initWithAdUnitID:@"728b5f9b-9b97-404b-8897-1e7b3d719aaf" viewController:self];
     fcAdFullScreenVideo.delegate=self;
     [fcAdFullScreenVideo loadAndShowAd];
}
 ```
 
2.回调方法
 ```
/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {

}

/// 广告曝光
- (void)fcAdExposured:(YFAdBaseAdapter *)model {
 
}

/// 广告点击
- (void)fcAdClicked:(YFAdBaseAdapter *)model {
  
}

- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description{
   
}


/// 广告关闭
- (void)fcAdDidClose {
 

}

/// 广告播放完成
- (void)fcAdFullScreenVideoOnAdPlayFinish {

}

 ```

### 4.4 激励视频⼴告

1.请求代码
 ```
 - (void)loadAdAndShow {
  
   YFAdRewardVideo * fcAdRewardVideo = [[YFAdRewardVideo alloc] initWithAdUnitID:PID viewController:self];
    fcAdRewardVideo.delegate=self;
    [fcAdRewardVideo loadAndShowAd];
}
 ```
 
2.回调方法
 ```
/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {

}

/// 视频缓存成功
- (void)fcAdRewardVideoOnAdVideoCached {
  

}

/// 到达激励时间
- (void)fcAdRewardVideoAdDidRewardEffective {

}

/// 广告曝光
- (void)fcAdExposured:(YFAdBaseAdapter *)model {

}

/// 广告点击
- (void)fcAdClicked:(YFAdBaseAdapter *)model {
  
}

/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description{



}



/// 广告关闭
- (void)fcAdDidClose:(YFAdBaseAdapter *)model {

}

/// 播放完成
- (void)fcAdRewardVideoAdDidPlayFinish {
 
}

 ```

### 4.5 信息流⼴告

1.请求代码
 ```
 - (void)loadAdAndShow {
  
       YFAdNativeExpress * advanceFeed = [[YFAdNativeExpress alloc] initWithAdUnitID:PID adContainer:nil  viewController:self adSize:CGSizeMake(self.view.bounds.size.width, 0)];
    advanceFeed.delegate = self;
    [advanceFeed loadAndShowAd];
}
 ```
 
2.回调方法
 ```
// 信息流广告比较特殊, 渲染逻辑需要自行处理
- (void)showNativeAd {
    for (NSInteger i = 0; i < self.arrViewsM.count; i++) {
        FCAdNativeExpressView *view = self.arrViewsM[i];
        [view render];
        [_dataArrM insertObject:self.arrViewsM[i] atIndex:1];
    }
    [self.tableView reloadData];

}

/// 广告数据拉取成功
- (void)fcAdNativeExpressOnAdLoadSuccess:(NSArray<FCAdNativeExpressView *> *)views {
    NSLog(@"广告拉取成功 %s", __func__);
    self.arrViewsM = [views mutableCopy];
    
    if (_isLoadAndShow) {
        [self showNativeAd];
    }
    


}


/// 广告曝光
- (void)fcAdNativeExpressOnAdShow:(FCAdNativeExpressView *)adView {

}

/// 广告点击
- (void)fcAdNativeExpressOnAdClicked:(FCAdNativeExpressView *)adView {
  
}

/// 广告渲染成功
/// 注意和广告数据拉取成功的区别  广告数据拉取成功, 但是渲染可能会失败
/// 广告加载失败 是广点通 穿山甲 mercury 在拉取广告的时候就全部失败了
/// 该回调的含义是: 比如: 广点通拉取广告成功了并返回了一组view  但是其中某个view的渲染失败了
/// 该回调会触发多次
- (void)fcAdNativeExpressOnAdRenderSuccess:(FCAdNativeExpressView *)adView {

    [self.tableView reloadData];
}

/// 广告渲染失败
/// 注意和广告加载失败的区别  广告数据拉取成功, 但是渲染可能会失败
/// 广告加载失败 是广点通 穿山甲 mercury 在拉取广告的时候就全部失败了
/// 该回调的含义是: 比如: 广点通拉取广告成功了并返回了一组view  但是其中某个view的渲染失败了
/// 该回调会触发多次
- (void)fcAdNativeExpressOnAdRenderFail:(FCAdNativeExpressView *)adView {

    [_dataArrM removeObject: adView];
    [self.tableView reloadData];
}

/// 广告加载失败
/// 该回调只会触发一次
- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description{
 
    [self deallocAd];

}

/// 广告被关闭
- (void)fcAdNativeExpressOnAdClosed:(FCAdNativeExpressView *)adView {
    //需要从tableview中删除

    [_dataArrM removeObject: adView];
    [self.tableView reloadData];
}



// MARK: ======================= UITableViewDelegate, UITableViewDataSource =======================

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
//    return _expressAdViews.count*2;
//    return 2;
    return _dataArrM.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    if ([_dataArrM[indexPath.row] isKindOfClass:[BYExamCellModelElement class]]) {
        return ((BYExamCellModelElement *)_dataArrM[indexPath.row]).cellh;
    } else {
        CGFloat height = ([_dataArrM[indexPath.row] expressView]).frame.size.height;
        NSLog(@"=======> %f", height);
        return height;
    }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell;
    if ([_dataArrM[indexPath.row] isKindOfClass:[BYExamCellModelElement class]]) {
        cell = [tableView dequeueReusableCellWithIdentifier:@"ExamTableViewCell"];
        ((ExamTableViewCell *)cell).item = _dataArrM[indexPath.row];
        return cell;
    } else {
        cell = [self.tableView dequeueReusableCellWithIdentifier:@"nativeexpresscell" forIndexPath:indexPath];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;

        UIView *subView = (UIView *)[cell.contentView viewWithTag:1000];
        if ([subView superview]) {
            [subView removeFromSuperview];
        }
        UIView *view = [_dataArrM[indexPath.row] expressView];

        view.tag = 1000;
        [cell.contentView addSubview:view];
        cell.accessibilityIdentifier = @"nativeTemp_ad";
//        [view mas_remakeConstraints:^(MASConstraintMaker *make) {
//            make.edges.equalTo(@0);
//        }];

        return cell;
    }
}
 ```
 ### 4.6 媒体自渲染

1.请求代码
 ```
- (void)loadAndShowAd {
    [super loadAndShowAd];
    [self loadAdWithState:AdState_Normal];
    self.adMediaRender = [[YFAdMediaRender alloc] initWithAdUnitID:@"d53d8fec49c544fd948f5eef5f805201" viewController:self];
    self.adMediaRender.delegate = self;
    _isAdLoaded = false;
    [self.adMediaRender loadAndShowAd];
    [self loadAdWithState:AdState_Loading];

}
 ```
 
2.回调方法
 ```
- (void)deallocAd {
    self.adMediaRender.delegate = nil;
    self.adMediaRender = nil;
    self.isLoaded = NO;
    [self loadAdWithState:AdState_Normal];
}


//广告展示
- (void)showRanderAd:(id)media {
    [media muteEnable:YES];

    DemoNativeSelfRenderView *selfRenderView = [[DemoNativeSelfRenderView alloc] initWithOffer:media];
    NSMutableArray * clickableViews = [[NSMutableArray alloc] initWithCapacity:0];
    if(selfRenderView.mediaView){
        [clickableViews addObject:selfRenderView.mediaView];
    }
    
    [clickableViews addObjectsFromArray:@[selfRenderView.ctaLabel,selfRenderView.titleLabel,selfRenderView.textLabel,selfRenderView.mainImageView,selfRenderView.iconImageView]];

    [media registerContainer:selfRenderView withClickableViews:clickableViews];
    DemoMediaRenderDetailViewController *showVc = [[DemoMediaRenderDetailViewController alloc] initWithAdView:selfRenderView offer:media];
    [self.navigationController pushViewController:showVc animated:YES];
    
}



/// 获取自渲染数据
- (void)fcAdGetMediaRenderDataSuccess:(NSArray *)mediaRenders {
    [self showRanderAd:mediaRenders.firstObject];
    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功", __func__]];
}


/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description {
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
    //通知主线程刷新
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error.userInfo.description]];
        [self showErrorWithDescription:description];
    });
    
    [self loadAdWithState:AdState_LoadFailed];
    [self deallocAd];

}

/**
 This method is called when native ad  render  success
 */
- (void)mediaAdRenderSuccess:(YFAdMedia *)mediaAd {
    NSLog(@"广告曝光回调 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}
/**
 This method is called when native ad  render  fail
 */
- (void)mediaAdRenderFail:(YFAdMedia *)mediaAd {
    NSLog(@"广告曝光回调 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光失败", __func__]];
}
/**
 This method is called when native ad is clicked.
 */
- (void)mediaAdDidClick:(YFAdMedia *)mediaAd {
    NSLog(@"广告点击 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击成功", __func__]];
}
/**
 This method is called when native ad play finished.
 */
- (void)mediaAdVideoPlayFinished:(YFAdMedia *)mediaAd {
    NSLog(@"广告视频播放完成 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告视频播放完成", __func__]];
}

 ```


 ### 4.6 视频贴片

1.请求代码
 ```
- (void)loadAndShowAd{
    if (!_contentV) {
        _contentV = [[UIView alloc] initWithFrame:CGRectMake(0, 100, self.view.bounds.size.width, self.view.bounds.size.width * 400.0 /600.0)];
        [self.view addSubview:self.contentV];
    }
    
    
    if (!self.adPatch) {
        self.adPatch = [[YFAdPatch alloc] initWithAdUnitID:[YFEnvironmentManager getPATCH_ID] adContainer:_contentV viewController:self];
        self.adPatch.delegate = self;
        [self.adPatch loadAndShowAd];
    }
    
}

 ```
 
2.回调方法
 ```



- (void)deallocAd {
    [self.contentV removeFromSuperview];
    self.contentV = nil;
    if (self.adPatch) {
        self.adPatch.delegate = nil;
        self.adPatch = nil;
    }
}

/// 广告数据加载成功
- (void)fcAdLoadSuccess:(YFAdBaseAdapter *)model {
    
}

/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description{
    
   
    [self deallocAd];
}


/// 广告曝光
-(void)fcAdExposured:(id)adapter{
    NSLog(@"贴片广告曝光回调 %s", __func__);
}

/// 广告点击
- (void)fcAdClicked:(id)adapter{
    NSLog(@"贴片广告点击 %s", __func__);
}

/// 广告关闭回调
- (void)fcAdDidClose:(id)adapter{
    NSLog(@"贴片广告关闭了 %s", __func__);
    [self deallocAd];
}

-(void)dealloc {
    NSLog(@"贴片释放 %s", __func__);
    [self deallocAd];
}


 ```

### 4.7 Draw 视频

1.请求代码
 ```
- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    
    _isLoadAndShow = NO;
    
    for (NSInteger i =0 ; i <= 5; i++) {
        [self.dataArr addObject:@"App NormalCell"];
    }
        
    self.advanceDraw = [[YFAdDraw alloc] initWithAdUnitID:[YFEnvironmentManager getDRAW_ID] adContainer:nil viewController:self adSize:CGSizeMake(self.view.bounds.size.width, self.view.bounds.size.width * 400.0 /600.0)];
    self.advanceDraw.count = 1;
    self.advanceDraw.delegate = self;
    [self.advanceDraw loadAd];
    [self loadAdWithState:AdState_Loading];

}

 ```
 
2.回调方法
 ```



- (void)showAd {
    if (!self.advanceDraw || !self.isLoaded || self.dataArr.count == 0 || self.adViews.count == 0) {
        [JDStatusBarNotification showWithStatus:@"请先加载广告" dismissAfter:1.5];
        return;
    }
    [self showNativeAd];
}


- (void)loadAndShowAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    
    _isLoadAndShow = YES;

    for (NSInteger i =0 ; i <= 5; i++) {
        [self.dataArr addObject:@"App NormalCell"];
    }
    
    self.advanceDraw = [[YFAdDraw alloc] initWithAdUnitID:[YFEnvironmentManager getDRAW_ID] adContainer:nil viewController:self adSize:CGSizeMake([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)];
    self.advanceDraw.delegate = self;
    self.advanceDraw.count = 1;
    [self.advanceDraw loadAndShowAd];
    [self loadAdWithState:AdState_Loading];
  
}

- (void)deallocAd {
    if (self.tableView.hidden) {
        return;
    }
    [self.dataArr removeAllObjects];
    [self.adViews removeAllObjects];
    self.advanceDraw.delegate = nil;
    self.advanceDraw = nil;
    self.isLoaded = NO;
    [self.tableView reloadData];
    [self loadAdWithState:AdState_Normal];
    self.tableView.hidden = YES;
    self.closeBtn.hidden = YES;
}

// Draw流广告比较特殊, 渲染逻辑需要自行处理
- (void)showNativeAd {
    
    [self.adViews enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        YFAdDrawView *expressView = (YFAdDrawView *)obj;
        NSUInteger index = arc4random() % (self.dataArr.count-3)+2;
        [self.dataArr insertObject:expressView atIndex:index];
    }];
    self.tableView.hidden = NO;
    self.closeBtn.hidden = NO;
    [self.tableView reloadData];
}



// MARK: ======================= YFAdDrawDelegate =======================
/// 广告数据拉取成功
- (void)fcAdDrawOnAdLoadSuccess:(NSArray *)views {
    NSLog(@"广告拉取成功 %s", __func__);
    self.adViews = [views mutableCopy];
    
    if (_isLoadAndShow) {
        [self showNativeAd];
    }
}


/// 广告曝光
- (void)fcAdDrawOnAdShow:(YFAdDrawView *)adView {
    NSLog(@"广告曝光 %s", __func__);
}

/// 广告点击
- (void)fcAdDrawOnAdClicked:(YFAdDrawView *)adView {
    NSLog(@"广告点击 %s", __func__);
}

/// 广告渲染成功
/// 注意和广告数据拉取成功的区别  广告数据拉取成功, 但是渲染可能会失败
/// 广告加载失败 是广点通 穿山甲 mercury 在拉取广告的时候就全部失败了
/// 该回调的含义是: 比如: 广点通拉取广告成功了并返回了一组view  但是其中某个view的渲染失败了
/// 该回调会触发多次
- (void)fcAdDrawOnAdRenderSuccess:(YFAdDrawView *)adView {
    NSLog(@"广告渲染成功 %s %@", __func__, adView);
}

/// 广告渲染失败
/// 注意和广告加载失败的区别  广告数据拉取成功, 但是渲染可能会失败
/// 广告加载失败 是广点通 穿山甲 mercury 在拉取广告的时候就全部失败了
/// 该回调的含义是: 比如: 广点通拉取广告成功了并返回了一组view  但是其中某个view的渲染失败了
/// 该回调会触发多次
- (void)fcAdDrawOnAdRenderFail:(YFAdDrawView *)adView {
    NSLog(@"广告渲染失败 %s %@", __func__, adView);
    [_dataArr removeObject: adView];
    [self.tableView reloadData];
}

/// 广告加载失败
/// 该回调只会触发一次
- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description{
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
    [self showErrorWithDescription:description];
    [self deallocAd];

}



/// 广告被关闭
- (void)fcAdDrawOnAdClosed:(YFAdDrawView *)adView {
    //需要从tableview中删除
    NSLog(@"广告关闭 %s", __func__);
    [_dataArr removeObject: adView];
    [self.tableView reloadData];
}


// MARK: ======================= UITableViewDelegate, UITableViewDataSource =======================

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
//    return _expressAdViews.count*2;
//    return 2;
    return self.dataArr.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return [DemoDrawNormalCell cellHeight];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSUInteger index = indexPath.row;
    id model = self.dataArr[index];
    if (![model isKindOfClass:[YFAdDrawView class]]) {
        DemoDrawNormalCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass(DemoDrawNormalCell.class)];
        if (!cell) {
            cell = [[DemoDrawNormalCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:NSStringFromClass(DemoDrawNormalCell.class)];
        }

        [cell refreshUIAtIndex:index];
        
        return cell;
    } else {
        DemoDrawAdCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass(DemoDrawAdCell.class)];
        if (!cell) {
            cell = [[DemoDrawAdCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:NSStringFromClass(DemoDrawAdCell.class)];
        }
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        YFAdDrawView *drawAd = _dataArr[index];
        [cell refreshWithDrawAd:drawAd];

        return cell;
    }
}

-(void)dealloc {
    NSLog(@"Draw流释放 %s", __func__);
}


-(NSMutableArray *)dataArr{
    if (!_dataArr) {
        _dataArr = [NSMutableArray array];
    }
    return _dataArr;
}

-(NSMutableArray *)adViews{
    if (!_adViews) {
        _adViews = [NSMutableArray array];
    }
    return _adViews;
}

- (UITableView *)tableView {
    if (_tableView == nil) {
        _tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.pagingEnabled = YES;
        _tableView.showsVerticalScrollIndicator = NO;
        _tableView.allowsSelection = NO;
        _tableView.hidden = YES;
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        if (@available(iOS 15, *)) {
            _tableView.prefetchingEnabled = NO;
        }
    }
    return _tableView;
}


 ```

## 5、错误码
10000 : @"服务器异常",</br>
10001 : @"跳转超时失败",</br>
10002 : @"配置返回失败",</br>
10003 : @"配置数据解析失败",</br>
10004 : @"上报返回失败",</br>
10005 : @"无广告返回，请联系管理员",</br>
10007 : @"超出当前配置的每小时广告展示次数，请联系管理员",</br>
10008 : @"超出当前配置的每天广告展示次数，请联系管理员",</br>
10009 : @"超出当前配置的展示次数，请联系管理员",</br>
10010 : @"广告单层超时",</br>
       
13001 : @"百度加载失败",</br>
13002 : @"百度渲染失败",</br>
13003 : @"百度缓存失败",</br>


19001 : @"京东加载失败",</br>
19002 : @"京东渲染失败",</br>

15001 : @"亿帆加载失败",</br>
15002 : @"亿帆渲染失败",</br>
       

11001 : @"穿山甲请求广告数据失败",</br>
11002 : @"穿山甲接收广告加载失败",</br>
11003 : @"穿山甲广告物料加载失败",</br>
11004 : @"穿山甲广告渲染失败",</br>
11005 : @"穿山甲视频广告播放完成发生错误",</br>
11006 : @"穿山甲广告展示失败",</br>
11007 : @"穿山甲广告异步请求的服务器验证失败",</br>
      

41001 : @"优量汇请求广告数据失败",</br>
41002 : @"优量汇接收广告加载失败",</br>
41003 : @"优量汇广告物料加载失败",</br>
41004 : @"优量汇广告渲染失败",</br>
41005 : @"优量汇视频广告播放完成发生错误",</br>
41006 : @"优量汇广告展示失败",</br>
41007 : @"优量汇广告异步请求的服务器验证失败",</br>

## 6、 收集的数据类型

| 数据类型 | 收集情况 | 备注  |
|--------|---------|----------|
| 1.精确位置 Precise Location </br>2.粗略位置 Rough Location|1.精确位置-可选收集</br> 2.粗略位置-不收集|会获取地理位置信息⽤于⼴告投放与反作弊。应⽤被⽤户授予地理位置权限时，会获取地理位置信息，不会主动获取地理位置权限及地理位置信息。|
|设备ID|可选收集|设备ID当应⽤被⽤户授予⼴告追踪权限时，将获取idfa⽤于⼴告归因与追踪。|
|1.使⽤数据 UsageData </br> 2.产品交互ProductInteraction</br>3.⼴告数据Advertising Data</br>4.其他使⽤数据 OtherUsage Data|1.使⽤数据-不收集</br>2.产品交互-不收集</br>3.⼴告数据-收集</br>4.其他使⽤数据-不收集|将统计⼴告数据，以⽤于⼴告主统计投放结果。展示 、点击 、转化|
|诊断Diagnostics</br>1.崩溃数据Crash Data</br>2.性能数据Performance Data</br>3.其他诊断数据 OtherDiagnostic Data|1.崩溃数据-收集</br>2.性能数据-收集其他</br>3.诊断数据-不收集|崩溃数据联盟将收集联盟SDK带来的崩溃信息，以此来优化代码缺陷。性能数据联盟将收集SDK运⾏过程中性能数据，以优化SDK的性能。|
|1.其他数据 OtherData </br>2.其他数据类型Other Data Types</br>|收集|技术上我们还会收集⼀些设备信息（例如，设备型号、操作系统及版本、时区、⽹络类型等）。|
