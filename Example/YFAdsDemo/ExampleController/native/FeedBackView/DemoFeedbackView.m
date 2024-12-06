//
//  DemoFeedbackView.m
//  YFAdsSDK_Example
//
//  Created by 麻明康 on 2024/10/13.
//  Copyright © 2024 Cheng455153666. All rights reserved.
//

#import "DemoFeedbackView.h"
@interface DemoFeedbackView ()
@property (nonatomic, strong) UIView *contentView;
@property (nonatomic, strong) UIButton *closeBtn;
@property (nonatomic, strong) UIView *subView;
@property (nonatomic, strong) UILabel *title;

@end
@implementation DemoFeedbackView

-(instancetype)init {
    if(self = [super init]){
        self.frame = UIScreen.mainScreen.bounds;
        self.backgroundColor = [UIColor colorWithRed:0.0 green:0.0 blue:0.0 alpha:0.6];
        [self setupViews];
    }
    return self;
}

-(void)setupViews {
    
    UILabel * one = [self createText:@"内容无法正常展示 (卡顿、黑白屏)" backColor:nil textColor:UIColor.blackColor];
    UIView * line1 = [self line];
    UILabel * two = [self createText:@"无法关闭" backColor:nil textColor:UIColor.blackColor];
    UIView * line2 = [self line];
    UILabel * three = [self createText:@"不感兴趣" backColor:nil textColor:UIColor.blackColor];
    UIView * line3 = [self line];
    UILabel * four = [self createText:@"举报广告" backColor:nil textColor:UIColor.blackColor];
    UILabel * five = [self createText:@"虚假欺诈" backColor:[UIColor colorWithRed:250/255.0  green:250/255.0 blue:250/255.0 alpha:1] textColor:[UIColor colorWithRed:153/255.0  green:153/255.0 blue:153/255.0 alpha:1]];
    UILabel * six = [self createText:@"低俗色情" backColor:[UIColor colorWithRed:250/255.0  green:250/255.0 blue:250/255.0 alpha:1] textColor:[UIColor colorWithRed:153/255.0  green:153/255.0 blue:153/255.0 alpha:1]];
    UILabel * seven = [self createText:@"疑似抄袭" backColor:[UIColor colorWithRed:250/255.0  green:250/255.0 blue:250/255.0 alpha:1] textColor:[UIColor colorWithRed:153/255.0  green:153/255.0 blue:153/255.0 alpha:1]];
    UILabel * eight = [self createText:@"违法违规" backColor:[UIColor colorWithRed:250/255.0  green:250/255.0 blue:250/255.0 alpha:1] textColor:[UIColor colorWithRed:153/255.0  green:153/255.0 blue:153/255.0 alpha:1]];
    
    [self addSubview:self.contentView];
    [self.contentView addSubview:one];
    [self.contentView addSubview:two];
    [self.contentView addSubview:three];
    [self.contentView addSubview:four];
    [self.contentView addSubview:five];
    [self.contentView addSubview:six];
    [self.contentView addSubview:seven];
    [self.contentView addSubview:eight];
    [self.contentView addSubview:line1];
    [self.contentView addSubview:line2];
    [self.contentView addSubview:line3];
    [self.contentView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(self.mas_centerX);
        make.centerY.mas_equalTo(self.mas_centerY);
        make.height.mas_equalTo(310);
        make.width.mas_equalTo((UIScreen.mainScreen.bounds.size.width - 60));
    }];
    
    [one mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(self.contentView.mas_top);
        make.height.mas_equalTo(50);
        make.left.mas_equalTo(self.contentView.mas_left).offset(10);
        make.right.mas_equalTo(self.contentView.mas_right).offset(-10);
    }];
    [line1 mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(one.mas_bottom);
        make.left.right.equalTo(one);
        make.height.mas_equalTo(0.5);
    }];
    [two mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(line1.mas_bottom);
        make.height.mas_equalTo(50);
        make.left.mas_equalTo(self.contentView.mas_left).offset(10);
        make.right.mas_equalTo(self.contentView.mas_right).offset(-10);
    }];
    [line2 mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(two.mas_bottom);
        make.left.right.equalTo(one);
        make.height.mas_equalTo(0.5);
    }];
    [three mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(line2.mas_bottom);
        make.height.mas_equalTo(50);
        make.left.mas_equalTo(self.contentView.mas_left).offset(10);
        make.right.mas_equalTo(self.contentView.mas_right).offset(-10);
    }];
    [line3 mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(three.mas_bottom);
        make.left.right.equalTo(one);
        make.height.mas_equalTo(0.5);
    }];
    [four mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(line3.mas_bottom);
        make.height.mas_equalTo(50);
        make.left.mas_equalTo(self.contentView.mas_left).offset(10);
        make.right.mas_equalTo(self.contentView.mas_right).offset(-10);
    }];
    five.textAlignment = NSTextAlignmentCenter;
    [five mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.contentView.mas_left).offset(10);
        make.top.equalTo(four.mas_bottom);
        make.size.mas_equalTo(CGSizeMake(100, 40));
    }];
    six.textAlignment = NSTextAlignmentCenter;
    [six mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(four.mas_bottom);
        make.size.mas_equalTo(CGSizeMake(100, 40));
        make.left.mas_equalTo(five.mas_right).offset(10);
    }];
    seven.textAlignment = NSTextAlignmentCenter;
    [seven mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.contentView.mas_left).offset(10);
        make.top.equalTo(six.mas_bottom).offset(10);
        make.size.mas_equalTo(CGSizeMake(100, 40));
    }];
    eight.textAlignment = NSTextAlignmentCenter;
    [eight mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(six.mas_bottom).offset(10);
        make.size.mas_equalTo(CGSizeMake(100, 40));
        make.left.equalTo(seven.mas_right).offset(10);
    }];
    [self layoutViews];
}

-(void)layoutViews {}

-(void)show {
    [[UIApplication sharedApplication].keyWindow addSubview:self];
}

-(void)close {
    [self removeFromSuperview];
}

-(UILabel *)createText:(NSString *)title backColor:(UIColor *)backColor textColor:(UIColor *)textColor {
    
    UILabel *label = [[UILabel alloc] init];
    label.text = title;
    label.baselineAdjustment = UIBaselineAdjustmentAlignCenters;
    label.clipsToBounds = YES;
    [label sizeToFit];
    label.textColor = textColor ? textColor:UIColor.blackColor;
    label.backgroundColor = backColor ? backColor:UIColor.clearColor;

    return label;
}



-(UIView *)line {
    UIView *label = [[UIView alloc] init];
    label.backgroundColor = [UIColor colorWithRed:250/255.0  green:250/255.0 blue:250/255.0 alpha:1];
    return label;
}

-(void)tapAction {
    [self close];
}

#pragma mark dynamic getter

- (UIView *)contentView;
{
  if (_contentView == nil) {
      _contentView = [[UIView alloc] init];
      _contentView.backgroundColor = UIColor.whiteColor;
      _contentView.clipsToBounds = YES;
      _contentView.layer.cornerRadius = 10;
      _contentView.userInteractionEnabled = YES;
      UITapGestureRecognizer *tapGR = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapAction)];
      tapGR.numberOfTapsRequired = 1;
      tapGR.numberOfTouchesRequired = 1;
      [_contentView addGestureRecognizer:tapGR];
   
  }
  return _contentView;
}


- (UIView *)subView;
{
    if (_subView == nil) {
        _subView = [[UIView alloc] init];
        _subView.backgroundColor = [UIColor colorWithRed:0.0 green:0.0 blue:0.0 alpha:0.6];;
    }
    return _subView;
}

- (UILabel *)title;
{
  if (_title == nil) {
      _title = [[UILabel alloc] init];
      _title.baselineAdjustment = UIBaselineAdjustmentAlignCenters;
      _title.clipsToBounds = YES;
      [_title sizeToFit];
      _title.textColor = UIColor.whiteColor;
  }
  return _title;
}

@end
