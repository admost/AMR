//
//  AMRNativeAdBaseView.h
//  AMRSDK
//
//  Created by Tolga Seremet on 17/09/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AMRTypes.h"

@class AMRPlacement;

@protocol AMRNativeAdBaseViewDelegate <NSObject>
- (void)didDismissNativeInterstitial;
@end

extern NSString * const kAMRImageNameDefaultPrivacyIcon;

extern NSString * const kAMRNativeAssetKeyTitle;
extern NSString * const kAMRNativeAssetKeyDescription;
extern NSString * const kAMRNativeAssetKeyCallToAction;
extern NSString * const kAMRNativeAssetKeyIconURL;
extern NSString * const kAMRNativeAssetKeyCoverURL;
extern NSString * const kAMRNativeAssetKeyPrivacyURL;
extern NSString * const kAMRNativeAssetKeyIconImage;
extern NSString * const kAMRNativeAssetKeyCoverImage;
extern NSString * const kAMRNativeAssetKeyPrivacyImage;
extern NSString * const kAMRNativeAssetKeyPrivacyImageName;
extern NSString * const kAMRNativeAssetKeyClickURL;

@interface AMRNativeAdBaseView : UIView

@property (nonatomic, weak) IBOutlet UILabel *LBLTitle;
@property (nonatomic, weak) IBOutlet UILabel *LBLDescription;
@property (nonatomic, weak) IBOutlet UILabel *LBLCallToAction;
@property (nonatomic, weak) IBOutlet UIImageView *IMGIcon;
@property (nonatomic, weak) IBOutlet UIImageView *IMGCover;
@property (nonatomic, weak) IBOutlet UIImageView *IMGCoverBG;
@property (nonatomic, weak) IBOutlet UIImageView *IMGPrivacyIcon;
@property (nonatomic, weak) IBOutlet UIButton *BTNClick;
@property (nonatomic, weak) IBOutlet UIView *trackingView;
@property (nonatomic, assign) AMRBannerSize bannerSize;
@property (nonatomic, weak) id<AMRNativeAdBaseViewDelegate> delegate;

+ (instancetype)baseViewWithPlacement:(AMRPlacement *)placement;
- (void)decorateWithDictionary:(NSDictionary *)dictionary;
@end
