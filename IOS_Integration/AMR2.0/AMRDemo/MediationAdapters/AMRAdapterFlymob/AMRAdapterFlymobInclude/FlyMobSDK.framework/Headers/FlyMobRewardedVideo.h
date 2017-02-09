//
//  FlyMobRewardedVideo.h
//  FlyMobSDK
//
//  Created by Ivan Kozlov on 29/08/16.
//  Copyright © 2016 FlyMob. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UIViewController;

@protocol FlyMobRewardedVideoDelegate;

@interface FlyMobRewardedVideo : NSObject

@property(nonatomic) NSUInteger zoneID;
@property(nonatomic) BOOL isReady;
@property(nonatomic, weak) id<FlyMobRewardedVideoDelegate> delegate;

+(instancetype)rewardedVideoWithZoneID:(NSUInteger)zoneID;

-(void)loadAd;

-(void)showFromViewController:(UIViewController *)viewController;

@end

@protocol FlyMobRewardedVideoDelegate <NSObject>

@optional

// Called when the ad is ready to show
-(void)rewardedVideoDidLoadAd:(FlyMobRewardedVideo *)rewardedVideo;

// Called when initial load request failed. No retry will be done
-(void)rewardedVideoDidFailToLoadAd:(FlyMobRewardedVideo *)rewardedVideo
                              error:(NSError *)error;

// Called when ad controller become visible
-(void)rewardedVideoDidShow:(FlyMobRewardedVideo *)rewardedVideo;

// Called when video finished
-(void)rewardedVideoDidComplete:(FlyMobRewardedVideo *)rewardedVideo;

// Called when video play started
-(void)rewardedVideoDidStart:(FlyMobRewardedVideo *)rewardedVideo;

// Called when ad controller removed from the screen
-(void)rewardedVideoDidClose:(FlyMobRewardedVideo *)rewardedVideo;

// Called in 15 min after initial loading
-(void)rewardedVideoDidExpire:(FlyMobRewardedVideo *)rewardedVideo;

@end
