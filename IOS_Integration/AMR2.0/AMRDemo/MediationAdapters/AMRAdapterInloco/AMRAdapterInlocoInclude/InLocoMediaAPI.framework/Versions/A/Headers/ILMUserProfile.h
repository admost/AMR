//
//  ILMUserProfile.h
//  InLocoMediaAPI
//
//  Created by InLocoMedia on 3/18/14.
//  Copyright (c) 2014 InLocoMedia. All rights reserved.
//

typedef enum
{
    ILMGenderUndefined = 0,
    ILMGenderMale = 1,
    ILMGenderFemale = 2
} ILMGender;

@interface ILMUserProfile : NSObject <NSCoding>

@property (nonatomic) NSUInteger minAge;
@property (nonatomic) NSUInteger maxAge;
@property (nonatomic) NSDate *birthDate;
@property (nonatomic) ILMGender gender;

/* Initialize an user profile with a age range and a gender
 Gender may be:
 ** ILMGenderUndefined
 ** ILMGenderMale
 ** ILMGenderFemale
 */
- (id)initWithMinAge:(NSUInteger)minAge andMaxAge:(NSUInteger)maxAge andGender:(ILMGender)gender;

/* Initialize an user profile with a given birth date and a gender
 Gender may be:
 ** ILMGenderUndefined
 ** ILMGenderMale
 ** ILMGenderFemale
 */
- (id)initWithBirthDate:(NSDate *)birth andGender:(ILMGender)gender;

// Transform the UserProfile in a dictionary
- (NSDictionary *)toDictionary;

// Verify if a UserProfile is valid. A UserProfile is valid when have either a birth date, or a valid age range or a gender.
- (BOOL)isValid;

/*
 Save the UserProfile instance to later use. This intance might be recovered by:
 - (void)loadAsDefaultUserProfile
 + (instancetype)defaultsUserProfile
 Also, the saved instance will also be use used in the API default ILMAdRequest if you does not set the UserProfile.
 */
- (void)saveAsDefaultUserProfile;

// Loads the UserProfile saved at saveAsDefaultUserProfile in the UserProfile instance.
- (void)loadAsDefaultUserProfile;

// The method returns the instance saved at saveAsDefaultUserProfile
+ (instancetype)defaultsUserProfile;

+ (void)reset;

@end