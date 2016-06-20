//
//  ADMAdLoadedDelegate.h
//  ADMStaticLib
//
//  Created by Tolga Seremet on 01/06/16.
//  Copyright © 2016 kokteyl. All rights reserved.
//

#ifndef ADMAdLoadedDelegate_h
#define ADMAdLoadedDelegate_h


#endif /* ADMAdLoadedDelegate_h */

@protocol ADMAdLoadedDelegate
@optional
- (void)didReceiveAd:(id)banner
        forPlacement:(NSString*)placement;
- (void)didFailToReceiveAd:(id)banner
              forPlacement:(NSString*)placement;
- (void)didReceiveAd:(id)banner
        forIndexPath:(NSIndexPath*)indexPath;
- (void)didFailToReceiveAdForPlacement:(NSString*)placement;
- (void)didFailToReceiveAdForPlacement:(NSString*)placement sender:(id)sender;
- (void)didDismissInterstitialForPlacement:(NSString*)placement;
- (void)didReceiveInterstitial:(id)banner forPlacement:(NSString*)placement;
- (void)didFailToReceiveInterstitial:(id)banner forPlacement:(NSString*)placement;
- (void)didFailToReceiveInterstitialForPlacement:(NSString*)placement;
- (void)didFailToReceiveInterstitialForPlacement:(NSString*)placement sender:(id)sender;


- (void)didReceiveAd:(id)banner;
- (void)didFailToReceiveAdForIndexPath:(NSIndexPath*)indexPath;
- (void)didFailToReceiveAdForIndexPath:(NSIndexPath *)indexPath sender:(id)sender;
- (void)didDismissAdForIndexPath:(NSIndexPath*)indexPath;
@end
