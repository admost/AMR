//
//  AMRInterstitial.h
//  AMRSDK
//
//  Created by Tolga Seremet on 25/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AMRSDK.h"

@class UIViewController;

@interface AMRInterstitial : AMRAd

/// An object conforms to <AMRInterstitialDelegate> protocol.
@property (weak) id<AMRInterstitialDelegate> delegate;

/**
 * Create an instance of AMRInterstitial to show in your application.
 * Example usage:
 * @code
 * [AMRInterstitial interstitialForZoneId:@"<zoneId>"];
 * @endcode
 * @see https://github.com/admost/AMR/blob/master/IOS_Integration/AMR2.0/README.md for more information.
 * @param zoneId Your interstitial's zone ID displayed on AMR Dashboard.
 * @return An instance of AMRInterstitial created by zoneId provided.
 */
+ (instancetype)interstitialForZoneId:(NSString *)zoneId;

/**
 * Start interstitial load request. Delegate must be set before loading an interstitial ad.
 * Example usage:
 * @code
 * [interstitial loadInterstitial];
 * @endcode
 */
- (void)loadInterstitial;

/**
 * Use to show interstitial after delegate callback of AMRInterstitialDelegate's didReceiveInterstitial method.
 * Example usage:
 * @code
 * [interstitial showFromViewController:myViewController];
 * @endcode
 * @see https://github.com/admost/AMR/blob/master/IOS_Integration/AMR2.0/README.md for more information.
 * @param viewController Your interstitial's presenting viewcontroller.
 */
- (void)showFromViewController:(UIViewController * )viewController;

@end
