//
//  AMRBannerDelegate.h
//  AMRSDK
//
//  Created by Tolga Seremet on 23/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

@class AMRBanner, AMRError;

/**
 * @protocol AMRBannerDelegate
 * @brief The AMRBannerDelegate protocol.
 * This protocol is used as a delegate for banner events.
 */
@protocol AMRBannerDelegate <NSObject>

/**
 * Successfully received a banner. Add AMRBanner's bannerView as a subview to show banner.
 * Example usage:
 * @code
 * [self.view addSubview:banner.bannerView];
 * @endcode
 * @param banner AMRBanner object with a bannerView to show
 */
- (void)didReceiveBanner:(AMRBanner *)banner;

/**
 * Failed to receive a banner. Inspect AMRError's errorCode and errorDescription properties to identify the problem.
 * @param banner Failed AMRBanner object
 * @param error AMRError object with error code and descriptions
 */
- (void)didFailToReceiveBanner:(AMRBanner *)banner error:(AMRError *)error;

@end
