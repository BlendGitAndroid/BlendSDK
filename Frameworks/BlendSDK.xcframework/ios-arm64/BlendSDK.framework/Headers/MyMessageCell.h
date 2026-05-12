/**
 *  MyMessageCell.h
 *  MyBiz (MyKit 子模块)
 *
 *  [架构层级]MyKit UI层 - 消息气泡 Cell
 *  [职  责]展示一条消息:头像,气泡背景,文本/图片/视频内容,发送状态指示器
 *  [关  系]
 *    - 被 MySessionViewController 的 UITableView 使用
 *    - 通过 refreshWithModel: 接收 MyMessageModel 数据
 *    - 根据 isOutgoing 切换左右布局
 */

#import <UIKit/UIKit.h>

@class MyMessageModel;

NS_ASSUME_NONNULL_BEGIN

/** Cell 重用标识符 */
extern NSString * const kMyMessageCellIdentifier;

/**
 *  重试按钮点击回调
 *  当发送失败的消息点击重试按钮时触发
 */
typedef void(^MyMessageCellRetryBlock)(void);

@interface MyMessageCell : UITableViewCell

/** 重试按钮点击回调 */
@property (nonatomic, copy, nullable) MyMessageCellRetryBlock retryBlock;

/**
 *  使用消息模型刷新 Cell 内容
 *
 *  @param model 消息展示模型
 *
 *  刷新逻辑:
 *    1. 根据 isOutgoing 设置左右布局(头像位置,气泡颜色)
 *    2. 根据 messageType 切换显示内容(文本/图片/视频)
 *    3. 根据 sendStatus 显示发送状态(菊花/成功/重试按钮)
 */
- (void)refreshWithModel:(MyMessageModel *)model;

@end

NS_ASSUME_NONNULL_END
