//
//  NSArray+Addition.h
//  YFAdsSDK
//
//  Created by Erik on 2024/11/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray<__covariant ObjectType> (Addition)

- (nullable ObjectType)yf_objectOrNilAtIndex:(NSUInteger)index;

@end


@interface NSMutableArray<ObjectType> (Addition)

/// 倒序
- (void)yf_reverse;

/// 随机排序
- (void)yf_shuffle;

- (id)yf_objectAtIndexSafely:(NSUInteger)index;

- (void)yf_addObjectSafely:(id)anObject;

- (void)yf_insertObjectSafely:(id)anObject atIndex:(NSUInteger)index;

- (void)yf_removeObjectAtIndexSafely:(NSUInteger)index;

- (void)yf_removeObjectSafely:(id)anObject;

- (void)yf_replaceObjectAtIndexSafely:(NSUInteger)index withObject:(id)anObject;

@end

NS_ASSUME_NONNULL_END
