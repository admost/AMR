//
//  MSMAdHandlerInitializer.h
//  DP
//
//  Created by Tolga Seremet on 01/09/15.
//  Copyright (c) 2015 Masomo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ADMAdHandlerInitializer : NSObject
@property (nonatomic, assign) BOOL shouldShowInterstitial;
+ (instancetype)SharedInstance;
@end
