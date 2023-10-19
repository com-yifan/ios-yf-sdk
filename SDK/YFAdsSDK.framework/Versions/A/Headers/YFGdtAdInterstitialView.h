
#import <UIKit/UIKit.h>


#if __has_include(<GDTMobSDK/GDTUnifiedNativeAdView.h>)
#import "YFAdInteractionType.h"
#import "YFAdCustomModel.h"
#import "YFAdView.h"
#import <GDTMobSDK/GDTUnifiedNativeAdView.h>

NS_ASSUME_NONNULL_BEGIN

@interface GdtAdInterView : GDTUnifiedNativeAdView
@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong) UIButton *closeBtn;
@property (nonatomic, strong) UIView *subView;
@property (nonatomic, strong) UILabel *title;
@property (nonatomic, strong) UILabel *otherBtn;
//广告是否已合法加载
@property (nonatomic, readonly) BOOL isValid;
//是否开启声音
@property (nonatomic, assign) BOOL videoSoundEnabled;
@end



@class GdtAdInterView;


@interface YFGdtAdInterstitialView : UIView
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
@property (nonatomic, strong) GdtAdInterView *adInterView;
-(void)loadAdData:(id)unifiedNativeDataObject;
-(void)show;
@end

NS_ASSUME_NONNULL_END
#endif
