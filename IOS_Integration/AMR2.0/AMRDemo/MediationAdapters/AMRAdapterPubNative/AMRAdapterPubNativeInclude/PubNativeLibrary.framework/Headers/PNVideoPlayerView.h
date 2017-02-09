//
// PNVideoPlayerView.h
//
// Created by Csongor Nagy on 06/03/14.
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

#import "PNVastModel.h"
#import "VastContainer.h"
#import "PNVideoPlayer.h"
#import "PNVideoPlayerViewDelegate.h"
#import "PNVideoCacher.h"
#import "PNKAProgressLabel.h"
#import "PNTrackingManager.h"

@interface PNVideoPlayerView : UIViewController <PNVideoPlayerDelegate>

@property (nonatomic, weak) IBOutlet UIView     *videoContainer;
@property (nonatomic, weak) IBOutlet UIView     *loadContainer;
@property (nonatomic, weak) IBOutlet UIView     *skipView;
@property (nonatomic, weak) IBOutlet UIButton   *skipButton;
@property (nonatomic, weak) IBOutlet UIButton   *muteButton;
@property (nonatomic, weak) IBOutlet UIButton   *learnMoreButton;
@property (nonatomic, weak) IBOutlet UIButton   *closeButton;
@property (nonatomic, weak) IBOutlet UIButton   *fullScreenButton;

@property (nonatomic, strong) PNVastModel       *model;
@property (nonatomic, strong) VastContainer     *vastAd;
@property (nonatomic, strong) PNVideoPlayer     *videoPlayer;
@property (nonatomic, strong) PNKAProgressLabel *loadLabel;


@property (nonatomic, assign) NSInteger         skipTime;
@property (nonatomic, assign) BOOL              isMaximized;
@property (nonatomic, assign) BOOL              isCompleted;


- (id)initWithFrame:(CGRect)frame
              model:(PNVastModel*)model
           delegate:(id<PNVideoPlayerViewDelegate>)delegate;

- (void)displayCloseButton;
- (void)hideCloseButton;
- (void)displayFullscreenButton;
- (void)hideFullscreenButton;

- (void)prepareAd:(VastContainer*)ad;
- (void)showAd:(VastContainer*)ad;
- (void)close;

- (IBAction)skipAd:(id)sender;
- (IBAction)muteAd:(id)sender;
- (IBAction)learnMoreAd:(id)sender;
- (IBAction)closeAd:(id)sender;
- (IBAction)fullscreenAd:(id)sender;

@end
