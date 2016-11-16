//
//  ILMInterstitialAd.h
//  InLocoMediaAPI
//
//  Created by InLocoMedia on 6/18/14.
//  Copyright (c) 2014 InLocoMedia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIApplication.h>
#import "ILMAdRequest.h"
#import "ILMInterstitialAdDelegate.h"

// InterstitialAd minimum request timeout interval, value = 5
extern NSTimeInterval const kILMAdRequestTimeoutMin;

@interface ILMInterstitialAd : NSObject

@property (nonatomic, weak) NSObject <ILMInterstitialAdDelegate> *delegate;

@property (nonatomic, assign) NSTimeInterval requestTimeout;

// Load interstitial ad with default request. The request will use the default UserProfile in case it exists.
- (void)loadAd;

// Load insterstitial with given AdRequest.
- (void)loadAdWithRequest:(ILMAdRequest *)request;

// Present interstitial ad from an given view controller.
- (void)presentFromViewController:(UIViewController *)viewController;

// Present interstitial ad from an given view controller.
- (void)present;

// Set screen orientation to the interstitial
- (void)setOrientation:(UIInterfaceOrientation)orientation;

// Set delegate object to receive callback functions of the insterstitial ad. The delegate should implement  the ILMInterstitialAdDelegate
- (void)setDelegate:(NSObject <ILMInterstitialAdDelegate> *)delegate;

@end