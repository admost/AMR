//
//  AMRBanner.h
//  AMRSDK
//
//  Created by Tolga Seremet on 23/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import "AMRBannerView.h"
#import "AMRTypes.h"
#import "AMRSDK.h"

@interface AMRBanner : AMRAd

/// An object conforms to <AMRBannerDelegate> protocol.
@property (weak) id<AMRBannerDelegate> delegate;
/// A UIView to add as a subview to show banner.
@property AMRBannerView *bannerView;
/// A parent UIViewController required to catch taps.
@property UIViewController *viewController;
/// Width value of banner, default is screen width. 
@property (nonatomic) CGFloat bannerWidth;

/**
 * Create an instance of AMRBanner to show in your application.
 * Example usage:
 * @code
 * [AMRBanner bannerForZoneId:@"<zoneId>"];
 * @endcode
 * @see https://github.com/admost/AMR/blob/master/IOS_Integration/AMR2.0/README.md for more information.
 * @param ZoneId Your banner's zone ID displayed on AMR Dashboard.
 * @return An instance of AMRBanner created by zoneId provided.
 */
+ (instancetype)bannerForZoneId:(NSString *)zoneId;

/**
 * Start banner loading request. Delegate must be set before loading a banner ad.
 * Example usage:
 * @code
 * [banner loadBanner];
 * @endcode
 */
- (void)loadBanner;

@end
