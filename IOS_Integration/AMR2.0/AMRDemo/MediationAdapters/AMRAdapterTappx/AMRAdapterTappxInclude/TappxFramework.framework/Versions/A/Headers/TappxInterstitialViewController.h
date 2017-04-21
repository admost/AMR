//
//  TappxInterstitialViewController.h
//  TappxFramework
//
//  Created by Sara Victor Fernandez on 3/1/2017.
//  Copyright © 2017 Tappx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TappxInterstitialViewDelegate.h"
#import "TappxInterstitialViewControllerDelegate.h"

@class TappxSettings;

@interface TappxInterstitialViewController: UIViewController <TappxInterstitialViewDelegate>
@property (nonatomic, assign) bool isReady;
- (instancetype)initWithDelegate:(id<TappxInterstitialViewControllerDelegate>)delegate;

-(void)setAutoShowWhenReady:(BOOL)autoShow;
- (void)load:(TappxSettings*)settings;
- (void)load;
- (bool)isReady;
- (void)show;
@end
