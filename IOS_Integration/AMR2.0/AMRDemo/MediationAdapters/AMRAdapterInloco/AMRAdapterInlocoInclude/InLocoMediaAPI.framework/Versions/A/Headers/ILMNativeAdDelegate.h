//
//  ILMNativeAdDelegate.h
//  InLocoMediaAPI
//
//  Created by Rafael Gouveia on 4/28/16.
//  Copyright © 2016 InLocoMedia. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ILMNativeAdResponse;

@protocol ILMNativeAdDelegate <NSObject>

@optional
///This will be called when the manager has received an advertisement and return to the use
- (void)ilmNativeAdViewDidReceiveAd:(ILMNativeAdResponse *)native;

///Called when an ad request has failed.
- (void)ilmDidFailToReceiveNativeAdWithError:(ILMError *)error;

//This will be called after the click was performed.
- (void)ilmNativeAdDidPerformClick:(ILMNativeAdResponse *)native successful:(BOOL)successful;

@end
