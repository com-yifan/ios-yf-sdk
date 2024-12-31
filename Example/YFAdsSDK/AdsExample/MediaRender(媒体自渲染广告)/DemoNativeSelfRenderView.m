//
//  ATNativeSelfRenderView.m
//  AnyThinkSDKDemo
//
//  Created by GUO PENG on 2022/5/7.
//  Copyright © 2022 AnyThink. All rights reserved.
//

#import "DemoNativeSelfRenderView.h"
#import <Masonry/Masonry.h>
#import <SDWebImage/SDWebImage.h>
#import "DemoFeedbackView.h"
#define random(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)/255.0]
#define randomColor random(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))

@interface DemoNativeSelfRenderView()
@property(nonatomic, strong) YFAdMedia *nativeAdOffer;
@end

@implementation DemoNativeSelfRenderView

- (void)dealloc {
    NSLog(@"🔥---DemoNativeSelfRenderView--销毁");
}

- (instancetype)initWithOffer:(YFAdMedia *)offer {
    if (self = [super init]) {
        _nativeAdOffer = offer;
        [self addView];
        [self makeConstraintsForSubviews];
        [self setupUI];
    }
    return self;
}

- (void)addView {
    
    self.advertiserLabel = [[UILabel alloc]init];
    self.advertiserLabel.font = [UIFont boldSystemFontOfSize:15.0f];
    self.advertiserLabel.textColor = [UIColor blackColor];
    self.advertiserLabel.textAlignment = NSTextAlignmentLeft;
    self.advertiserLabel.userInteractionEnabled = YES;
    [self addSubview:self.advertiserLabel];
        
    self.titleLabel = [[UILabel alloc]init];
    self.titleLabel.font = [UIFont boldSystemFontOfSize:18.0f];
    self.titleLabel.textColor = [UIColor blackColor];
    self.titleLabel.textAlignment = NSTextAlignmentLeft;
    self.titleLabel.userInteractionEnabled = YES;
    [self addSubview:self.titleLabel];
    
    self.textLabel = [[UILabel alloc]init];
    self.textLabel.font = [UIFont systemFontOfSize:15.0f];
    self.textLabel.textColor = [UIColor blackColor];
    self.textLabel.userInteractionEnabled = YES;
    [self addSubview:self.textLabel];
    
    self.ctaLabel = [[UILabel alloc]init];
    self.ctaLabel.font = [UIFont systemFontOfSize:15.0f];
    self.ctaLabel.textColor = [UIColor blackColor];
    self.ctaLabel.userInteractionEnabled = YES;
    [self addSubview:self.ctaLabel];

    self.ratingLabel = [[UILabel alloc]init];
    self.ratingLabel.font = [UIFont systemFontOfSize:15.0f];
    self.ratingLabel.textColor = [UIColor blackColor];
    self.ratingLabel.userInteractionEnabled = YES;
    [self addSubview:self.ratingLabel];
    
    self.domainLabel = [[UILabel alloc]init];
    self.domainLabel.font = [UIFont systemFontOfSize:15.0f];
    self.domainLabel.textColor = [UIColor blackColor];
    self.domainLabel.userInteractionEnabled = YES;
    [self addSubview:self.domainLabel];
    
    self.warningLabel = [[UILabel alloc]init];
    self.warningLabel.font = [UIFont systemFontOfSize:15.0f];
    self.warningLabel.textColor = [UIColor blackColor];
    self.warningLabel.userInteractionEnabled = YES;
    [self addSubview:self.warningLabel];
    
    self.iconImageView = [[UIImageView alloc]init];
    self.iconImageView.layer.cornerRadius = 4.0f;
    self.iconImageView.layer.masksToBounds = YES;
    self.iconImageView.contentMode = UIViewContentModeScaleAspectFit;
    self.iconImageView.userInteractionEnabled = YES;
    [self addSubview:self.iconImageView];
    
    self.mainImageView = [[UIImageView alloc]init];
    self.mainImageView.contentMode = UIViewContentModeScaleAspectFit;
    self.mainImageView.userInteractionEnabled = YES;
    [self addSubview:self.mainImageView];
    

    if(self.nativeAdOffer.data.mediaView){
        self.mediaView = self.nativeAdOffer.data.mediaView;
        [self addSubview:self.mediaView];
    }
    
    self.logoUrlImageView = [[UIImageView alloc]init];
    self.logoUrlImageView.contentMode = UIViewContentModeScaleAspectFit;
    self.logoUrlImageView.userInteractionEnabled = YES;
    [self addSubview:self.logoUrlImageView];
    
    self.logoImageView = [[UIImageView alloc]init];
    self.logoImageView.contentMode = UIViewContentModeScaleAspectFit;
    self.logoImageView.userInteractionEnabled = YES;
    // 添加负反馈事件
    UITapGestureRecognizer *tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(showFeedBackView)];
    tapGesture.numberOfTapsRequired = 1;
    [self.logoImageView addGestureRecognizer:tapGesture];
    [self addSubview:self.logoImageView];
    
    // 关闭按钮
    self.closeBtn = [[UIButton alloc]init];
    [self.closeBtn addTarget:self action:@selector(removeFromSuperview) forControlEvents:UIControlEventTouchUpInside];
    if (@available(iOS 13.0, *)) {
        [self.closeBtn setImage:[UIImage systemImageNamed:@"xmark"] forState:UIControlStateNormal];
    } else {
        [self.closeBtn setTitle:@"x" forState:UIControlStateNormal];
        // Fallback on earlier versions
    }
    self.closeBtn.backgroundColor = [[UIColor grayColor] colorWithAlphaComponent:0.5];
    self.closeBtn.userInteractionEnabled = YES;
    self.closeBtn.layer.cornerRadius = 7.5;
    self.closeBtn.contentEdgeInsets = UIEdgeInsetsMake(2, 2, 2, 2);
    [self addSubview:self.closeBtn];
//    UIImage *closeImg = [UIImage imageNamed:@"icon_webview_close" inBundle:[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"AnyThinkSDK" ofType:@"bundle"]] compatibleWithTraitCollection:nil];
//    self.dislikeButton = [UIButton buttonWithType:UIButtonTypeCustom];
//    self.dislikeButton.backgroundColor = randomColor;
//    [self.dislikeButton setImage:closeImg forState:0];
//    [self addSubview:self.dislikeButton];
}

- (void)setupUI {
    if (self.nativeAdOffer.data.icon) {
        self.iconImageView.image = self.nativeAdOffer.data.icon;
    } else {
        [self.iconImageView sd_setImageWithURL:[NSURL URLWithString:self.nativeAdOffer.data.iconUrl]];
        NSLog(@"🔥----iconUrl:%@",self.nativeAdOffer.data.iconUrl);
    }

    if (self.nativeAdOffer.data.mainImage) {
        self.mainImageView.image = self.nativeAdOffer.data.mainImage;
    } else {
        [self.mainImageView sd_setImageWithURL:[NSURL URLWithString:self.nativeAdOffer.data.imageUrl]];
        NSLog(@"🔥----imageUrl:%@",self.nativeAdOffer.data.imageUrl);
    }
    
    //这两个logo建议优先使用logoUrl，此为联盟返回
    if (self.nativeAdOffer.data.logoUrl.length) {
        NSLog(@"🔥----logoUrl:%@",self.nativeAdOffer.data.logoUrl);
        [self.logoUrlImageView sd_setImageWithURL:[NSURL URLWithString:self.nativeAdOffer.data.logoUrl]];
    }
    if (self.nativeAdOffer.data.logo) {
        NSLog(@"🔥----logo:%@",self.nativeAdOffer.data.logo);
        self.logoImageView.image = self.nativeAdOffer.data.logo;
    } 
    if (!self.nativeAdOffer.data.logoUrl.length&&!self.nativeAdOffer.data.logo) {
        //如果没有logo返回，建议设置一个默认的logo
    }
        
    self.advertiserLabel.text = self.nativeAdOffer.data.advertiser;
    self.titleLabel.text = self.nativeAdOffer.data.title;
    self.textLabel.text = self.nativeAdOffer.data.mainText;
    self.ctaLabel.text = self.nativeAdOffer.data.ctaText;
    self.ratingLabel.text = [NSString stringWithFormat:@"%@", self.nativeAdOffer.data.rating ? self.nativeAdOffer.data.rating : @""];
    
    // 仅yandex平台支持，有返回时必须渲染
    self.domainLabel.text = self.nativeAdOffer.data.domain;
    self.warningLabel.text = self.nativeAdOffer.data.warning;
    NSLog(@"🔥----native文本内容title:%@ ; text:%@ ; cta:%@ ",self.nativeAdOffer.data.title,self.nativeAdOffer.data.mainText,self.nativeAdOffer.data.ctaText);
}

- (void)makeConstraintsForSubviews {
    self.backgroundColor = randomColor;
    self.titleLabel.backgroundColor = randomColor;
    self.textLabel.backgroundColor = randomColor;
    
    [self.closeBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.equalTo(@15);
        make.height.equalTo(@15);
        make.top.equalTo(self).equalTo(@10);
        make.right.equalTo(self).equalTo(@-10);
    }];
    
    [self.logoUrlImageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.equalTo(@37.5);
        make.height.equalTo(@13);
        make.bottom.equalTo(self).equalTo(@-5);
        make.left.equalTo(self).equalTo(@5);
    }];
    [self.logoImageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.equalTo(@37.5);
        make.height.equalTo(@13);
        make.bottom.equalTo(self).equalTo(@-5);
        make.left.equalTo(self.logoUrlImageView.mas_right).equalTo(@5);
    }];
    [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self).offset(100);
        make.right.equalTo(self).offset(-40);
        make.height.equalTo(@20);
        make.top.equalTo(self).offset(20);
    }];
    
    [self.textLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self).offset(100);
        make.right.equalTo(self).offset(-40);
        make.height.equalTo(@20);
        make.top.equalTo(self.titleLabel.mas_bottom).offset(10);
    }];
    
    [self.ctaLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.textLabel.mas_bottom).equalTo(@5);
        make.width.equalTo(@100);
        make.height.equalTo(@40);
        make.left.equalTo(self.textLabel.mas_left);
    }];
    
    [self.ratingLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.ctaLabel.mas_right).offset(20);
        make.height.equalTo(@40);
        make.top.equalTo(self.ctaLabel.mas_top).offset(0);
        make.width.equalTo(@20);
    }];
    
    [self.domainLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.ratingLabel.mas_right).offset(20);
        make.right.equalTo(self).offset(-40);
        make.top.equalTo(self.ctaLabel.mas_top).offset(0);
        make.height.equalTo(@40);
    }];
    
    [self.advertiserLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.height.equalTo(@30);
        make.right.equalTo(self).equalTo(@-5);
        make.left.equalTo(self.ctaLabel.mas_right).offset(50);
        make.bottom.equalTo(self.iconImageView.mas_bottom);
    }];
    
    [self.iconImageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self).offset(20);
        make.height.width.equalTo(@75);
        make.top.equalTo(self).offset(20);
    }];
    
    [self.mainImageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self).offset(20);
        make.right.equalTo(self).offset(-20);
        make.top.equalTo(self.iconImageView.mas_bottom).offset(25);
        make.bottom.equalTo(self).offset(-5);
    }];

    [self.warningLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self).offset(5);
        make.right.equalTo(self.mas_right).equalTo(@-5);
        make.bottom.equalTo(self).offset(-5);
        make.height.equalTo(@40);
    }];

//    [self.dislikeButton mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.height.width.equalTo(@30);
//        make.top.equalTo(self).equalTo(@5);
//        make.right.equalTo(self.mas_right).equalTo(@-5);
//    }];
    
    
    if(self.nativeAdOffer.data.mediaView){
        [self.nativeAdOffer.data.mediaView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.equalTo(self);
            make.right.equalTo(self);
            make.top.equalTo(self.iconImageView.mas_bottom).offset(25);
            make.bottom.equalTo(self);

        }];
    }
   
}

/// 显示负反馈视图
- (void)showFeedBackView {
    DemoFeedbackView *feedBackView = [[DemoFeedbackView alloc] init];
    [feedBackView show];
}


@end
