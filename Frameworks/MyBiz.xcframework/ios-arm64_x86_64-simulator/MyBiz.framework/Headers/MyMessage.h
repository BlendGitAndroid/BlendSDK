/**
 *  MyMessage.h
 *  MyBiz (MyKit 子模块)
 *
 *  [架构层级]MyKit UI层 - 核心消息模型
 *  [职  责]描述一条完整的消息,包括内容,发送者,时间戳,发送状态等
 *  [关  系]
 *    - 依赖 MyMessageType.h(类型枚举)和 MyMessageObject.h(附件协议)
 *    - 被 MyMessageModel 包装后用于 Cell 渲染
 *    - 被 MySessionDataSource 管理(内存数组)
 *    - 被 MyMessageMaker 工厂创建
 *    - 通过 MyMessageSendingDelegate 协议传递给外部发送
 *
 *  这是整个消息系统的核心数据结构,贯穿从创建到展示的完整生命周期.
 */

#import <Foundation/Foundation.h>
#import <MyBiz/MyMessageType.h>
#import <MyBiz/MyMessageObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface MyMessage : NSObject

/** 消息唯一标识符(创建时自动生成 UUID) */
@property (nonatomic, copy, readonly) NSString *messageId;

/** 消息类型:文本 / 图片 / 视频 */
@property (nonatomic, assign) MyMessageType messageType;

/** 文本内容(仅 messageType == Text 时有值) */
@property (nonatomic, copy, nullable) NSString *text;

/**
 *  消息附件对象(图片或视频)
 *  仅 messageType == Image 或 Video 时有值
 *  可强转为 MyImageObject 或 MyVideoObject
 */
@property (nonatomic, strong, nullable) id<MyMessageObject> messageObject;

/** 发送者名称(如 "我","客服小美") */
@property (nonatomic, copy, nullable) NSString *from;

/**
 *  是否为自己发送的消息
 *  YES = 显示在右侧(蓝色气泡),NO = 显示在左侧(灰色气泡)
 */
@property (nonatomic, assign) BOOL isOutgoing;

/** 消息创建时间戳(用于时间分隔线判断和显示) */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  发送状态:Sending / Success / Failed
 *  仅对 isOutgoing == YES 的消息有意义
 *  UI 层根据此状态显示菊花/对勾/重试按钮
 */
@property (nonatomic, assign) MyMessageSendStatus sendStatus;

/**
 *  消息来源的客服类型
 *
 *  YES = 人工客服消息，NO = 机器人消息
 *  参考原SDK的 staffType 字段：staffType==0 为人工，staffType!=0 为机器人
 *  仅对 isOutgoing == NO（收到的消息）有意义
 */
@property (nonatomic, assign) BOOL humanOrMachine;

@end

NS_ASSUME_NONNULL_END
