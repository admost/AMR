//
//  TappxBannerViewControllerDelegate.h
//  TappxFramework
//
//  Created by Sara Victor Fernandez on 3/1/2017.
//  Copyright © 2017 Tappx. All rights reserved.
//

#ifndef TappxBannerViewControllerDelegate_h
#define TappxBannerViewControllerDelegate_h
@class TappxBannerViewController;
#import "TappxErrorAd.h"

@protocol TappxBannerViewControllerDelegate <NSObject>

-(UIViewController*)presentViewController;

@optional
-(void) tappxBannerViewControllerDidFinishLoad:(TappxBannerViewController*) vc;
-(void) tappxBannerViewControllerDidPress:(TappxBannerViewController*) vc;
-(void) tappxBannerViewControllerDidFail:(TappxBannerViewController*) vc withError:(TappxErrorAd*) error;
-(void) tappxBannerViewControllerDidClose:(TappxBannerViewController*) vc;

// mraid
/*-(void) tappxBannerViewControllerDidCollapse:(TappxBannerViewController*) vc;
-(void) tappxBannerViewControllerDidExpanse:(TappxBannerViewController*) vc;*/
@end

#endif /* TappxBannerViewControllerDelegate_h */
