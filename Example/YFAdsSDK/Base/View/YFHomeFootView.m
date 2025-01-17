//
//  YFHomeFootView.m
//
//  Created by mac on 2021/12/6.
//

#import "YFHomeFootView.h"
#import <AdSupport/AdSupport.h>
#import <YFAdsSDK/YFAdSDKSetting.h>
#import <YFAdsSDK/YFAdUtils.h>

@interface YFHomeFootView()

@property (nonatomic, strong) UIButton *coButton;

@property (nonatomic, strong) UIButton *devButton;

@property (nonatomic, strong) UILabel *versionLabel;

@end

@implementation YFHomeFootView

- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        self.backgroundColor = kRGB(245, 245, 245);
        [self setupUI];
    }
    return self;
}

- (void)setupUI
{
    [self addSubview:self.coButton];
    
    [self addSubview:self.devButton];

    [self addSubview:self.versionLabel];
}

- (void)layoutSubviews
{
    [self.coButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.mas_top).offset(kScaleW(20));
        make.left.equalTo(self.mas_left).offset(kScaleW(20));
        make.right.equalTo(self.mas_right).offset(kScaleW(-20));
        make.height.mas_equalTo(kScaleW(80));
    }];
    
    
    [self.devButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.coButton.mas_bottom).offset(kScaleW(20));
        make.left.equalTo(self.mas_left).offset(kScaleW(20));
        make.right.equalTo(self.mas_right).offset(kScaleW(-20));
        make.height.mas_equalTo(kScaleW(80));
    }];
    
    [self.versionLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.devButton.mas_bottom).offset(kScaleW(20));
        make.left.equalTo(self.mas_left).offset(kScaleW(20));
        make.right.equalTo(self.mas_right).offset(kScaleW(-20));
        make.height.mas_equalTo(kScaleW(40));
    }];
}

#pragma mark - Action
- (void)clickCopy
{
    UIPasteboard *pasteBoard = [UIPasteboard generalPasteboard];
    pasteBoard.string = [ASIdentifierManager sharedManager].advertisingIdentifier.UUIDString;
    
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Copied" message:nil preferredStyle:UIAlertControllerStyleAlert];
    [[self superViewController] presentViewController:alert animated:YES completion:^{
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [alert dismissViewControllerAnimated:YES completion:nil];
        });
    }];
}


- (void)clickDeviceCopy
{
    UIPasteboard *pasteBoard = [UIPasteboard generalPasteboard];
    pasteBoard.string = [YFAdUtils getDeviceID];
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Copied" message:nil preferredStyle:UIAlertControllerStyleAlert];
    [[self superViewController] presentViewController:alert animated:YES completion:^{
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [alert dismissViewControllerAnimated:YES completion:nil];
        });
    }];
}





- (UIViewController *)superViewController {
    for (UIView* next = [self superview]; next; next = next.superview) {
        UIResponder *nextResponder = [next nextResponder];
        if ([nextResponder isKindOfClass:[UIViewController class]]) {
            return (UIViewController *)nextResponder;
        }
    }
    return nil;
}

#pragma mark - lazy




- (UIButton *)devButton
{
    if (!_devButton) {
        _devButton = [[UIButton alloc] initWithFrame:CGRectMake(kScaleW(120), kScaleW(20), kScreenW - kScaleW(240), kScaleW(80))];
        _devButton.backgroundColor = kRGB(158, 158, 158);
        _devButton.layer.masksToBounds = YES;
        _devButton.layer.cornerRadius = 5;
        [_devButton setTitle:[NSString stringWithFormat:@"点击复制设备ID：%@",[YFAdUtils getDeviceID]] forState:UIControlStateNormal];
        _devButton.titleLabel.font = [UIFont systemFontOfSize:12];
        _devButton.titleLabel.numberOfLines = 2;
        [_devButton addTarget:self action:@selector(clickDeviceCopy) forControlEvents:UIControlEventTouchUpInside];
    }
    return _devButton;
}


- (UIButton *)coButton
{
    if (!_coButton) {
        _coButton = [[UIButton alloc] initWithFrame:CGRectMake(kScaleW(120), kScaleW(20), kScreenW - kScaleW(240), kScaleW(80))];
        _coButton.backgroundColor = kRGB(158, 158, 158);
        _coButton.layer.masksToBounds = YES;
        _coButton.layer.cornerRadius = 5;
        [_coButton setTitle:[NSString stringWithFormat:@"点击复制IDFA：%@", [ASIdentifierManager sharedManager].advertisingIdentifier.UUIDString] forState:UIControlStateNormal];
        _coButton.titleLabel.font = [UIFont systemFontOfSize:12];
        _coButton.titleLabel.numberOfLines = 2;
        [_coButton addTarget:self action:@selector(clickCopy) forControlEvents:UIControlEventTouchUpInside];
    }
    return _coButton;
}

- (UILabel *)versionLabel
{
    if (!_versionLabel) {
        _versionLabel = [[UILabel alloc] initWithFrame:CGRectMake(kScaleW(130), kScaleW(100), kScreenW - kScaleW(240), kScaleW(40))];
        _versionLabel.text = [NSString stringWithFormat:@"V%@", [YFAdSDKSetting sdkVersion]];
        _versionLabel.textColor = [UIColor blueColor];
        _versionLabel.font = [UIFont systemFontOfSize:20];
        _versionLabel.textAlignment = NSTextAlignmentCenter;
    }
    return _versionLabel;
}

@end
