//
//  PNAdRequestParameters.h
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

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <AdSupport/AdSupport.h>

@interface PNAdRequestParameters : NSObject

@property (nonatomic, strong) NSString  *app_token;
@property (nonatomic, strong) NSString  *bundle_id;
@property (nonatomic, strong) NSString  *zone_id;
@property (nonatomic, strong) NSNumber  *ad_count;
@property (nonatomic, strong) NSString  *user_agent;
@property (nonatomic, strong) NSString  *os;
@property (nonatomic, strong) NSString  *os_version;
@property (nonatomic, strong) NSString  *device_model;
@property (nonatomic, strong) NSString  *ip;
@property (nonatomic, strong) NSString  *locale;
@property (nonatomic, strong) NSString  *icon_size;
@property (nonatomic, strong) NSString  *banner_size;
@property (nonatomic, strong) NSString  *portrait_banner_size;
@property (nonatomic, strong) NSString  *device_resolution;
@property (nonatomic, strong) NSString  *device_type;
@property (nonatomic, strong) NSString  *latitude;
@property (nonatomic, strong) NSString  *longitude;
@property (nonatomic, strong) NSString  *gender;
@property (nonatomic, strong) NSString  *age;
@property (nonatomic, strong) NSString  *keywords;
@property (nonatomic, strong) NSString  *partner;
@property (nonatomic, strong) NSString  *apple_idfa;
@property (nonatomic, strong) NSString  *apple_idfa_sha1;
@property (nonatomic, strong) NSString  *apple_idfa_md5;
@property (nonatomic, strong) NSString  *android_imei;
@property (nonatomic, strong) NSString  *android_imei_sha1;
@property (nonatomic, strong) NSString  *android_imei_md5;
@property (nonatomic, strong) NSString  *mac_address;
@property (nonatomic, strong) NSString  *mac_address_sha1;
@property (nonatomic, strong) NSString  *mac_address_md5;
@property (nonatomic, strong) NSString  *no_user_id;
@property (nonatomic, strong) NSString  *server_integration;

+ (instancetype)requestParameters;
- (void)fillWithDefaults;
@end
