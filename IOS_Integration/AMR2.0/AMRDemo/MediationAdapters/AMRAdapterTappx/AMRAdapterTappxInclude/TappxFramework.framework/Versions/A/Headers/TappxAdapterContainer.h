//
//  TappxAdapterContainer.h
//  TappxFramework
//
//  Created by David Alarcon on 02/01/2017.
//  Copyright © 2017 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TappxAdapter.h"

@protocol TappxAdapterContainer <NSObject>

//@property (class, nonatomic, copy) NSMutableArray* adapters;

+ (void)loadAdapters:(NSArray*)adapters;
+ (void)loadAdapter:(id<TappxAdapter>)adapter;
+ (id<TappxAdapter>)adapterWithId:(NSString*)id;

@end
