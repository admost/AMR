//
//  ILMAdOptions.h
//  InLocoMediaAPI
//
//  Created by InLocoMedia on 2/28/14.
//  Copyright (c) 2014 InLocoMedia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//Keys for each advertisement type that may be used for the view runtime attributes on the Interface Builder
#define ILM_ADTYPE_KEY_NOTIFICATION @"notification"

#define ILM_ADTYPE_KEY_NATIVE_SMALL @"native_small"
#define ILM_ADTYPE_KEY_NATIVE_LARGE @"native_large"

#define ILM_ADTYPE_KEY_DISPLAY_BANNER_SMALL @"display_banner_small"
#define ILM_ADTYPE_KEY_DISPLAY_BANNER_SMALL_LANDSCAPE @"display_banner_small_landscape"
#define ILM_ADTYPE_KEY_DISPLAY_BANNER_TABLET @"display_banner_small_tablet"

#define ILM_ADTYPE_KEY_DISPLAY_SMART_BANNER_PORTRAIT @"display_smart_banner_portrait"
#define ILM_ADTYPE_KEY_DISPLAY_SMART_BANNER_LANDSCAPE @"display_smart_banner_landscape"

#define ILM_ADTYPE_KEY_DISPLAY_BANNER_LARGE @"display_banner_large"
#define ILM_ADTYPE_KEY_DISPLAY_TILE @"display_tile"
#define ILM_ADTYPE_KEY_DISPLAY_MEDIUM_RECTANGLE_IAB @"display_banner_medium_rectangle_iab"
#define ILM_ADTYPE_KEY_DISPLAY_FULL_BANNER_IAB @"display_banner_full_iab"

#define ILM_ADTYPE_KEY_DISPLAY_FULLSCREEN @"display_full_screen"
#define ILM_ADTYPE_KEY_DISPLAY_FULLSCREEN_LANDSCAPE @"display_full_screen_landscape"

#define ILM_ADTYPE_KEY_DISPLAY_FULLSCREEN_TABLET @"display_full_screen_tablet"
#define ILM_ADTYPE_KEY_DISPLAY_FULLSCREEN_TABLET_LANDSCAPE @"display_full_screen_tablet_landscape"

#define ILM_ADTYPE_KEY_DISPLAY_TILE @"display_tile"

#define ILMAdTypeNotification ILMAdType.notification
#define ILMAdTypeNativeAdSmall ILMAdType.nativeSmall
#define ILMAdTypeNativeAdLarge ILMAdType.nativeLarge
#define ILMAdTypeDisplayAdBannerSmall ILMAdType.displaySmall
#define ILMAdTypeDisplayAdBannerSmallLandscape ILMAdType.displaySmallLandscape
#define ILMAdTypeDisplayAdBannerTablet ILMAdType.displayTablet
#define ILMAdTypeDisplayAdSmartBannerPortrait ILMAdType.displaySmartPortrait
#define ILMAdTypeDisplayAdSmartBannerLandscape ILMAdType.displaySmartLandscape
#define ILMAdTypeDisplayAdMediumRectangleIAB ILMAdType.displayMediumRectangleIAB
#define ILMAdTypeDisplayAdFullBannerIAB ILMAdType.displayFullIAB
#define ILMAdTypeDisplayAdBannerLarge ILMAdType.displayLarge
#define ILMAdTypeDisplayAdFullScreen ILMAdType.displayFullScreen
#define ILMAdTypeDisplayAdFullScreenLandscape ILMAdType.displayFullScreenLandscape
#define ILMAdTypeDisplayAdFullScreenTablet ILMAdType.displayFullScreenTablet
#define ILMAdTypeDisplayAdFullScreenTabletLandscape ILMAdType.displayFullScreenTabletLandscape
#define ILMAdTypeDisplayAdTile ILMAdType.displayTile

@interface ILMAdType : NSObject

@property (nonatomic, assign, readonly) CGSize size;
@property (nonatomic, strong, readonly) NSString *key;

@property (nonatomic, assign, readonly) BOOL isLandscape;
@property (nonatomic, assign, readonly) BOOL isFullscreen;
@property (nonatomic, assign, readonly) BOOL isNative;
@property (nonatomic, assign, readonly) BOOL isDisplay;
@property (nonatomic, assign, readonly) BOOL isSmart;

- (instancetype)init NS_UNAVAILABLE;

- (BOOL)isKeyEqual:(NSString *)key;

- (ILMAdType *)smartAdType;

// Recover ad type from string key.
+ (ILMAdType *)adTypeFromKey:(NSString *)key;

// Recover ad type of a given size. If there is not an ad type for the given size it will return nil.
+ (ILMAdType *)adTypeFromSize:(CGSize)size;

/// Notification
+ (ILMAdType *)notification;

/// An ad that will be filled accordingly with the nib file that was used to inflate it.
+ (ILMAdType *)nativeSmall;

/// An ad that will be filled accordingly with the nib file that was used to inflate it.
+ (ILMAdType *)nativeLarge;

/// 320x50
+ (ILMAdType *)displaySmall;

/// 480x32
+ (ILMAdType *)displaySmallLandscape;

/// 728x90
+ (ILMAdType *)displayTablet;

/// An ad that will fill the width of the screen.
/// The height will be either 50px for iphone/ipod, or 90px for ipad.
+ (ILMAdType *)displaySmartPortrait;

/// An ad that will fill the width of the screen.
/// The height will be either 32px for iphone/ipod, or 90px for ipad.
+ (ILMAdType *)displaySmartLandscape;

/// 300x250
+ (ILMAdType *)displayMediumRectangleIAB;

/// 468x60
+ (ILMAdType *)displayFullIAB;

/// 320x100
+ (ILMAdType *)displayLarge;

/// 320x480
+ (ILMAdType *)displayFullScreen;

/// 480x320
+ (ILMAdType *)displayFullScreenLandscape;

/// 768x1024
+ (ILMAdType *)displayFullScreenTablet;

/// 1024x768
+ (ILMAdType *)displayFullScreenTabletLandscape;

/// 240x240
+ (ILMAdType *)displayTile;

@end

extern CGSize CGSizeFromILMAdType(ILMAdType *adType) __deprecated_msg("Use adType.size instead");
extern ILMAdType *ILMAdTypeFromCGSize(CGSize size) __deprecated_msg("Use [ILMAdType adTypeFromSize:size] instead");