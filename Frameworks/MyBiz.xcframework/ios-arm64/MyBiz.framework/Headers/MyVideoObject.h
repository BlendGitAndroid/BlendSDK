/**
 *  MyVideoObject.h
 *  MyBiz (MyKit 子模块)
 *
 *  [架构层级]MyKit UI层 - 视频消息附件
 *  [职  责]存储视频消息的具体数据(文件路径,封面图,时长)
 *  [关  系]遵循 MyMessageObject 协议,被 MyMessage.messageObject 持有
 */

#import <UIKit/UIKit.h>
#import <MyBiz/MyMessageObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface MyVideoObject : NSObject <MyMessageObject>

/** 视频文件在本地磁盘的路径 */
@property (nonatomic, copy, nullable) NSString *path;

/** 视频封面图(用于消息列表中的缩略图预览) */
@property (nonatomic, strong, nullable) UIImage *coverImage;

/** 视频时长(单位:秒),用于在缩略图上显示时长标签 */
@property (nonatomic, assign) NSTimeInterval duration;

@end

NS_ASSUME_NONNULL_END
