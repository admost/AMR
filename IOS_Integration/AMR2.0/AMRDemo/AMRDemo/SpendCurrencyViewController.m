//
//  CollectRewardsViewController.m
//  AMRDemo
//
//  Created by Tolga Seremet on 28/11/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import "SpendCurrencyViewController.h"
#import <AMRSDK/AMRSDK.h>

@interface SpendCurrencyViewController () <AMRVirtualCurrencyDelegate> @end

@implementation SpendCurrencyViewController

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
    [AMRSDK setVirtualCurrencyDelegate:nil];
}

- (IBAction)spend {
    [AMRSDK setVirtualCurrencyDelegate:self];
    [AMRSDK spendVirtualCurrency];
}

#pragma mark - <AMRVirtualCurrencyDelegate>

- (void)didSpendVirtualCurrenct:(NSString *)currency
                          amout:(NSNumber *)amount
                        network:(AMRNetworkType)network {
    NSLog(@"Virtual Currency Spent: %@ - %@", amount, currency);
}

@end