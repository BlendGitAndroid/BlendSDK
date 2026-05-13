/**
 *  MyMessageSendingDelegate.h
 *  MyBiz (MyKit 子模块)
 *
 *  [架构层级]MyKit UI层 - 消息发送协议(解耦桥梁)
 *  [职  责]定义消息发送的回调接口,实现 UI 层与通信层的解耦
 *  [关  系]
 *    - MySessionViewController 持有 weak delegate(调用方)
 *    - ViewController(Demo 层)实现此协议(被调用方)
 *    - 未来可由真实的 IM 通信层实现
 *
 *  [设计意图 - 为什么用 Delegate 而不是直接调用?]
 *    消息的 UI 展示(MyKit)不应该知道消息是怎么发出去的.
 *    发送可能走 WebSocket,HTTP,甚至本地模拟--UI 层不关心.
 *    通过 Delegate 协议,UI 层只负责"通知外部要发消息了",
 *    具体怎么发,发给谁,由实现方(Demo 或真实 IM)决定.
 *
 *  [调用链路]
 *    用户点击发送 -> MyInputView 通知 MySessionViewController
 *    -> MySessionViewController 调用 [delegate sendMessage:completion:]
 *    -> Demo 层的 ViewController 实现协议,模拟网络发送
 *    -> completion 回调通知成功/失败 -> UI 更新发送状态
 */

#import <Foundation/Foundation.h>

@class MyMessage;

NS_ASSUME_NONNULL_BEGIN

@protocol MyMessageSendingDelegate <NSObject>

@required

/**
 *  发送一条消息
 *
 *  @param message    要发送的消息对象
 *  @param completion 发送结果回调,error 为 nil 表示成功,非 nil 表示失败
 *
 *  实现方需要在适当时机调用 completion:
 *    - 成功:completion(nil)
 *    - 失败:completion([NSError ...])
 *
 *  注意:completion 必须在主线程回调,因为 UI 会在回调中更新状态
 */
- (void)sendMessage:(MyMessage *)message
         completion:(void(^)(NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
