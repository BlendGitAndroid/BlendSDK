# BlendSDK

BlendSDK 是一个模块化的 iOS 客服 SDK，提供即时通讯、消息管理、视频通话、云存储等能力。采用二进制分发（闭源），支持真机（arm64）和模拟器（arm64 + x86_64）。

## 环境要求

- iOS 13.0+
- Xcode 15.0+
- CocoaPods 1.16.0+

## 集成方式

### CocoaPods（推荐）

在 `Podfile` 中添加：

```ruby
pod 'BlendSDK', '~> 1.1.0'
```

然后执行：

```bash
pod install
```

### 手动集成

1. 下载本仓库 `Frameworks/BlendSDK.xcframework`
2. 拖入 Xcode 项目的 `Frameworks, Libraries, and Embedded Content`
3. 设置为 `Do Not Embed`（静态库不需要嵌入）
4. 手动添加依赖：[SDWebImage](https://github.com/SDWebImage/SDWebImage)、[IQKeyboardManager](https://github.com/hackiftekhar/IQKeyboardManager)

## 功能特性

- 完整的聊天会话界面
- 文本/图片/视频消息支持
- 机器人与人工客服切换
- 视频通话能力
- 云存储文件上传
- 客户满意度评价

## 快速开始

所有模块统一使用 `#import <BlendSDK/...>` 引入：

### 1. 导入 SDK

```objc
// 导入全部头文件（推荐）
#import <BlendSDK/BlendSDK.h>

// 或者按需导入单个头文件
#import <BlendSDK/MyGreeter.h>
#import <BlendSDK/MySessionViewController.h>
```

### 2. 获取 SDK 版本

```objc
#import <BlendSDK/MyGreeter.h>

NSString *version = [MyGreeter sdkVersion];
NSLog(@"BlendSDK Version: %@", version);
```

### 3. 创建会话

```objc
MyGreeter *greeter = [[MyGreeter alloc] init];
NSString *session = [greeter startSessionWithUserId:@"user_123"];
```

### 4. 使用聊天界面

```objc
#import <BlendSDK/MySessionViewController.h>
#import <BlendSDK/MyMessageSendingDelegate.h>

// 创建聊天控制器
MySessionViewController *chatVC = [[MySessionViewController alloc] init];
chatVC.sessionId = @"session_001";
chatVC.sendingDelegate = self; // 实现 MyMessageSendingDelegate 协议

// 推入导航栈
[self.navigationController pushViewController:chatVC animated:YES];
```

### 5. 实现消息发送代理

```objc
// 遵守协议
@interface YourViewController () <MyMessageSendingDelegate>
@end

// 实现发送方法
- (void)sendMessage:(MyMessage *)message
         completion:(void (^)(BOOL success))completion {
    // 在这里实现你的消息发送逻辑（如调用服务端 API）
    [YourAPI sendText:message.text completion:^(BOOL ok) {
        completion(ok);
    }];
}
```

### 6. 接收消息

```objc
// 当收到新消息时，调用此方法展示到聊天界面
MyMessage *incomingMsg = /* 从服务端收到的消息 */;
[chatVC receiveMessage:incomingMsg];
```

### 7. 视频通话

```objc
#import <BlendSDK/MyGreeter+MyGreeter_Video.h>

MyGreeter *greeter = [[MyGreeter alloc] init];
[greeter startVideoCallWithSessionId:@"session_001"];
// 挂断
[greeter hangUpVideo];
```

### 8. 云存储上传

```objc
#import <BlendSDK/MyCloudStorage.h>

MyCloudStorage *storage = [[MyCloudStorage alloc] init];
// 使用 storage 进行文件上传
```

## 核心 API

### MyGreeter（SDK 入口）

```objc
+ (NSString *)sdkVersion;                                       // 获取 SDK 版本号
- (NSString *)greetWithName:(NSString *)name;                   // 欢迎语
- (NSString *)startSessionWithUserId:(NSString *)userId;        // 创建会话
- (NSString *)connectIM:(NSString *)userId;                     // 连接 IM
- (NSString *)sendMessage:(NSString *)text toSession:(NSString *)sessionId; // 发送消息
- (NSString *)uploadFile:(NSString *)fileName;                  // 上传文件
- (NSString *)currentServerInfo;                                // 获取服务器信息
- (NSString *)getStaffInfo;                                     // 获取客服信息
```

### MySessionViewController（聊天界面）

```objc
@property (nonatomic, copy, nullable) NSString *sessionId;                          // 会话 ID
@property (nonatomic, weak, nullable) id<MyMessageSendingDelegate> sendingDelegate; // 发送代理
- (void)receiveMessage:(MyMessage *)message;                                        // 接收消息
```

### MyGreeter+Video（视频扩展）

```objc
- (NSString *)startVideoCallWithSessionId:(NSString *)sessionId; // 发起视频通话
- (NSString *)hangUpVideo;                                       // 挂断视频
```

## 版本记录

| 版本 | 日期 | 说明 |
|------|------|------|
| 1.1.0 | 2025-05-12 | 合并为单一 xcframework (静态库), 优化集成体验 |
| 1.0.0 | 2025-05-11 | 首次发布，包含完整的客服 SDK 功能 |

## 许可证

BlendSDK 基于 MIT 许可证发布，详见 [LICENSE](LICENSE)。
