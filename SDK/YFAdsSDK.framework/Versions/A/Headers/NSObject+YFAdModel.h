
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (YFAdModel)

+ (nullable instancetype)fcAd_modelWithJSON:(id)json;

+ (nullable instancetype)fcAd_modelWithDictionary:(NSDictionary *)dictionary;

- (BOOL)fcAd_modelSetWithJSON:(id)json;

- (BOOL)fcAd_modelSetWithDictionary:(NSDictionary *)dic;

- (nullable id)fcAd_modelToJSONObject;

- (nullable NSData *)fcAd_modelToJSONData;

- (nullable NSString *)fcAd_modelToJSONString;

- (nullable id)fcAd_modelCopy;

- (void)fcAd_modelEncodeWithCoder:(NSCoder *)aCoder;

- (id)fcAd_modelInitWithCoder:(NSCoder *)aDecoder;

- (NSUInteger)fcAd_modelHash;

- (BOOL)fcAd_modelIsEqual:(id)model;

- (NSString *)fcAd_modelDescription;

@end

@interface NSString (FCAdModel)

+ (nullable NSDictionary *)fcAd_JsonStringToObject:(id)json;

@end

@interface NSArray (FCAdModel)

+ (nullable NSArray *)fcAd_modelArrayWithClass:(Class)cls json:(id)json;

@end

@interface NSDictionary (FCAdModel)

+ (nullable NSDictionary *)fcAd_modelDictionaryWithClass:(Class)cls json:(id)json;
@end

@protocol FCAdModel <NSObject>
@optional

+ (nullable NSDictionary<NSString *, id> *)modelCustomPropertyMapper;

+ (nullable NSDictionary<NSString *, id> *)modelContainerPropertyGenericClass;

+ (nullable Class)modelCustomClassForDictionary:(NSDictionary *)dictionary;

+ (nullable NSArray<NSString *> *)modelPropertyBlacklist;

+ (nullable NSArray<NSString *> *)modelPropertyWhitelist;

- (NSDictionary *)modelCustomWillTransformFromDictionary:(NSDictionary *)dic;

- (BOOL)modelCustomTransformFromDictionary:(NSDictionary *)dic;

- (BOOL)modelCustomTransformToDictionary:(NSMutableDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
