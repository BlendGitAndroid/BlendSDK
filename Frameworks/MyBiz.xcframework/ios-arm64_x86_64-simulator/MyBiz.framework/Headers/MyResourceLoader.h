//
//  MyResourceLoader.h
//  MyBiz
//
//  统一加载 BlendSDK 资源 bundle (图片 / 多语言 / 配置)
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MyResourceLoader : NSObject

/// 从 BlendResource.bundle 加载图片(name 不需要带 @2x 后缀)
+ (nullable UIImage *)imageNamed:(NSString *)name;

/// 从 BlendLanguage.bundle 加载本地化文案,找不到时返回 key 本身
+ (NSString *)localizedStringForKey:(NSString *)key;

/// 找不到时返回 fallback 兜底
+ (NSString *)localizedStringForKey:(NSString *)key fallback:(NSString *)fallback;

/// 加载 BlendConfig.bundle/config.json 顶层字典(已缓存)
+ (nullable NSDictionary *)config;

/// 按点分隔 keyPath 取嵌套值,例如 @"endpoints.im_server_cn"
+ (nullable id)configValueForKeyPath:(NSString *)keyPath;

@end

NS_ASSUME_NONNULL_END
