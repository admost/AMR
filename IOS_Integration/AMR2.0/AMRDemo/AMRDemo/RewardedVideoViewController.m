//
//  RewardedVideoViewController.m
//  AMRDemo
//
//  Created by Tolga Seremet on 31/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import "RewardedVideoViewController.h"
#import <KKLog/KKLog.h>
#import <AMRSDK/AMRSDK.h>

@interface RewardedVideoViewController () <AMRRewardedVideoDelegate> {
    AMRRewardedVideo* _rewardedVideo;
    IBOutlet UIActivityIndicatorView *AILoading;
}

@end

#pragma mark - View lifecycle

@implementation RewardedVideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    _rewardedVideo = [AMRRewardedVideo rewardedVideoForZoneId:@"2bdefd44-5269-4cbc-b93a-373b74a2f067"];
    _rewardedVideo.delegate = self;
    [_rewardedVideo loadRewardedVideo];
}

- (void)dealloc {
    
}

#pragma mark - <AMRRewardedVideoDelegate>

- (void)didReceiveRewardedVideo:(AMRRewardedVideo *)rewardedVideo {
    [AILoading stopAnimating];
    [rewardedVideo showFromViewController:self];
}

- (void)didFailToReceiveRewardedVideo:(AMRRewardedVideo *)rewardedVideo error:(AMRError *)error {
    [AILoading stopAnimating];
    KKLogError(error.errorDescription);
}

- (void)didDismissRewardedVideo:(AMRRewardedVideo *)rewardedVideo {
    KKLogInfo(@"Rewarded video dismissed");
}

- (void)didCancelRewardedVideo:(AMRRewardedVideo *)rewardedVideo {
    KKLogInfo(@"Rewarded video skipped");
}

- (void)didCompleteRewardedVideo:(AMRRewardedVideo *)rewardedVideo {
    KKLogInfo(@"Rewarded video completed");
}

@end