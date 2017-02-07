//
//  BannerTableViewDataCell.h
//  AMRDemo
//
//  Created by Tolga Seremet on 07/02/17.
//  Copyright © 2017 Tolga Seremet. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BannerTableViewDataCell : UITableViewCell
@property (strong, nonatomic) IBOutlet UILabel *LBLHeader;
@property (strong, nonatomic) IBOutlet UILabel *LBLBody;
@property (strong, nonatomic) IBOutlet UIImageView *IMGImage;
@end
