//
//  DemoCommonSwitchCell.m
//  YFAdsDemo_Example
//
//  Created by Erik on 2025/3/26.
//  Copyright © 2025 Nanjing Fengchuan Yunju Infomation Technology Co., LTD. All rights reserved.
//

#import "DemoCommonSwitchCell.h"
#import <Masonry/Masonry.h>

@interface DemoCommonSwitchCell ()

@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UISwitch *switchBtn;

@end

@implementation DemoCommonSwitchCell


- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        [self setViews];
    }
    return self;
}

- (void)setViews {
    _titleLabel = [[UILabel alloc] init];
    _titleLabel.font = [UIFont systemFontOfSize:14];
    [self.contentView addSubview:_titleLabel];
    [_titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerY.mas_equalTo(0);
        make.left.mas_equalTo(15);
    }];
    
    _switchBtn = [UISwitch new];
    [_switchBtn addTarget:self action:@selector(switchStateDidChanged) forControlEvents:(UIControlEventValueChanged)];
    [self.contentView addSubview:_switchBtn];
    [_switchBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerY.mas_equalTo(0);
        make.right.mas_equalTo(-15);
    }];
}

- (void)updateTitle:(NSString *)title {
    self.titleLabel.text = title;
}

- (void)updateSwitchState:(BOOL)isOn {
    self.switchBtn.on = isOn;
}

- (void)switchStateDidChanged {
    if (self.switchStateChanged) {
        self.switchStateChanged(self.switchBtn.on);
    }
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
