//
//  ILMAdRequest.h
//  InLocoMediaAPI
//
//  Created by InLocoMedia on 5/13/14.
//  Copyright (c) 2014 InLocoMedia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ILMUserProfile.h"

@interface ILMAdRequest : NSObject

//User profile used to filter the AdRequest results
@property (nonatomic, strong) ILMUserProfile *userProfile;

//Set of NSString to optimize the AdRequest results
@property (nonatomic, strong) NSMutableSet *keywords;

//Locale for the keywords
@property (nonatomic, strong) NSString *locale;

//Query for filtering the Ad Request
@property (nonatomic, strong) NSString *query;

//Id for showing a specific advertisement
@property (nonatomic, strong) NSString *advertisementId;

@property (nonatomic, assign, getter = isDevelopmentEnabled, setter = setDevelopmentEnabled :) BOOL developmentEnabled;

/**
 * Request agent string to identify the ad request's origin.
 * Third party libraries that reference the InLocoMedia SDK set this variable to denote the platform from which the ad request originated.
 * For example, if a third party ad network called "CoolAds network" mediates requests to the InLocoMedia SDK, it should set this variable with "CoolAds".
 */
@property (nonatomic, strong) NSString *requestAgent;

//Custom html that will be delivered for display ad requests in development mode.
@property (nonatomic, strong) NSString *testHtml;

//Identifier of a specific creative that was genereted after a campaign content was created
@property (nonatomic, strong) NSString *creativeId;
// AdUnit identifier
@property (nonatomic, strong) NSString *adUnitId;

//Add a Set of keywords to the AdRequest target
- (void)addKeywords:(NSSet *)keywords;

//Add a keyword to the AdRequest target
- (void)addKeyword:(NSString *)keyword;

@end