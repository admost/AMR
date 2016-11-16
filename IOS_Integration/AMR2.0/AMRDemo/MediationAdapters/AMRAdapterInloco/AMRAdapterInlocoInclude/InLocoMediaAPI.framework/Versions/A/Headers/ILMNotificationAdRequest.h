//
//  ILMNotificationAdRequest.h
//  InLocoMediaAPI
//
//  Created by Rafael Gouveia on 8/15/16.
//  Copyright © 2016 InLocoMedia. All rights reserved.
//

@interface ILMNotificationAdRequest : NSObject <NSCoding>

- (instancetype)initWithAdUnit:(NSString *)adUnit;

@property NSString *adUnit;

@end