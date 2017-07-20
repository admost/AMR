//
//  AMRRewardedVideoDelegate.h
//  AMRSDK
//
//  Created by Tolga Seremet on 26/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

@class AMRRewardedVideo, AMRError;

/**
 * @protocol AMRRewardedVideoDelegate
 * @brief The AMRRewardedVideoDelegate protocol.
 * This protocol is used as a delegate for rewarded video events.
 */
@protocol AMRRewardedVideoDelegate <NSObject>

/**
 * Successfully received a rewarded video. Call AMRRewardedVideo's showFromViewController method to start rewarded video.
 * Example usage:
 * @code
 * [rewardedVideo showFromViewController:myViewController];
 * @endcode
 * @param rewardedVideo AMRRewardedVideo object to show.
 */
- (void)didReceiveRewardedVideo:(AMRRewardedVideo *)rewardedVideo;

/**
 * Failed to receive an rewarded video. Inspect AMRError's errorCode and errorDescription properties to identify the problem.
 * @param rewardedVideo Failed AMRRewardedVideo object
 * @param error AMRError object with error code and descriptions
 */
- (void)didFailToReceiveRewardedVideo:(AMRRewardedVideo *)rewardedVideo error:(AMRError *)error;

@optional

/**
 * Successfully shown received rewarded video.
 * @param rewardedVideo Shown AMRRewardedVideo object
 */
- (void)didShowRewardedVideo:(AMRRewardedVideo *)rewardedVideo;

/**
 * Presented rewardedvideo is dismissed. Continue stopped tasks while the rewardedvideo ad is present. Called after didCompleteRewardedVideo delegate callback.
 * @param rewardedVideo Dismissed AMRRewardedVideo object
 */
- (void)didDismissRewardedVideo:(AMRRewardedVideo *)rewardedVideo;

/**
 * User watched rewarded video till end. User can get the reward.
 * @param rewardedVideo AMRRewardedVideo object
 */
- (void)didCompleteRewardedVideo:(AMRRewardedVideo *)rewardedVideo;

/**
 * User rewarded with amount for completing a task or watching a rewarded video.
 * @param rewardedVideo AMRRewardedVideo object
 * @param rewardAmount Reward amount
 */
- (void)didRewardUser:(NSNumber *)rewardAmount forRewardedVideo:(AMRRewardedVideo *)rewardedVideo;

@end
