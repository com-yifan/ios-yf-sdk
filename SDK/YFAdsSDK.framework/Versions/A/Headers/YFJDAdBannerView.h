
#import <UIKit/UIKit.h>
#if __has_include(<JADYun/JADYun.h>)
#import <JADYun/JADYun.h>
#import <JADYun/JADNativeAdData.h>
#import <JADYun/JADNativeAd.h>
#import "YFAdInteractionType.h"
#import "YFAdView.h"
#import "YFJDBannerView.h"

NS_ASSUME_NONNULL_BEGIN

@interface YFJDAdBannerView : YFJDBannerView
@property (nonatomic, strong) YFAdImageView *contentView;
@property (nonatomic, strong) UIButton *closeBtn;
@property (nonatomic, strong) UIView *subView;
@property (nonatomic, strong) UILabel *title;
@property (nonatomic, strong) UILabel *otherBtn;
-(instancetype)initWithFrame:(CGRect)frame model:(id)model;

-(float)getViewHeight;
-(void)loadAdData:(JADNativeAd *)dataObject;

@end

NS_ASSUME_NONNULL_END
#endif
