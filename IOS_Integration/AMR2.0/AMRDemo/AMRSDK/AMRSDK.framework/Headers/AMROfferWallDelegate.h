//
//  AMROfferWallDelegate.h
//  AMRSDK
//
//  Created by Tolga Seremet on 28/11/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

@class AMROfferWall, AMRError;

/**
 * @protocol AMROfferWallDelegate
 * @brief The AMROfferWallDelegate protocol.
 * This protocol is used as a delegate for offerwall events.
 */
@protocol AMROfferWallDelegate <NSObject>

/**
 * Successfully received an offerwall. Call AMROfferWall's showFromViewController method to show offerwall.
 * Example usage:
 * @code
 * [offerwall showFromViewController:myViewController];
 * @endcode
 * @param offerwall AMROfferWall object to show.
 */
- (void)didReceiveOfferWall:(AMROfferWall *)offerwall;

/**
 * Failed to receive an offerwall. Inspect AMRError's errorCode and errorDescription properties to identify the problem.
 * @param offerwall Failed AMROfferWall object
 * @param error AMRError object with error code and descriptions
 */
- (void)didFailToReceiveOfferWall:(AMROfferWall *)offerwall error:(AMRError * )error;

/**
 * Presented offerwall is dismissed. Continue stopped tasks while the offerwall ad is present.
 * @param offerwall Dismissed AMROfferWall object
 */
- (void)didDismissOfferWall:(AMROfferWall *)offerwall;

@end

