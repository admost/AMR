//
//  MSMBannerHelper.h
//  DP
//
//  Created by Tolga Seremet on 08/10/15.
//  Copyright (c) 2015 Masomo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    ADMAdHandlerBannerTypeAdmob,
    ADMAdHandlerBannerTypeFacebook,
    ADMAdHandlerBannerTypeFlurry,
    ADMAdHandlerBannerTypeMopub,
    ADMAdHandlerBannerTypeInmobi,
    ADMAdHandlerBannerTypeAdcolony,
    ADMAdHandlerBannerTypeAvocarrot,
    ADMAdHandlerBannerTypeLoopMe,
    ADMAdHandlerBannerTypeAdmost,
    ADMAdHandlerBannerTypeAdx,
    ADMAdHandlerBannerTypeAmazon,
    ADMAdHandlerBannerTypeVungle,
    ADMAdHandlerBannerTypeChartboost,
    ADMAdHandlerBannerTypeAdFalcon,
    ADMAdHandlerBannerTypeMobFox,
    ADMAdHandlerBannerTypeUndefined = 0
    
    
} ADMAdHandlerBannerType;



@interface ADMBannerHelper : NSObject
@property (nonatomic, strong) NSIndexPath* indexPath;
@property (nonatomic, assign) ADMAdHandlerBannerType bannerType;
@end
