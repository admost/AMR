//
//  TappxInterstitialViewDelegate.h
//  TappxFramework
//
//  Created by Sara Victor Fernandez on 3/1/2017.
//  Copyright © 2017 Tappx. All rights reserved.
//

#ifndef TappxInterstitialViewDelegate_h
#define TappxInterstitialViewDelegate_h

@class TappxInterstitialCustomView;

@protocol TappxInterstitialViewDelegate

- (void)tappxInterstitialViewDidPress:(TappxInterstitialCustomView*)interstitialView;
- (void)tappxInterstitialViewDidClose:(TappxInterstitialCustomView*)interstitialView;

@end

#endif /* TappxInterstitialViewDelegate_h */
