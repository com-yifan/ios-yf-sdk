//
//  DemoTextLinkViewController.m
//  YFAdsDemo_Example
//
//  Created by Codex on 2026/4/9.
//

#import "DemoTextLinkViewController.h"
#import <YFAdsSDK/YFAdTextLink.h>
#import "YFEnvironmentManager.h"
#import "JDStatusBarNotification.h"
#import "UIAlertController+Blocks.h"

@interface DemoTextLinkViewController () <YFAdTextLinkDelegate>

@property (nonatomic, strong) YFAdTextLink *textLink;
@property (nonatomic, strong) YFAdTextLinkView *textLinkView;
@property (nonatomic, strong) UIView *adContainerView;
@property (nonatomic, assign) BOOL isLoadAndShow;
@property (nonatomic, assign) CGFloat configWidth;
@property (nonatomic, assign) CGFloat configHeight;
@property (nonatomic, assign) CGFloat configFontSize;
@property (nonatomic, assign) CGFloat configTextPadding;
@property (nonatomic, assign) CGFloat configCornerRadius;
@property (nonatomic, strong) UIColor *configFontColor;
@property (nonatomic, strong) UIColor *configBackgroundColor;
@property (nonatomic, strong) UILabel *configSummaryLabel;

@end

@implementation DemoTextLinkViewController

- (void)applyDefaultSettingsAndShowTip:(BOOL)showTip {
    self.configWidth = 0;
    self.configHeight = 0;
    self.configFontSize = 0;
    self.configTextPadding = -1;
    self.configCornerRadius = -1;
    self.configFontColor = nil;
    self.configBackgroundColor = nil;
    [self updateConfigSummary];
    if (showTip) {
        [JDStatusBarNotification showWithStatus:@"已恢复默认配置，下次 load 生效" dismissAfter:1.5];
    }
}

- (CGFloat)resolvedContainerWidthForConfig {
    return self.configWidth > 0 ? MIN(self.configWidth, self.view.bounds.size.width) : (self.view.bounds.size.width - 32.0);
}

- (void)applyCornerRadiusIfNeededToTextLinkView:(YFAdTextLinkView *)textLinkView {
    if (!textLinkView) {
        return;
    }
    if (self.configCornerRadius > 0) {
        textLinkView.layer.cornerRadius = self.configCornerRadius;
        textLinkView.layer.masksToBounds = YES;
    }
}

- (void)updateConfigSummary {
    NSString *fontColorName = [self colorNameForCurrentTextColor];
    NSString *backgroundColorName = [self colorNameForCurrentBackgroundColor];
    NSString *widthText = self.configWidth > 0 ? [NSString stringWithFormat:@"%.0f", self.configWidth] : @"SDK默认";
    NSString *heightText = self.configHeight > 0 ? [NSString stringWithFormat:@"%.0f", self.configHeight] : @"SDK默认";
    NSString *fontText = self.configFontSize > 0 ? [NSString stringWithFormat:@"%.0f", self.configFontSize] : @"SDK默认";
    NSString *paddingText = self.configTextPadding >= 0 ? [NSString stringWithFormat:@"%.0f", self.configTextPadding] : @"SDK默认";
    NSString *cornerText = self.configCornerRadius >= 0 ? [NSString stringWithFormat:@"%.0f", self.configCornerRadius] : @"不设置";
    self.configSummaryLabel.text = [NSString stringWithFormat:@"宽%@ 高%@ 字号%@ 边距%@ 圆角%@ 文字%@ 背景%@\n配置修改后需下次 load 生效", widthText, heightText, fontText, paddingText, cornerText, fontColorName, backgroundColorName];
}

- (void)applyContainerFrame {
    CGFloat width = CGRectGetWidth(self.adContainerView.frame) > 0 ? CGRectGetWidth(self.adContainerView.frame) : [self resolvedContainerWidthForConfig];
    CGFloat height = CGRectGetHeight(self.adContainerView.frame) > 0 ? CGRectGetHeight(self.adContainerView.frame) : 60.0;
    CGFloat originX = MAX((self.view.bounds.size.width - width) * 0.5, 0.0);
    self.adContainerView.frame = CGRectMake(originX, 300, width, height);
    self.configSummaryLabel.frame = CGRectMake(20, CGRectGetMaxY(self.adContainerView.frame) + 12.0, self.view.bounds.size.width - 40.0, 64.0);
    self.textV.frame = CGRectMake(0, CGRectGetMaxY(self.configSummaryLabel.frame) + 12.0, self.view.frame.size.width, self.view.frame.size.height - CGRectGetMaxY(self.configSummaryLabel.frame) - 20.0);
}

- (void)startLoadTextLink {
    self.textLink = [[YFAdTextLink alloc] initWithAdUnitID:[YFEnvironmentManager getTextLink_ID] withViewController:self];
    self.textLink.delegate = self;
    if (self.configWidth > 0 || self.configHeight > 0) {
        self.textLink.adSize = CGSizeMake(self.configWidth, self.configHeight);
    }
    if (self.configFontSize > 0) {
        self.textLink.fontSize = self.configFontSize;
    }
    if (self.configTextPadding >= 0) {
        self.textLink.textPadding = self.configTextPadding;
    }
    if (self.configFontColor) {
        self.textLink.fontColor = self.configFontColor;
    }
    if (self.configBackgroundColor) {
        self.textLink.adBackgroundColor = self.configBackgroundColor;
    }
    [self.textLink loadAd];
    [self loadAdWithState:AdState_Loading];
    CGFloat containerHeight = self.configHeight > 0 ? MAX(self.configHeight + 16.0, 60.0) : 60.0;
    self.adContainerView.frame = CGRectMake(0, 300, [self resolvedContainerWidthForConfig], containerHeight);
    [self applyContainerFrame];
    [self updateConfigSummary];
    [self showProcessWithText:@"配置修改后需下次 load 生效\r\n未设置项走 SDK 默认配置"];
}

- (void)showSettings {
    [UIAlertController showActionSheetInViewController:self withTitle:@"文字链设置" message:@"修改开放接口相关属性，变更会在下次 load 时生效" cancelButtonTitle:@"取消" destructiveButtonTitle:nil otherButtonTitles:@[@"编辑尺寸和边距", @"文字颜色", @"背景颜色", @"快速样式", @"恢复默认"] popoverPresentationControllerBlock:^(UIPopoverPresentationController *popover) {
        popover.barButtonItem = self.navigationItem.rightBarButtonItem;
    } tapBlock:^(UIAlertController *controller, UIAlertAction *action, NSInteger buttonIndex) {
        if (buttonIndex == controller.firstOtherButtonIndex) {
            [self showTextSettingsAlert];
        } else if (buttonIndex == controller.firstOtherButtonIndex + 1) {
            [self showTextColorSheet];
        } else if (buttonIndex == controller.firstOtherButtonIndex + 2) {
            [self showBackgroundColorSheet];
        } else if (buttonIndex == controller.firstOtherButtonIndex + 3) {
            [self showPresetSheet];
        } else if (buttonIndex == controller.firstOtherButtonIndex + 4) {
            [self resetSettings];
        }
    }];
}

- (void)showTextSettingsAlert {
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"编辑配置" message:@"支持修改宽高、文字大小、文字边距和圆角" preferredStyle:UIAlertControllerStyleAlert];
    [alertController addTextFieldWithConfigurationHandler:^(UITextField *textField) {
        textField.placeholder = @"宽度";
        textField.keyboardType = UIKeyboardTypeNumberPad;
        textField.text = self.configWidth > 0 ? [NSString stringWithFormat:@"%.0f", self.configWidth] : @"";
    }];
    [alertController addTextFieldWithConfigurationHandler:^(UITextField *textField) {
        textField.placeholder = @"高度";
        textField.keyboardType = UIKeyboardTypeNumberPad;
        textField.text = self.configHeight > 0 ? [NSString stringWithFormat:@"%.0f", self.configHeight] : @"";
    }];
    [alertController addTextFieldWithConfigurationHandler:^(UITextField *textField) {
        textField.placeholder = @"文字大小";
        textField.keyboardType = UIKeyboardTypeDecimalPad;
        textField.text = self.configFontSize > 0 ? [NSString stringWithFormat:@"%.0f", self.configFontSize] : @"";
    }];
    [alertController addTextFieldWithConfigurationHandler:^(UITextField *textField) {
        textField.placeholder = @"文字边距";
        textField.keyboardType = UIKeyboardTypeDecimalPad;
        textField.text = self.configTextPadding >= 0 ? [NSString stringWithFormat:@"%.0f", self.configTextPadding] : @"";
    }];
    [alertController addTextFieldWithConfigurationHandler:^(UITextField *textField) {
        textField.placeholder = @"圆角";
        textField.keyboardType = UIKeyboardTypeDecimalPad;
        textField.text = self.configCornerRadius >= 0 ? [NSString stringWithFormat:@"%.0f", self.configCornerRadius] : @"";
    }];
    [alertController addAction:[UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:nil]];
    [alertController addAction:[UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
        NSArray<UITextField *> *fields = alertController.textFields;
        CGFloat width = [fields[0].text doubleValue];
        CGFloat height = [fields[1].text doubleValue];
        CGFloat fontSize = [fields[2].text doubleValue];
        CGFloat textPadding = [fields[3].text doubleValue];
        CGFloat cornerRadius = [fields[4].text doubleValue];
        self.configWidth = (fields[0].text.length > 0 && width > 0) ? width : 0;
        self.configHeight = (fields[1].text.length > 0 && height > 0) ? height : 0;
        self.configFontSize = (fields[2].text.length > 0 && fontSize > 0) ? fontSize : 0;
        self.configTextPadding = (fields[3].text.length > 0 && textPadding >= 0) ? textPadding : -1;
        self.configCornerRadius = (fields[4].text.length > 0 && cornerRadius >= 0) ? cornerRadius : -1;
        [self updateConfigSummary];
        [JDStatusBarNotification showWithStatus:@"文字链配置已更新，下次 load 生效" dismissAfter:1.5];
    }]];
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)showTextColorSheet {
    [UIAlertController showActionSheetInViewController:self withTitle:@"文字颜色" message:nil cancelButtonTitle:@"取消" destructiveButtonTitle:nil otherButtonTitles:@[@"黑色", @"深灰", @"蓝色", @"红色"] popoverPresentationControllerBlock:^(UIPopoverPresentationController *popover) {
        popover.barButtonItem = self.navigationItem.rightBarButtonItem;
    } tapBlock:^(UIAlertController *controller, UIAlertAction *action, NSInteger buttonIndex) {
        if (buttonIndex == controller.firstOtherButtonIndex) {
            self.configFontColor = UIColor.blackColor;
        } else if (buttonIndex == controller.firstOtherButtonIndex + 1) {
            self.configFontColor = [UIColor colorWithWhite:0.2 alpha:1.0];
        } else if (buttonIndex == controller.firstOtherButtonIndex + 2) {
            self.configFontColor = [UIColor colorWithRed:0.15 green:0.34 blue:0.85 alpha:1.0];
        } else if (buttonIndex == controller.firstOtherButtonIndex + 3) {
            self.configFontColor = [UIColor colorWithRed:0.84 green:0.19 blue:0.18 alpha:1.0];
        }
        [self updateConfigSummary];
        [JDStatusBarNotification showWithStatus:@"文字颜色已更新，下次 load 生效" dismissAfter:1.0];
    }];
}

- (void)showBackgroundColorSheet {
    [UIAlertController showActionSheetInViewController:self withTitle:@"背景颜色" message:nil cancelButtonTitle:@"取消" destructiveButtonTitle:nil otherButtonTitles:@[@"透明", @"浅灰", @"浅黄", @"浅蓝"] popoverPresentationControllerBlock:^(UIPopoverPresentationController *popover) {
        popover.barButtonItem = self.navigationItem.rightBarButtonItem;
    } tapBlock:^(UIAlertController *controller, UIAlertAction *action, NSInteger buttonIndex) {
        if (buttonIndex == controller.firstOtherButtonIndex) {
            self.configBackgroundColor = UIColor.clearColor;
        } else if (buttonIndex == controller.firstOtherButtonIndex + 1) {
            self.configBackgroundColor = [UIColor colorWithWhite:0.92 alpha:1.0];
        } else if (buttonIndex == controller.firstOtherButtonIndex + 2) {
            self.configBackgroundColor = [UIColor colorWithRed:1.0 green:0.97 blue:0.82 alpha:1.0];
        } else if (buttonIndex == controller.firstOtherButtonIndex + 3) {
            self.configBackgroundColor = [UIColor colorWithRed:0.90 green:0.95 blue:1.0 alpha:1.0];
        }
        [self updateConfigSummary];
        [JDStatusBarNotification showWithStatus:@"背景颜色已更新，下次 load 生效" dismissAfter:1.0];
    }];
}

- (void)showPresetSheet {
    [UIAlertController showActionSheetInViewController:self withTitle:@"快速样式" message:@"一键切换常用配置组合" cancelButtonTitle:@"取消" destructiveButtonTitle:nil otherButtonTitles:@[@"默认样式", @"深色文字卡片", @"强调蓝色样式", @"紧凑小号样式"] popoverPresentationControllerBlock:^(UIPopoverPresentationController *popover) {
        popover.barButtonItem = self.navigationItem.rightBarButtonItem;
    } tapBlock:^(UIAlertController *controller, UIAlertAction *action, NSInteger buttonIndex) {
        if (buttonIndex == controller.firstOtherButtonIndex) {
            [self resetSettings];
            return;
        }
        if (buttonIndex == controller.firstOtherButtonIndex + 1) {
            self.configWidth = self.view.bounds.size.width - 60.0;
            self.configHeight = 44.0;
            self.configFontSize = 15.0;
            self.configTextPadding = 10.0;
            self.configCornerRadius = 12.0;
            self.configFontColor = [UIColor colorWithWhite:0.12 alpha:1.0];
            self.configBackgroundColor = [UIColor colorWithWhite:0.92 alpha:1.0];
        } else if (buttonIndex == controller.firstOtherButtonIndex + 2) {
            self.configWidth = self.view.bounds.size.width - 40.0;
            self.configHeight = 46.0;
            self.configFontSize = 16.0;
            self.configTextPadding = 12.0;
            self.configCornerRadius = 14.0;
            self.configFontColor = [UIColor colorWithRed:0.12 green:0.30 blue:0.82 alpha:1.0];
            self.configBackgroundColor = [UIColor colorWithRed:0.91 green:0.95 blue:1.0 alpha:1.0];
        } else if (buttonIndex == controller.firstOtherButtonIndex + 3) {
            self.configWidth = self.view.bounds.size.width - 80.0;
            self.configHeight = 40.0;
            self.configFontSize = 13.0;
            self.configTextPadding = 8.0;
            self.configCornerRadius = 8.0;
            self.configFontColor = UIColor.blackColor;
            self.configBackgroundColor = UIColor.clearColor;
        }
        [self updateConfigSummary];
        [JDStatusBarNotification showWithStatus:@"样式预设已应用，下次 load 生效" dismissAfter:1.0];
    }];
}

- (void)resetSettings {
    [self applyDefaultSettingsAndShowTip:YES];
}

- (NSString *)colorNameForCurrentTextColor {
    if (!self.configFontColor) return @"SDK默认";
    if ([self.configFontColor isEqual:UIColor.blackColor]) return @"黑色";
    if ([self.configFontColor isEqual:[UIColor colorWithWhite:0.2 alpha:1.0]]) return @"深灰";
    if ([self.configFontColor isEqual:[UIColor colorWithRed:0.15 green:0.34 blue:0.85 alpha:1.0]]) return @"蓝色";
    if ([self.configFontColor isEqual:[UIColor colorWithRed:0.84 green:0.19 blue:0.18 alpha:1.0]]) return @"红色";
    return @"自定义";
}

- (NSString *)colorNameForCurrentBackgroundColor {
    if (!self.configBackgroundColor) return @"SDK默认";
    if ([self.configBackgroundColor isEqual:UIColor.clearColor]) return @"透明";
    if ([self.configBackgroundColor isEqual:[UIColor colorWithWhite:0.92 alpha:1.0]]) return @"浅灰";
    if ([self.configBackgroundColor isEqual:[UIColor colorWithRed:1.0 green:0.97 blue:0.82 alpha:1.0]]) return @"浅黄";
    if ([self.configBackgroundColor isEqual:[UIColor colorWithRed:0.90 green:0.95 blue:1.0 alpha:1.0]]) return @"浅蓝";
    return @"自定义";
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"文字链广告";
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"配置" style:UIBarButtonItemStylePlain target:self action:@selector(showSettings)];
    [self.btnLoad setTitle:@"加载广告数据" forState:UIControlStateNormal];
    [self.btnShow setTitle:@"展示广告数据" forState:UIControlStateNormal];
    [self.btnLoadAndShow setTitle:@"加载展示广告数据" forState:UIControlStateNormal];
    [self applyDefaultSettingsAndShowTip:NO];
    self.adContainerView = [[UIView alloc] initWithFrame:CGRectMake(20, 300, [self resolvedContainerWidthForConfig], 60)];
    [self.view addSubview:self.adContainerView];
    self.configSummaryLabel = [[UILabel alloc] initWithFrame:CGRectMake(20, CGRectGetMaxY(self.adContainerView.frame) + 12.0, self.view.bounds.size.width - 40.0, 64.0)];
    self.configSummaryLabel.font = [UIFont systemFontOfSize:12.0];
    self.configSummaryLabel.numberOfLines = 3;
    self.configSummaryLabel.textColor = [UIColor colorWithWhite:0.35 alpha:1.0];
    [self.view addSubview:self.configSummaryLabel];
    [self applyContainerFrame];
    [self updateConfigSummary];
    self.textV.scrollEnabled = YES;
    self.textV.alwaysBounceVertical = YES;
    self.textV.showsVerticalScrollIndicator = YES;
    [self.view bringSubviewToFront:self.labNotify];
    [self.view bringSubviewToFront:self.textV];
}

- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    self.isLoadAndShow = NO;
    [self startLoadTextLink];
}

- (void)showAd {
    if (!self.isLoaded || !self.textLinkView) {
        [JDStatusBarNotification showWithStatus:@"请先 load，再把 adView 添加到容器" dismissAfter:1.5];
        return;
    }
    if (!self.textLink.isValid) {
        [JDStatusBarNotification showWithStatus:@"广告已失效，请重新拉取" dismissAfter:1.5];
        return;
    }

    [self.textLinkView removeFromSuperview];
    CGFloat displayHeight = self.configHeight > 0 ? self.configHeight : CGRectGetHeight(self.textLinkView.bounds);
    if (displayHeight <= 0) {
        displayHeight = 27.0;
    }
    CGFloat displayWidth = self.configWidth > 0 ? MIN(self.configWidth, CGRectGetWidth(self.adContainerView.bounds)) : CGRectGetWidth(self.textLinkView.bounds);
    if (displayWidth <= 0) {
        displayWidth = CGRectGetWidth(self.adContainerView.bounds);
    }
    self.textLinkView.frame = CGRectMake(0, MAX((CGRectGetHeight(self.adContainerView.bounds) - displayHeight) * 0.5, 0.0), displayWidth, displayHeight);
    [self applyCornerRadiusIfNeededToTextLinkView:self.textLinkView];
    [self.adContainerView addSubview:self.textLinkView];
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 开发者已将 adView 添加到容器展示", __func__]];
}

- (void)loadAndShowAd {
    [super loadAndShowAd];
    [self deallocAd];
    self.isLoadAndShow = YES;
    [self startLoadTextLink];
}

- (void)deallocAd {
    [self.textLinkView removeFromSuperview];
    self.textLinkView = nil;
    self.textLink.delegate = nil;
    self.textLink = nil;
    self.isLoaded = NO;
    [self loadAdWithState:AdState_Normal];
}

- (void)fcAdTextLinkOnAdLoadSuccess:(YFAdTextLink *)textLink adView:(YFAdTextLinkView *)adView {
    self.textLinkView = adView;
    [self applyCornerRadiusIfNeededToTextLinkView:self.textLinkView];
    self.isLoaded = YES;
    [self loadAdWithState:AdState_LoadSucceed];
    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功 请求ID：%@\r\n 返回结果为 adView，需由开发者自行添加到容器", __func__, textLink.mgr.rID]];
}

- (void)fcAdTextLinkOnAdLoadFail:(YFAdTextLink *)textLink withError:(NSError *)error {
    [self loadAdWithState:AdState_LoadFailed];
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载异常:\r\n%@", __func__, error.userInfo.description]];
    [self showErrorWithDescription:error.userInfo];
    [self deallocAd];
}

- (void)fcAdTextLinkOnAdRenderSuccess:(YFAdTextLink *)textLink adView:(YFAdTextLinkView *)adView {
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染成功 %@", __func__, textLink.isValid ? @"✅有效" : @"❌失效"]];
    if (self.isLoadAndShow && adView.superview == nil) {
        [self showAd];
    }
}

- (void)fcAdTextLinkOnAdRenderFail:(YFAdTextLink *)textLink adView:(YFAdTextLinkView *)adView {
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告渲染失败", __func__]];
}

- (void)fcAdTextLinkOnAdShow:(YFAdTextLink *)textLink adView:(YFAdTextLinkView *)adView {
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

- (void)fcAdTextLinkOnAdClick:(YFAdTextLink *)textLink adView:(YFAdTextLinkView *)adView {
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击了", __func__]];
}

- (void)fcAdTextLinkOnAdClose:(YFAdTextLink *)textLink adView:(YFAdTextLinkView *)adView {
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 用户点击关闭按钮，广告已关闭", __func__]];
    [self deallocAd];
}

- (void)fcAdTextLinkOnAdDetailPageClose:(YFAdTextLink *)textLink adView:(YFAdTextLinkView *)adView {
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭落地页", __func__]];
}

@end
