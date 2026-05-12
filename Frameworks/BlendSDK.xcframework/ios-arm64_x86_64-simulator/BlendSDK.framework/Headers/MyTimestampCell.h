/**
 *  MyTimestampCell.h
 *  MyBiz (MyKit 子模块)
 *
 *  [架构层级]MyKit UI层 - 时间戳分隔 Cell
 *  [职  责]在消息列表中显示时间分隔线(如 "10:30","昨天 14:20")
 *  [关  系]被 MySessionViewController 的 UITableView 使用,当 model.isTimestamp == YES 时展示
 */

#import <UIKit/UIKit.h>

@class MyMessageModel;

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kMyTimestampCellIdentifier;

@interface MyTimestampCell : UITableViewCell

- (void)refreshWithModel:(MyMessageModel *)model;

@end

NS_ASSUME_NONNULL_END
