//
//  MyGreeter.h
//  MySDK
//
//  Created by admin on 2026/4/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MyGreeter : NSObject

-(NSString *)greetWithName:(NSString *)name;

+(NSString *)sdkVersion;

- (NSString *)getStaffInfo;

- (NSString *)startSessionWithUserId:(NSString *)userId;

- (NSString *)connectIM:(NSString *)userId;

- (NSString *)sendMessage:(NSString *)text toSession:(NSString *)sessionId;

- (NSString *)uploadFile:(NSString *)fileName;
- (NSString *)currentServerInfo;

@end

NS_ASSUME_NONNULL_END
