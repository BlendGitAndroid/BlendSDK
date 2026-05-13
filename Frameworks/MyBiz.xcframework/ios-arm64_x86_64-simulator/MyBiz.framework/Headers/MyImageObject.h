/**
 *  MyImageObject.h
 *  MyBiz (MyKit 子模块)
 *
 *  [架构层级]MyKit UI层 - 图片消息附件
 *  [职  责]存储图片消息的具体数据(图片对象,缩略图,文件路径,尺寸)
 *  [关  系]遵循 MyMessageObject 协议,被 MyMessage.messageObject 持有
 */

#import <UIKit/UIKit.h>
#import <MyBiz/MyMessageObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface MyImageObject : NSObject <MyMessageObject>

/** 原图(用于查看大图) */
@property (nonatomic, strong, nullable) UIImage *image;

/** 缩略图(用于消息列表中的预览显示,尺寸较小,加载更快) */
@property (nonatomic, strong, nullable) UIImage *thumbImage;

/** 图片文件在本地磁盘的路径 */
@property (nonatomic, copy, nullable) NSString *path;

/** 图片原始尺寸(用于计算 Cell 中的显示尺寸,保持宽高比) */
@property (nonatomic, assign) CGSize size;

@end

NS_ASSUME_NONNULL_END
