//
//  FlyMobInterstitial.h
//  InAppTest
//
//  Created by Ivan Kozlov on 31/05/16.
//  Copyright © 2016 Ivan Kozlov. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UIViewController;

@protocol FlyMobInterstitialDelegate;

@interface FlyMobInterstitial : NSObject

@property(nonatomic) NSUInteger zoneID;
@property(nonatomic) BOOL isReady;
@property(nonatomic, weak) id<FlyMobInterstitialDelegate> delegate;

+(instancetype)interstitialWithZoneID:(NSUInteger)zoneID;

-(void)loadAd;

-(void)showFromViewController:(UIViewController *)viewController;

@end

@protocol FlyMobInterstitialDelegate <NSObject>

@optional;

// Called when the ad is ready to show
-(void)interstitialDidLoadAd:(FlyMobInterstitial *)interstitial;

// Called when initial load request failed. No retry will be done
-(void)interstitialDidFailToLoadAd:(FlyMobInterstitial *)interstitial
                             error:(NSError *)error;

// Called when ad controller become visible
-(void)interstitialDidShow:(FlyMobInterstitial *)interstitial;

// Any click inside ad controller
-(void)interstitialDidClick:(FlyMobInterstitial *)interstitial;

// Called when ad controller removed from the screen
-(void)interstitialDidClose:(FlyMobInterstitial *)interstitial;

// Called in 15 min after initial loading
-(void)interstitialDidExpire:(FlyMobInterstitial *)interstitial;

@end