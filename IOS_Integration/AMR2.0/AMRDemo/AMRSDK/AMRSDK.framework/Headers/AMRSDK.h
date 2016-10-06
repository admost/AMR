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

@interface AMRSDK : NSObject

/**
 * Start AMRSDK with your application ID displayed on AMR Dashboard.
 * Example usage:
 * @code
 * [AMRSDK startWithAppId:@"<appId>"];
 * @endcode
 * @see https://github.com/kokteyldev/AMR/blob/master/IOS_Integration/README.md for more information.
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
 * Set status bar hidden status of AMRSDK to set the status bar
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

@end
