//
//  ILMNativeAdManager.h
//  InLocoMediaAPI
//
//  Created by Rafael Gouveia on 4/28/16.
//  Copyright © 2016 InLocoMedia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ILMNativeAdDelegate.h"
#import "ILMNativeAdResponse.h"

@interface ILMNativeAdManager : NSObject

@property NSObject <ILMNativeAdDelegate> *delegate;

+ (void)requestNativeAdWithAdRequest:(ILMAdRequest *)request andDelegate:(NSObject <ILMNativeAdDelegate> *)delegate;
+ (void)requestNativeAdWithDelegate:(NSObject <ILMNativeAdDelegate> *)delegate;
- (instancetype)init NS_UNAVAILABLE;

@end
