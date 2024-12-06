//
//  DemoDrawNormalCell.m
//

#import "DemoDrawNormalCell.h"

#define GlobleHeight [UIScreen mainScreen].bounds.size.height
#define GlobleWidth [UIScreen mainScreen].bounds.size.width
#define inconWidth 45
#define inconEdge 15
#define bu_textEnde 5
#define bu_textFont 14

@interface DemoDrawNormalCell()
@property (nonatomic, strong, nullable) UIImageView *likeImg;
@property (nonatomic, strong, nullable) UILabel *likeLable;
@property (nonatomic, strong, nullable) UIImageView *commentImg;
@property (nonatomic, strong, nullable) UILabel *commentLable;
@property (nonatomic, strong, nullable) UIImageView *forwardImg;
@property (nonatomic, strong, nullable) UILabel *forwardLable;
@end

@implementation DemoDrawNormalCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        self.backgroundColor = [UIColor whiteColor];
        [self buildupView];
    }
    return self;
}

-(void)refreshUIAtIndex:(NSUInteger)index {
    self.titleLabel.text = [NSString localizedStringWithFormat:@"title %zd",index];
    self.descriptionLabel.text = @"drawDescription";
    UIColor *color1 = [UIColor grayColor];
    UIColor *color2 = [UIColor cyanColor];
    if (index%2) {
        self.backgroundColor = color1;
    } else {
        self.backgroundColor = color2;
    }
}


- (void)buildupView {
    self.titleLabel = [UILabel new];
    self.titleLabel.frame = CGRectMake(13, GlobleHeight-180, GlobleWidth-26, 30);
    self.titleLabel.font = [UIFont boldSystemFontOfSize:19];
    self.titleLabel.numberOfLines = 0;
    self.titleLabel.textAlignment = NSTextAlignmentLeft;
    self.titleLabel.textColor = [UIColor darkGrayColor];
    [self.contentView addSubview:self.titleLabel];
    
    self.descriptionLabel = [UILabel new];
    self.descriptionLabel.frame = CGRectMake(13, GlobleHeight-180+40, GlobleWidth-26, 50);
    self.descriptionLabel.font = [UIFont systemFontOfSize:16];
    self.descriptionLabel.numberOfLines = 0;
    self.descriptionLabel.textColor = [UIColor darkGrayColor];
    [self.contentView addSubview:self.descriptionLabel];
    
    _headImg = [[UIImageView alloc] initWithFrame:CGRectMake(GlobleWidth-inconWidth-13, GlobleHeight*0.3, inconWidth, inconWidth)];
    _headImg.image = [UIImage imageNamed:@"head"];
    _headImg.clipsToBounds = YES;
    _headImg.layer.cornerRadius = inconWidth / 2.0f;
    _headImg.layer.borderColor = [UIColor darkGrayColor].CGColor;
    _headImg.layer.borderWidth = 1;
    [self.contentView addSubview:_headImg];
    
    _likeImg = [[UIImageView alloc] initWithFrame:CGRectMake(GlobleWidth-inconWidth-13, _headImg.frame.origin.y + inconWidth + inconEdge, inconWidth, inconWidth)];
    _likeImg.image = [UIImage imageNamed:@"like"];
    [self.contentView addSubview:_likeImg];
    
    _likeLable = [[UILabel alloc] initWithFrame:CGRectMake(GlobleWidth-inconWidth-13, _likeImg.frame.origin.y + inconWidth + bu_textEnde, inconWidth, bu_textFont)];
    _likeLable.font = [UIFont systemFontOfSize:bu_textFont];
    _likeLable.textAlignment = NSTextAlignmentCenter;
    _likeLable.textColor = [UIColor darkGrayColor];
    _likeLable.text = @"21.4w";
    [self.contentView addSubview:_likeLable];
    
    _commentImg = [[UIImageView alloc] initWithFrame:CGRectMake(GlobleWidth-inconWidth-13, _likeLable.frame.origin.y + bu_textFont + inconEdge, inconWidth, inconWidth)];
    _commentImg.image = [UIImage imageNamed:@"comment"];
    [self.contentView addSubview:_commentImg];
    
    _commentLable = [[UILabel alloc] initWithFrame:CGRectMake(GlobleWidth-inconWidth-13, _commentImg.frame.origin.y + inconWidth + bu_textEnde, inconWidth, bu_textFont)];
    _commentLable.font = [UIFont systemFontOfSize:bu_textFont];
    _commentLable.textAlignment = NSTextAlignmentCenter;
    _commentLable.textColor = [UIColor darkGrayColor];
    _commentLable.text = @"3065";
    [self.contentView addSubview:_commentLable];
    
    _forwardImg = [[UIImageView alloc] initWithFrame:CGRectMake(GlobleWidth-inconWidth-13, _commentLable.frame.origin.y + bu_textFont + inconEdge, inconWidth, inconWidth)];
    _forwardImg.image = [UIImage imageNamed:@"forward"];
    [self.contentView addSubview:_forwardImg];
    
    _forwardLable = [[UILabel alloc] initWithFrame:CGRectMake(GlobleWidth-inconWidth-13, _forwardImg.frame.origin.y + inconWidth + bu_textEnde, inconWidth, bu_textFont)];
    _forwardLable.font = [UIFont systemFontOfSize:bu_textFont];
    _forwardLable.textAlignment = NSTextAlignmentCenter;
    _forwardLable.textColor = [UIColor darkGrayColor];
    _forwardLable.text = @"2.9w";
    [self.contentView addSubview:_forwardLable];
}

+ (CGFloat)cellHeight{
    return GlobleHeight;
}

@end

