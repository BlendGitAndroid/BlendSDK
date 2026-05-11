//
//  MyVideoClient.h
//  MyVideoService
//
//  Created by admin on 2026/4/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MyVideoClient : NSObject

/// 发起视频通话
- (NSString *)startVideoCallWithSessionId:(NSString *)sessionId;

/// 挂断
- (NSString *)hangUp;

/// 是否通话中
- (BOOL)isCalling;

@end

NS_ASSUME_NONNULL_END
