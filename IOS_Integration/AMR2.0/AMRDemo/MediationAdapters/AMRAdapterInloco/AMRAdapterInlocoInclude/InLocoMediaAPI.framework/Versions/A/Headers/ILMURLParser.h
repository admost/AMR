//
//  ILMURLParser.h
//  InLocoMediaAPI
//
//  Created by InLocoMedia on 3/10/14.
//  Copyright (c) 2014 InLocoMedia. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ILMURLParser : NSObject

- (id)initWithURL:(NSURL *)url;

- (id)initWithURLString:(NSString *)url;

- (NSString *)valueForQueryParameter:(NSString *)varName;

@end
