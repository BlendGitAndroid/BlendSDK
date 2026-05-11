//
//  MyCloudStorage.h
//  MyAWSService
//
//  Created by admin on 2026/4/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MyCloudStorage : NSObject

/// 上传文件到 AWS S3
- (NSString *)uploadFileToS3:(NSString *)fileName;

/// 获取 S3 文件下载链接
- (NSString *)getS3DownloadUrl:(NSString *)fileName;

@end

NS_ASSUME_NONNULL_END
