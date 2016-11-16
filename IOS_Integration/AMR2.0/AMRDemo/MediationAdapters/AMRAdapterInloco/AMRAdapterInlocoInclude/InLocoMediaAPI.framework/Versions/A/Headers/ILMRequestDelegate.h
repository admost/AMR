//
//  UBRequestDelegate.h
//  InLocoMediaAPI
//
//  Created by InLocoMedia on 11/20/13.
//  Copyright (c) 2013 InLocoMedia. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ILMLocation;
@class ILMAdvertisementModel;
@class ILMError;

@protocol ILMRequestDelegate <NSObject>

@required
- (void)onRequestFailure:(ILMError *)error;

@optional
- (void)onLocationReceived:(ILMLocation *)locationResult;
- (void)onAdvertisementReceived:(ILMAdvertisementModel *)advertisementResult;
- (void)onRetailsReceived:(NSArray *)retails;
@end

@protocol ILMRetailsDelegate <ILMRequestDelegate>
@required
- (void)onRetailsReceived:(NSArray *)retails;
@end

@protocol ILMLocationDelegate <ILMRequestDelegate>
@required
- (void)onLocationReceived:(ILMLocation *)locationResult;
@end
