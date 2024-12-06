#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

//extern NSString *const kYFAdNativeConfigurationContextAdOptionsViewFrameKey;//CGRect wrapped as NSValue, supported by facebook
//extern NSString *const kYFAdNativeConfigurationContextAdLogoViewFrameKey;//CGRect wrapped as NSValue, supported by gdt&baidu, defaults to top-left corner
//extern NSString *const kYFAdNativeConfigurationContextNetworkLogoViewFrameKey;//CGRect wrapped as NSValue, support by baidu, defaults to bottom-right corner
@protocol YFAdNativeDelegate;
@class YFAdNativePrepareInfo;

@interface YFAdNativeConfiguration : NSObject
/**
 You can store some extra network specific context info in this dictionary.
 */
@property(nonatomic) NSDictionary *context;
@property(nonatomic) Class renderingViewClass;
@property(nonatomic) CGRect ADFrame;
@property(nonatomic) CGRect mediaViewFrame;
@property(nonatomic, weak) UIViewController *rootViewController;
@property(nonatomic, weak) id<YFAdNativeDelegate> delegate;
@property(nonatomic) BOOL sizeToFit;
@property(nonatomic) BOOL useCustomPlayer;

@property(nonatomic, strong) YFAdNativePrepareInfo *nativePrepareInfo;


@end

NS_ASSUME_NONNULL_END
