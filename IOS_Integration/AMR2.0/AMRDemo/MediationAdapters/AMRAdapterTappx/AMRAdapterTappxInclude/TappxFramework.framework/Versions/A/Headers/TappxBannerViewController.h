	//
//  TappxBannerViewController.h
//  TappxFramework
//
//  Created by Sara Victor Fernandez on 3/1/2017.
//  Copyright © 2017 Tappx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TappxBannerViewControllerDelegate.h"
#import "TappxFramework.h"
#import "TappxSettings.h"
#import "TappxBannerCustomView.h"

@interface TappxBannerViewController : UIViewController <TappxBannerViewControllerDelegate>

- (void)tappxBannerviewDidPress:(TappxBannerCustomView* _Nullable )view;

- (instancetype _Nonnull)initWithDelegate:(id<TappxBannerViewControllerDelegate> _Nullable)delegate andSize:(TappxBannerSize)size andPosition:(TappxBannerPosition)position;

- (instancetype _Nonnull)initWithDelegate:(id<TappxBannerViewControllerDelegate> _Nullable)delegate andSize:(TappxBannerSize)size andLocation:(CGPoint)location;

- (instancetype _Nonnull)initWithDelegate:(id<TappxBannerViewControllerDelegate> _Nullable)delegate andSize:(TappxBannerSize)size andView:(UIView* _Nonnull)viewAd;

- (void)load:(TappxSettings* _Nonnull)settings;
- (void)load;
- (void)removeBanner;


@end
