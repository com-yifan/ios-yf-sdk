# 亿帆SDK对接⽂档: V6.0.4.3

## 1.开发⽂档修改记录

|  版本号   |                                                                                                                                                 修改内容                                                                                                                                                 |                                         更新步骤                                          |   更新时间   |
| -------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------- | ---------- |
| 6.0.4.3 | 1.升级联盟SDK<br />2.移除Tanx SDK<br />3.优化按需集成联盟SDK的能力<br />4.优化媒体自渲染能力<br />5.性能优化<br />6.修复已知问题 | 必选：参照Podfile集成或手动导入集成；<br />移除Tanx : <font color="red">Cocoapods集成：Podfile中移除pod 'Tanx'和pod 'YFAdsSDK/YFAdsTXAdapter'；手动集成：移除TanxSDK.library和YFAdsTXAdapter.xcframework</font> | 2025.2.17 |
| 6.0.4.1 | 1.联盟SDK升级<br/>2.广告场景优化<br/>3.广告样式优化<br/>4.屏幕适配方案优化<br/>5.Demo结构优化<br/>6.模块化，现已支持拆分引入<br/ >7.新增是否允许更改声道接口<br/>8.修复已知BUG | 必选：</br> 支持联盟适配器按需导入，参照Podfile集成； | 2024.12.31 |
| 6.0.3.6  | 1. 修复已知问题                                                                                                                                                                                                                                                                           | 必选：</br> 替换YFAdsSDK.framework；</br> Podfile更新⼴告源SDK版本 | 2024.12.10 |
| 6.0.3.5  | 1. 修复已知问题                                                                                                                                                                                                                                                                           | 必选：</br> 替换YFAdsSDK.framework；</br> Podfile更新⼴告源SDK版本 | 2024.11.27 |
| 6.0.3.4  | 1. 修复已知问题与性能优化                                                                                                                                                                                                                                                                           | 必选：</br> 替换YFAdsSDK.framework；</br> Podfile更新⼴告源SDK版本 | 2024.11.23 |
| 6.0.3.3 | 1.新增融合Banner广告类型 <br><font color="red">2.新增穿山甲直播拉流广告能力，需在pod中增加BUAdLive-Lib模块：pod 'Ads-CN','6.4.1.7', :subspecs => ['BUAdSDK', 'CSJMediation', 'BUAdLive-Lib'] </font> <br>3.广告样式优化 <br>4.修复部分已知问题<br>5.优化广告有效性校验，使用isValid判断广告有效性,支持开屏、插屏、banner、融合banner、信息流、激励视频、全屏视频、贴片。<font color="red">注意信息流和融合banner需使用对应广告视图的isValid，不要使用广告加载器的isValid。</font>                                                                                                                                                                                                                                                                                         | 必选：</br> 替换YFAdsSDK.framework；</br> Podfile更新⼴告源SDK版本 | 2024.11.07 |
| 6.0.3.2  | 1.修复部分已知问题                                                                                                                                                                                                                                                                                         | 必选：</br> 替换YFAdsSDK.framework；</br> Podfile更新⼴告源SDK版本 | 2024.10.16 |
| 6.0.3.0  |  1.升级联盟双十一版本SDK </br> 2.广告样式优化  </br>3.媒体自渲染能力优化 </br>4.支持开屏底部bottomView自定义能力与背景视图backgroundView自定义能力  </br>5.DEMO新增模拟场景 </br>6.修复已知问题与性能优化                                                                                                                    | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本; | 2024.10.13 |
| 6.0.2.12  | 1.Tanx3.6.0适配 </br>2.修复部分已知问题题                                                                                                                                                                                                                                                                  | 必选：</br> 替换YFAdsSDK.framework；</br> Podfile更新⼴告源SDK版本 | 2024.9.29 |
| 6.0.2.2  | 1.修复部分已知问题                                                                                                                                                                                                                                                                                         | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.8.20  |
| 6.0.2.0  | 1.广告样式优化</br>2.修复部分已知问题                                                                                                                                                                                                                                                                        | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.8.14  |
| 6.0.1.8  | <font color="red"> 1.获取广告数据失败方法替换- (void)fcAdFailedWithError:(NSError *)error description:(NSDictionary *)description DEPRECATED_MSG_ATTRIBUTE(" 此方法将被替换为:- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter description:(NSDictionary *)description");</br>2.修复部分已知问题 | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.7.10  |
| 6.0.1.6  | <font color="red">1.更新穿山甲、优量汇、快手、百度、京东 广告SDK </br> 2.支持淘宝Tanx广告</br></font>3. 优化聚合SDK性能，提升执行效率</br>4.新增640x100、600x410尺寸 banner 、信息流样式 </br>5. YFAdNativeExpressView 增加 -(void)setRootController:(UIViewController *)rootController 方法</br>6.修复部分已知问题          | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.7.1   |
| 6.0.0.0  | <font color="red">1.穿山甲、优量汇、快手、百度、京东 618预算SDK更新</font> </br> 2.支持 gromore SDK                                                                                                                                                                                                            | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.05.10 |
| 5.3.3.8  | 1.京东展示优化 </br> <font color="red">2.穿山甲、优量汇SDK更新</font> </br>                                                                                                                                                                                                                                  | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.04.15 |
| 5.3.3.6  | 1.修复穿山甲、优量汇展示问题</br> <font color="red">2.穿山甲、优量汇SDK更新</font>                                                                                                                                                                                                                             | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.03.29 |
| 5.3.2.80 | 1.修复百度展示问题</br>                                                                                                                                                                                                                                                                                    | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.03.15 |
| 5.3.2.27 | 1.修复穿山甲展示问题</br>                                                                                                                                                                                                                                                                                  | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.03.05 |
| 5.3.2.4  | 1.修复已知问题</br>                                                                                                                                                                                                                                                                                       | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.02.18 |
| 5.3.2.3  | 1.修复已知问题</br> <font color="red">2.开屏、激励视频 、横幅、插屏、信息流、全屏视频 、draw 、贴片 回调修改</br></font>                                                                                                                                                                                            | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.02.01 |
| 5.3.2.0  | 1. 更新百青藤⾄5.332</br>  2.更新京东摇一摇组件</br> 3.新增广告类型贴片、draw </br> <font color="red">4.开屏、激励视频 、横幅、插屏、信息流、全屏视频 、draw 、贴片 回调修改</br></font>                                                                                                                                  | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.01.29 |
| 5.3.1.0  | 1. 新增媒体自渲染广告 </br> 2.更新穿⼭甲⾄5.8.1.2 </br>  3.更新优量汇⾄4.14.62</br>  4.更新百青藤⾄5.332</br>  5.更新快手⾄3.3.57 </br> 6.更新京东⾄2.5.4                                                                                                                                                           | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2024.01.06 |
| 5.3.0.21 | 1、开屏⼴告样式优化</br>2、插屏⼴告样式优化                                                                                                                                                                                                                                                                   | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2023.12.28 |
| 5.3.0.10 | 1、插屏⼴告样式优化 </br> 2、Banner⼴告样式优化； </br>3、填充率优化；</br>4、更新⼴点通⾄4.14.45 </br>5、更新穿⼭甲⾄5.6.0.7 </br>6、更新百度SDK⾄5.322 </br>7、更新京东版本⾄2.5.0                                                                                                                                     | 必选：</br> 替换YFAdsSDK.framework；</br> 替换YFAdsSDK.bundle；</br> Podfile更新⼴告源SDK版本 | 2023.11.30 |

## 2.支持的联盟平台版本及广告类型

|   平台   | 版本 | 开屏 | 激励视频 | 横幅 | 插屏 | 信息流 | 全屏视频 | draw | 贴片 | 融合Banner |
| :------: | :--: | :-----: | :--: | :--: | :---: | :-----: | :--: | :--: | :--: | :------: |
| 穿山甲    | 6.6.1.3 | ✅  | ✅      | ✅  | ✅  | ✅    | ✅      | ✅   | ❌  | ✅ |
| 优量汇    | 4.15.22 | ✅  | ✅      | ✅  | ✅  | ✅    | ✅      | ❌   | ✅  | ✅ |
| 百青藤    | 5.373 | ✅  | ✅      | ✅  | ✅  | ✅    | ✅      | ❌   | ❌  | ✅ |
| 快手     | 3.3.72 | ✅  | ✅      | ✅  | ✅  | ✅    | ✅      | ✅   | ❌  | ✅ |
| 京东     | 2.6.8 | ✅  | ❌      | ✅  | ✅  | ✅    | ❌      | ❌   | ❌  | ✅ |
| 亿帆     | 6.0.4.3 | ✅  | ✅      | ✅  | ✅  | ✅    | ✅      | ❌   | ❌  | ✅ |
| gromore  | 6.6.1.3 | ✅  | ✅      | ✅  | ✅  | ✅    | ✅      | ❌   | ❌ | ❌ |

**注意:**
1.该版本是基于上述SDK平台版本进行开发适配，如需指定其他版本请联系技术同学确认；
2.SDK⽀持的架构有： x86_64 arm64（**由于联盟支持架构变更，亿帆联盟适配器支持架构也对应删除了arm64架构。故可能不支持模拟器运行，请使用真机测试**）；
3.原则上⽀持iOS12.0及及以上版本。如需支持较低版本，可通过拆分引入方式。

## 3. 快速接入

### 3.1 开发环境准备

- 开发工具：推荐使用Xcode 14及以上版本（23年4月起，Xcode 14以下编译的包不再支持上架app store）
- 部署目标：iOS 12.0及以上版本
- 开发管理工具：[CocoaPods](https://cocoapods.org/)

### 3.2 引入SDK

#### 方法一：手动部署
**1.导入依赖库**
右键点击⼯程，选择Add File to…，选择解压SDK包后得到的YFAdsSDK.xcframework(主SDK必须)，YFAdsCSJAdapter.xcframework(穿山甲)，YFAdsGDTAdapter.xcframework(优量汇)，YFAdsBDAdapter.xcframework(百青藤)，YFAdsKSAdapter.xcframework(快手)，YFAdsJDAdapter.xcframework(京东)，YFAdsTXAdapter.xcframework(Tanx)，YFAdsGROAdapter.xcframework(Gromore),点击Add。或者
将⽂件拖⼊Xcode⼯程⽬录结构中，在弹出的界⾯中勾选“Copy items into destination group's folder(if needed)”，并确保Add To Targets勾选相应的target。同时将YFAdsSDK.framework ⽬录⾥⾯的YFAdsSDK.bundle⽂件导⼊Xcode。如不知需要导入的平台，请联系运营同学。

**2.添加-ObjC**

在Target->Build Settings -> Other Linker Flags中添加-ObjC, 字母o和c大写。

**3.关闭Bitcode**

前往项目的Build Setting中的Enable Bitcode设置为NO

**4.添加系统依赖库**

前往项目的General中Frameworks,Libraries,and Embedded Content添加以下依赖库

```
// 公共依赖系统库【必须添加】
AdSupport.framework
AppTrackingTransparency.framework
AudioToolbox.framework
AVFoundation.framework
CoreGraphics.framework
CoreImage.framework
CoreLocation.framework
CoreMedia.framework
CoreMotion.framework
JavaScriptCore.framework
UIKit.framework
WebKit.framework
StoreKit.framework
Accelerate.framework
CoreTelephony.framework
SystemConfiguration.framework
Security.framework
MediaPlayer.framework
MapKit.framework
libc++.tbd
libz.tbd
libresolv.9.tbd
libsqlite3.tbd
libc++abi.tbd
SafariServices.framework
ImageIO.framework
MobileCoreServices.framework
// 穿山甲依赖系统库
CoreML.framework （6.3.0.0及以上版本新增）
CoreText.framework
QuartzCore.framework
DeviceCheck.framework依赖（4.8.0.3及以上版本新增）
libbz2.tbd
libiconv.tbd
libxml2.tbd
libc++abi.tbd
// 优量汇依赖系统库
libxml2.tbd
// 百度依赖系统库
MessageUI.framework
// 快手依赖系统库
MessageUI.framework
CoreData
QuickLook
AddressBook
c++
// 京东依赖系统库
Photos.framework
AssetsLibrary.framework
```



#### <font color="red">方法二（推荐）：</font>
**1.Cocoapods导入**
通过Cocoapods导⼊三⽅⼴告SDK，以及第三⽅依赖（如遇到拉不下来，可能是github访问问题，可以使⽤VPN），如不清楚需要接入的联盟平台，请咨询运营同学
***1.1***
```
# 亿帆SDK【必须】
pod 'YFAdsSDK', '6.0.4.3'
#  百度【必须】
pod 'BaiduMobAdSDK','5.373'
# 优量汇【必须】
pod 'GDTMobSDK' ,'4.15.22'
# 京东【必须】
pod 'JADYun', '2.6.8'
pod 'JADYunMotion', '2.6.8'  #京东摇一摇组件
#  穿山甲【必须】
pod 'Ads-CN','6.6.1.3', :subspecs => ['BUAdSDK', 'CSJMediation','BUAdLive-Lib']
#  快手【必须】
pod 'KSAdSDK','3.3.72'
# 微信OpenSDK【必须】，如App内已通过其他方式集成OpenSDK，无需再次集成
pod 'WechatOpenSDK-XCFramework'
```
***1.2 拆分模块方式引入***

```
# 亿帆SDK【必须】
pod 'YFAdsSDK/YFAdsSDK', '6.0.4.3'
#  百度【可选】
pod 'YFAdsSDK/YFAdsBDAdapter'
pod 'BaiduMobAdSDK','5.373'
# 优量汇【可选】
pod 'YFAdsSDK/YFAdsGDTAdapter'
pod 'GDTMobSDK' ,'4.15.22'
# 京东【可选】
pod 'YFAdsSDK/YFAdsJDAdapter'
pod 'JADYun', '2.6.8'
pod 'JADYunMotion', '2.6.8'  #京东摇一摇组件
#  穿山甲【可选】
pod 'YFAdsSDK/YFAdsCSJAdapter'
pod 'Ads-CN','6.6.1.3', :subspecs => ['BUAdSDK', 'CSJMediation','BUAdLive-Lib']
#  Gromore【可选】 
pod 'YFAdsSDK/YFAdsGROAdapter'
#  快手【可选】
pod 'YFAdsSDK/YFAdsKSAdapter'
pod 'KSAdSDK','3.3.72'
# 微信OpenSDK【必须】，如App内已通过其他方式集成OpenSDK，无需再次集成
pod 'WechatOpenSDK-XCFramework'
```
**2.穿山甲iOS直播拉流接入注意事项**
***2.1 背景***
穿山甲直播拉流类预算有利于提升广告收益和广告价值。
***2.2 获取 TeamID***
接入穿山甲直播拉流广告需将TeamID提供到亿帆广告的运营同学，主要用于抖音校验媒体安全性。
TeamID获取方法：进入[苹果开发者平台](https://developer.apple.com/account)，点击[会员资格详细信息](https://developer.apple.com/account#MembershipDetailsCard)，即可看到TeamID。
***2.3 接入说明***

1. 如宿主app不包含FFmpeg（TTSDK、ijkplayer等，或自行编译的FFmpeg），只需要增加BUAdLive-Lib的subspec即可。【推荐】
```
    pod 'Ads-CN','6.6.1.3', :subspecs => ['BUAdSDK', 'CSJMediation', 'BUAdLive-Lib']
```
2. 如宿主app包含FFmpeg
```
    pod 'Ads-CN', '6.6.1.3', :subspecs => ['BUAdSDK', 'CSJMediation', 'BUAdLive']
    pod 'TTSDKFramework', '1.44.2.7-premium', :subspecs => ['LivePull-Lite'], :source => 'https://github.com/volcengine/volcengine-specs'
    # 此版本不再依赖OneKit，可以删除，如有其他组件依赖OneKit可保留
    # pod 'OneKit', '1.4.2', :subspecs => ['BaseKit', 'Reachability', 'ByteDanceKit/Foundation'], :source => 'https://github.com/volcengine/volcengine-specs'
```
3. 如宿主app在穿山甲SDK 6.4.1.0版本前已经接入了直播拉流，需要移除OneKit，更新版本号完成升级
```
    pod 'Ads-CN', '6.6.1.3', :subspecs => ['BUAdSDK', 'CSJMediation', 'BUAdLive']
    pod 'TTSDK', '1.44.2.7-premium', :subspecs => ['LivePull-Lite'], :source => 'https://github.com/volcengine/volcengine-specs'
    #pod 'OneKit', '1.4.2', :subspecs => ['BaseKit', 'Reachability', 'ByteDanceKit/Foundation'], :source => 'https://github.com/volcengine/volcengine-specs'
```
#### <font color="red">注意事项：</font>

**1.HTTP权限设置：**

设置HTTP权限请求，需要在info.plist⾥⾯增加⼀条App Transport Security Settings，添加Allow Arbitrary Loads(NSAllowsArbitraryLoads)，值为YES

**2.删除Scene：**

1.先直接删除SceneDelegate.h .m⽂件
2.在AppDelegate.h添加@property (strong, nonatomic) UIWindow * window;属性
3.移除AppDelegate⾥⾯的UIScene代理
4.最后在info.plist⽂件中移除Application Scene Manifest

**3.位置权限：**

如果应⽤开启了位置权限，SDK可以获取应⽤位置信息⽤以精准推送⼴告，需要在应⽤的 info.plist 添加相应权限提示信息，避免AppStore 审核被拒：

```
Privacy - Location When In Use Usage Description
Privacy - Location Always and When In Use Usage Description
Privacy - Location Always Usage Description
Privacy - Location Usage Description
```

**<font color="red">4.iOS14适配（重要）：</font>**

由于iOS14.5系统策略更新，我们需要在App中添加SKAdNetwork标识和ATT权限，以避免⼴告收益降低。

1.升级穿⼭甲 iOS SDK 3.4.2.3 及以上版本，升级优量汇4.12.3及以上版本，提供了iOS14与SKAdNetwork⽀持
2.将SKAdNetwork ID 添加到 info.plist 中，以保证 SKAdNetwork 的正确运⾏，以下内容复制到您的info.plist中

```
穿⼭甲：238da6jt44.skadnetwork，22mmun2rn5.skadnetwork，x2jnk7ly8j.skadnetwork
优量汇：f7s53z58qe.skadnetwork
快手：r3y5dwb26t.skadnetwork
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
      <string>x2jnk7ly8j.skadnetwork</string>
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

3.获取App Tracking Transparency 权限，请更新您的 Info.plist，添加NSUserTrackingUsageDescription 字段和⾃定义⽂案描述

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

***5.1背景***
集成微信OpenSDK，可有效提升流量的填充和CPM值
***5.2集成步骤***
在微信开发平台注册APPID和Universal Links
集成微信open sdk
提供APPID和Universal Links给运营进⾏绑定

**<font color="red">6.LSApplicationQueriesSchemes⽩名单设置：</font>**

为了提升⼴告价值，需要在info.plist⾥⾯配置url⽩名单，确保配置在前50个以内。

```
    <key>LSApplicationQueriesSchemes</key>
    <array>
<!--	以下为必选配置-->
		<string>tel</string>
		<string>alipays</string>
		<string>taptap</string>
		<string>tbopen</string>
		<string>taobaolite</string>
		<string>duapp</string>
		<string>qiyi-iphone</string>
		<string>baiduboxlite</string>
		<string>diditaxi</string>
		<string>snssdk2329</string>
		<string>douyutv</string>
		<string>eleme</string>
		<string>openApp.jdMobile</string>
		<string>openjdjrapp</string>
		<string>kwai</string>
		<string>ksnebula</string>
		<string>iMeituan</string>
		<string>pinduoduo</string>
		<string>tmallopen</string>
		<string>sinaweibo</string>
		<string>VSSpecialSwitch</string>
		<string>fleamarket</string>
		<string>youku</string>
		<string>zhihu</string>
		<string>ucbrowser</string>
		<string>douyuapp</string>
<!--	以下为推荐配置-->
		<string>autohome</string>
		<string>taobaolive</string>
		<string>dangdang</string>
		<string>quark</string>
		<string>sky20170605</string>
		<string>yymobile</string>
		<string>meituanwaimai</string>
    </array>
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
    [YFAdSDKManager setupSDKWithAppId:@"APPID"];
```

### 3.6 扩展字段参数

⽬前⽀持多维度的扩展字段，可以设置⾃定义数据，后台可以根据维度做云控和数据统计

```
    NSMutableDictionary * customDefine = [[NSMutableDictionary alloc] initWithCapacity:0];
//    [customDefine setValue:@"c1" forKey:@"c1"];
//    [customDefine setValue:@"c2" forKey:@"c2"];
//    [customDefine setValue:@"c3" forKey:@"c3"];
//    [customDefine setValue:@"c4" forKey:@"c4"];
//    [customDefine setValue:@"5" forKey:@"c5"];
//    [customDefine setValue:@"6" forKey:@"c6"];
    [YFAdSDKSetting shareInstance].customDefine = customDefine;
    
///  自定义用户标签
    NSMutableDictionary * userDefine = [[NSMutableDictionary alloc] initWithCapacity:0];
//    这里需要替换成真实的用户ID
    [userDefine setValue:@"yf_demo_user_id" forKey:@"UserID"];
    [YFAdSDKSetting shareInstance].userDefine = userDefine;

    [YFAdSDKSetting shareInstance].customIDFA = idfa;
    [YFAdSDKSetting shareInstance].userId = @"test";

    // 是否允许SDK进行声道控制，默认允许
    [YFAdSDKSetting shareInstance].allowAudioSetting = YES;
```

## 4. ⼴告渲染

### 4.1 开屏⼴告

具体示例参照Demo项目中DemoSplashViewController.m或者AppDelegate.m

1.请求代码

 ```objective-c
// 在加载广告对象中设置强引用
@property(strong, nonatomic) YFAdSplash *splash;
// 开屏广告背景图 6.0.4.0起不再提供内部接口，开屏背景图由开发者自行管理
@property (nonatomic, strong) UIImageView *splashBackgroundView;

/// 获取当前最上层控制器
UIViewController *rootVC = self.window.rootViewController;
// 初始化自定义的广告背景图
if (!_splashBackgroundView)
	_splashBackgroundView = [UIImageView new];
_splashBackgroundView.image = [UIImage imageNamed:@"splashBg"];
// 自定义的背景图添加至主控制器 广告关闭或者失败时进行移除
[rootVC.view addSubview:_splashBackgroundView];
_splashBackgroundView.frame = UIScreen.mainScreen.bounds;
// 注意： 初始化传入当前可见最上层控制器，避免无法弹出落地页，广告位id见广告配置表
self.splash = [[YFAdSplash alloc] initWithAdUnitID:[YFEnvironmentManager getColdSPLASH_ID] viewController:rootVC];
self.splash.delegate = self;
/// 设置开屏底部视图（可选）不要超过屏幕高度的20%
UIImageView *imageView = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, kScreenW, 80)];
imageView.image = [UIImage imageNamed:@"app_logo"];
UILabel *bottomLabel = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, kScreenW, 80)];
// bottomLabel.text = @"这是开屏底部视图，不要超过屏幕高度的20%";
bottomLabel.textAlignment = NSTextAlignmentCenter;
[imageView addSubview:bottomLabel];
self.splash.bottomView = imageView;
// 超时时间
self.splash.timeout = 5;
// 是否展示底部logo视图
self.splash.showLogoRequire = YES;
// 加载广告
[self.splash loadAd];

 ```

2.回调方法

 ```objective-c
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

**开屏⼴告闪屏问题：**
**⾸⻚闪现之后在弹出⼴告。这种现象对⽤户体验不友好。推荐使用自定义开屏背景图来添加到首页上，具体实现可参照Demo中DemoSplashViewController开屏广告示例。**

### 4.2 横幅⼴告

具体示例参照Demo项目中DemoBannerViewController.m

1.请求代码

 ```objective-c
// 请求对象中设置强引用
@property(nonatomic, strong) YFAdBanner * fcAdBanner;

- (void)loadAdAndShow {
  // 期望的广告尺寸
	UIView *contentV = [[UIView alloc] initWithFrame:CGRectMake(0, 100, self.view.bounds.size.width, 		self.view.bounds.size.width * 400.0 /600.0)];
 	[self.view addSubview:contentV];
 // viewController建议传入最上层可见控制器，以免造成无法推出落地页影响转化和收益
	_fcAdBanner = [[YFAdBanner alloc] initWithAdUnitID:pID adContainer:contentV viewController:self];
	_fcAdBanner.delegate = self;
	[_fcAdBanner loadAndShowAd];
}
 ```

2.回调方法

 ```objective-c
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

具体示例参照Demo项目中DemoInterstitialViewController.m

1.请求代码

 ```objective-c
 // 请求类中设置强引用
 @property(nonatomic, strong) YFAdInterstitial * fcAdInterstitial;
 
 - (void)loadAdAndShow {
   // viewController建议传入最上层可见控制器，以免造成无法推出落地页影响转化和收益
    _fcAdInterstitial = [[YFAdInterstitial alloc] initWithAdUnitID:@"广告位id" viewController:self];
    _fcAdInterstitial.delegate = self;
    [_fcAdInterstitial loadAndShowAd];
}
 ```

2.回调方法

 ```objective-c
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

具体示例参照Demo项目中DemoFullScreenVideoController.m

1.请求代码

 ```objective-c
  // 请求类中设置强引用
 @property(nonatomic, strong) YFAdFullScreenVideo * fcAdFullScreenVideo;
 
 - (void)loadAdAndShow {
   // viewController建议传入最上层可见控制器，以免造成无法推出广告和落地页影响转化和收益
     _fcAdFullScreenVideo  = [[YFAdFullScreenVideo alloc] initWithAdUnitID:@"广告位id" viewController:self];
     _fcAdFullScreenVideo.delegate = self;
     [_fcAdFullScreenVideo loadAndShowAd];
}
 ```

2.回调方法

 ```objective-c
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

具体示例参照Demo项目中DemoRewardVideoViewController.m

1.请求代码

 ```objective-c
  // 请求类中设置强引用
 @property(nonatomic, strong) YFAdRewardVideo * fcAdRewardVideo; 
 
 - (void)loadAdAndShow {
   // viewController建议传入最上层可见控制器，以免造成无法推出广告和落地页影响转化和收益
   _fcAdRewardVideo = [[YFAdRewardVideo alloc] initWithAdUnitID:@"广告位id" viewController:self];
   _fcAdRewardVideo.delegate=self;
   [_fcAdRewardVideo loadAndShowAd];
}
 ```

2.回调方法

 ```objective-c
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

具体示例参照Demo项目中DemoListFeedExpressViewController.m

1.请求代码

 ```objective-c
  // 请求类中设置强引用
 @property(nonatomic, strong) YFAdNativeExpress * advanceFeed; 
 
 - (void)loadAdAndShow {
   // viewController建议传入最上层可见控制器，以免造成无法推出广告和落地页影响转化和收益
    _advanceFeed = [[YFAdNativeExpress alloc] initWithAdUnitID:@"广告位id" adContainer:nil  viewController:self adSize:CGSizeMake(self.view.bounds.size.width, 0)];
   	_advanceFeed.delegate = self;
   	_advanceFeed.count = 1;
   	[_advanceFeed loadAndShowAd];
}
 ```

 **接⼊建议：调⽤loadAds接⼝的时候，size的⾼度height传0；⼴告加载成功的时候，判断返回的⼴告View⾼度，如果是0还需要等待渲染成功再展示，如果⾼度⼤于0，可直接展示。**

2.回调方法

 ```objective-c
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
        return cell;
    }
}
 ```

### 4.6 媒体自渲染

具体示例参照Demo项目中DemoMediaRenderViewController.m

1.请求代码

 ```objective-c
  // 请求类中设置强引用
 @property(nonatomic, strong) YFAdMediaRender * adMediaRender; 

- (void)loadAndShowAd {
    [super loadAndShowAd];
    [self loadAdWithState:AdState_Normal];
  	// viewController建议传入最上层可见控制器，以免造成无法推出广告落地页影响转化和收益
    self.adMediaRender = [[YFAdMediaRender alloc] initWithAdUnitID:@"广告位id" viewController:self];
    self.adMediaRender.delegate = self;
    _isAdLoaded = false;
    [self.adMediaRender loadAndShowAd];
    [self loadAdWithState:AdState_Loading];
}
 ```

2.回调方法

 ```objective-c
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

- (void)mediaAdRenderSuccess:(YFAdMedia *)mediaAd {
    NSLog(@"广告曝光回调 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

- (void)mediaAdRenderFail:(YFAdMedia *)mediaAd {
    NSLog(@"广告曝光回调 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光失败", __func__]];
}

- (void)mediaAdDidClick:(YFAdMedia *)mediaAd {
    NSLog(@"广告点击 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击成功", __func__]];
}

- (void)mediaAdVideoPlayFinished:(YFAdMedia *)mediaAd {
    NSLog(@"广告视频播放完成 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告视频播放完成", __func__]];
}

 ```

### 4.6 视频贴片

具体示例参照Demo项目中DemoPatchViewController.m

1.请求代码

 ```objective-c
// 请求类中设置强引用
@property(nonatomic, strong) YFAdPatch * adPatch; 

- (void)loadAndShowAd{
    if (!_contentV) {
        _contentV = [[UIView alloc] initWithFrame:CGRectMake(0, 100, self.view.bounds.size.width, self.view.bounds.size.width * 400.0 /600.0)];
        [self.view addSubview:self.contentV];
    }
    if (!self.adPatch) {
      // viewController建议传入最上层可见控制器，以免造成无法推出广告落地页影响转化和收益
        self.adPatch = [[YFAdPatch alloc] initWithAdUnitID:@"广告位id" adContainer:_contentV viewController:self];
        self.adPatch.delegate = self;
        [self.adPatch loadAndShowAd];
    }
}
 ```

2.回调方法

 ```objective-c
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
 ```

### 4.7 Draw 视频

具体示例参照Demo项目中DemoDrawViewController.m

1.请求代码

 ```objective-c
// 请求类中设置强引用
@property(nonatomic, strong) YFAdDraw * advanceDraw; 

- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    
    _isLoadAndShow = NO;
    
    for (NSInteger i =0 ; i <= 5; i++) {
        [self.dataArr addObject:@"App NormalCell"];
    }
    // viewController建议传入最上层可见控制器，以免造成无法推出广告落地页影响转化和收益
    self.advanceDraw = [[YFAdDraw alloc] initWithAdUnitID:[YFEnvironmentManager getDRAW_ID] adContainer:nil viewController:self adSize:CGSizeMake(self.view.bounds.size.width, self.view.bounds.size.width * 400.0 /600.0)];
    self.advanceDraw.count = 1;
    self.advanceDraw.delegate = self;
    [self.advanceDraw loadAd];
    [self loadAdWithState:AdState_Loading];

}

 ```

2.回调方法

 ```objective-c
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

### 4.8 融合Banner

具体示例参照Demo项目中DemoFusionBannerViewController.m

1.请求代码

```objective-c
// 请求类中设置强引用
@property(nonatomic, strong) YFAdFusionBanner * adBanner; 

// 初始化广告加载器 
// viewController建议传入最上层可见控制器，以免造成无法推出广告和落地页影响转化和收益
self.adBanner = [[YFAdFusionBanner alloc] initWithAdUnitID:@"广告位id" viewController:self];
// 设置融合banner代理对象
self.adBanner.delegate = self;
// 设置融合banner加载数量（建议1条，最多3条）
self.adBanner.adCount = _isListMode ?  2 : 1;
// 设置融合banner返回广告尺寸宽度，高度按广告实际比例返回
self.adBanner.adWidth = self.view.bounds.size.width - (self.slider.value * 60 * 2);
// 加载广告
[self.adBanner loadAndShowAd];
```

2.回调方法

```objective-c
/// 广告数据拉取成功
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdLoadSuccess:(NSArray<YFAdFusionBannerView *> * _Nullable)views {
    if (views.count > 0) {
        self.isLoaded = YES;
        if(self.isOnlyLoad) {}
        [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功", __func__]];
        /// 调用渲染方法
        for (YFAdFusionBannerView *bannerView in views) {
            [bannerView render];
        }
    } else {
        NSLog(@"广告展示失败 %s  返回广告为空", __func__);
        //通知主线程刷新
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n广告返回为空", __func__]];
        });
    }
    
}

/// 广告加载失败
- (void)fcAdFailedWithError:(NSError *)error adapter:(id)adapter  description:(NSDictionary *)description{
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
    //通知主线程刷新
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常: \r\n%@", __func__,error.userInfo.description]];
        [self showErrorWithDescription:description];
    });
}

/// 广告曝光
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdShow:(YFAdFusionBannerView * _Nullable)adView {
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

/// 广告点击
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdClicked:(YFAdFusionBannerView * _Nullable)adView {
    NSLog(@"广告点击 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击", __func__]];
}

/// 广告渲染成功
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdRenderSuccess:(YFAdFusionBannerView * _Nullable)adView {
    ///  渲染成功后 依据广告大小重设容器；其他需求可同理实现
    if (_isListMode) {
        if (self.dataArrays.count > 5) {
            if (![self.dataArrays[0] isKindOfClass:[YFAdFusionBannerView class]]) {
                [self.dataArrays insertObject:adView atIndex:0];
            } else if (![self.dataArrays[2] isKindOfClass:[YFAdFusionBannerView class]]) {
                [self.dataArrays insertObject:adView atIndex:2];
            } else if (![self.dataArrays[4] isKindOfClass:[YFAdFusionBannerView class]]) {
                [self.dataArrays insertObject:adView atIndex:4];
            } else {
                [self.dataArrays addObject:adView];
            }
        }
        [self.tableView reloadData];
    } else {
        [self.contentV addSubview:adView];
        self.contentV.frame = CGRectMake(self.slider.value * 60, 10,adView.bounds.size.width, self.container.bounds.size.height);
        self.contentV.contentSize = CGSizeMake(adView.bounds.size.width, adView.bounds.size.height);
        adView.frame = CGRectMake(0, 0, adView.bounds.size.width, adView.bounds.size.height);
        [self.container addSubview:self.contentV];
    }
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染成功", __func__]];
}

/// 广告渲染失败
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdRenderFail:(YFAdFusionBannerView * _Nullable)adView {
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染失败", __func__]];
}

/// 广告被关闭
- (void)fcAdFusionBanner:(YFAdFusionBanner * _Nonnull)fusionBanner onAdClosed:(YFAdFusionBannerView * _Nullable)adView {
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭了", __func__]];
    if (_isListMode) {
        [self.dataArrays removeObject:adView];
        [self.tableView reloadData];
    } else {
        /// 广告关闭移除广告视图
        [adView removeFromSuperview];
        [self.container removeFromSuperview];
    }
    /// 可在此处理 fusionBanner 与其关联的广告视图，当全部广告关闭时，可释放fusionBanner加载器
    /// ...............
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
15003 : @"亿帆无广告填充",</br>
15004 : @"亿帆视频播放器初始化失败",
15005 : @"亿帆视频播放器资源出现未知错误",
15006 : @"亿帆视频播放器资源播放失败",

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

|                                                       数据类型                                                        |                                   收集情况                                    |                                                      备注                                                      |
| ------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------- |
| 1.精确位置 Precise Location </br>2.粗略位置 Rough Location                                                             | 1.精确位置-可选收集</br> 2.粗略位置-不收集                                        | 会获取地理位置信息⽤于⼴告投放与反作弊。应⽤被⽤户授予地理位置权限时，会获取地理位置信息，不会主动获取地理位置权限及地理位置信息。 |
| 设备ID                                                                                                               | 可选收集                                                                      | 设备ID当应⽤被⽤户授予⼴告追踪权限时，将获取idfa⽤于⼴告归因与追踪。                                                    |
| 1.使⽤数据 UsageData </br> 2.产品交互ProductInteraction</br>3.⼴告数据Advertising Data</br>4.其他使⽤数据 OtherUsage Data | 1.使⽤数据-不收集</br>2.产品交互-不收集</br>3.⼴告数据-收集</br>4.其他使⽤数据-不收集 | 将统计⼴告数据，以⽤于⼴告主统计投放结果。展示 、点击 、转化                                                           |
| 诊断Diagnostics</br>1.崩溃数据Crash Data</br>2.性能数据Performance Data</br>3.其他诊断数据 OtherDiagnostic Data           | 1.崩溃数据-收集</br>2.性能数据-收集其他</br>3.诊断数据-不收集                       | 崩溃数据联盟将收集联盟SDK带来的崩溃信息，以此来优化代码缺陷。性能数据联盟将收集SDK运⾏过程中性能数据，以优化SDK的性能。         |
| 1.其他数据 OtherData </br>2.其他数据类型Other Data Types</br>                                                           | 收集                                                                         | 技术上我们还会收集⼀些设备信息（例如，设备型号、操作系统及版本、时区、⽹络类型等）。                                        |
