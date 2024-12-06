//
//  YFDownloadNetworkTool.h
//  YFAdsSDK
//
//  Created by feng on 2023/11/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol YFDownLoadDelegate <NSObject>

@optional
- (void)backDownprogress:(float)progress tag:(NSInteger)tag;
- (void)downSucceed:(NSURL*)url tag:(NSInteger)tag;
- (void)downError:(NSError*)error tag:(NSInteger)tag;

@end

@interface YFDownloadNetworkTool : NSObject
@property (nonatomic, copy) NSString* fileName;
@property (nonatomic, weak) id<YFDownLoadDelegate> deleate;
@property (nonatomic, assign) NSInteger tag;// 某个文件下载的的标记
- (void)downFile:(NSString*)fileUrl;
- (void)suspendDownload;
- (void)suspendAndSaveFileDownload;
@end

NS_ASSUME_NONNULL_END
