//
//  AMROfferWall.h
//  AMRSDK
//
//  Created by Tolga Seremet on 28/11/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AMRSDK.h"

@class UIViewController;

@interface AMROfferWall : AMRAd

/// An object conforms to <AMRInterstitialDelegate> protocol.
@property (weak) id<AMROfferWallDelegate> delegate;

/**
 * Create an instance of AMROfferWall to show in your application.
 * Example usage:
 * @code
 * [AMROfferWall offerWallForZoneId:@"<zoneId>"];
 * @endcode
 * @see https://github.com/admost/AMR/blob/master/IOS_Integration/AMR2.0/README.md for more information.
 * @param zoneId Your offerwall's zone ID displayed on AMR Dashboard.
 * @return An instance of AMROfferWall created by zoneId provided.
 */
+ (instancetype)offerWallForZoneId:(NSString *)zoneId;

/**
 * Start offerwall load request. Delegate must be set before loading an offerwall.
 * Example usage:
 * @code
 * [offerwall loadOfferWall];
 * @endcode
 */
- (void)loadOfferWall;

/**
 * Use to show offerwall after delegate callback of AMROfferWallDelegate's didReceiveOfferWall method.
 * Example usage:
 * @code
 * [offerwall showFromViewController:myViewController];
 * @endcode
 * @see https://github.com/admost/AMR/blob/master/IOS_Integration/AMR2.0/README.md for more information.
 * @param viewController Your offerwall's presenting viewcontroller.
 */
- (void)showFromViewController:(UIViewController * )viewController;

@end
