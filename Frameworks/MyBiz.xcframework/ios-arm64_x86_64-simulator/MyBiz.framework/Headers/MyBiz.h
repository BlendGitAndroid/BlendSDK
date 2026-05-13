//
//  MyBiz.h
//  MyBiz
//
//  Created by admin on 2026/4/8.
//

#import <Foundation/Foundation.h>

//! Project version number for MyBiz.
FOUNDATION_EXPORT double MyBizVersionNumber;

//! Project version string for MyBiz.
FOUNDATION_EXPORT const unsigned char MyBizVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <MyBiz/PublicHeader.h>

// ========== 原有业务组件 ==========
#import <MyBiz/MyBizService.h>
#import <MyBiz/MyAbroadSetting.h>

// ========== MyKit - 消息模型层 ==========
#import <MyBiz/MyMessageType.h>
#import <MyBiz/MyMessageObject.h>
#import <MyBiz/MyMessage.h>
#import <MyBiz/MyImageObject.h>
#import <MyBiz/MyVideoObject.h>
#import <MyBiz/MyMessageModel.h>

// ========== MyKit - 消息工厂 & 协议 ==========
#import <MyBiz/MyMessageMaker.h>
#import <MyBiz/MyMessageSendingDelegate.h>

// ========== MyKit - 数据源 ==========
#import <MyBiz/MySessionDataSource.h>

// ========== MyKit - UI 组件 ==========
#import <MyBiz/MyInputView.h>
#import <MyBiz/MyMessageCell.h>
#import <MyBiz/MyTimestampCell.h>

// ========== MyBiz - 业务控制器 ==========
#import <MyBiz/MySessionViewController.h>

// ========== 资源加载工具 ==========
#import <MyBiz/MyResourceLoader.h>