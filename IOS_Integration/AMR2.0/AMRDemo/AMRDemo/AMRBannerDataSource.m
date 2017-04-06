//
//  AMRBannerDataSource.m
//  AMRDemo
//
//  Created by Tolga Seremet on 15/02/17.
//  Copyright © 2017 Tolga Seremet. All rights reserved.
//

#import "AMRBannerDataSource.h"
#import "BannerTableViewAdCell.h"

static NSInteger const kAMRBannerFrequency = 5;
static NSInteger const kAMRNumberOfBannersToPreload = 2;

@interface AMRBannerDataSource () <AMRBannerDelegate> @end

@implementation AMRBannerDataSource {
    NSMutableArray *_rawDataWithBanners;
    __weak UITableView *_tableView;
    NSString *_zoneId;
    AMRBannerSize _bannerSize;
}

#pragma mark - NSObject
+ (instancetype)bannerDataSourceWithTableView:(UITableView *)tableView
                                       zoneId:(NSString *)zoneId
                                   bannerSize:(AMRBannerSize)bannerSize {
    
    return [[self alloc] initWithTableView:tableView
                                    zoneId:zoneId
                                bannerSize:bannerSize];
}

- (instancetype)initWithTableView:(UITableView *)tableView
                           zoneId:(NSString *)zoneId
                       bannerSize:(AMRBannerSize)bannerSize {
    
    if (!(self = [super init]))
        return nil;
    
    _rawDataWithBanners = [NSMutableArray new];
    _tableView = tableView;
    _zoneId = zoneId;
    _bannerSize = bannerSize;
    return self;
}

- (void)dealloc {
    [self resetBanners];
}

#pragma mark - Data preparation
- (void)resetBanners {
    [_rawDataWithBanners removeAllObjects];
}

- (void)addBannersToRawData:(NSArray *)rawData {
    if (rawData == nil || rawData.count == 0) {return;}
    
    NSInteger offsetIndex = (_rawDataWithBanners.count - 1) - [self lastBannerIndex];
    if (offsetIndex < 0) offsetIndex = 0;
    
    // add banner placeholder after each kAMRBannerFrequency items.
    for (int i = 0; i < rawData.count; i++) {
        [_rawDataWithBanners addObject:rawData[i]];
        if ((i+1+offsetIndex)%kAMRBannerFrequency == 0 && i >0) {
            [_rawDataWithBanners addObject:[AMRBannerPlaceHolder placeHolderWithType:AMRBannerPlaceHolderTypeNew]];
        }
    }
}

#pragma mark - Data methods
- (id)dataForIndexPath:(NSIndexPath *)indexPath {
    return _rawDataWithBanners[indexPath.row];
}

- (BOOL)isAd:(NSIndexPath *)indexPath {
    if ([[_rawDataWithBanners objectAtIndex:indexPath.row] isKindOfClass:[AMRBannerPlaceHolder class]] ||
        [[_rawDataWithBanners objectAtIndex:indexPath.row] isKindOfClass:[AMRBanner class]]) {
        return YES;
    }
    return NO;
}

- (BOOL)isAdLoaded:(NSIndexPath *)indexPath {
    if ([[_rawDataWithBanners objectAtIndex:indexPath.row] isKindOfClass:[AMRBanner class]]) {
        AMRBanner* banner = [_rawDataWithBanners objectAtIndex:indexPath.row];
        // if banner is loaded use its bannerview
        if (banner.bannerView != nil) {
            return YES;
        }
    }
    return NO;
}

- (BOOL)isAdFailed:(NSIndexPath *)indexPath {
    if ([[_rawDataWithBanners objectAtIndex:indexPath.row] isKindOfClass:[AMRBannerPlaceHolder class]] &&
        ((AMRBannerPlaceHolder *)[_rawDataWithBanners objectAtIndex:indexPath.row]).type == AMRBannerPlaceHolderTypeFailed) {
        return YES;
    }
    return NO;
}

- (NSIndexPath *)indexPathForBanner:(AMRBanner *)banner {
    NSInteger index = [_rawDataWithBanners indexOfObject:banner];
    if (index != NSNotFound) {
        return [NSIndexPath indexPathForRow:index inSection:0];
    }
    return nil;
}

#pragma mark - <UITableViewDelegate, UITableViewDataSource>
- (void)tableViewDidScroll {
    NSArray *indexPathsForVisibleRows = _tableView.indexPathsForVisibleRows;
    
    NSInteger highestRowNum = ((NSIndexPath *)[indexPathsForVisibleRows lastObject]).row;
    
    NSInteger preloadedBanners = 0;
    
    for (NSInteger i = highestRowNum; i<_rawDataWithBanners.count; i ++) {
        
        if (preloadedBanners == kAMRNumberOfBannersToPreload) {
            break;
        }
        
        id object = _rawDataWithBanners[i];
        
        // if banner incerement preloadedBanners count
        if ([self isAd:[NSIndexPath indexPathForRow:i inSection:0]]) {
            preloadedBanners++;
        }
        
        if ([object isKindOfClass:[AMRBannerPlaceHolder class]] &&
            ((AMRBannerPlaceHolder*)object).type == AMRBannerPlaceHolderTypeNew) {
            AMRBanner* banner = [AMRBanner bannerForZoneId:_zoneId];
            banner.delegate = self;
            [_rawDataWithBanners replaceObjectAtIndex:[_rawDataWithBanners indexOfObject:object] withObject:banner];
            [banner loadBanner];
            
            NSLog(@"WILL PRELOAD %@ - %@", @(preloadedBanners), @(i));
        }
    }
}

- (NSInteger)numberOfRows {
    if (_rawDataWithBanners != nil) {
        return _rawDataWithBanners.count;
    }
    return 0;
}

- (CGFloat)heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    if ([self isAdLoaded:indexPath]) {
        // Loaded, return zone banner height; 50, 90 or 250.
        return [AMRBannerDataSource bannerHeightForBannerSize:_bannerSize];
    }
    if ([self isAdFailed:indexPath]) {
        // Failed to load, return 0, hide cell.
        return 0;
    }
    // Not loaded, return a placeholder height, 0 or content height.
    return 20;
}

- (UITableViewCell *)cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    BannerTableViewAdCell *cell = [_tableView dequeueReusableCellWithIdentifier:@"BannerTableViewAdCell"];
    if (cell == nil) {
        cell = [[BannerTableViewAdCell alloc] initWithStyle:UITableViewCellStyleDefault
                                            reuseIdentifier:@"BannerTableViewAdCell"];
    }
    return cell;
}

- (void)willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    //load banner for placeholder object
    if ([[_rawDataWithBanners objectAtIndex:indexPath.row] isKindOfClass:[AMRBannerPlaceHolder class]]) {
        if (((AMRBannerPlaceHolder*)[_rawDataWithBanners objectAtIndex:indexPath.row]).type == AMRBannerPlaceHolderTypeNew) {
            // load an ad to placeHolder if its not failed
            AMRBanner* banner = [AMRBanner bannerForZoneId:_zoneId];
            banner.delegate = self;
            [_rawDataWithBanners replaceObjectAtIndex:indexPath.row withObject:banner];
            [banner loadBanner];
        }
    } else if ([[_rawDataWithBanners objectAtIndex:indexPath.row] isKindOfClass:[AMRBanner class]]) {
        AMRBanner* banner = [_rawDataWithBanners objectAtIndex:indexPath.row];
        // if banner is loaded use its bannerview
        if (banner.bannerView != nil) {
            ((BannerTableViewAdCell *)cell).bannerView = banner.bannerView;
        }
    }
}

#pragma mark - <AMRBannerDelegate>
- (void)didReceiveBanner:(AMRBanner *)banner {
    // reload cell if visible;
    NSIndexPath *indexPath = [self indexPathForBanner:banner];
    if ([_tableView.indexPathsForVisibleRows containsObject:indexPath]) {
        [_tableView reloadRowsAtIndexPaths:@[indexPath]
                          withRowAnimation:UITableViewRowAnimationNone];
    }
}

- (void)didFailToReceiveBanner:(AMRBanner *)banner error:(AMRError *)error {
    // mark banner is failed
    NSIndexPath *indexPath = [self indexPathForBanner:banner];
    [_rawDataWithBanners replaceObjectAtIndex:indexPath.row withObject:[AMRBannerPlaceHolder placeHolderWithType:AMRBannerPlaceHolderTypeFailed]];
    
    // reload cell if visible
    if ([_tableView.indexPathsForVisibleRows containsObject:indexPath]) {
        [_tableView reloadRowsAtIndexPaths:@[indexPath]
                          withRowAnimation:UITableViewRowAnimationNone];
    }
}

#pragma mark - Utilities
- (NSUInteger)lastBannerIndex {
    for (NSInteger i=_rawDataWithBanners.count-1; i >= 0; i--) {
        if ([[_rawDataWithBanners objectAtIndex:i] isKindOfClass:[AMRBannerPlaceHolder class]] ||
            [[_rawDataWithBanners objectAtIndex:i] isKindOfClass:[AMRBanner class]]) {
            return i;
        }
    }
    
    return 0;
}

+ (CGFloat)bannerHeightForBannerSize:(AMRBannerSize)bannerSize {
    switch (bannerSize) {
        case AMRBannerSizeHeight50:
            return 50;
            break;
            
        case AMRBannerSizeHeight90:
            return 90;
            break;
            
        case AMRBannerSizeHeight250:
            return 250;
            break;
            
        default:
            return 50;
            break;
    }
}

@end

#pragma mark - AMRBannerPlaceHolder
@implementation AMRBannerPlaceHolder

+ (instancetype)placeHolderWithType:(AMRBannerPlaceHolderType)type {
    return [[[self class] alloc] initWithPlaceHolderType:type];
}

- (instancetype)initWithPlaceHolderType:(AMRBannerPlaceHolderType)type {
    if (!(self = [super init]))
        return nil;
    _type = type;
    
    return self;
}

@end
