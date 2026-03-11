
#import <YFAdsSDK/YFInterstitialView.h>
#import <YFAdsSDK/YFAdReportWorker.h>


NS_ASSUME_NONNULL_BEGIN

@interface YFAdEnvelopeVideoView : YFInterstitialView

@property (nonatomic, strong) YFAdReportWorker *reportWorker;
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;

@end

NS_ASSUME_NONNULL_END


