//
//  ILMAdvertisement.h
//  InLocoMediaAPI
//
//  Created by InLocoMedia on 1/17/14.
//  Copyright (c) 2014 InLocoMedia. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ILMAdvertisementModel;

@interface ILMAdvertisement : NSObject

// The identifier of the advertisement
@property (nonatomic, strong) NSString *identifier;

// The url with the content of the advertisement
@property (nonatomic, strong) NSString *url;

// The url with the content of the deeplink
@property (nonatomic, strong) NSString *deeplink;

// The url with the content of the advertisement
@property (nonatomic, strong) NSString *title;

// The message is an ad description
@property (nonatomic, strong) NSString *message;

// The time the ad was received
@property (nonatomic, strong) NSNumber *timeStamp;

- (instancetype)init NS_UNAVAILABLE;

@end