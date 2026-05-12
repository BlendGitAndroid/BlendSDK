/**
 *  MyMessageMaker.h
 *  MyBiz (MyKit 子模块)
 *
 *  [架构层级]MyKit UI层 - 消息工厂
 *  [职  责]提供便捷的类方法快速创建各种类型的消息对象
 *  [关  系]
 *    - 依赖 MyMessage,MyImageObject,MyVideoObject
 *    - 被 MySessionViewController(业务层)调用来创建消息
 *    - 被 ViewController(Demo 层)调用来创建模拟回复消息
 *
 *  使用工厂模式的好处:
 *    1. 统一消息的创建逻辑,避免到处散落的初始化代码
 *    2. 自动处理默认值(如 isOutgoing,sendStatus)
 *    3. 参数校验(如空文本返回 nil)
 */

#import <UIKit/UIKit.h>

@class MyMessage;

NS_ASSUME_NONNULL_BEGIN

@interface MyMessageMaker : NSObject

/**
 *  创建一条文本消息(发送方向:自己发出)
 *
 *  @param text 文本内容,不能为空或纯空格
 *  @return 文本消息对象;如果 text 为空则返回 nil
 */
+ (nullable MyMessage *)msgWithText:(NSString *)text;

/**
 *  创建一条图片消息(发送方向:自己发出)
 *
 *  @param image UIImage 对象
 *  @return 图片消息对象;如果 image 为 nil 则返回 nil
 */
+ (nullable MyMessage *)msgWithImage:(UIImage *)image;

/**
 *  创建一条视频消息(发送方向:自己发出)
 *
 *  @param videoPath 视频文件的本地路径
 *  @return 视频消息对象;如果 videoPath 为 nil 则返回 nil
 */
+ (nullable MyMessage *)msgWithVideo:(NSString *)videoPath;

/**
 *  创建一条接收到的文本消息(发送方向:对方发来)
 *
 *  @param text 文本内容
 *  @param sender 发送者名称(如 "客服小美")
 *  @return 接收消息对象(isOutgoing=NO,sendStatus=Success)
 */
+ (nullable MyMessage *)incomingMsgWithText:(NSString *)text from:(NSString *)sender;

@end

NS_ASSUME_NONNULL_END
