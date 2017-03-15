//
//  AMRTypes.h
//  AMRSDK
//
//  Created by Tolga Seremet on 23/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#ifndef AMRTypes_h
#define AMRTypes_h

#import <Foundation/Foundation.h>

/** Log levels of AMRSDK. */

typedef NS_ENUM(NSInteger, AMRLogLevel){
    /// No logs
    AMRLogLevelSilent = 0,

    /// All errors logged
    AMRLogLevelError = 1,

    /// All errors and warnings logged
    AMRLogLevelWarning = 2,

    /// All errors, warnings and infos logged
    AMRLogLevelInfo = 3,

    /// ALL errors, warnings, 3rd party logs and infos logged
    AMRLogLevel3rdParty = 4,

    /// All logged, default
    AMRLogLevelAll = 99
};

/** Banner sizes to use with AMRBanner. */

typedef NS_ENUM(NSInteger, AMRBannerSize){
    /// 320+ x 50
    AMRBannerSizeHeight50 = 0,

    /// 320+ x 90
    AMRBannerSizeHeight90,

    /// 320+ x 250
    AMRBannerSizeHeight250,
};

/** Network Types of AMRSDK. */

typedef NS_ENUM(NSInteger, AMRNetworkType){
    /// NO NETWORK
    AMRNetworkTypeNoNetwork = 0,

    /// ADCOLONY
    AMRNetworkTypeAdColony,

    /// ADFALCON
    AMRNetworkTypeAdFalcon,

    /// ADMOB
    AMRNetworkTypeAdMob,

    /// ADMOST
    AMRNetworkTypeAdMost,

    /// ADX
    AMRNetworkTypeAdX,

    /// AMAZON
    AMRNetworkTypeAmazon,

    /// APPLOVIN
    AMRNetworkTypeApplovin,

    /// APPNEXT
    AMRNetworkTypeAppnext,
    
    /// AVOCARROT
    AMRNetworkTypeAvocarrot,

    /// CHARTBOOST
    AMRNetworkTypeChartboost,

    /// CONVERSANT
    AMRNetworkTypeConversant,

    /// FACEBOOK
    AMRNetworkTypeFacebook,

    /// FLURRY
    AMRNetworkTypeFlurry,

    /// FLYMOB
    AMRNetworkTypeFlymob,

    /// FYBER
    AMRNetworkTypeFyber,

    /// HYPERADS
    AMRNetworkTypeHyper,

    /// INLOCO
    AMRNetworkTypeInloco,

    /// INMOBI
    AMRNetworkTypeInMobi,
    
    /// IRONSOURCE
    AMRNetworkTypeIronsource,

    /// LOOPME
    AMRNetworkTypeLoopme,

    /// MILLENIAL
    AMRNetworkTypeMillenial,

    /// MOBFOX
    AMRNetworkTypeMobfox,

    /// MOBUSI
    AMRNetworkTypeMobusi,

    /// MOPUB
    AMRNetworkTypeMopub,

    /// NATIVEX
    AMRNetworkTypeNativeX,
    
    /// NEXTAGE
    AMRNetworkTypeNexAge,
    
    /// PUBNATIVE
    AMRNetworkTypePubNative,

    /// REVMOB
    AMRNetworkTypeRevMob,

    /// SMAATO
    AMRNetworkTypeSmaato,

    /// STARTAPP
    AMRNetworkTypeStartApp, 

    /// SUPERSONIC
    AMRNetworkTypeSupersonic,

    /// TAPJOY
    AMRNetworkTypeTapjoy,

    /// UNITY
    AMRNetworkTypeUnityAds,

    /// VUNGLE
    AMRNetworkTypeVungle
};

typedef NS_ENUM(NSInteger, AMRReachabilityNetworkStatus){
    /// Not reachable
    AMRReachabilityNetworkStatusNotReachable = 0,

    /// Reachable via Wireless LAN
    AMRReachabilityNetworkStatusViaWifi,

    /// Reachable via Wireless Wide Area Network
    AMRReachabilityNetworkStatusViaWWAN,
};

#endif /* AMRTypes_h */
