//
//  TappxBannerCustomView.h
//  TappxFramework
//
//  Created by David Alarcon on 09/01/2017.
//  Copyright © 2017 Tappx. All rights reserved.
//

#import <UIKit/UIKit.h>
@class TappxBannerCustomView;

@protocol TappxBannerViewDelegate <NSObject>
- (void)tappxBannerviewDidPress:(TappxBannerCustomView* _Nonnull)view;
@end

@interface TappxBannerCustomView : UIView

@property (nonatomic, weak, nullable) id<UIWebViewDelegate, TappxBannerViewDelegate> delegate;
@property (nonatomic, strong, nonnull) UIWebView* webView;
- (void)loadAdBanner:(NSString* _Nullable)interstitial withSize:(CGSize)size;
@end
