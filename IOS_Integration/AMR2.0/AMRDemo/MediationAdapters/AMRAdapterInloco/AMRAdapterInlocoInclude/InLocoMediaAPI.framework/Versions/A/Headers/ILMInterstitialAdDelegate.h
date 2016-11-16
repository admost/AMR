//
//  ILMInterstitialAdDelegate.h
//  InLocoMediaAPI
//
//  Created by InLocoMedia on 6/18/14.
//  Copyright (c) 2014 InLocoMedia. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ILMInterstitialAd;
@class ILMError;

/*
 The delegate that notifies some of the actions that happened on the view.
 */
@protocol ILMInterstitialAdDelegate <NSObject>

@optional

//This will be called when the interstitial ad has been completed and is ready to be shown
- (void)ilmInterstitialAdDidReceiveAd:(ILMInterstitialAd *)interstitialAd;

//Called when an ad request has failed.
- (void)ilmInterstitialAd:(ILMInterstitialAd *)adView didFailToReceiveAdWithError:(ILMError *)error;

//Called before the Interstitial appear
- (void)ilmInterstitialAdWillAppear:(ILMInterstitialAd *)interstitialAd;

//Called before the Interstitial will close
- (void)ilmInterstitialAdWillDisappear:(ILMInterstitialAd *)interstitialAd;

//Called after the Interstitial did close
- (void)ilmInterstitialAdDidDisappear:(ILMInterstitialAd *)interstitialAd;

//This will be called after the view is clicked and before leaving the application to open the content of the advertisement.
- (void)ilmInterstitialAdViewWillLeaveApplication:(ILMInterstitialAd *)interstitialAd;

@end
