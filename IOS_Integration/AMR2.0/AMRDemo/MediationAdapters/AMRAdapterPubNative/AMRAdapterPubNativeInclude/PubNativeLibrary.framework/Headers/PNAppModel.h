//
//  PNAppModel.h
//
//  Created by Csongor Nagy on 04/06/14.
//  Copyright (c) 2014 PubNative
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "PNYADMJSONApiModel.h"

@protocol PNAppModel

@property (strong, nonatomic) NSString  *name;
@property (strong, nonatomic) NSString  *platform;
@property (strong, nonatomic) NSString  *review;
@property (strong, nonatomic) NSString  *review_url;
@property (strong, nonatomic) NSArray   *review_pros;
@property (strong, nonatomic) NSArray   *review_cons;
@property (strong, nonatomic) NSString  *publisher;
@property (strong, nonatomic) NSString  *developer;
@property (strong, nonatomic) NSString  *version;
@property (strong, nonatomic) NSString  *size;
@property (strong, nonatomic) NSString  *age_rating;
@property (strong, nonatomic) NSString  *url_scheme;
@property (strong, nonatomic) NSString  *store_rating;
@property (strong, nonatomic) NSString  *store_description;
@property (strong, nonatomic) NSString  *store_url;
@property (strong, nonatomic) NSString  *store_id;
@property (strong, nonatomic) NSArray   *store_categories;
@property (strong, nonatomic) NSString  *release_date;
@property (strong, nonatomic) NSString  *total_ratings;
@property (strong, nonatomic) NSString  *installs;
@property (strong, nonatomic) NSString  *category;
@property (strong, nonatomic) NSString  *sub_category;

@end

@interface PNAppModel : PNYADMJSONApiModel <PNAppModel>

@end