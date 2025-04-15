//
//  YFBaseViewController.m
//  Example
//
//  Created by CherryKing on 2019/12/20.
//  Copyright © 2019 CherryKing. All rights reserved.
//

#import "DemoBaseViewController.h"
#import "ViewBuilder.h"


#define ssRGBHex(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define ssRGBHexAlpha(rgbValue,a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:(a)]


@interface DemoBaseViewController () <UITableViewDataSource, UITableViewDelegate>


@property (nonatomic, copy) NSString *text;

@end

@implementation DemoBaseViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    _text = @"";
    self.isOnlyLoad = YES;
    self.view.backgroundColor = [UIColor whiteColor];
        
    if (@available(iOS 15.0, *)) {
        UINavigationBarAppearance *appearance = [[UINavigationBarAppearance alloc] init];
        appearance.backgroundEffect = [UIBlurEffect effectWithStyle:UIBlurEffectStyleRegular];
        self.navigationController.navigationBar.scrollEdgeAppearance = appearance;
        self.navigationController.navigationBar.standardAppearance = appearance;
    }
    
    [self.view addSubview:self.btnLoad];
    [self.view addSubview:self.btnShow];
    [self.view addSubview:self.btnLoadAndShow];
    [self.view addSubview:self.labNotify];
    [self.view addSubview:self.textV];
    [self loadAdWithState:AdState_Normal];
    
    double width = (UIScreen.mainScreen.bounds.size.width - 2 * 50);

    self.btnLoad.frame = CGRectMake(50, 100, width, 40);
    self.btnShow.frame = CGRectMake(50, 160, width, 40);
    self.btnLoadAndShow.frame = CGRectMake(50, 220, width, 40);
    self.labNotify.frame = CGRectMake(0,280, self.view.frame.size.width, 40);
    self.textV.frame = CGRectMake(0, 340, self.view.frame.size.width, self.view.frame.size.height - CGRectGetMaxY(self.labNotify.frame) - 20);
}

- (void)generateEarlyReturn{
    if ([DemoAdConfig sharedInstance].earlyRetrunTime == 0) {
        return;
    }
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)([DemoAdConfig sharedInstance].earlyRetrunTime * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self childVCTakeResultImmediately];
    });
}

/// 到子类中实现
- (void)childVCTakeResultImmediately{
    NSString *remind = [NSString stringWithFormat:@"子类中未实现%@方法",NSStringFromSelector(_cmd)];
//    NSAssert(NO, remind);
    NSLog(@"YFAdsDemo: %@",remind);
}

-(void)changeVC {
    
    
}

- (void)setIsOnlyLoad:(BOOL)isOnlyLoad {
//    _isOnlyLoad = isOnlyLoad;
//    self.btnLoad.hidden = !_isOnlyLoad;
//    self.btnShow.hidden = !_isOnlyLoad;
}




- (void)loadAd {
    [self clearText];
    [self loadAdWithState:AdState_Normal];
}

- (void)showAd {
    
}

- (void)loadAndShowAd {
    [self clearText];
    [self loadAdWithState:AdState_Normal];
}

- (void)deallocAd {
    
}

- (void)showProcessWithText:(NSString *)text {
    
    _text = [_text stringByAppendingString:[NSString stringWithFormat:@"\r\n%@",text]];
    self.textV.text = _text;
}

- (void)showErrorWithDescription:(NSDictionary *)description {
    if (!description) {
        return;
    }
    
    NSString *highlightText = [NSString stringWithFormat:@"%@",description];
    _text = [_text stringByAppendingString:[NSString stringWithFormat:@", 失败原因如下:\r\n%@",highlightText]];

    self.textV.text = _text;

}

-(NSString*)convertToJSONData:(id)infoDict
{
    
    if(!infoDict){
        return @"";
    }
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:infoDict
                                                       options:NSJSONWritingPrettyPrinted // Pass 0 if you don't care about the readability of the generated string
                                                         error:&error];

    NSString *jsonString = @"";

    if (!jsonData)
    {
        NSLog(@"Got an error: %@", error);
    }else
    {
        jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    }

    jsonString = [jsonString stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];  //去除掉首尾的空白字符和换行字符

    [jsonString stringByReplacingOccurrencesOfString:@"\n" withString:@""];

    return jsonString;
}


- (void)clearText {
    
    _text = @"";
    self.textV.text = nil;
}

- (void)loadAdWithState:(AdState)state {
    switch (state) {
        case AdState_Normal:
            self.labNotify.text = @"未加载广告";
            break;
        case AdState_Loading:
            self.labNotify.text = @"广告加载中...";
            break;
        case AdState_LoadSucceed:
            self.labNotify.text = @"广告加载成功";
            break;
        case AdState_LoadFailed:
            self.labNotify.text = @"广告加载失败";
            break;

        default:
            break;
    }
}

- (UIButton *)btnLoad {
    if (!_btnLoad) {
        _btnLoad = [UIButton buttonWithType:UIButtonTypeSystem];
        _btnLoad.backgroundColor = UIColor.clearColor;
        _btnLoad.layer.cornerRadius = 5.f;
        _btnLoad.layer.masksToBounds = YES;
        _btnLoad.layer.borderColor = UIColor.systemBlueColor.CGColor;
        _btnLoad.layer.borderWidth = 2.f;
        [_btnLoad setTitle:@"加载广告数据" forState:UIControlStateNormal];
        [_btnLoad setTitleColor:[UIColor systemBlueColor] forState:UIControlStateNormal];
        [_btnLoad addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
    }
    return _btnLoad;
}

- (UIButton *)btnShow {
    if (!_btnShow) {
        _btnShow = [UIButton buttonWithType:UIButtonTypeSystem];
        _btnShow.backgroundColor = UIColor.clearColor;
        _btnShow.layer.cornerRadius = 5.f;
        _btnShow.layer.masksToBounds = YES;
        _btnShow.layer.borderWidth = 2.f;
        _btnShow.layer.borderColor = UIColor.systemBlueColor.CGColor;
        [_btnShow setTitle:@"展示广告数据" forState:UIControlStateNormal];
        [_btnShow setTitleColor:[UIColor systemBlueColor] forState:UIControlStateNormal];
        [_btnShow addTarget:self action:@selector(showAd) forControlEvents:UIControlEventTouchUpInside];

    }
    return _btnShow;
}


- (UIButton *)btnLoadAndShow {
    if (!_btnLoadAndShow) {
        _btnLoadAndShow = [UIButton buttonWithType:UIButtonTypeSystem];
        _btnLoadAndShow.backgroundColor = UIColor.clearColor;
        _btnLoadAndShow.layer.cornerRadius = 5.f;
        _btnLoadAndShow.layer.borderWidth = 2.f;
        _btnLoadAndShow.layer.masksToBounds = YES;
        _btnLoadAndShow.layer.borderColor = UIColor.systemBlueColor.CGColor;
        [_btnLoadAndShow setTitle:@"加载展示广告数据" forState:UIControlStateNormal];
        [_btnLoadAndShow setTitleColor:[UIColor systemBlueColor] forState:UIControlStateNormal];
        [_btnLoadAndShow addTarget:self action:@selector(loadAndShowAd) forControlEvents:UIControlEventTouchUpInside];
    }
    return _btnLoadAndShow;
}

- (UILabel *)labNotify {
    if (!_labNotify) {
        _labNotify = [UILabel new];
        _labNotify.textColor = UIColor.systemBlueColor;
        _labNotify.font = [UIFont systemFontOfSize:15];
        _labNotify.textAlignment = NSTextAlignmentCenter;
    }
    return _labNotify;
}

- (UITextView *)textV {
    if (!_textV) {
        _textV = [UITextView new];
        _textV.font = [UIFont systemFontOfSize:15];
        _textV.contentInset = UIEdgeInsetsMake(10, 10, 10, 10);
        _textV.textAlignment = NSTextAlignmentLeft;
        _textV.editable = NO;
    
    }
    return _textV;
}


- (NSString *)getSianKeyWithDic:(NSDictionary *)dic
{
    //按字典排序
    
    NSArray* arr = [dic allKeys];
    
    arr = [arr sortedArrayUsingComparator:^NSComparisonResult(id obj1, id obj2){
        NSComparisonResult result = [obj1 compare:obj2];
        
        return result == NSOrderedDescending;
    }];
    
    //拼接字符串
    NSMutableArray * strArray =[[NSMutableArray alloc]init];
    [arr enumerateObjectsUsingBlock:^(id  obj, NSUInteger idx, BOOL * _Nonnull stop) {
        NSString *appendStr = [[NSString alloc] init];
        
        appendStr = obj;
        
        NSError *par = dic[obj];
        
        if (dic[obj]!=NULL) {
            
            appendStr = [appendStr stringByAppendingString:par.userInfo.description];
            
            NSInteger code = par.code;
            NSString *desc = par.userInfo[NSLocalizedDescriptionKey];
            if (!desc) {
                desc = par.userInfo[@"desc"];
            }
            
            NSString *errorInfo = [NSString stringWithFormat:@"%@: code: %ld 错误详情:%@", obj, code, desc];
            [strArray addObject:errorInfo];

        }
        
    }];
    
    NSString * str = [strArray componentsJoinedByString:@"\r\n"];
    
    return str;
    
}

- (NSMutableAttributedString *)setupAttributeString:(NSString *)text highlightText:(NSString *)highlightText {
    
    NSRange hightlightTextRange = [text rangeOfString:highlightText];
    NSMutableAttributedString *attributeStr = [[NSMutableAttributedString alloc] initWithString:text];
    
    if (hightlightTextRange.length > 0) {
        [attributeStr addAttribute:NSForegroundColorAttributeName
                             value:[UIColor redColor]
                             range:hightlightTextRange];
        [attributeStr addAttribute:NSFontAttributeName value:[UIFont boldSystemFontOfSize:15.0f] range:hightlightTextRange];
        
        return attributeStr;
    } else {
        return [highlightText copy];
    }
}

@end
