
#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCryptor.h>
#import <CommonCrypto/CommonDigest.h>
NS_ASSUME_NONNULL_BEGIN
 
@interface YFAdAESEncrypt : NSObject

+ (NSString *)AES256Encrypt:(NSString *)content Key:(NSString *)key;

+ (NSData *)AES256EncryptWithData:(NSData *)content Key:(NSString *)key;

+ (NSData *)AES256Decrypt:(NSString *)content Key:(NSString *)key;
+ (NSData *)AES256gzipDecrypt:(NSString *)content Key:(NSString *)key;

+ (NSData *)AES256DecryptWithData:(NSData *)content Key:(NSString *)key;

+ (NSString *)AES128Encrypt:(NSString *)content Key:(NSString *)key;

+ (NSString *)AES128Decrypt:(NSString *)content Key:(NSString *)key;

+ (NSString *)encryptAES:(NSString *)content;

+ (NSString *)decryptAES:(NSString *)content;

+ (NSString *)encryptAES128:(NSString *)content Key:(NSString *)key;

+ (NSData *)CCCryptWithOptration:(CCOperation)operation Data:(NSData *)data Key:(NSString *)key;

@end
 
NS_ASSUME_NONNULL_END
