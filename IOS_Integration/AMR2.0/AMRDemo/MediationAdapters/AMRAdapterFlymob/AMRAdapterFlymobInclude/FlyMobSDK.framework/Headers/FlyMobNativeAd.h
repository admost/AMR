//
//  FlyMobNativeAd.h
//  FlyMobSDK
//
//  Created by Ivan Kozlov on 21/06/16.
//  Copyright © 2016 FlyMob. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UIImage, UIView, UIViewController;

@protocol FlyMobNativeAdDelegate;

@interface FlyMobNativeAd : NSObject

@property(nonatomic) NSUInteger zoneID;
@property(nonatomic) BOOL isReady;

@property(nonatomic, strong) NSURL *iconURL;
@property(nonatomic, strong) NSURL *imageURL;
@property(nonatomic, copy) NSString *cta;
@property(nonatomic, copy) NSString *rating;
@property(nonatomic, copy) NSString *text;
@property(nonatomic, copy) NSString *title;

@property(nonatomic, strong) UIImage *image;
@property(nonatomic, strong) UIImage *icon;

@property(nonatomic) BOOL shouldPreloadImage;
@property(nonatomic) BOOL shouldPreloadIcon;

@property(nonatomic, weak) id<FlyMobNativeAdDelegate> delegate;

+(instancetype)nativeAdWithZoneID:(NSUInteger)zoneID;

-(void)loadAd;
-(void)registerView:(UIView *)view withViewController:(UIViewController *)viewController;

@end

@protocol FlyMobNativeAdDelegate <NSObject>

@optional;

// Called when the ad is ready to show
-(void)nativeAdDidLoadAd:(FlyMobNativeAd *)nativeAd;

// Called when initial load request failed. No retry will be done
-(void)nativeAdDidFailToLoadAd:(FlyMobNativeAd *)nativeAd error:(NSError *)error;

// Called when impression already counted (view should be visible at leat one second)
-(void)nativeAdDidShow:(FlyMobNativeAd *)nativeAd;

// Called when container view detects click
-(void)nativeAdDidClick:(FlyMobNativeAd *)nativeAd;

// Called in 15 min after initial loading
-(void)nativeAdDidExpire:(FlyMobNativeAd *)nativeAd;

@end