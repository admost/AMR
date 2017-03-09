//
//  Copyright © 2017 IronSource. All rights reserved.
//

#ifndef IRONSOURCE_CONFIGURATION_H
#define IRONSOURCE_CONFIGURATION_H

#import <Foundation/Foundation.h>
#import "ISGender.h"

@interface ISConfigurations : NSObject

@property (nonatomic, strong)   NSString            *userId;
@property (nonatomic, strong)   NSString            *appKey;
@property (nonatomic, strong)   NSString            *segment;
@property (nonatomic, strong)   NSDictionary        *rewardedVideoCustomParameters;
@property (nonatomic, strong)   NSDictionary        *offerwallCustomParameters;
@property (nonatomic, strong)   NSString            *version;
@property (nonatomic, strong)   NSNumber            *adapterTimeOutInSeconds;
@property (nonatomic, strong)   NSNumber            *maxNumOfAdaptersToLoadOnStart;
@property (nonatomic, strong)   NSString            *plugin;
@property (nonatomic, strong)   NSString            *pluginVersion;
@property (nonatomic, strong)   NSString            *pluginFrameworkVersion;
@property (nonatomic, strong)   NSNumber            *maxVideosPerIteration;
@property (nonatomic, assign)   NSInteger           userAge;
@property (nonatomic, assign)   ISGender            userGender;
@property (nonatomic, assign)   BOOL                trackReachability;
@property (nonatomic, strong)   NSString            *dynamicUserId;

+ (ISConfigurations *)configurations;

@end

#endif
