//
// VastContainer.h
//
// Created by Csongor Nagy on 12/08/14.
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

@interface VastContainer : NSObject

@property (nonatomic, strong) NSString	*adId;
@property (nonatomic, strong) NSString	*adSystem;
@property (nonatomic, strong) NSString	*adTitle;
@property (nonatomic, strong) NSString	*adDescription;
@property (nonatomic, strong) NSString	*impressionID;

@property (nonatomic, strong) NSString	*duration;

@property (nonatomic, strong) NSString	*trackingCreativeView;
@property (nonatomic, strong) NSString	*trackingStart;
@property (nonatomic, strong) NSString	*trackingFirstQuartile;
@property (nonatomic, strong) NSString	*trackingMidpoint;
@property (nonatomic, strong) NSString	*trackingThirdQuartile;
@property (nonatomic, strong) NSString	*trackingComplete;
@property (nonatomic, strong) NSString	*trackingMute;
@property (nonatomic, strong) NSString	*trackingUnmute;
@property (nonatomic, strong) NSString	*trackingPause;
@property (nonatomic, strong) NSString	*trackingFullscreen;

@property (nonatomic, strong) NSString	*clickThrough;

@property (nonatomic, strong) NSString	*mediaFile;
@property (nonatomic, strong) NSString	*mediaHeight;
@property (nonatomic, strong) NSString	*mediaWidth;
@property (nonatomic, strong) NSString	*mediaType;
@property (nonatomic, strong) NSString	*mediaDelivery;
@property (nonatomic, strong) NSString	*mediaScalable;

@end
