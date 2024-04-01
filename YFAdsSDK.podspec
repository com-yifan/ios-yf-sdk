Pod::Spec.new do |s|
  s.name = "YFAdsSDK"
  s.version = "5.3.3.6"
  s.summary = "iOS YFAdsSDK"
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"yifan"=>"576661787@qq.com"}
  s.homepage = "http://www.yifan.com/"
  s.description = "YFAdsSDK"
  s.requires_arc = true
  s.source  = { :git => "https://github.com/com-yifan/ios-yf-sdk.git", :tag => "#{s.version}" }
  valid_archs = ['i386', 'armv7', 'x86_64', 'arm64']
   s.pod_target_xcconfig = {'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'x86_64 arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'x86_64 arm64' }
  # s.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO'}
  # s.user_target_xcconfig = { 'ENABLE_BITCODE' => 'NO'}
  s.resource     = 'SDK/YFAdsSDK.bundle'
  s.ios.deployment_target    = '11.0'
  s.ios.vendored_framework   = 'SDK/YFAdsSDK.framework'
  s.xcconfig = {
      'VALID_ARCHS' =>  valid_archs.join(' '),
  }

end
