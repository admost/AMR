//
//  ADMAdHandlerDelegate.h
//  ADMStaticLib
//
//  Created by Bora-Mac on 15/04/16.
//  Copyright © 2016 kokteyl. All rights reserved.
//

#ifndef ADMAdHandlerDelegate_h
#define ADMAdHandlerDelegate_h


#endif /* ADMAdHandlerDelegate_h */

@protocol ADMAdHandlerDelegate
@required
- (void)didFailToReceiveAd;
@optional
- (void)didReceiveAd:(id)banner
        forIndexPath:(NSIndexPath*)indexPath;
- (void)didReceiveAd:(id)banner
        forPlacement:(NSString*)placement;
- (void)didFailToReceiveAd:(id)banner
              forPlacement:(NSString*)placement;
- (void)didFailToReceiveAdForIndexPath:(NSIndexPath*)indexPath;
- (void)didReceiveAd:(id)banner;
- (void)didShowAd;
- (void)didDismissAdForIndexPath:(NSIndexPath*)indexPath;
- (void)didDismissInterstitialForPlacement:(NSString*)placement;
- (void)didReceiveInterstitial:(id)banner forPlacement:(NSString*)placement;
- (void)didFailToReceiveInterstitial:(id)banner forPlacement:(NSString*)placement;
@end

@protocol ADMInterstitialCloseDelegate
@required
- (void)didCloseInterstitial;
@end

