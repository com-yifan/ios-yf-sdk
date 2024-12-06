//
//  YFTxAdFeedView.h
//  YFAdsSDK
//
//  Created by aiken on 2024/6/13.
//
#if __has_include(<TanxSDK/TanxSDK.h>)
#import <TanxSDK/TanxSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFTxAdFeedView : TXAdFeedView
@property (nonatomic, weak) TXAdFeedPlayerView *videoAdView;

@end

NS_ASSUME_NONNULL_END
#endif
