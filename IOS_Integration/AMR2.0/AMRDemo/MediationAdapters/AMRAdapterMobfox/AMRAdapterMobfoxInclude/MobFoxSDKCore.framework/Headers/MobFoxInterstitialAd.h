//
//  MobFoxInterstitialVideo.h
//  MobFoxSDKSource
//
//  Created by Itamar Nabriski on 8/12/15.
//
//

#ifndef MobFoxSDKSource_MobFoxInterstitialVideo_h
#define MobFoxSDKSource_MobFoxInterstitialVideo_h

#include "MobFoxAd.h"
#import "MobFoxInterstitialCustomEvent.h"


@class MobFoxInterstitialAd;

@protocol MobFoxInterstitialAdDelegate <NSObject>


@required

- (void)MobFoxInterstitialAdDidLoad:(MobFoxInterstitialAd *)interstitial;

@optional

- (void)MobFoxInterstitialAdDidFailToReceiveAdWithError:(NSError *)error;

- (void)MobFoxInterstitialAdWillShow:(MobFoxInterstitialAd *)interstitial;

- (void)MobFoxInterstitialAdClosed;

- (void)MobFoxInterstitialAdClicked;

- (void)MobFoxInterstitialAdFinished;



@end


@interface MobFoxInterstitialAd : NSObject<MobFoxAdDelegate,MobFoxInterstitialCustomEventDelegate, NSURLSessionDelegate, NSURLSessionDataDelegate, NSURLSessionTaskDelegate>


@property (nonatomic, weak) id<MobFoxInterstitialAdDelegate> delegate;
@property (nonatomic, weak) UIViewController* rootViewController;

@property BOOL ready;
@property (strong, nonatomic) MobFoxAd* ad;
@property (nonatomic, strong) LocationServicesManager *locationServicesManager;


-(id) init:(NSString*)invh;
-(id) init:(NSString*)invh withRootViewController:(UIViewController*)root;
-(void) loadAd;
-(void) show;
+ (void)locationServicesDisabled:(BOOL)disabled;



@end

#endif
