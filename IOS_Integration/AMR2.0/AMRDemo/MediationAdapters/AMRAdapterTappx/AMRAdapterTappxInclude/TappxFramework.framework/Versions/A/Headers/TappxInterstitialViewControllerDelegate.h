//
//  TappxInterstitialViewControllerDelegate.h
//  TappxFramework
//
//  Created by Sara Victor Fernandez on 3/1/2017.
//  Copyright © 2017 Tappx. All rights reserved.
//

#ifndef TappxInterstitialViewControllerDelegate_h
#define TappxInterstitialViewControllerDelegate_h

@class TappxInterstitialViewController;
#import "TappxErrorAd.h"

@protocol TappxInterstitialViewControllerDelegate <NSObject>

-(UIViewController*)presentViewController;

@optional

-(void) tappxInterstitialViewControllerDidFinishLoad:(TappxInterstitialViewController*) viewController;
-(void) tappxInterstitialViewControllerDidPress:(TappxInterstitialViewController*) viewController;
-(void) tappxInterstitialViewControllerDidClose:(TappxInterstitialViewController*) viewController;
-(void) tappxInterstitialViewControllerDidFail:(TappxInterstitialViewController*) viewController withError:(TappxErrorAd*) error;
-(void) tappxInterstitialViewControllerDidAppear:(TappxInterstitialViewController*) viewController;

@end

#endif /* TappxInterstitialViewControllerDelegate_h */
