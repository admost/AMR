//
//  Mobusi.h
//  Mobusi
//
//  Created by mobusi on 12/1/15.
//  Copyright (c) 2015 Mobusi. All rights reserved.
//
//  Mobusi SDK 2.3.3

#import <CoreLocation/CoreLocation.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <CoreTelephony/CTCarrier.h>
#import <AVFoundation/AVFoundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <ImageIO/ImageIO.h>
#import <MobileCoreServices/MobileCoreServices.h>

#import <Mobusi/MADMobusiDelegate.h>


/**
 *  Mobusi
 */
@interface Mobusi : NSObject

/**
 *  Start Mobusi
 */
+ (void)start;

/**
 *  Show Ads
 *
 *  @param zoneId   Zone ID
 *  @param delegate Mobusi Delegate
 */
+ (void)showAdsWithZoneId:(NSString *)zoneId delegate:(UIViewController<MADMobusiDelegate> *)delegate;

/**
 *  Hide Ads
 */
+ (void)hideAds;

/**
 *  Show Ads Instantly
 *
 *  @return Result
 */
+ (BOOL)showInstantly;

/**
 *  Refresh Manual Banner
 */
+ (void)refreshBanner;

/**
 *  Enable Logs
 *
 *  @param enabled Enabled
 */
+ (void)setLogEnabled:(BOOL)enabled;

/**
 * Cocos2D Project
 *
 * @param enabled Enabled
 */
+ (void)setCocos2DProject:(BOOL)enabled;

/**
 * Unity Project
 *
 * @param enabled Enabled
 */
+ (void)setUnityProject:(BOOL)enabled;

@end
