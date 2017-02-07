//
//  BannerTableViewAdCell.m
//  AMRDemo
//
//  Created by Tolga Seremet on 07/02/17.
//  Copyright © 2017 Tolga Seremet. All rights reserved.
//

#import "BannerTableViewAdCell.h"

@implementation BannerTableViewAdCell


#pragma mark - View Lifecycle

- (void)prepareForReuse {
    if (_bannerView != nil) {
        [_bannerView removeFromSuperview];
    }
    [super prepareForReuse];
}

#pragma mark - Setters

- (void)setBannerView:(UIView *)bannerView {
    _bannerView = bannerView;
    [self addSubview:bannerView];
}
@end
