//
//  ILMrror.h
//  InLocoMediaAPI
//
//  Created by InLocoMedia on 11/20/13.
//  Copyright (c) 2013 InLocoMedia. All rights reserved.
//

#import <Foundation/Foundation.h>

//#define ILME_ERROR_MESSAGE_REGEX_1 @"^errors:\\[(\\w+)\\.(\\w+)(\\-\\w+)*\\]$"
#define ILME_ERROR_MESSAGE_REGEX_1 @"(\\w+)\\.(\\w+)(\\-\\w+)*"

extern NSString *const ILMAdsErrorDomain;
extern NSString *const ILMLocationErrorDomain;
extern NSString *const ILMMapsErrorDomain;
extern NSString *const ILMAuthenticationErrorDomain;
extern NSString *const ILMNetworkErrorDomain;
extern NSString *const ILMExceptionErrorDomain;

enum {
    //System 1xxx
    ILMUnsupportedSystemVersionError = 1000,
    ILMInitializationMissing = 1001,
    ILMInvalidArgumentsError = 1002,
    ILMInternalError = 1003,

    //Files 2xxx
    ILMFileNotFound = 2000,

    //Network 3xxx
    ILMInternetNotConnectedError = 3000,
    ILMInvalidURLForWebImageView = 3001,
    ILMUnauthorizedAccessTokenError = 3002,
    ILMURLConnectionCouldNotBeCreated = 3003,
    ILMURLUnsupportedURLResponseType = 3004,
    ILMTimeoutError = 3005,
    ILMUnauthorized = 3006,
    ILMInvalidURLFormat = 3007,
    ILMInvalidContent = 3008,

    //Location 4xxx
    ILMLocationScanningError = 4000,
    ILMLocationNotFound = 4001,
    ILMLocationProvidersUnavaialble = 4002,
    ILMLocationInvalidRequestParams = 4003,
    ILMLocationUnavailable = 4004,
    ILMLocationUnauthorized = 4005,

    //Ads 5xxx
    ILMInvalidAdType = 5000,
    ILMMissingAdType = 5001,
    ILMInterstitialAdAlreadyLoaded = 5002,
    ILMInvalidAdRequest = 5003,
    ILMAdRequestNoFill = 5004,
    ILMAdsDisabled = 5005

};

@interface ILMError : NSError

// FIXME: remove the properties below and use the NSError's userInfo Dictionary to store the data. (https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSError_Class/Reference/Reference.html)

@property (nonatomic, strong) NSDictionary *extraInfo;

- (id)initWithDomain:(NSString *)domain code:(NSInteger)code description:(NSString *)description;

+ (ILMError *)errorWithDomain:(NSString *)domain code:(NSInteger)code description:(NSString *)description;

+ (ILMError *)errorWithException:(NSException *)exception;

@end
