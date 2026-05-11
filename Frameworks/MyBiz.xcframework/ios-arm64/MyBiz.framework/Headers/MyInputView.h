/**
 *  MyInputView.h
 *  MyBiz (MyKit 子模块)
 *
 *  [架构层级]MyKit UI层 - 输入面板
 *  [职  责]底部输入栏,包含文本输入框,发送按钮,图片按钮,视频按钮
 *  [关  系]
 *    - 被 MySessionViewController 持有(底部固定位置)
 *    - 通过 MyInputViewDelegate 通知控制器用户的输入事件
 *    - 内部处理键盘弹起/收起的动画适配
 */

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

// 头文件里 @class，实现文件里 #import，
@class MyInputView;

/**
 *  输入面板代理协议
 *
 *  MySessionViewController 实现此协议来响应用户的输入操作.
 */
@protocol MyInputViewDelegate <NSObject>

/** 用户点击发送按钮,发送文本消息 */
- (void)inputView:(MyInputView *)inputView didSendText:(NSString *)text;

@optional

/** 用户点击相册按钮 */
- (void)inputViewDidTapPhoto:(MyInputView *)inputView;

/** 用户点击视频按钮 */
- (void)inputViewDidTapVideo:(MyInputView *)inputView;

/** 输入面板高度变化（更多面板展开/收起、文本换行） */
- (void)inputView:(MyInputView *)inputView didChangeHeight:(CGFloat)height;

/** 用户点击快捷入口按钮 */
- (void)inputView:(MyInputView *)inputView didTapActionWithTitle:(NSString *)title atIndex:(NSInteger)index;

@end

@class MyActionBar;

@interface MyInputView : UIView

@property (nonatomic, weak, nullable) id<MyInputViewDelegate> delegate;

/** 快捷入口操作栏（输入框上方，参考 原SDK输入视图.actionBar） */
@property (nonatomic, strong, readonly) MyActionBar *actionBar;

/** 输入框当前的总高度(包含按钮区域),供外部布局使用 */
@property (nonatomic, assign, readonly) CGFloat currentHeight;

/**
 *  设置快捷入口按钮
 *
 *  参考原SDK输入视图.setActionInfoArray: 的方式：
 *  传入标题数组，ActionBar 自动创建圆角药丸按钮并带推入动画
 *
 *  @param titles 按钮标题数组，传 nil 或空数组则隐藏
 */
- (void)setActionButtonTitles:(nullable NSArray<NSString *> *)titles;

@end

NS_ASSUME_NONNULL_END
