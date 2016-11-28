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

@protocol AMRSDKRewardDelegate;

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

/// Check if the status bar is hidden
+ (BOOL)isStatusBarHidden;

/**
 * Set reward delegate for reward collection events.
 * Reward delegate must be set before using rewarded videos or offerwalls.
 * @param delegate An object conforms to <AMRSDKRewardDelegate> protocol.
 */
+ (void)setRewardDelegate:(id<AMRSDKRewardDelegate>)delegate;

/**
 * Start collecting rewards.
 * Reward delegate must be set before starting to collect rewards.
 */
+ (void)collectReward;

@end

/**
 * @protocol AMRSDKRewardDelegate
 * @brief The AMRSDKRewardDelegate protocol.
 * This protocol is used as a delegate for reward collection events.
 */
@protocol AMRSDKRewardDelegate <NSObject>

/**
 * Successfully acquired a reward.
 * @param amount Amount of collected reward.
 * @param currency Currency of collected reward.
 * @param network Network type of rewarding ad network.
 */
- (void)didCollectRewardWithAmount:(NSNumber *)amount
                          currency:(NSString *)currency
                           network:(AMRNetworkType)network;

@end