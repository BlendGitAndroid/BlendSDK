Pod::Spec.new do |s|
  s.name         = 'BlendSDK'
  s.version      = '3.0.0'
  s.summary      = 'An iOS SDK demo for learning SDK development, packaging and distribution.'
  s.description  = <<-DESC
    BlendSDK is a demo SDK for learning iOS SDK development workflows.
    It demonstrates modular architecture, XCFramework packaging,
    and CocoaPods binary distribution.
    Features include chat UI, IM messaging, and media handling.
    Note: This is for learning purposes only, no real network requests involved.
  DESC
  s.homepage     = 'https://github.com/BlendGitAndroid/BlendSDK'
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.author       = { 'Blend' => '1059152860@qq.com' }

  s.source       = { :git => 'https://github.com/BlendGitAndroid/BlendSDK.git', :tag => s.version.to_s }

  s.platform     = :ios, '13.0'
  s.requires_arc = true

  # 二进制分发：单一 xcframework
  s.vendored_frameworks = 'Frameworks/BlendSDK.xcframework'

  # 静态库
  s.static_framework = true

  # 系统框架依赖 (静态库链接时需要)
  s.frameworks = 'UIKit', 'Foundation', 'MobileCoreServices'

  # 第三方依赖
  s.dependency 'SDWebImage', '~> 5.0'
  s.dependency 'IQKeyboardManager'
end
