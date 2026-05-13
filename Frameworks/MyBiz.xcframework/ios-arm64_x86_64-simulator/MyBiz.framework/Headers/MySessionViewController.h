/**
 *  MySessionViewController.h
 *  MyBiz
 *
 *  [架构层级] MyBiz 业务层 - 会话控制器 (核心)
 *  [职  责] 组装消息列表 (UITableView) 和输入面板 (MyInputView),
 *           管理消息发送/接收/重试的完整业务流程
 *  [关  系]
 *    - 持有 MySessionDataSource (数据源)
 *    - 持有 MyInputView (输入面板), 实现 MyInputViewDelegate
 *    - 持有 weak sendingDelegate (发送协议), 由 Demo 层实现
 *    - 使用 MyMessageMaker 创建消息对象
 *    - 使用 MyMessageCell / MyTimestampCell 展示消息
 *
 *  [调用链路 - 发送消息]
 *    用户输入文本 -> MyInputView.delegate.didSendText
 *    -> MySessionViewController 创建 MyMessage (Sending状态)
 *    -> 添加到 MySessionDataSource -> 刷新 TableView
 *    -> 调用 sendingDelegate.sendMessage:completion:
 *    -> completion 回调 -> 更新消息状态(Success/Failed) -> 刷新 Cell
 *
 *  [调用链路 - 接收消息]
 *    外部调用 receiveMessage: -> 添加到数据源 -> 刷新 TableView -> 自动滚动
 */

#import <UIKit/UIKit.h>
#import <MyBiz/MyMessageSendingDelegate.h>

@class MyMessage;

NS_ASSUME_NONNULL_BEGIN

@interface MySessionViewController : UIViewController

/** 会话标识符 (用于区分不同聊天会话) */
@property (nonatomic, copy, nullable) NSString *sessionId;

/**
 *  消息发送代理
 *
 *  由外部 (如 Demo 的 ViewController) 实现, 负责实际的消息发送逻辑.
 *  MySessionViewController 不知道消息怎么发送, 只负责 UI 展示.
 */
@property (nonatomic, weak, nullable) id<MyMessageSendingDelegate> sendingDelegate;

/**
 *  接收一条消息并展示到列表中
 *
 *  外部在收到新消息时调用此方法, 消息会自动添加到列表末尾.
 *  如果用户正在浏览历史消息 (不在底部 100pt 内), 不会自动滚动.
 *
 *  @param message 接收到的消息对象 (isOutgoing 应为 NO)
 */
- (void)receiveMessage:(MyMessage *)message;

@end

NS_ASSUME_NONNULL_END