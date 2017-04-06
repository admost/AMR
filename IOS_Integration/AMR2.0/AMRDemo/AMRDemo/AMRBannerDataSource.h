//
//  AMRBannerDataSource.h
//  AMRDemo
//
//  Created by Tolga Seremet on 15/02/17.
//  Copyright © 2017 Tolga Seremet. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AMRSDK/AMRSDK.h>

@interface AMRBannerDataSource : NSObject
#pragma mark - NSObject
+ (instancetype)bannerDataSourceWithTableView:(UITableView *)tableView
                                       zoneId:(NSString *)zoneId
                                   bannerSize:(AMRBannerSize)bannerSize;
#pragma mark - Data preparation
- (void)resetBanners;
- (void)addBannersToRawData:(NSArray *)rawData;

#pragma mark - Data methods
- (id)dataForIndexPath:(NSIndexPath *)indexPath;
- (BOOL)isAd:(NSIndexPath *)indexPath;

#pragma mark - <UITableViewDelegate, UITableViewDataSource>
- (void)tableViewDidScroll;
- (NSInteger)numberOfRows;
- (CGFloat)heightForRowAtIndexPath:(NSIndexPath *)indexPath;
- (UITableViewCell *)cellForRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath;
@end

#pragma mark - AMRBannerPlaceHolder
typedef enum {
    AMRBannerPlaceHolderTypeNew,
    AMRBannerPlaceHolderTypeFailed
} AMRBannerPlaceHolderType;

@interface AMRBannerPlaceHolder : NSObject
@property AMRBannerPlaceHolderType type;
+ (instancetype)placeHolderWithType:(AMRBannerPlaceHolderType)type;

@end
