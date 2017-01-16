//
//  PNCacheManager.h
//  PubNativeDemo
//
//  Created by Csongor Nagy on 18/12/14.
//  Copyright (c) 2014 PubNative. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PNCroissantCache.h"

@interface PNCacheManager : NSObject

typedef void (^PNCacheManagerCompletionBlock)(NSData *data);

+ (void)dataWithURLString:(NSString*)urlString
               andCompletion:(PNCacheManagerCompletionBlock)completionBlock;

@end
