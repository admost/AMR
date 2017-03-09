//
//  BannerTableViewController.m
//  AMRDemo
//
//  Created by Tolga Seremet on 07/02/17.
//  Copyright © 2017 Tolga Seremet. All rights reserved.
//

#import "BannerTableViewController.h"
#import "AMRBannerDataSource.h"
#import "BannerTableViewDataCell.h"
#import "BannerTableViewAdCell.h"
#import <AMRSDK/AMRSDK.h>

static NSString *const kAMRBannerZoneId = @"1b65e016-5b26-4ba0-aff5-b500a96d5157";

@interface BannerTableViewController () <
UITableViewDelegate,
UITableViewDataSource
>
@end

@implementation BannerTableViewController {
    IBOutlet UITableView *tbMain;
    AMRBannerDataSource *_bannerDataSource;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // initialize banner data source
    _bannerDataSource = [AMRBannerDataSource bannerDataSourceWithTableView:tbMain
                                                                    zoneId:@"1b65e016-5b26-4ba0-aff5-b500a96d5157"
                                                                bannerSize:AMRBannerSizeHeight250];
    
    // fetch raw data
    NSArray *news = [[self dictionaryWithJSONFile:@"news"] objectForKey:@"news"];
    
    // add banners to raw data
    [_bannerDataSource addBannersToRawData:news];
    
    // reload tableView with added banners
    [tbMain reloadData];
}

#pragma mark - Action

- (IBAction)AddMoreData:(id)sender {
    NSArray *news = [[self dictionaryWithJSONFile:@"news"] objectForKey:@"news"];
    [_bannerDataSource addBannersToRawData:news];
    
    [tbMain reloadData];
}

#pragma mark - <UITableViewDelegate>

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    [_bannerDataSource tableViewDidScroll];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    if ([_bannerDataSource isAd:indexPath]) {
        return [_bannerDataSource heightForRowAtIndexPath:indexPath];
    } else {
        return 90; // Not ad, return content height.
    }
}

#pragma mark - <UITableViewDataSource>

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [_bannerDataSource numberOfRows];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    if ([_bannerDataSource isAd:indexPath]) {
        return [_bannerDataSource cellForRowAtIndexPath:indexPath];
    } else {
        BannerTableViewDataCell *cell = [tableView dequeueReusableCellWithIdentifier:@"BannerTableViewDataCell"];
        if (cell == nil) {
            cell = [[BannerTableViewDataCell alloc] initWithStyle:UITableViewCellStyleDefault
                                                  reuseIdentifier:@"BannerTableViewDataCell"];
        }
        return cell;
    }
}

- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    if ([_bannerDataSource isAd:indexPath]) {
        [_bannerDataSource willDisplayCell:cell forRowAtIndexPath:indexPath];
    } else {
        NSDictionary* newsItem = [_bannerDataSource dataForIndexPath:indexPath];
        ((BannerTableViewDataCell *)cell).LBLHeader.text = newsItem[@"header"];
        ((BannerTableViewDataCell *)cell).LBLBody.text = newsItem[@"body"];
        ((BannerTableViewDataCell *)cell).IMGImage.image = [UIImage imageNamed:newsItem[@"image"]];
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
