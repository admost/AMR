//
//  ILMNativeAdResponse.h
//  InLocoMediaAPI
//
//  Created by Rafael Gouveia on 4/28/16.
//  Copyright © 2016 InLocoMedia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ILMNativeAdDelegate.h"

@class ILMNativeAd;

@interface ILMNativeAdResponse : NSObject

@property (nonatomic, strong) ILMNativeAd *nativeAd;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithNativeAd:(ILMNativeAd *)nativeAd withDelegate:(NSObject <ILMNativeAdDelegate> *)delegate;
- (NSString *)title;
- (NSString *)description;
- (NSString *)highlightText;
- (NSString *)iconUrl;
- (NSString *)mainImageUrl;
- (NSString *)callToAction;
- (BOOL)performClick;
- (void)registerImpression;

@end