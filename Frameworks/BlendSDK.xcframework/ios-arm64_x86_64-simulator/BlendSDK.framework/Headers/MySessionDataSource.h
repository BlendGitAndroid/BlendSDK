/**
 *  MySessionDataSource.h
 *  MyBiz (MyKit 子模块)
 *
 *  [架构层级]MyKit UI层 - 消息数据源
 *  [职  责]管理消息的内存数组,负责添加消息,插入时间戳分隔,提供数据访问
 *  [关  系]
 *    - 内部持有 MyMessageModel 数组
 *    - 被 MySessionViewController 持有和使用
 *    - 自动在两条消息间隔超过 5 分钟时插入时间戳分隔行
 *    - 通过 MyMessageDB 实现消息持久化
 *
 *  [参  考] 原 SDK 消息数据源：
 *    - resetMessagesWithLimit: 从数据库加载最近消息
 *    - appendMessages: 追加消息到内存数组
 *    - loadHistoryMessagesWithLimit: 下拉加载历史
 */

#import <UIKit/UIKit.h>

@class MyMessage;
@class MyMessageModel;

NS_ASSUME_NONNULL_BEGIN

@interface MySessionDataSource : NSObject

/** 当前消息总数(包含时间戳分隔行) */
@property (nonatomic, assign, readonly) NSInteger modelCount;

/**
 *  从数据库加载最近的消息
 *
 *  在 viewDidLoad 时调用，从 SQLite 中读取最近 N 条消息并填充到内存数组。
 *
 *  @param limit 加载的消息数量上限
 */
- (void)loadRecentMessagesWithLimit:(NSInteger)limit;

/**
 *  追加一条消息到末尾（同时保存到数据库）
 *
 *  会自动判断是否需要在前面插入时间戳分隔行(间隔 > 5 分钟).
 *  返回本次实际插入的 IndexPath 数组(可能包含时间戳行 + 消息行).
 *
 *  @param message 消息对象
 *  @return 本次插入的所有 IndexPath(用于 UITableView insertRows 动画)
 */
- (NSArray<NSIndexPath *> *)appendMessage:(MyMessage *)message;

/**
 *  获取指定位置的展示模型
 *
 *  @param index 索引位置
 *  @return MyMessageModel(可能是消息行或时间戳行)
 */
- (nullable MyMessageModel *)modelAtIndex:(NSInteger)index;

@end

NS_ASSUME_NONNULL_END