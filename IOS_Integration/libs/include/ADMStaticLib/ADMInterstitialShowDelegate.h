//
//  ADMInterstitialShowDelegate.h
//  ADMStaticLib
//
//  Created by Tolga Seremet on 01/06/16.
//  Copyright © 2016 kokteyl. All rights reserved.
//

#ifndef ADMInterstitialShowDelegate_h
#define ADMInterstitialShowDelegate_h


#endif /* ADMInterstitialShowDelegate_h */

@protocol ADMInterstitialShowDelegate
@required
- (BOOL)isInterstitialLoaded;
- (void)showInterstitial;
@optional
- (void)showInterstitialFromViewController:(UIViewController *)controller;
@end