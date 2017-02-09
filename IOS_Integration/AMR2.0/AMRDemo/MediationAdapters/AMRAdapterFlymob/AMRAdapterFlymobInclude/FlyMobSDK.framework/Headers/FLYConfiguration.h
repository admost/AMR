//
//  FLYConfiguration.h
//  InAppTest
//
//  Created by Ivan Kozlov on 30/05/16.
//  Copyright © 2016 Ivan Kozlov. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FLYInterstitialModel;

typedef void (^FLYConfigurationSuccessBlock)(FLYInterstitialModel *interstitialModel);
typedef void (^FLYConfigurationFailureBlock)(NSError *error);

@interface FLYConfiguration : NSObject

@property(nonatomic) BOOL coppa;
@property(nonatomic) BOOL dnt;
@property(nonatomic) BOOL testing;

+(instancetype)sharedInstance;

-(NSDictionary *)dictionaryRepresentation:(NSUInteger)zoneID;

@end