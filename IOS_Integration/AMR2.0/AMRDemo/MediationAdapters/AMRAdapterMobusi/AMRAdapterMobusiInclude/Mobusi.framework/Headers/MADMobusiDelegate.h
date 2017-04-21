//
//  MADMobusiDelegate.h
//  Mobusi
//
//  Created by mobusi on 13/1/15.
//  Copyright (c) 2015 Mobusi. All rights reserved.
//

#import <Mobusi/MADAdvertView.h>


/**
 *  Advert Type
 */
typedef NS_ENUM(NSUInteger, MADType)
{
    /**
     *  Banner
     */
    MADBanner = 0,
    
    /**
     *  Interstitial
     */
    MADInterstitial,
    
    /**
     *  Video
     */
    MADVideo,
    
    /**
     *  VastVideo
     */
    MADVastVideo
};


/**
 *  Mobusi Delegate
 */
@protocol MADMobusiDelegate

@optional

/**
 *  Advert Loaded
 *
 *  @param advert Advert View
 *  @param type Advert Type
 */
- (void)advertLoaded:(MADAdvertView *)advert type:(MADType)type;

/**
 *  Advert Will Present Screen
 *
 *  @param type   Advert Type
 *  @param zoneId Zone ID
 */
- (void)advertWillPresentScreen:(MADType)type zone:(NSString *)zoneId;

/**
 *  Advert Did Present Screen
 *
 *  @param type   Advert Type
 *  @param zoneId Zone ID
 */
- (void)advertDidPresentScreen:(MADType)type zone:(NSString *)zoneId;

/**
 *  Advert Will Dismiss Screen
 *
 *  @param type   Advert Type
 *  @param zoneId Zone ID
 */
- (void)advertWillDismissScreen:(MADType)type zone:(NSString *)zoneId;

/**
 *  Advert Did Dismiss Screen
 *
 *  @param type   Advert Type
 *  @param zoneId Zone ID
 */
- (void)advertDidDismissScreen:(MADType)type zone:(NSString *)zoneId;

/**
 *  Advert Did Interact
 *
 *  @param type Advert Type
 *  @param info   Advert Params
 */
- (void)advertDidInteract:(MADType)type withParams:(NSDictionary *)info;

/**
 * Advert Web View Did Close
 */
- (void)advertWebViewDidClose;

/**
 * Advert Request Fail
 */
- (void)advertsRequestFail;

@end
