//
//  AdmobCustomEventsViewController.m
//  AMRDemo
//
//  Created by Tolga Seremet on 08/05/17.
//  Copyright © 2017 Tolga Seremet. All rights reserved.
//

#import "DFPCustomEventsViewController.h"

@import GoogleMobileAds;

@interface DFPCustomEventsViewController () <
GADBannerViewDelegate,
GADInterstitialDelegate> @end

@implementation DFPCustomEventsViewController {
    GADBannerView *_banner;
    GADInterstitial *_interstitial;
    DFPBannerView *_dFPBanner;
    DFPInterstitial *_dFPInterstitial;
}

- (void)viewDidLoad {
    [super viewDidLoad];
}

#pragma mark - IBActions

- (IBAction)loadBanner {
    dispatch_async(dispatch_get_main_queue(), ^{
        GADAdSize customAdSize = GADAdSizeFromCGSize(CGSizeMake([UIScreen mainScreen].bounds.size.width, 50));
        _banner = [[GADBannerView alloc] initWithAdSize:customAdSize];
        _banner.adUnitID = @"ca-app-pub-3297656589511112/8773234182";
        _banner.delegate = self;
        _banner.rootViewController = self;
        [_banner loadRequest:[GADRequest request]];
    });
}

- (IBAction)loadInterstitial {

    dispatch_async(dispatch_get_main_queue(), ^{
        _interstitial = [[GADInterstitial alloc] initWithAdUnitID:@"ca-app-pub-3297656589511112/6995449788"];
        _interstitial.delegate = self;
        [_interstitial loadRequest:[GADRequest request]];
    });
}

- (IBAction)loadDFPBanner {
    dispatch_async(dispatch_get_main_queue(), ^{
        _dFPBanner = [[DFPBannerView alloc] initWithAdSize:kGADAdSizeBanner];
        _dFPBanner.adUnitID = @"/96769799/amr_ios_banner";
        _dFPBanner.delegate = self;
        _dFPBanner.rootViewController = self;
        [_dFPBanner loadRequest:[DFPRequest request]];
    });
}

- (IBAction)loadDFPInterstitial {
    dispatch_async(dispatch_get_main_queue(), ^{
        _dFPInterstitial = [[DFPInterstitial alloc] initWithAdUnitID:@"/96769799/amr_ios_interstitial"];
        _dFPInterstitial.delegate = self;
        [_dFPInterstitial loadRequest:[GADRequest request]];
    });
}

#pragma mark - <GADCustomEventBanner>

- (void)adViewDidReceiveAd:(GADBannerView *)bannerView {
    bannerView.frame = CGRectMake(0, 100, bannerView.frame.size.width, bannerView.frame.size.height);
    [self.view addSubview:bannerView];
}

- (void)adView:(GADBannerView *)bannerView didFailToReceiveAdWithError:(GADRequestError *)error {
    NSLog(@"ERROR: %@", error.description);
}

- (void)adViewWillLeaveApplication:(GADBannerView *)bannerView {}

#pragma mark - <GADInterstitialDelegate>

- (void)interstitialDidReceiveAd:(GADInterstitial *)ad {
    [ad presentFromRootViewController:self];
}

- (void)interstitial:(GADInterstitial *)ad didFailToReceiveAdWithError:(GADRequestError *)error {
    NSLog(@"ERROR: %@", error.description);
}

- (void)interstitialWillPresentScreen:(GADInterstitial *)ad {}

- (void)interstitialDidDismissScreen:(GADInterstitial *)ad {
    NSLog(@"Dismissed");
}

@end
