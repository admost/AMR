//
//  ADMHelperBase.h
//  ADMStaticLib
//
//  Created by Tolga Seremet on 28/07/16.
//  Copyright © 2016 kokteyl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ADMAdHandler.h"
#import "ADMAdHandlerDelegate.h"

@protocol ADMHelperTimeoutDelegate <NSObject>
- (void)handleTimeout;
@end

@interface ADMHelperBase : NSObject <ADMHelperTimeoutDelegate>
- (void)startInterstitialTimer;
- (void)cancelInterstitialTimer;
@property (nonatomic, assign) BOOL isTimeOuted;
@end
