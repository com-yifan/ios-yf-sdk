Pod::Spec.new do |s|
    s.name             = 'YFAdsSDK'
    s.version          = '6.0.5.0'
    s.summary          = 'iOS YFAdsSDK'
    s.description      = <<-DESC
    欢迎大家使用YFAdsSDK
    DESC

    s.homepage         = 'http://www.yifan.com/'

    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.author           = { 'yifan' => '576661787@qq.com' }
    s.source  = { :git => "https://github.com/com-yifan/ios-yf-sdk.git", :tag => "#{s.version}" }

    s.ios.deployment_target = '11.0'
    s.platform     = :ios, "11.0"

    s.frameworks = 'UIKit', 'Foundation', 'StoreKit', 'MobileCoreServices', 'WebKit', 'MediaPlayer', 'CoreMedia', 'CoreLocation', 'AVFoundation', 'CoreTelephony', 'SystemConfiguration', 'AdSupport', 'CoreMotion', 'Accelerate', 'QuartzCore', 'Security', 'ImageIO', 'CFNetwork', 'CoreGraphics', 'SafariServices'

    s.libraries = 'resolv.9', 'c++', 'z', 'sqlite3', 'bz2', 'xml2', 'c++abi', 'sqlite3.0'

    s.pod_target_xcconfig = {
        'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
        'DEFINES_MODULE' => 'YES'
      }
    s.user_target_xcconfig = {
        'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
        'DEFINES_MODULE' => 'YES'
      }
    s.default_subspecs = 'YFAdsBDAdapter', 'YFAdsGDTAdapter', 'YFAdsJDAdapter', 'YFAdsKSAdapter', 'YFAdsCSJAdapter', 'YFAdsGROAdapter'

    s.subspec 'YFAdsSubstrate' do |ss|
        ss.vendored_frameworks = 'YFAdsSDKS/YFAdsSubstrate/*.xcframework'
        ss.preserve_paths = 'YFAdsSDKS/YFAdsSubstrate/*.xcframework'
    end

    s.subspec 'YFAdsSDK' do |ss|
        ss.dependency 'YFAdsSDK/YFAdsSubstrate'
        ss.vendored_frameworks = 'YFAdsSDKS/YFAdsSDK/*.xcframework'
        ss.preserve_paths = 'YFAdsSDKS/YFAdsSDK/*.xcframework'
        ss.resources = 'YFAdsSDKS/YFAdsSDK/*.bundle'
    end

    s.subspec 'YFAdsBDAdapter' do |ss|
        ss.vendored_frameworks = 'YFAdsSDKS/YFAdsBDAdapter/*.xcframework'
        ss.dependency 'YFAdsSDK/YFAdsSDK'
    end

    s.subspec 'YFAdsGDTAdapter' do |ss|
        ss.vendored_frameworks = 'YFAdsSDKS/YFAdsGDTAdapter/*.xcframework'
        ss.dependency 'YFAdsSDK/YFAdsSDK'
    end

    s.subspec 'YFAdsJDAdapter' do |ss|
        ss.vendored_frameworks = 'YFAdsSDKS/YFAdsJDAdapter/*.xcframework'
        ss.dependency 'YFAdsSDK/YFAdsSDK'
    end

    s.subspec 'YFAdsKSAdapter' do |ss|
        ss.vendored_frameworks = 'YFAdsSDKS/YFAdsKSAdapter/*.xcframework'
        ss.dependency 'YFAdsSDK/YFAdsSDK'
    end

    s.subspec 'YFAdsCSJAdapter' do |ss|
        ss.vendored_frameworks = 'YFAdsSDKS/YFAdsCSJAdapter/*.xcframework'
        ss.dependency 'YFAdsSDK/YFAdsSDK'
    end

    s.subspec 'YFAdsGROAdapter' do |ss|
        ss.vendored_frameworks = 'YFAdsSDKS/YFAdsGROAdapter/*.xcframework'
        ss.dependency 'YFAdsSDK/YFAdsSDK'
    end
end
