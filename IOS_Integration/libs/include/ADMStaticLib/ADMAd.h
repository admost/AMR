//
//  MSMAd.h
//  DP
//
//  Created by Tolga Seremet on 25/08/15.
//  Copyright (c) 2015 Masomo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    ADMAdCellTypeTableViewCell = 1,
    ADMAdCellTypeTableViewCellLarge,
    ADMAdCellTypeCollectionViewCell,
    ADMAdCellTypeCollectionViewCellRow,
    ADMAdCellTypeCollectionViewCellRowLarge,
    ADMAdCellTypeView
} ADMAdCellType;
typedef enum{
    ADMAdHandlerBannerPlacementTypeBanner = 1,
    ADMAdHandlerBannerPlacementTypeNative = 2,
    ADMAdHandlerBannerPlacementTypeNativeInstall = 3,
    ADMAdHandlerBannerPlacementTypeVideo = 4
}ADMAdHandlerBannerPlacementType;

@interface ADMAd : NSObject
@property (nonatomic, strong) NSIndexPath* indexPath;
@property (nonatomic, strong, readonly) NSString* cellIdentifier;
@property (nonatomic, strong, readonly) NSString* cellIClassName;
@property (nonatomic, assign, readonly) float cellHeight;
@property (nonatomic, strong) id banner;
@property (nonatomic, assign) BOOL isLoaded;
@property (nonatomic, assign) BOOL isFailed;
@property (nonatomic, assign) BOOL isMarkedAsFailed;
@property (nonatomic, assign) ADMAdHandlerBannerPlacementType bannerPlacementType;
@property (nonatomic, assign) ADMAdCellType cellType;
@property (nonatomic, assign) BOOL isBig;
- (instancetype)initWithIndexPath:(NSIndexPath*)indexPath
                         cellType:(ADMAdCellType)cellType
                            isBig:(BOOL)isBig;
@end

@interface ADMAdPlaceHolder : NSObject @end

@protocol ADMAdProperties <NSObject>
@optional
+ (float)heightForCellForBanner:(id)banner;
+ (float)heightForCellForBanner:(id)banner forCellType:(ADMAdCellType)cellType;
@end
