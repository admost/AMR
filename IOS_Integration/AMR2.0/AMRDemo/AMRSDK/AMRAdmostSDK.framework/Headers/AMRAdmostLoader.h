//
//  AMRAdmostLoader.h
//  AMRAdmostSDK
//
//  Created by Tolga Seremet on 05/10/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <Foundation/Foundation.h>
@class AMRAdmostLoader;

@protocol AMRAdmostLoaderDelegate <NSObject>
@optional
- (void)admostLoader:(AMRAdmostLoader *)loader didReceiveMediationZones:(NSArray *)zoneIds;
- (void)admostLoader:(AMRAdmostLoader *)loader didFailWithError:(NSError *)error;

- (void)didReceiveMediationZones:(NSArray *)zoneIds __attribute__((deprecated("Please use new protocol")));
- (void)didFailWithError:(NSError *)error __attribute__((deprecated("Please use new protocol")));
@end

@interface AMRAdmostLoader : NSObject
@property (weak) id<AMRAdmostLoaderDelegate> delegate;
@property (readonly) NSArray *zoneIds;
/**
 * Initialize Loader with custom parameters
 * screen_name and game_type parameters should be set in custom parameters
 */
+ (instancetype)admostLoaderWithPBK:(NSString *)PBK
                   customParameters:(NSDictionary *)parameters;
- (void)load;

@end
