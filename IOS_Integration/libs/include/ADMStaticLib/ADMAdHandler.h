//
//  MSMAdHandler.h
//  DP
//
//  Created by Tolga Seremet on 24/08/15.
//  Copyright (c) 2015 Masomo. All rights reserved.
//

#define LOG_ENABLED YES

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ADMAd.h"
#import "ADMBannerHelper.h"
#import "MPAdView.h"
#import "MPNativeAd.h"
#import "MPNativeAdDelegate.h"
#import <AmazonAd/AmazonAdView.h>
#import "ADMAdLoadedDelegate.h"
#import "ADMInterstitialShowDelegate.h"

#define ADHANDLER_TIMEOUT 2
typedef enum {
    ADMAdHandlerBannerLocationTypeInline = 1,
    ADMAdHandlerBannerLocationTypeInterstital = 2,
    ADMAdHandlerBannerLocationTypeUndefined = 0
} ADMAdHandlerBannerLocationType;

typedef enum {
    ADMAdHandlerBannerZoneNative,
    ADMAdHandlerBannerZoneBanner
} ADMAdHandlerBannerZone;

typedef enum {
    ADMAdHandlerBannerHeightLarge,
    ADMAdHandlerBannerHeightNormal
} ADMAdHandlerBannerHeight;

@interface ADMAdHandler : NSObject<MPAdViewDelegate,AmazonAdViewDelegate,MPNativeAdDelegate>
@property (nonatomic, weak) id<ADMAdLoadedDelegate> delegate;

#pragma mark - Initialization

- (instancetype)initWithADMZone:(NSString*)zone
                          isBig:(BOOL)isBig
                       cellType:(ADMAdCellType)cellType
             rootViewController:(UIViewController*)viewController;

- (instancetype)initWithADMZone:(NSString*)zone
                          isBig:(BOOL)isBig
             rootViewController:(UIViewController*)viewController;

- (instancetype)initWithADMZone:(NSString*)zone
                          isBig:(BOOL)isBig
                       cellType:(ADMAdCellType)cellType
             rootViewController:(UIViewController*)viewController
                 containerWidth:(CGFloat)containerWidth;

- (instancetype)initWithAdmostPBK:(NSString*)pbk
                            isBig:(BOOL)isBig
                         cellType:(ADMAdCellType)cellType
               rootViewController:(UIViewController*)viewController
                   containerWidth:(CGFloat)containerWidth
                        smallIs50:(BOOL)smallIs50;

- (instancetype)initWithAdmostPBK:(NSString*)pbk
                            isBig:(BOOL)isBig
                         cellType:(ADMAdCellType)cellType
               rootViewController:(UIViewController*)viewController
                   containerWidth:(CGFloat)containerWidth;

#pragma mark -LoadBanner

// AMR Methods
- (void)loadBannerForPlacement:(NSString*)placement;
- (void)loadInterstitialForPlacement:(NSString*)placement;
// ADMost Method
- (void)loadBannerForIndexPath:(NSIndexPath*)indexPath isInterstitial:(BOOL)isInterstitial;

- (ADMAd*)adForIndexPath:(NSIndexPath*)indexPath;
- (void)resetBanners;
#pragma mark - Interstitial
- (BOOL)showInterstitialForIndexPath:(NSIndexPath*)indexPath;
- (BOOL)showInterstitialForPlacement:(NSString*)indexPath;
- (BOOL)showInterstitialForPlacement:(NSString*)placement fromViewController:(UIViewController *)controller;
+ (NSString*)deviceName;
#pragma mark - Register Nibs
+ (void)registerNibsForCollectionView:(UICollectionView*)collectionView;
+ (void)registerNibsForTableView:(UITableView*)tableView;
+ (NSString*)nibNameForCollectionViewPlaceHolder;
+ (NSString*)nibNameForTableViewPlaceHolder:(BOOL)isDarkBackground;
+ (float)defaultHeightForTableViewPlaceHolder;
#pragma mark - Collection Manipulation
+ (NSMutableArray*)addAdsToResultArray:(NSMutableArray*)resultArray
                       forCurrentCount:(NSInteger)currentCount
                        withStartIndex:(NSInteger)startIndex
                   andRecurrencyPeriod:(NSInteger)recurrencyPeriod;
+ (NSMutableArray*)addAdsToResultArray:(NSMutableArray*)resultArray
                     excludingIndexses:(NSIndexSet*)excludedIndexes
                       forCurrentCount:(NSInteger)currentCount
                        withStartIndex:(NSInteger)startIndex
                   andRecurrencyPeriod:(NSInteger)recurrencyPeriod;
#pragma mark - utilities
+ (NSString *)mediationNetworkNameForBanner:(id)banner;
+ (BOOL)isInterstitialViewControllerOnTop;
+ (BOOL)isInterstitialViewControllerOnTop:(UIViewController*)viewController;
#pragma mark - Static methods
+ (id)bannerHelperForIndexPath:(NSIndexPath*)indexPath
            rootViewController:(UIViewController*)rootViewController
                  locationType:(ADMAdHandlerBannerLocationType)locationType
                      cellType:(ADMAdCellType)cellType
                    bannerType:(ADMAdHandlerBannerType)bannerType
                      adUnitID:(NSString*)adUnitID
                         isBig:(BOOL)isBig
           bannerPlacementType:(ADMAdHandlerBannerPlacementType)bannerPlacementType
                containerWidth:(CGFloat)containerWidth
              admostDictionary:(NSDictionary*)admostDictionary
                     isSmall50:(BOOL)isSmall50;
#pragma mark - Set Admost Parameters
- (void)setAdmostParameters:(NSMutableDictionary*)admostParameters;
@end
