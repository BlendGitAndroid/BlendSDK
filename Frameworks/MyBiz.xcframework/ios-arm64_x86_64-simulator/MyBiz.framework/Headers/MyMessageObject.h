/**
 *  MyMessageObject.h
 *  MyBiz (MyKit 子模块)
 *
 *  [架构层级]MyKit UI层 - 消息附件协议
 *  [职  责]定义消息附件对象的通用协议,所有非文本内容(图片,视频)都遵循此协议
 *  [关  系]MyImageObject 和 MyVideoObject 遵循此协议;MyMessage 持有一个 id<MyMessageObject> 属性
 *
 *  通过协议实现多态:MyMessage 不关心具体是图片还是视频,
 *  只需要通过 messageObjectType 判断类型,然后强转为具体子类使用.
 */

#import <Foundation/Foundation.h>
#import <MyBiz/MyMessageType.h>

/**
 *  消息附件对象协议
 *
 *  所有非文本类型的消息内容都需要遵循此协议.
 *  UI 层通过此协议的 messageObjectType 方法来判断具体类型,
 *  再强转为 MyImageObject 或 MyVideoObject 来获取具体数据.
 */
@protocol MyMessageObject <NSObject>

@required

/**
 *  返回附件对象对应的消息类型
 *
 *  MyImageObject 返回 MyMessageTypeImage
 *  MyVideoObject 返回 MyMessageTypeVideo
 *
 *  @return 消息类型枚举值
 */
- (MyMessageType)messageObjectType;

@end
