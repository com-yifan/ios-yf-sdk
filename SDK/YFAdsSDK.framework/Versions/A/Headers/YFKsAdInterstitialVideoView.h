
#import <UIKit/UIKit.h>


#if __has_include(<KSAdSDK/KSAdSDK.h>)
#import "YFAdInteractionType.h"

#import "YFAdCustomModel.h"
#import "YFAdBaseView.h"
#import "YFAdView.h"
#import <KSAdSDK/KSAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class YFKsAdInterstitialVideoView;

@protocol YFKsAdInterstitialVideoViewDelegate <NSObject>
@optional

@end

@interface YFKsAdInterstitialVideoView : YFAdBaseView

@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong) UIButton *closeBtn;
@property (nonatomic, strong) UIView *subView;
@property (nonatomic, strong) UILabel *title;
@property (nonatomic, strong) UILabel *subTitle;
@property (nonatomic, strong) UILabel *otherBtn;
@property (nonatomic, strong) UIView *subBackView;
@property (nonatomic, strong) YFAdImageView *imgView;

@property (nonatomic, weak) id<YFKsAdInterstitialVideoViewDelegate> delegate;
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;
-(void)loadAdData:(KSNativeAd *)dataObject close: (void(^)(id))close;
;@end

NS_ASSUME_NONNULL_END
#endif
