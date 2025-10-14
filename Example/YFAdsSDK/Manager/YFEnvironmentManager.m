

#import "YFEnvironmentManager.h"
#import <YFAdsSDK/YFAdUtils.h>
#import <YFAdsSDK/YFAdSDKManager.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>
#import "JDStatusBarNotification.h"

static NSString *environmentName;
static NSMutableDictionary *EnvironmentDic;
static NSMutableArray *EnvironmentArr;
static YFEnvironmentManager *environmentManager;

@implementation YFEnvironmentManager

+ (YFEnvironmentManager *)shareManager {
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        environmentManager = [[YFEnvironmentManager alloc] init];
    });
    return environmentManager;
}

+ (void)initialize {

    EnvironmentDic=[NSMutableDictionary dictionary];
    EnvironmentArr=[NSMutableArray array];

    NSString *filePath = [[NSBundle mainBundle] pathForResource:@"environment" ofType:@"json"];
    NSData *data = [[NSData alloc] initWithContentsOfFile:filePath];
    
    NSArray *arr = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableContainers error:nil];
    EnvironmentArr = arr.mutableCopy;
    
    environmentName=[[NSUserDefaults standardUserDefaults]objectForKey:YFEnvironmentNameKey];
    if (environmentName==nil) {
        EnvironmentDic = EnvironmentArr.firstObject;
        environmentName = [self getENV_NAME];
    }
    
    for (NSDictionary *dic in EnvironmentArr) {
        NSString *tempname = dic[@"YF_ENV_NAME"];
        if ([tempname isEqualToString:environmentName]) {
            EnvironmentDic = dic.mutableCopy;
            environmentName = tempname;
            break;
        }
    }
}

- (void)showPopWithVC:(UIViewController *)vc complete:(void (^)(NSString *))complete{
    
    UIAlertController *actionSheet = [UIAlertController alertControllerWithTitle:nil message:nil preferredStyle:UIAlertControllerStyleActionSheet];
    
    for (NSDictionary *dic in EnvironmentArr) {
        [actionSheet addAction:[UIAlertAction actionWithTitle:dic[@"YF_ENV_NAME"] style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                [YFEnvironmentManager setEnvironmentWithName:dic[@"YF_ENV_NAME"]];
                complete(dic[@"YF_ENV_NAME"]);
        }]];
    }
    
    // 兼容ipad
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad) {
        actionSheet.popoverPresentationController.sourceView = vc.view;
        actionSheet.popoverPresentationController.sourceRect = CGRectMake(vc.view.bounds.size.width / 2.0, vc.view.bounds.size.height / 2.0, 1.0, 1.0);
        actionSheet.popoverPresentationController.permittedArrowDirections = UIPopoverArrowDirectionUp;
    }

    
    [actionSheet addAction:[UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:nil]];
    
    [vc presentViewController:actionSheet animated:YES completion:nil];
}


//配置Doraemon工具集
- (void)configDoraemonKit {

//    for (NSDictionary *dic in EnvironmentArr) {
//        [[DoraemonManager shareInstance] addPluginWithTitle:dic[@"YF_ENV_NAME"] icon:@"doraemon_default" desc:@"用于app内部环境切换功能" pluginName:@"KDDoraemonEnvPlugin" atModule:@"环境切换" handle:^(NSDictionary * _Nonnull itemData) {
//            [YFEnvironmentManager setEnvironmentWithName:dic[@"YF_ENV_NAME"]];
//            [[DoraemonManager shareInstance] hiddenHomeWindow];
//        }];
//    }

}

/**
 *  根据文件夹名更改环境
 */
+ (void)setEnvironmentWithName:(NSString *)name {
    if (name != nil) {
        for (NSDictionary *dic in EnvironmentArr) {
            NSString *tempname = dic[@"YF_ENV_NAME"];
            if ([tempname isEqualToString:name]) {
                EnvironmentDic = dic.mutableCopy;
                [[NSUserDefaults standardUserDefaults]setObject:name forKey:YFEnvironmentNameKey];
                //重新初始化
                [self initADSDK];
//                [[NSNotificationCenter defaultCenter] postNotificationName:YFEnvironmentChangeNotification object:nil];
                [JDStatusBarNotification showWithStatus:[NSString stringWithFormat:@"%@环境加载成功",name] dismissAfter:1.5];
                break;
            }
        }
    }
}

+ (void)initADSDK {
        
    ///   申请权限代码 requestAppTrackAuth;
        __block NSString *idfa = @"";
        ASIdentifierManager *manager = [ASIdentifierManager sharedManager];
        if (@available(iOS 14, *)) {
            [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
                if (status == ATTrackingManagerAuthorizationStatusAuthorized) {
                    idfa = [[manager advertisingIdentifier] UUIDString];
                }
                dispatch_async(dispatch_get_main_queue(), ^{
                });
            }];
        }else{
        if ([manager isAdvertisingTrackingEnabled]) {
            idfa = [[manager advertisingIdentifier] UUIDString];
        }
    }
    
    [YFAdSDKSetting shareInstance].fc_conf_url = [YFEnvironmentManager getFC_CONF_URL];
    [YFAdSDKSetting shareInstance].yf_conf_url = [YFEnvironmentManager getYF_CONF_URL];
    [YFAdSDKSetting shareInstance].fc_upload_url = [YFEnvironmentManager getFC_UPLOAD_URL];
    [YFAdSDKSetting shareInstance].yf_log_url = [YFEnvironmentManager getYF_LOG_URL];

    [YFAdSDKManager setupSDKWithAppId:[YFEnvironmentManager getAPP_ID]];
    
    

}

+ (NSString *)getENV_NAME {
    return EnvironmentDic[@"YF_ENV_NAME"];
}

+ (NSString *)getAPP_ID {
    return EnvironmentDic[@"YF_APP_ID"];
}

+ (NSString *)getFULLSCREEN_ID {
    return EnvironmentDic[@"YF_FULLSCREEN_ID"];
}

+ (NSString *)getREWARD_ID {
    return EnvironmentDic[@"YF_REWARD_ID"];
}

+ (NSString *)getHotSPLASH_ID{
    return EnvironmentDic[@"YF_HOT_SPLASH_ID"];
}

+ (NSString *)getColdSPLASH_ID{
    return EnvironmentDic[@"YF_COLD_SPLASH_ID"];
}

+ (NSString *)getBANNER_ID{
    return EnvironmentDic[@"YF_BANNER_ID"];
}

+ (NSString *)getFusionBanner_ID {
    return EnvironmentDic[@"YF_FUSIONBANNER_ID"];
}

+ (NSString *)getINSERT_ID{
    return EnvironmentDic[@"YF_INSERT_ID"];
}

+ (NSString *)getMEDIA_ID {
    return EnvironmentDic[@"YF_MEDIA_ID"];
}

+ (NSString *)getNATIVE_ID{
    return EnvironmentDic[@"YF_NATIVE_ID"];
}

+ (NSString *)getDRAW_ID{
    return EnvironmentDic[@"YF_DRAW_ID"];
}

+ (NSString *)getPATCH_ID{
    return EnvironmentDic[@"YF_PATCH_ID"];
}

+ (NSString *)getFC_CONF_URL{
    return EnvironmentDic[@"FC_CONF_URL"];
}

+ (NSString *)getFC_UPLOAD_URL{
    return EnvironmentDic[@"FC_UPLOAD_URL"];
}

+ (NSString *)getTopPush_ID {
    return EnvironmentDic[@"YF_TOPPUSH_ID"];
}

+ (NSString *)getYF_CONF_URL{
    return EnvironmentDic[@"YF_CONF_URL"];
}

+ (NSString *)getYF_LOG_URL{
    return EnvironmentDic[@"YF_LOG_URL"];
}


+ (NSString *)getYF_DATA_URL{
    return EnvironmentDic[@"YF_DATA_URL"];
}

@end
