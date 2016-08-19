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
@property (nonatomic, assign) BOOL statusBarHidden;
@property (nonatomic, assign) BOOL revmobInitialized;
@property (nonatomic, assign) BOOL tapjoyInitialized;
+ (instancetype)SharedInstance;
@end
