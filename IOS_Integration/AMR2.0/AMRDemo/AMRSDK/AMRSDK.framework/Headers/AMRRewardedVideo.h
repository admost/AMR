//
//  AMRRewardedVideo.h
//  AMRSDK
//
//  Created by Tolga Seremet on 26/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AMRSDK.h"

@class AMRAd, UIViewController;

@interface AMRRewardedVideo : AMRAd

/// An object conforms to <AMRRewardedVideoDelegate> protocol.
@property (weak) id<AMRRewardedVideoDelegate> delegate;

/**
 * Create an instance of AMRRewardedVideo to show in your application.
 * Example usage:
 * @code
 * [AMRRewardedVideo rewardedVideoForZoneId:@"<zoneId>"];
 * @endcode
 * @see https://github.com/admost/AMR/blob/master/IOS_Integration/AMR2.0/README.md for more information.
 * @param zoneId Your rewardedvideo's zone ID displayed on AMR Dashboard.
 * @return An instance of AMRRewardedVideo created by zoneId provided.
 */
+ (instancetype)rewardedVideoForZoneId:(NSString *)zoneId;

/**
 * Start rewardedvideo load request. Delegate must be set before loading an rewardedvideo.
 * Example usage:
 * @code
 * [rewardedVideo loadRewardedVideo];
 * @endcode
 */
- (void)loadRewardedVideo;

/**
 * Use to show rewardedvideo after delegate callback of AMRRewardedVideoDelegate's didReceiveRewardedVideo method.
 * Example usage:
 * @code
 * [rewardedVideo showFromViewController:myViewController];
 * @endcode
 * @see https://github.com/admost/AMR/blob/master/IOS_Integration/AMR2.0/README.md for more information.
 * @param viewController Your rewardedvideo's presenting viewcontroller.
 */
- (void)showFromViewController:(UIViewController * )viewController;

@end
