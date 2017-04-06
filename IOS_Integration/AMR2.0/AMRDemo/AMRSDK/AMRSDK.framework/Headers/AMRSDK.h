//
//  AMRSDK.h
//  AMRSDK
//
//  Created by Tolga Seremet on 23/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import "AMRTypes.h"
#import "AMRError.h"
#import "AMRAd.h"
#import "AMRBannerDelegate.h"
#import "AMRBanner.h"
#import "AMRBannerView.h"
#import "AMRInterstitialDelegate.h"
#import "AMRInterstitial.h"
#import "AMRRewardedVideoDelegate.h"
#import "AMRRewardedVideo.h"
#import "AMROfferWallDelegate.h"
#import "AMROfferWall.h"
#import "AMRNativeAdBaseView.h"

@protocol AMRVirtualCurrencyDelegate;

@interface AMRSDK : NSObject

/**
 * Start AMRSDK with your application ID displayed on AMR Dashboard.
 * Example usage:
 * @code
 * [AMRSDK startWithAppId:@"<appId>"];
 * @endcode
 * @see https://github.com/admost/AMR/blob/master/IOS_Integration/AMR2.0/README.md for more information.
 * @param appId Your application ID.
 */
+ (void)startWithAppId:(NSString *)appId;

/**
 * Set logging level of AMRSDK.
 * Default value is AMRLogLevelAll which logs everything.
 * Example usage:
 * @code
 * [AMRSDK setLogLevel:AMRLogLevelInfo];
 * @endcode
 * @see AMRTypes.h for more information.
 * @param logLevel Level of log.
 */
+ (void)setLogLevel:(AMRLogLevel)logLevel;

/**
 * Set status bar hidden status of AMRSDK to set the status bar.
 * visible after a full screen ad is dismissed. Recommended for full screen games.
 * Default value is NO.
 * Example usage:
 * @code
 * [AMRSDK setStatusBarHidden:YES];
 * @endcode
 * @param isHidden hidden status of status bar.
 */
+ (void)setStatusBarHidden:(BOOL)isHidden;


/**
 * Set this value to YES to clear cache on application termination.
 * Default value is NO.
 * Following file types will be deleted from application's cache folder.
 * [@"mp4", @"m4v", @"jpg", @"jpeg", @"png", @"gif", @"svg", @"ttf", @"js", @"css", @"html", @"htm"].
 * @code
 * [AMRSDK setClearCacheOnTerminate:YES];
 * @endcode
 * @param shouldClear boolean value to clear cache on application termination.
 */

+ (void)setClearCacheOnTerminate:(BOOL)shouldClear;

/**
 * Warning: Only applies to non-fullscreen banners.
 * Preload banners in spesific zones to show instantly when they are needed to be shown.
 * Pass your zone IDs displayed on AMR Dashboard to preload banners.
 * Example usage:
 * @code
 * [AMRSDK preloadBannersWithZoneIds:@[<zoneId1>,<zoneId2>]];
 * @endcode
 * @param zoneIds NSArray with zoneIds string objects.
 */
+ (void)preloadBannersWithZoneIds:(NSArray *)zoneIds;

/// Get current SDK version
+ (NSString *)SDKVersion;

/// Check if the status bar is hidden
+ (BOOL)isStatusBarHidden;

/**
 * Set virtual currenct delegate for virtual currency events.
 * Virtual currency delegate must be set before using offerwalls.
 * @param delegate An object conforms to <AMRVirtualCurrencyDelegate> protocol.
 */
+ (void)setVirtualCurrencyDelegate:(id<AMRVirtualCurrencyDelegate>)delegate;

/**
 * Start spending virtual currencies.
 * Virtual currency delegate must be set before starting to spend virtual currencies.
 */
+ (void)spendVirtualCurrency;

@end

/**
 * @protocol AMRVirtualCurrencyDelegate
 * @brief The AMRVirtualCurrencyDelegate protocol.
 * This protocol is used as a delegate for virtual currency events.
 */
@protocol AMRVirtualCurrencyDelegate <NSObject>

/**
 * Successfully spent virtual currency.
 * @param amount Amount of virtual currency.
 * @param currency Currency of virtual currency.
 * @param network Network type of cirtual currency ad network.
 */
- (void)didSpendVirtualCurrency:(NSString *)currency
                          amout:(NSNumber *)amount
                        network:(AMRNetworkType)network;

@end
