//
//  ViewController.m
//  AMRDemo
//
//  Created by Tolga Seremet on 19/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import "BannerViewController.h"
#import <KKLog/KKLog.h>
#import <AMRSDK/AMRSDK.h>
#import <AMRAdmostSDK/AMRAdmostSDK.h>

#import <StoreKit/StoreKit.h>

@interface BannerViewController () <AMRBannerDelegate, AMRAdmostLoaderDelegate> {
    AMRBanner* _banner50;
    AMRBanner* _banner90;
    AMRBanner* _banner250;
    IBOutlet UIView *VBannerContainer50;
    IBOutlet UIView *VBannerContainer90;
    IBOutlet UIView *VBannerContainer250;
    IBOutlet UIActivityIndicatorView *AILoading;

    AMRAdmostLoader *_admostLoader;
}
@end

@implementation BannerViewController

#pragma mark - View lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    [self loadBanners];
}

- (void)dealloc {}

#pragma mark - Load banners

- (void)loadBanners {

    /*
     AMR TEST ZONES
     2.0 Banner 50	native	b4009772-de04-42c4-bbaa-c18da9e4a1ab
     2.0 Banner 90	native	8b72580f-c8ed-4080-aac0-004ecab65030
     2.0 Banner 250	native	1b65e016-5b26-4ba0-aff5-b500a96d5157

     1.0 Banner 3b657ba6-a304-4c28-b419-a7fc55449bc9
     1.0 Interstitial 8dc73abb-fc83-4354-b7b5-20bdcbd98984
     1.0 Native 10217edf-9a99-4fd0-be0a-a0ef2252af15
     */

    _banner50 = [AMRBanner bannerForZoneId:@"3b657ba6-a304-4c28-b419-a7fc55449bc9"];
    _banner50.delegate = self;
    [_banner50 loadBanner];

//    _banner90 = [AMRBanner bannerForZoneId:@"8b72580f-c8ed-4080-aac0-004ecab65030"];
//    _banner90.delegate = self;
//    [_banner90 loadBanner];
//
//    _banner250 = [AMRBanner bannerForZoneId:@"1b65e016-5b26-4ba0-aff5-b500a96d5157"];
//    _banner250.delegate = self;
//    [_banner250 loadBanner];

    // AMRAdmostSDK
//    _admostLoader = [AMRAdmostLoader admostLoaderWithPBK:@"47759" customParameters:@{@"screen_name": @"BannerViewController"}];
//    _admostLoader.delegate = self;
//    [_admostLoader load];
}

#pragma mark - IBActions

- (IBAction)reloadBanners {
    [self loadBanners];
}

#pragma mark - <AMRBannerDelegate>

- (void)didReceiveBanner:(AMRBanner *)banner {
    [AILoading stopAnimating];
    if (banner == _banner50) {
        [VBannerContainer50 addSubview:banner.bannerView];
    } else if (banner == _banner90) {
        [VBannerContainer90 addSubview:banner.bannerView];
    } else if (banner == _banner250) {
        [VBannerContainer250 addSubview:banner.bannerView];
    }
}

- (void)didFailToReceiveBanner:(AMRBanner *)banner error:(AMRError *)error {
    [AILoading stopAnimating];
    KKLogError(error.errorDescription);
}

#pragma mark - <AMRAdmostLoaderDelegate>

- (void)didReceiveMediationZones:(NSArray *)zoneIds {}

- (void)didFailWithError:(NSError *)error {}

@end
