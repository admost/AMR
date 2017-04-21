//
//  TappxSettings.h
//  TappxFramework
//
//  Created by David Alarcon on 03/01/2017.
//  Copyright © 2017 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TappxFramework.h"

#define TappxGenderString(enum) [@[@"male",@"female",@"Other"] objectAtIndex:enum]
typedef NS_ENUM(NSInteger, TappxGender) {
    TappxGenderMale = 0, //"male"
    TappxGenderFemale = 1, //"female"
    TappxGenderOther = 2//"Other"
};

#define TappxMaritalString(enum) [@[@"Single",@"Living Common",@"Married", @"Divorced", @"Widowed"] objectAtIndex:enum]
typedef NS_ENUM(NSInteger, TappxMarital) {
    TappxMaritalSingle         = 0,
    TappxMaritalLivingCommon   = 1,
    TappxMaritalMarried        = 2,
    TappxMaritalDivorced       = 3,
    TappxMaritalWidowed        = 4
};

#define TappxBannerSizeString(enum) [@[@"Smart Banner", @"320x50",@"728x90",@"300x250"] objectAtIndex:enum]
typedef NS_ENUM(NSInteger, TappxBannerSize) {
    TappxBannerSmartBanner      = 0,
    TappxBannerSize320x50       = 1,
    TappxBannerSize728x90       = 2,
    TappxBannerSize300x250      = 3
};

#define TappxBannerPositionString(enum) [@[@"TOP", @"BOTTOM", @"CUSTOM"] objectAtIndex:enum]
typedef NS_ENUM(NSInteger, TappxBannerPosition) {
    TappxBannerPositionTop      = 0,
    TappxBannerPositionBottom   = 1,
    TappxBannerPositionCustom   = 2
};

@interface TappxSettings : NSObject

@property(nonatomic, copy, nonnull) NSString* sdkType;
@property(nonatomic, copy, nullable) NSString* mediator;
@property(nonatomic, copy, nullable) NSArray* keywords;
@property(nonatomic, copy, nullable) NSString* yearOfBirth;
@property(nonatomic, copy, nullable) NSString* age;
@property(nonatomic, assign) TappxGender gender;
@property(nonatomic, assign) TappxMarital marital;

- (instancetype _Nonnull)initWithTestId:(NSUInteger)testId;

@end
