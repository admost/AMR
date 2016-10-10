//
//  AMRAdmostLoader.h
//  AMRAdmostSDK
//
//  Created by Tolga Seremet on 05/10/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AMRAdmostLoaderDelegate <NSObject>
- (void)didReceiveMediationZones:(NSArray *)zoneIds;
- (void)didFailWithError:(NSError *)error;
@end

@interface AMRAdmostLoader : NSObject
@property (weak) id<AMRAdmostLoaderDelegate> delegate;

/**
 * Initialize Loader with custom parameters
 * screen_name and game_type parameters should be set in custom parameters
 */
+ (instancetype)admostLoaderWithPBK:(NSString *)PBK
                   customParameters:(NSDictionary *)parameters;
- (void)load;

@end
