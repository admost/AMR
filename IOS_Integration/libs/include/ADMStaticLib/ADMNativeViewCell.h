//
//  SharedCollectionViewCellRowLarge.h
//  DP
//
//  Created by Tolga Seremet on 02/02/16.
//  Copyright © 2016 Masomo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ADMNativeAdContainerHelper.h"
#import "MPNativeAdRendering.h"
#import "MPNativeAdRenderingImageLoader.h"
@interface ADMNativeViewCell : UIView<MPNativeAdRendering>
@property (strong, nonatomic) IBOutlet UILabel *LBLHeadLine;
@property (strong, nonatomic) IBOutlet UIImageView *IMGLogo;
@property (strong, nonatomic) IBOutlet UIImageView *IMGBig;
@property (strong, nonatomic) IBOutlet UIButton *BTNCallToAction;
@property (strong, nonatomic) IBOutlet UIImageView *IMGStars;
@property (strong, nonatomic) IBOutlet UILabel *LBLDescription;
@property (strong, nonatomic) IBOutlet UILabel *LBLStore;
@property (strong, nonatomic) IBOutlet UILabel *LBLPrice;
@property (strong, nonatomic) IBOutlet UIImageView *iconMopub;
@property BOOL isBig;
@property BOOL isMopub;
@property BOOL isSmall50;

- (void)setVisualWithContainerHelper:(ADMNativeAdContainerHelper*)nativeAdContainerHelper isBig:(BOOL)isBig isSmall50:(BOOL)isSmall50;

@end
