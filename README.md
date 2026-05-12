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
pod 'BlendSDK', '~> 1.0.0'
```

然后执行：

```bash
pod install
```

### 手动集成

1. 下载本仓库 `Frameworks/` 目录下的所有 `.xcframework`
2. 拖入 Xcode 项目的 `Frameworks, Libraries, and Embedded Content`
3. 设置为 `Embed & Sign`
4. 手动添加依赖：[SDWebImage](https://github.com/SDWebImage/SDWebImage)、[IQKeyboardManager](https://github.com/hackiftekhar/IQKeyboardManager)

## 模块说明

BlendSDK 由 5 个模块组成：

| 模块 | 说明 |
|------|------|
| **MySDK** | 核心模块，提供 SDK 入口类 `MyGreeter`，包含版本查询、会话创建、消息发送等基础能力 |
| **MyBiz** | 业务 UI 层，提供完整的聊天界面 `MySessionViewController`，包含消息列表、输入面板、更多面板等 |
| **MyIMLib** | IM 通信层，负责底层即时通讯连接 |
| **MyAWSService** | 云存储服务，提供文件上传能力（`MyCloudStorage`） |
| **MyVideoService** | 视频通话服务，通过 Category 扩展为 `MyGreeter` 添加视频通话能力 |

### 架构依赖关系

```
MyVideoService ──> MySDK <── MyBiz
                              │
                           MyIMLib
                              │
                        MyAWSService
```

## 快速开始

### 1. 获取 SDK 版本

```objc
#import <MySDK/MyGreeter.h>

NSString *version = [MyGreeter sdkVersion];
NSLog(@"BlendSDK Version: %@", version);
```

### 2. 创建会话

```objc
MyGreeter *greeter = [[MyGreeter alloc] init];
NSString *session = [greeter startSessionWithUserId:@"user_123"];
```

### 3. 使用聊天界面

```objc
#import <MyBiz/MySessionViewController.h>
#import <MyBiz/MyMessageSendingDelegate.h>

// 创建聊天控制器
MySessionViewController *chatVC = [[MySessionViewController alloc] init];
chatVC.sessionId = @"session_001";
chatVC.sendingDelegate = self; // 实现 MyMessageSendingDelegate 协议

// 推入导航栈
[self.navigationController pushViewController:chatVC animated:YES];
```

### 4. 实现消息发送代理

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

### 5. 接收消息

```objc
// 当收到新消息时，调用此方法展示到聊天界面
MyMessage *incomingMsg = /* 从服务端收到的消息 */;
[chatVC receiveMessage:incomingMsg];
```

### 6. 视频通话（可选模块）

```objc
#import <MyVideoService/MyGreeter+MyGreeter_Video.h>

MyGreeter *greeter = [[MyGreeter alloc] init];
[greeter startVideoCallWithSessionId:@"session_001"];
// 挂断
[greeter hangUpVideo];
```

### 7. 云存储上传（可选模块）

```objc
#import <MyAWSService/MyCloudStorage.h>

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
| 1.0.0 | 2025-05-11 | 首次发布，包含完整的客服 SDK 功能 |

## 许可证

BlendSDK 基于 MIT 许可证发布，详见 [LICENSE](LICENSE)。
