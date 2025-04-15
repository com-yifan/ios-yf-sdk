//
//  DemoEarlyRetrunCell.m
//  YFAdsDemo_Example
//
//  Created by 麻明康 on 2025/3/25.
//  Copyright © 2025 Nanjing Fengchuan Yunju Infomation Technology Co., LTD. All rights reserved.
//

#import "DemoEarlyRetrunCell.h"
#import "DemoAdConfig.h"

@implementation DemoEarlyRetrunCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
    self.stepper.value = [DemoAdConfig sharedInstance].earlyRetrunTime;
    if ([DemoAdConfig sharedInstance].earlyRetrunTime == 0) {
        self.timeLab.text = @"不开启";
    }else{
        self.timeLab.text = [NSString stringWithFormat:@"%ld 秒", (long)[DemoAdConfig sharedInstance].earlyRetrunTime];
    }
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}
- (IBAction)stepperValueChanged:(id)sender {
    [DemoAdConfig sharedInstance].earlyRetrunTime = self.stepper.value;
    if ([DemoAdConfig sharedInstance].earlyRetrunTime == 0) {
        self.timeLab.text = @"不开启";
    }else{
        self.timeLab.text = [NSString stringWithFormat:@"%ld 秒", (long)[DemoAdConfig sharedInstance].earlyRetrunTime];
    }
}

@end
