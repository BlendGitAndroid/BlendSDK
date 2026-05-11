//
//  MyAbroadSetting.h
//  MyBiz
//
//  Created by admin on 2026/4/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MyAbroadSetting : NSObject

@property (nonatomic, assign) BOOL isForeign;
@property (nonatomic, copy) NSString *serverAddress;

+ (instancetype)shared;

@end

NS_ASSUME_NONNULL_END
