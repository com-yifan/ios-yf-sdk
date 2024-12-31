//
//  YFPreloadTableViewCell.m
//  YFAdsDemo_Example
//
//  Created by Erik on 2024/12/20.
//  Copyright © 2024 Nanjing Fengchuan Yunju Infomation Technology Co., LTD. All rights reserved.
//

#import "DemoPreloadTableViewCell.h"

@interface DemoPreloadTableViewCell ()

@property (nonatomic, strong) UILabel *titleLabel;

@end

@implementation DemoPreloadTableViewCell

#pragma mark - property

- (UILabel *)titleLabel {
    if (!_titleLabel) {
        _titleLabel = [UILabel new];
        _titleLabel.backgroundColor = UIColor.clearColor;
        _titleLabel.layer.cornerRadius = 5.f;
        _titleLabel.layer.masksToBounds = YES;
        _titleLabel.layer.borderWidth = 2.f;
        _titleLabel.layer.borderColor = UIColor.systemBlueColor.CGColor;
        _titleLabel.textColor = [UIColor systemBlueColor];
        _titleLabel.textAlignment = NSTextAlignmentCenter;
    }
    return _titleLabel;
}

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        [self setupViews];
    }
    return self;
}

- (void)setupViews {
    [self.contentView addSubview:self.titleLabel];
    [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.center.mas_equalTo(0);
        make.width.mas_equalTo((UIScreen.mainScreen.bounds.size.width - 2 * 50));
        make.height.mas_equalTo(40);
    }];
}

- (void)setTitle:(NSString *)title {
    self.titleLabel.text = title;
}

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
