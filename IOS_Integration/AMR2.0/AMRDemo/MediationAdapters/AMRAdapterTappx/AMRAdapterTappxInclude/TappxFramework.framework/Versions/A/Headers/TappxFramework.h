//
//  TappxFramework.h
//  TappxFramework
//
//  Created by David Alarcon on 01/01/2017.
//  Copyright © 2017 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TappxAdapterContainer.h"

@interface TappxFramework : NSObject <TappxAdapterContainer>

+ (void)addTappxKey:(NSString*)clientId;

+ (NSString*)versionSDK;

/*
+ (void)loadAdapters:(NSArray *)newAdapters;
+ (void)loadAdapter:(id<TappxAdapter>)adapter;
 */

@end
