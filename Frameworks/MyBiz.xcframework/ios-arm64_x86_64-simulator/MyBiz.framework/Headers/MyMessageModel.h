/**
 *  MyMessageModel.h
 *  MyBiz (MyKit 子模块)
 *
 *  [架构层级]MyKit UI层 - 消息展示模型(ViewModel)
 *  [职  责]将 MyMessage 数据模型包装为 UI 可直接使用的展示模型
 *  [关  系]
 *    - 持有一个 MyMessage 对象
 *    - 被 MySessionDataSource 管理
 *    - 被 MyMessageCell 消费(通过 refreshWithModel: 方法)
 *
 *  [为什么需要这层包装?]
 *    MyMessage 是纯数据模型(内容,发送者等),不包含 UI 相关信息.
 *    MyMessageModel 在数据模型之上增加了 UI 需要的计算结果:
 *      - contentSize:根据文字长度或图片尺寸计算出的显示尺寸
 *      - isTimestamp:标记这是一个时间分隔行而非真正的消息
 *    这样 Cell 就不用每次都重新计算,提高列表滚动性能.
 */

#import <UIKit/UIKit.h>

@class MyMessage;

NS_ASSUME_NONNULL_BEGIN

@interface MyMessageModel : NSObject

/** 原始消息数据(时间戳行时为 nil) */
@property (nonatomic, strong, nullable) MyMessage *message;

/** 计算好的内容显示尺寸(文本气泡或图片/视频缩略图的大小) */
@property (nonatomic, assign) CGSize contentSize;

/** 是否为时间戳分隔行(YES 时使用 MyTimestampCell,message 对象用于获取时间) */
@property (nonatomic, assign) BOOL isTimestamp;

/**
 *  根据消息内容计算展示尺寸
 *
 *  @param maxWidth 最大允许宽度(通常为屏幕宽度 - 头像 - 间距)
 *
 *  计算逻辑:
 *    - 文本:根据字体和 maxWidth 计算多行文本的 boundingRect
 *    - 图片:按原始宽高比缩放,最大 200pt
 *    - 视频:同图片处理方式
 */
- (void)calculateContentSizeWithMaxWidth:(CGFloat)maxWidth;

@end

NS_ASSUME_NONNULL_END
