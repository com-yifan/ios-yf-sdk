

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


#define YFEnvironmentNameKey @"YFEnvironmentNameKey"
//#define YFEnvironmentChangeNotification @"yf_changeEnvironment"


@interface YFEnvironmentManager : NSObject

+ (YFEnvironmentManager *)shareManager;

- (void)showPopWithVC:(UIViewController *)vc complete:(void(^)(NSString *))complete;

/**
 *  根据文件夹名更改环境
 */
- (void)configDoraemonKit;

+ (NSString *)getENV_NAME;

+ (NSString *)getAPP_ID;

+ (NSString *)getFULLSCREEN_ID;

+ (NSString *)getREWARD_ID;

+ (NSString *)getHotSPLASH_ID;

+ (NSString *)getColdSPLASH_ID;

+ (NSString *)getBANNER_ID;

+ (NSString *)getFusionBanner_ID;

+ (NSString *)getINSERT_ID;

+ (NSString *)getNATIVE_ID;

+ (NSString *)getDRAW_ID;

+ (NSString *)getPATCH_ID;

+ (NSString *)getMEDIA_ID;

+ (NSString *)getMall_ID;

+ (NSString *)getFC_CONF_URL;

+ (NSString *)getFC_UPLOAD_URL;

+ (NSString *)getYF_CONF_URL;

+ (NSString *)getYF_LOG_URL;

+ (NSString *)getYF_DATA_URL;

+ (NSString *)getTopPush_ID;
@end
