//
//  OfferWallViewController.m
//  AMRDemo
//
//  Created by Tolga Seremet on 28/11/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import "OfferWallViewController.h"
#import <KKLog/KKLog.h>
#import <AMRSDK/AMRSDK.h>

@interface OfferWallViewController () <AMROfferWallDelegate> {
    AMROfferWall *_offerWall;
    IBOutlet UIActivityIndicatorView *AILoading;
    BOOL _isShown;
}

@end

#pragma mark - View lifecycle

@implementation OfferWallViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    if(!_isShown) {
        _isShown = YES;
        _offerWall = [AMROfferWall offerWallForZoneId:@"c3ccd9f4-f2d7-48d8-93a3-25810fe4cb6c"];
        _offerWall.delegate = self;
        [_offerWall loadOfferWall];
    }
}

#pragma mark - <AMROfferWallDelegate>

- (void)didReceiveOfferWall:(AMROfferWall *)offerwall {
    [AILoading stopAnimating];
    [offerwall showFromViewController:self.navigationController];
}

- (void)didFailToReceiveOfferWall:(AMROfferWall *)offerwall error:(AMRError *)error {
    [AILoading stopAnimating];
    KKLogError(error.errorDescription);
}

- (void)didDismissOfferWall:(AMROfferWall *)offerwall {
    KKLogInfo(@"Offerwall dismissed");
}

@end
