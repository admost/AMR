//
//  Pubnative.h
//
//  Created by David Martin on 12/12/14.
//  Copyright (c) 2014 PubNative
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Basic
#import "PNAdRequest.h"
#import "PNAdRenderingManager.h"
#import "PNTrackingManager.h"
#import "PubnativeAdDelegate.h"
#import "PubnativeExtension.h"

// In feed
#import "PNTableViewManager.h"
#import "PNBannerTableViewCell.h"
#import "PNCarouselTableViewCell.h"
#import "PNIconTableViewCell.h"
#import "PNNativeTableViewCell.h"
#import "PNVideoTableViewCell.h"

// ViewControllers
#import "PNIconViewController.h"
#import "PNBannerViewController.h"
#import "PNInterstitialAdViewController.h"
#import "PNVideoBannerViewController.h"
#import "PNVideoInterstitialViewController.h"
#import "PNGameListAdViewController.h"

// Ad

// Types and Contstants
//================================
typedef NS_ENUM(NSInteger, Pubnative_AdType) {
    Pubnative_AdType_Banner             = 0,
    Pubnative_AdType_VideoBanner        = 1,
    Pubnative_AdType_Interstitial       = 2,
    Pubnative_AdType_Icon               = 3,
    Pubnative_AdType_VideoInterstitial  = 4,
    Pubnative_AdType_GameList           = 5
};

// Pubnative simplified interface
//================================

@interface Pubnative : NSObject

+ (void)requestAdType:(Pubnative_AdType)type
       withParameters:(PNAdRequestParameters*)parameters
          andDelegate:(NSObject<PubnativeAdDelegate>*)delegate;

+ (PNTableViewCell*)dequeueFeedType:(Pubnative_FeedType)feedType;
+ (CGFloat)heightForRowType:(Pubnative_FeedType)feedType;

@end
