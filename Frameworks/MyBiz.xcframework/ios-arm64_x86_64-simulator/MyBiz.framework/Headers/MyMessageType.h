/**
 *  MyMessageType.h
 *  MyBiz (MyKit 子模块)
 *
 *  [架构层级]MyKit UI层 - 消息模型基础定义
 *  [职  责]定义消息类型枚举和发送状态枚举
 *  [关  系]被 MyMessage,MyMessageCell 等所有消息相关类引用
 *
 *  这是整个消息系统最基础的类型定义文件,所有消息相关的类都依赖它.
 */

#import <Foundation/Foundation.h>

/**
 *  消息类型枚举
 *
 *  用于区分不同类型的消息内容.每种类型对应不同的 Cell 布局和渲染方式.
 *  - Text:  纯文本消息,显示在气泡内的 UILabel 中
 *  - Image: 图片消息,显示在气泡内的 UIImageView 中
 *  - Video: 视频消息,显示视频封面缩略图 + 播放按钮
 */
typedef NS_ENUM(NSInteger, MyMessageType) {
    MyMessageTypeText         = 0,   // 文本消息
    MyMessageTypeImage        = 1,   // 图片消息
    MyMessageTypeVideo        = 2,   // 视频消息
    MyMessageTypeNotification = 3,   // 通知消息（居中灰色提示，如"客服已接入"）
};

/**
 *  消息发送状态枚举
 *
 *  描述一条消息在发送生命周期中的当前状态.
 *  UI 层根据此状态显示不同的指示器(菊花/对勾/重试按钮).
 *
 *  状态流转:Sending -> Success 或 Sending -> Failed
 *  重试时:Failed -> Sending -> Success/Failed
 */
typedef NS_ENUM(NSInteger, MyMessageSendStatus) {
    MyMessageSendStatusSending = 0,   // 发送中(显示菊花)
    MyMessageSendStatusSuccess = 1,   // 发送成功(隐藏指示器)
    MyMessageSendStatusFailed  = 2,   // 发送失败(显示红色重试按钮)
};
