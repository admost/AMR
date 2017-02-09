//
// PNAdConstants.h
//
// Created by Csongor Nagy on 19/06/14.
// Copyright (c) 2014 PubNative
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

FOUNDATION_EXPORT NSInteger  const kPNPadding;
FOUNDATION_EXPORT NSInteger  const kPNPortraitBannerWidth;
FOUNDATION_EXPORT NSInteger  const kPNPortraitBannerHeigth;
FOUNDATION_EXPORT NSInteger  const kPNLandscapeBannerWidth;
FOUNDATION_EXPORT NSInteger  const kPNLandscapeBannerHeigth;

FOUNDATION_EXPORT NSString * const kPNAdConstantAPIModelStatusSuccess;
FOUNDATION_EXPORT NSInteger  const kPNAdConstantShowTimeForImpression;

FOUNDATION_EXPORT NSInteger  const kPNAdConstantRequestDefaultTimeout;
FOUNDATION_EXPORT NSString * const kPNAdConstantRequestAPINativeUrlString;
FOUNDATION_EXPORT NSString * const kPNAdConstantRequestAPINativeVideoUrlString;
FOUNDATION_EXPORT NSString * const kPNAdConstantRequestAPIImageUrlString;
FOUNDATION_EXPORT NSString * const kPNAdConstantMethodGET;

FOUNDATION_EXPORT NSString * const kPNAdConstantRequestParametersIpadDeviceName;
FOUNDATION_EXPORT NSString * const kPNAdConstantRequestParametersIphoneDeviceName;
FOUNDATION_EXPORT NSInteger  const kPNAdConstantRequestParametersDefaultAdCount;
FOUNDATION_EXPORT NSString * const kPNAdConstantRequestParametersDefaultNoUserID;

FOUNDATION_EXPORT NSString * const kPNAdConstantTrackingConfirmedAdsKey;
FOUNDATION_EXPORT NSString * const kPNAdConstantTrackingBeaconImpressionTypeString;

FOUNDATION_EXPORT NSString * const kPNAdConstantSponsoredContentString;

@interface PNAdConstants : NSObject

+ (NSString*)version;
+ (UIColor*)pubnativeColor;

@end
