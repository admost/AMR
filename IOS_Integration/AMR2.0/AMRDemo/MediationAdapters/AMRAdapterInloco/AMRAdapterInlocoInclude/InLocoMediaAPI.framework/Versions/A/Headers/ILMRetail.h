//
//  UBRetail.h
//  InLocoMediaAPI
//
//  Created by Luis Medeiros on 11/14/13.
//  Copyright (c) 2013 InLocoMedia. All rights reserved.
//

//Represents a retail store to the maps API
@interface ILMRetail : NSObject

@property (nonatomic) NSString *identifier;
@property (nonatomic) NSNumber *version;
@property (nonatomic) NSString *name;
@property (nonatomic) NSString *street;
@property (nonatomic) NSString *city;
@property (nonatomic) NSString *state;
@property (nonatomic) NSString *phone;
@property (nonatomic) NSString *website;
@property (nonatomic) NSString *desc;
@property (nonatomic) NSString *imageUrl;
@property (nonatomic) NSString *imageThumbnailUrl;

@property (nonatomic) NSNumber *latitude;
@property (nonatomic) NSNumber *longitude;

+ (NSArray *)parseArrayFromJSON:(NSData *)data error:(NSError **)err;

@end