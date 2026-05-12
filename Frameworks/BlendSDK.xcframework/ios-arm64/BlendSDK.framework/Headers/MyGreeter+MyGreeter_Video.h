//
//  MyGreeter+MyGreeter_Video.h
//  MyVideoService
//
//  Created by admin on 2026/4/8.
//

#import <MySDK/MySDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface MyGreeter (MyGreeter_Video)

/// 发起视频通话
- (NSString *)startVideoCallWithSessionId:(NSString *)sessionId;

/// 挂断视频
- (NSString *)hangUpVideo;

@end

NS_ASSUME_NONNULL_END
