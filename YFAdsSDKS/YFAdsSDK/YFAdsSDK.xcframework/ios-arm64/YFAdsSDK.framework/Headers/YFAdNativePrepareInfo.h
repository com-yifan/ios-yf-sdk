//
//  YFAdNativePrepareInfo.h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface YFAdNativePrepareInfo : NSObject

@property(nonatomic, strong) UILabel *advertiserLabel;
@property(nonatomic, strong) UILabel *textLabel;
@property(nonatomic, strong) UILabel *titleLabel;
@property(nonatomic, strong) UILabel *ctaLabel;
@property(nonatomic, strong) UILabel *ratingLabel;
@property(nonatomic, strong) UIImageView *iconImageView;
@property(nonatomic, strong) UIImageView *mainImageView;
@property(nonatomic, strong) UIImageView *logoImageView;
@property(nonatomic, strong) UIButton *dislikeButton;
@property(nonatomic, strong) UIView *mediaView;

// only for yandex native
@property(nonatomic, strong) UILabel *domainLabel;
@property(nonatomic, strong) UILabel *warningLabel;
@property(nonatomic, strong) UIView *mediaContainerView;

+ (instancetype)loadPrepareInfo: (void(^)(YFAdNativePrepareInfo *prepareInfo))loadPrepareInfoBlock;
                                            
@end

NS_ASSUME_NONNULL_END
