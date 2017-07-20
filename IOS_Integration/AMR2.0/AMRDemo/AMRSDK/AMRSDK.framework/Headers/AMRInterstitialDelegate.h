//
//  AMRInterstitialDelegate.h
//  AMRSDK
//
//  Created by Tolga Seremet on 25/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

@class AMRInterstitial, AMRError;

/**
 * @protocol AMRInterstitialDelegate
 * @brief The AMRInterstitialDelegate protocol.
 * This protocol is used as a delegate for interstitial events.
 */
@protocol AMRInterstitialDelegate <NSObject>

/**
 * Successfully received an interstitial. Call AMRInterstitial's showFromViewController method to show interstitial.
 * Example usage:
 * @code
 * [interstitial showFromViewController:myViewController];
 * @endcode
 * @param interstitial AMRInterstitial object to show.
 */
- (void)didReceiveInterstitial:(AMRInterstitial *)interstitial;

/**
 * Failed to receive an interstitial. Inspect AMRError's errorCode and errorDescription properties to identify the problem.
 * @param interstitial Failed AMRInterstitial object
 * @param error AMRError object with error code and descriptions
 */
- (void)didFailToReceiveInterstitial:(AMRInterstitial *)interstitial error:(AMRError * )error;

@optional

/**
 * Successfully shown received interstital.
 * @param interstitial Shown AMRInterstitial object
 */
- (void)didShowInterstitial:(AMRInterstitial *)interstitial;

/**
 * Presented interstital is dismissed. Continue stopped tasks while the interstital ad is present.
 * @param interstitial Dismissed AMRInterstitial object
 */
- (void)didDismissInterstitial:(AMRInterstitial *)interstitial;

@end
