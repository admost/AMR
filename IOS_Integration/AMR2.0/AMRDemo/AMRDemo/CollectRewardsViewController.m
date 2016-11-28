//
//  CollectRewardsViewController.m
//  AMRDemo
//
//  Created by Tolga Seremet on 28/11/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import "CollectRewardsViewController.h"
#import <AMRSDK/AMRSDK.h>

@interface CollectRewardsViewController () <AMRSDKRewardDelegate> @end

@implementation CollectRewardsViewController

#pragma mark - View lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc {
    [AMRSDK setRewardDelegate:nil];
}

- (IBAction)collect {
    [AMRSDK setRewardDelegate:self];
    [AMRSDK collectReward];
}

#pragma mark - <AMRSDKRewardDelegate>

- (void)didCollectRewardWithAmount:(NSNumber *)amount
                          currency:(NSString *)currency
                           network:(AMRNetworkType)network {
    NSLog(@"Reward Collected: %@ - %@", amount, currency);
}

@end