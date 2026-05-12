Pod::Spec.new do |s|
  s.name         = 'BlendSDK'
  s.version      = '1.1.0'
  s.summary      = 'A modular customer service SDK for iOS (binary distribution).'
  s.description  = <<-DESC
    BlendSDK is a modular customer service SDK that provides:
    - Chat session management (MyBiz)
    - IM communication layer (MyIMLib)
    - Text/Image/Video messaging
    - Cloud storage service (MyAWSService)
    - Video service (MyVideoService)
    - Robot and human agent switching
  DESC
  s.homepage     = 'https://github.com/BlendGitAndroid/BlendSDK'
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.author       = { 'Blend' => '1059152860@qq.com' }

  # source 指向公共仓库 BlendSDK，通过 tag 拉取对应版本
  s.source       = { :git => 'https://github.com/BlendGitAndroid/BlendSDK.git', :tag => s.version.to_s }

  s.platform     = :ios, '13.0'
  s.requires_arc = true

  # 二进制分发：包含所有 xcframework
  s.vendored_frameworks = [
    'Frameworks/MySDK.xcframework',
    'Frameworks/MyBiz.xcframework',
    'Frameworks/MyIMLib.xcframework',
    'Frameworks/MyAWSService.xcframework',
    'Frameworks/MyVideoService.xcframework'
  ]

  # 第三方依赖
  s.dependency 'SDWebImage', '~> 5.0'
  s.dependency 'IQKeyboardManager'

  # Framework 搜索路径
  s.pod_target_xcconfig = {
    'FRAMEWORK_SEARCH_PATHS' => '$(inherited) "${PODS_ROOT}/BlendSDK/Frameworks"'
  }
end
