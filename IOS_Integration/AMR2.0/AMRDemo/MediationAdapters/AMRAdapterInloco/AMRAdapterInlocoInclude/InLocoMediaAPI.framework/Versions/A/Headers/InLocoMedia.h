//
//  InLocoMediaAPI.h
//  InLocoMediaAPI
//
//  Created by Luis Medeiros on 11/14/13.
//  Copyright (c) 2013 InLocoMedia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ILMModules.h"
#import "ILMAdType.h"
#import "ILMRequestDelegate.h"
#import "ILMAdvertisement.h"
#import "ILMOptions.h"
#import "ILMAdView.h"
#import "ILMURLParser.h"
#import "ILMRetail.h"
#import "ILMUserProfile.h"
#import "ILMError.h"
#import "ILMAdRequest.h"
#import "ILMInterstitialAd.h"
#import "ILMLogger.h"
#import "ILMPublicMacros.h"
#import "ILMWebImageView.h"
#import "ILMNotificationAdRequest.h"
#import "ILMNativeAdTableViewManager.h"
#import "ILMNativeAdResponse.h"
#import "ILMNativeAdManager.h"
#import "ILMNativeAdDelegate.h"

@interface InLocoMedia : NSObject

/**
 Initialize the API
 **/
+ (void)initWithOptions:(ILMOptions *)options;

/**
 Method to enable Notification Ads with location tracking. Notification can be created both when the app is running in background and when is in foreground.
 */
+ (void)enableNotificationAds;

/**
 Method to enable Notification Ads with location tracking. Notification can be created only whe app is in background.
 */
+ (void)enableNotificationAdsOnlyInBackground;

/**
 Method to disable Notification Ads.
 */
+ (void)disableNotificationAds;

/**
 Method sets the notificationAdRequest to be used on notificationAds requested
 */
+ (void)setNotiticationAdRequest:(ILMNotificationAdRequest *)notificationAdRequest;

/**
 Method to verify if NotificationAds is enabled
 */
+ (BOOL)isNotificationAdsEnabled;

/**
 Method to be called when you receive a local notification after enabling notification ads
 **/
+ (ILMAdvertisement *)didReceiveNotification:(UILocalNotification *)notification;

/**
 This method is deprecated. Please use [InLocoMedia didReceiveNotification:notification]
 **/
+ (ILMAdvertisement *)didReceivedNotification:(UILocalNotification *)notification __deprecated_msg("Use didReceiveNotification instead.");

/**
 Method to request a list of the retails registered to your application
 **/
+ (void)requestRetails:(NSObject <ILMRetailsDelegate> *)delegate;

/**
 Call it in your:
 - (void)application:(UIApplication *)application performFetchWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler
 
 In its execution, it will verify if the application should monitor location changes for notification ads.
 */
+ (void)applicationPerformFetchWithResult:(void (^)(UIBackgroundFetchResult))fetchResultBlock;

/**
 Signal to the API that your application registered to receive notifications. With this information we will start to send notification ads to your user.
 **/
+ (void)applicationDidRegisterUserNotificationSettings;

/**
 Alert the API that your application has entered in foreground state.
 **/
+ (void)applicationDidBecomeActive;

/**
 If application is in Background it will open the url associated with the notification ad clicked by the user.
 In case the application is in foreground, it will directly open the url of a received notification.
 (Not recomended to use while in foreground)
 **/
+ (void)handleNotificationWithDefaultBackgroundBehavior:(ILMAdvertisement *)ad;

@end