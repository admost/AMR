//
//  TappxErrorAd.h
//  TappxFramework
//
//  Created by Rubén Tappx on 7/3/17.
//  Copyright © 2017 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TappxErrorCode) {
    
    /// The ad request is invalid.
    DEVELOPER_ERROR,
    
    /// The ad request was successful, but no ad was returned.
    NO_FILL,
    
    /// There was an error loading data from the network.
    NETWORK_ERROR,
    
    /// The ad server experienced a failure processing the request.
    SERVER_ERROR,
    
    /// Internal error.
    INTERNAL_ERROR,
    
    /// Received invalid response.
    UNSPECIFIED
};

@interface TappxErrorAd : NSError

-(instancetype)initCode:(TappxErrorCode)code;

-(NSString*)descriptionError;

@end
