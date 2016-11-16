//
//  ILMAdViewDelegate.h
//  InLocoMediaAPI
//
//  Created by InLocoMedia on 5/14/14.
//  Copyright (c) 2014 InLocoMedia. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ILMAdView;
@class ILMError;
/*
 The delegate that notifies some of the actions that happened on the view.
 */
@protocol ILMAdViewDelegate <NSObject>

@optional

///This will be called when the view has received an advertisement and will load the image
- (void)ilmAdViewDidReceiveAd:(ILMAdView *)adView;

///Called when an ad request has failed.
- (void)ilmAdView:(ILMAdView *)adView didFailToReceiveAdWithError:(ILMError *)error;

/**
 This will be called after the view is clicked and before the click action is performed
 Return YES if you allow the click action to be performed, NO otherwise.
 */
- (BOOL)ilmAdViewWillPerformClick:(ILMAdView *)adView;

/**
 This will be called after the view is clicked and before leaving the application to open the content of the advertisement.
 */
- (void)ilmAdViewWillLeaveApplication:(ILMAdView *)adView;

/**
 This will be called when a rich media ad has been expanded into fullscreen.
 */
- (void)ilmAdViewExpanded:(ILMAdView *)adView;

/**
 This will be called when a rich media ad has been resized in the current view controller;
 */
- (void)ilmAdViewResized:(ILMAdView *)adView;

@end
