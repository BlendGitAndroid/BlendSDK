//
//  MyBizService.h
//  MyBiz
//
//  Created by admin on 2026/4/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MyBizService : NSObject

- (NSString *)fetchStaffInfo;
- (NSString *)createSessionWithUserId:(NSString *)userId;

- (NSString *)connectIM:(NSString *)userId;
- (NSString *)sendText:(NSString *)text toSession:(NSString *)sessionId;

- (NSString *)uploadFile:(NSString *)fileName;
- (NSString *)currentServerInfo;

@end

NS_ASSUME_NONNULL_END
