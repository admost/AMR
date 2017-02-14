//
//  BannerTableViewController.m
//  AMRDemo
//
//  Created by Tolga Seremet on 07/02/17.
//  Copyright © 2017 Tolga Seremet. All rights reserved.
//

#import "BannerTableViewController.h"
#import "BannerTableViewDataCell.h"
#import "BannerTableViewAdCell.h"
#import <AMRSDK/AMRSDK.h>

static NSString *const kAMRInitedBannerPlaceholderText = @"kAMRInitedBannerPlaceholderText";
static NSString *const kAMRFailedBannerPlaceholderText = @"kAMRFailedBannerPlaceholderText";
static NSString *const kAMRBannerZoneId = @"1b65e016-5b26-4ba0-aff5-b500a96d5157";

@interface BannerTableViewController () <
UITableViewDelegate,
UITableViewDataSource,
AMRBannerDelegate
>
@end

@implementation BannerTableViewController {
    NSMutableArray *_newsWithAds;
    IBOutlet UITableView *tbMain;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    // prepare data
    _newsWithAds = [self prepareData];
    // optionally you can preload banners
    [self preloadBanners];
}

#pragma mark - Data methods

- (NSMutableArray *)prepareData {

    NSDictionary* newsDict = [self dictionaryWithJSONFile:@"news"];
    NSArray *news = [newsDict objectForKey:@"news"];
    NSMutableArray *newsWithAdPlaceholders = [NSMutableArray new];

    // add banner placeholder after each 5 items.

    for (int i =0 ; i < news.count; i++) {
        if (i%5 == 0 && i >0) {
            [newsWithAdPlaceholders addObject:kAMRInitedBannerPlaceholderText];
        }
        [newsWithAdPlaceholders addObject:news[i]];
    }

    return newsWithAdPlaceholders;
}

- (void)preloadBanners {

    for (int i = 0; i < _newsWithAds.count; i++) {
        id object = _newsWithAds[i];

        if ([object isKindOfClass:[NSString class]] &&
            [object isEqualToString:kAMRInitedBannerPlaceholderText]) {
            AMRBanner* banner = [AMRBanner bannerForZoneId:kAMRBannerZoneId];
            banner.delegate = self;
            [_newsWithAds replaceObjectAtIndex:[_newsWithAds indexOfObject:object] withObject:banner];
            [banner loadBanner];
        }
    }
}

- (void)configureDataCell:(BannerTableViewDataCell *)cell forIndexPath:(NSIndexPath *)indexPath {
    NSDictionary* newsItem = _newsWithAds[indexPath.row];
    cell.LBLHeader.text = newsItem[@"header"];
    cell.LBLBody.text = newsItem[@"body"];
    cell.IMGImage.image = [UIImage imageNamed:newsItem[@"image"]];
}

- (void)configureAdCell:(BannerTableViewAdCell *)cell forIndexPath:(NSIndexPath *)indexPath {
    // load banner for placeholder object
    if ([[_newsWithAds objectAtIndex:indexPath.row] isKindOfClass:[NSString class]]) {
        if ([[_newsWithAds objectAtIndex:indexPath.row] isEqualToString:kAMRInitedBannerPlaceholderText]) {
            // load an ad to placeHolder if its not failed
            AMRBanner* banner = [AMRBanner bannerForZoneId:kAMRBannerZoneId];
            banner.delegate = self;
            [_newsWithAds replaceObjectAtIndex:indexPath.row withObject:banner];
            [banner loadBanner];
        }
    } else if ([[_newsWithAds objectAtIndex:indexPath.row] isKindOfClass:[AMRBanner class]]) {
        AMRBanner* banner = [_newsWithAds objectAtIndex:indexPath.row];
        // if banner is loaded use its bannerview
        if (banner.bannerView != nil) {
            cell.bannerView = banner.bannerView;
        }
    }
}

- (BOOL)isAd:(NSIndexPath *)indexPath {
    if (![[_newsWithAds objectAtIndex:indexPath.row] isKindOfClass:[NSDictionary class]]) {
        return YES;
    }
    return NO;
}

- (BOOL)isAdLoaded:(NSIndexPath *)indexPath {
    if ([[_newsWithAds objectAtIndex:indexPath.row] isKindOfClass:[AMRBanner class]]) {
        AMRBanner* banner = [_newsWithAds objectAtIndex:indexPath.row];
        // if banner is loaded use its bannerview
        if (banner.bannerView != nil) {
            return YES;
        }
    }
    return NO;
}

- (BOOL)isAdFailed:(NSIndexPath *)indexPath {
    if ([[_newsWithAds objectAtIndex:indexPath.row] isKindOfClass:[NSString class]] &&
        [[_newsWithAds objectAtIndex:indexPath.row] isEqualToString:kAMRFailedBannerPlaceholderText]) {
        return YES;
    }
    return NO;
}

- (NSIndexPath *)indexPathForBanner:(AMRBanner *)banner {
    NSInteger index = [_newsWithAds indexOfObject:banner];
    if (index != NSNotFound) {
        return [NSIndexPath indexPathForRow:index inSection:0];
    }
    return nil;
}

#pragma mark - <UITableViewDelegate>

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    if ([self isAd:indexPath]) {
        if ([self isAdLoaded:indexPath]) {
            return 250; // Loaded, return zone banner height; 50, 90 or 250.
        }
        if ([self isAdFailed:indexPath]) {
            return 0; // Failed to load, return 0, hide cell.
        }
        return 20; // Not loaded, return a placeholder height, 0 or content height.
    }
    return 90; // Not ad, return content height.
}

#pragma mark - <UITableViewDataSource>

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 71;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {

    if ([self isAd:indexPath]) {
        BannerTableViewAdCell *cell = [tableView dequeueReusableCellWithIdentifier:@"BannerTableViewAdCell"];
        if (cell == nil) {
            cell = [[BannerTableViewAdCell alloc] initWithStyle:UITableViewCellStyleDefault
                                                reuseIdentifier:@"BannerTableViewAdCell"];
        }
        [self configureAdCell:cell forIndexPath:indexPath];
        return cell;
    } else {
        BannerTableViewDataCell *cell = [tableView dequeueReusableCellWithIdentifier:@"BannerTableViewDataCell"];
        if (cell == nil) {
            cell = [[BannerTableViewDataCell alloc] initWithStyle:UITableViewCellStyleDefault
                                                  reuseIdentifier:@"BannerTableViewDataCell"];
        }
        [self configureDataCell:cell forIndexPath:indexPath];
        return cell;
    }
}

#pragma mark - <AMRBannerDelegate>

- (void)didReceiveBanner:(AMRBanner *)banner {
    // reload cell if visible;
    NSIndexPath *indexPath = [self indexPathForBanner:banner];
    if ([tbMain.indexPathsForVisibleRows containsObject:indexPath]) {
        [tbMain reloadRowsAtIndexPaths:[NSArray arrayWithObject:indexPath]
                      withRowAnimation:UITableViewRowAnimationNone];
    }
}

- (void)didFailToReceiveBanner:(AMRBanner *)banner error:(AMRError *)error {

    // mark banner is failed
    NSIndexPath *indexPath = [self indexPathForBanner:banner];
     [_newsWithAds replaceObjectAtIndex:indexPath.row withObject:kAMRFailedBannerPlaceholderText];

    // reload cell if visible
    if ([tbMain.indexPathsForVisibleRows containsObject:indexPath]) {
        [tbMain reloadRowsAtIndexPaths:[NSArray arrayWithObject:indexPath]
                      withRowAnimation:UITableViewRowAnimationNone];
    }
}

#pragma mark - Utils

- (NSDictionary*)dictionaryWithJSONFile:(NSString*)fileName{
    NSString *filePath = [[NSBundle mainBundle] pathForResource:fileName ofType:@"json"];
    NSString *jsonString = [[NSString alloc] initWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:NULL];
    NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    NSError *error;
    NSDictionary *jsonDict = [NSJSONSerialization JSONObjectWithData:jsonData options:0 error:&error];
    if (!error) {
        return jsonDict;
    } else {
        return nil;
    }
}

@end
